#include "Lista.h"
#include "PesteLimite.h"

//Lista::Lista():substanta(new Liniuta[50]),dim(0),capat(50)
//{
//
//}
//Lista::Lista(Liniuta const& x):dim(1),capat(50)
//{
//    this->substanta = new Liniuta[50];
//    this->substanta[0]=x;
//}
Lista::Lista(Liniuta const * const& x, int const & d):substanta(new Liniuta[d]),dim(d),capat(((d/50)+1)*50)
{
    for (int i=0;i<d;++i)
        this->substanta[i]=x[i];
}
Lista::Lista(Lista const& x):substanta(new Liniuta[x.capat]),dim(x.dim),capat(x.capat)
{
    for (int i = 0; i<dim; ++i)
        substanta[i]=x.substanta[i];
}

Lista::~Lista()
{
    delete[] substanta;
}

void Lista::push_back(Liniuta const& x)
{
    ++dim;
    if(dim>capat)
    {
        capat+=50;
        Liniuta * aux = new Liniuta[capat];
        for (int i = 0; i<dim;++i)
            aux[i]=substanta[i];
        delete[] substanta;
        substanta=aux;
    }
    substanta[dim-1]=x;
}

void Lista::pop_back()
{
    if(dim==0)
        throw PesteLimite(-1);
    --dim;
    if(dim<capat-100)
    {
        capat-=50;
        Liniuta * aux = new Liniuta[capat];
        for (int i = 0; i<dim;++i)
            aux[i]=substanta[i];
        delete[] substanta;
        substanta=aux;
    }
}

int const& Lista::size() const
{
    return dim;
}

Liniuta const& Lista::operator[](int const & x) const
{
    if(x > dim)
        throw PesteLimite(x,dim);
    if(x < 0)
        throw PesteLimite(x);
    return substanta[x];
}

std::istream& operator>>(std::istream& f,Lista& x)
{
    f>>x.dim;
    delete[] x.substanta;
    x.capat=((x.dim/50)+1)*50;
    x.substanta=new Liniuta[x.capat];
    int aux,b,i,j;
    for (i = 0; i<x.dim;++i)
    {
        f>>aux;
        for (j = 0; j<aux;++j)
        {
            f>>b;
            x.substanta[i].push_back(b);
        }
    }
    return f;
}

std::ostream& operator<<(std::ostream& g,Lista const& x)
{
    int i;
    for (i = 0 ; i < x.dim; ++i)
        g<<x[i]<<'\n';
    return g;
}

Lista const& Lista::operator= (Lista const& x)
{
    delete[] (this->substanta);
    this->capat=x.capat;
    this->dim=x.dim;
    for (int i = 0; i<this->dim; ++i)
        this->substanta[i] = x.substanta[i];
    return (*this);
}

bool Lista::operator== (Lista const& x) const
{
    if(this==(&x))
        return true;
    if(dim!=x.dim)
        return false;
    for (int i = 0; i<dim; ++i)
        if(substanta[i]!=x.substanta[i])
            return false;
    return true;
}

bool Lista::operator!= (Lista const& x) const
{
    return !((*this)==x);
}
