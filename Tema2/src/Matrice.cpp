#include "Matrice.h"
#include "PesteLimite.h"
//#include <iostream>

//Matrice::Matrice():dimensiune(0)
//{
//    substanta=new Liniuta[0];
//}

Matrice::Matrice(int ** const& mat, int const& len):dimensiune(len)
{
    substanta=new Liniuta[len];
    for(int i=0;i<dimensiune;++i)
        for(int j=0;j<dimensiune;++j)
            substanta[i].push_back(mat[i][j]);
}

Matrice::Matrice(Matrice const& x):dimensiune(x.dimensiune)
{
    this->substanta = new Liniuta[this->dimensiune];
    for (int i=0;i<this->dimensiune;++i)
        this->substanta[i]=x[i];
}

Matrice::~Matrice()
{
    delete[] substanta;
}

Liniuta const& Matrice::operator[](int const &x) const
{
    if(x > dimensiune)
        throw PesteLimite(x,dimensiune);
    if(x < 0)
        throw PesteLimite(x);
    return this->substanta[x];
}

std::istream& operator>>(std::istream& f, Matrice& x)
{
    f>>x.dimensiune;
    delete[] x.substanta;
    x.substanta = new Liniuta[x.dimensiune];
    int aux;
    for (int i=0;i<x.dimensiune;++i)
    {
        for (int j=0;j<x.dimensiune;++j)
        {
            f>>aux;
            x.substanta[i].push_back(aux);
        }
    }
    return f;
}

std::ostream& operator<<(std::ostream& g, Matrice const &x)
{
    for(int i = 0; i < x.dimensiune; ++i)
    {
        g<<x[i];
        g<<'\n';
    }
    return g;
}

Matrice const& Matrice::operator=(Matrice const& x)
{
    this->dimensiune=x.dimensiune;
    delete[] this->substanta;
    this->substanta = new Liniuta[this->dimensiune];
    for (int i=0;i<this->dimensiune;++i)
        this->substanta[i]=x[i];
    return (*this);
}

int const& Matrice::size() const
{
    return (this->dimensiune);
}

bool Matrice::operator== (Matrice const& x) const
{
    if(this==(&x))
        return true;
    if(dimensiune!=x.dimensiune)
        return false;
    for (int i = 0; i<dimensiune; ++i)
        if(substanta[i]!=x.substanta[i])
            return false;
    return true;
}

bool Matrice::operator!= (Matrice const& x) const
{
    return !((*this)==x);
}
