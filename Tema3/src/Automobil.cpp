#include "Automobil.h"

Automobil::Automobil(double lungime, double volum, int tip):lungime(lungime),volum(volum),tip(tip)
{}
Automobil::~Automobil()
{}

std::string Automobil::GetTip() const
{
    switch(this->tip)
    {
    case 0: return "hatchback";
    case 1: return "combi";
    case 2: return "sedan";
    }
    return "Idunno";
}

//std::string Automobil::ToString() const
//{
//    return ("{ lungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\ntip: " + GetTip() + " }");
//}

int Automobil::GiveTip(std::string x)
{
    if(x=="hatchback")
        return 0;
    else if(x=="combi")
        return 1;
    else if(x=="sedan")
        return 2;
    else
        return -1;
}

std::ostream& operator << (std::ostream& g,const Automobil& x)
{
    x.Afisare(g);
    return g;
}

std::istream& operator >> (std::istream& f,const Automobil& x)
{
    throw piraterie();
    return f;
}
