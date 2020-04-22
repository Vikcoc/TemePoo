#include "PesteLimite.h"
#include <string>
PesteLimite::PesteLimite(const int & acc, const int & lim) noexcept : vreau(acc),am(lim)
{
    if(acc<0)
    {
        std::string aux={"S-a incercat accesarea pozitiei negative "+(std::to_string(vreau))+" si nu merge"};
        fu = new char[aux.size()];
        for(unsigned i = 0; i<aux.size() ; ++i)
            fu[i]=aux[i];
        fu[aux.size()]=0;

    }
    else
    {
        std::string aux = {"S-a incercat accesarea pozitiei "+(std::to_string(vreau))+" in afara limitei de "+(std::to_string(am))};
        fu = new char[aux.size()];
        for(unsigned i = 0; i<aux.size() ; ++i)
            fu[i]=aux[i];
        fu[aux.size()]=0;
    }
}
PesteLimite::PesteLimite(PesteLimite const & x)noexcept : vreau(x.vreau), am(x.am)
{
    if(vreau<0)
    {
        std::string aux={"S-a incercat accesarea pozitiei negative "+(std::to_string(vreau))+" si nu merge"};
        fu = new char[aux.size()];
        for(unsigned i = 0; i<aux.size() ; ++i)
            fu[i]=aux[i];
        fu[aux.size()]=0;

    }
    else
    {
        std::string aux = {"S-a incercat accesarea pozitiei "+(std::to_string(vreau))+" in afara limitei de "+(std::to_string(am))};
        fu = new char[aux.size()];
        for(unsigned i = 0; i<aux.size() ; ++i)
            fu[i]=aux[i];
        fu[aux.size()]=0;
    }
}
PesteLimite & PesteLimite::operator= (PesteLimite const & x)noexcept
{
    vreau=x.vreau;
    am=x.am;
    if(vreau<0)
    {
        std::string aux={"S-a incercat accesarea pozitiei negative "+(std::to_string(vreau))+" si nu merge"};
        fu = new char[aux.size()];
        for(unsigned i = 0; i<aux.size() ; ++i)
            fu[i]=aux[i];
        fu[aux.size()]=0;

    }
    else
    {
        std::string aux = {"S-a incercat accesarea pozitiei "+(std::to_string(vreau))+" in afara limitei de "+(std::to_string(am))};
        fu = new char[aux.size()];
        for(unsigned i = 0; i<aux.size() ; ++i)
            fu[i]=aux[i];
        fu[aux.size()]=0;
    }
}

PesteLimite::~PesteLimite()
{ delete[] fu;}

const char* PesteLimite::what() const noexcept
{

    return fu;
}
