#include "Liniuta.h"
#include "PesteLimite.h"

Liniuta::Liniuta(int const * const & elmnt, int const & lung):lungimea(lung),capat(((lung/50)+1)*50)
{
//    capat=lung/50;
//    ++capat;
//    capat*=50;

    substanta = new int[capat];

    for(int i = 0; i < lung; ++i)
    {
        substanta[i] = elmnt[i];
    }
}
//Liniuta::Liniuta():lungimea(0),capat(50)
//{
//    substanta=new int[capat];
//}
Liniuta::Liniuta(Liniuta const& x):lungimea(x.lungimea),capat(x.capat)
{
    this->substanta=new int[capat];
    for(int i = 0; i < lungimea; ++i)
        this->substanta[i]=x.substanta[i];
}

Liniuta::~Liniuta()
{
    delete[] substanta;
//    std::cout<<"e mort\n";
}

int const& Liniuta::operator[] (int const& index) const
{
    if(index > lungimea)
        throw PesteLimite(index,lungimea);
    if(index < 0)
        throw PesteLimite(index);
    return substanta[index];
}

void Liniuta::push_back(const int & x)
{
    ++lungimea;
    if(lungimea>capat)
    {
        capat+=50;
        int * aux=new int[capat];
        for(int i = 0; i<lungimea; ++i)
            aux[i]=substanta[i];
        delete[] substanta;
        substanta=aux;
    }
    substanta[lungimea-1]=x;
}

void Liniuta::pop_back()
{
    if(lungimea==0)
        throw PesteLimite(-1);
    --lungimea;
    if(lungimea<capat-100)
    {
        capat-=50;
        int * aux=new int[capat];
        for(int i = 0; i<lungimea; ++i)
            aux[i]=substanta[i];
        delete[] substanta;
        substanta=aux;
    }
}

Liniuta const& Liniuta::operator= (Liniuta const& x)
{
    this->capat=x.capat;
    this->lungimea=x.lungimea;
    delete[] (this->substanta);
    this->substanta=new int[capat];
    for(int i = 0; i < lungimea; ++i)
        this->substanta[i]=x.substanta[i];
    return *(this);
}

int const& Liniuta::size() const
{
    return lungimea;
}

std::istream& operator>>(std::istream & f,Liniuta & x)
{
    f>>x.lungimea;
    delete[] x.substanta;
    x.capat=x.lungimea/50;
    ++x.capat;
    x.capat*=50;
    x.substanta=new int[x.capat];
    for(int i = 0; i<x.lungimea; ++i)
        f>>x.substanta[i];
    return f;
}

std::ostream& operator<<(std::ostream & g,Liniuta const & x)
{
    g<<x.lungimea<<'\n';
    for(int i = 0;i<x.lungimea;++i)
        g<<x.substanta[i]<<' ';
    return g;
}

bool Liniuta::operator== (const Liniuta& x) const
{
    if(this == (&x))
        return true;
    if(this->lungimea != x.lungimea)
        return false;
    for (int i = 0; i< lungimea; ++i)
        if(substanta[i]!=x.substanta[i])
            return false;
    return true;
}
bool Liniuta::operator!= (const Liniuta& x) const
{
    return !((*this)==x);
}
