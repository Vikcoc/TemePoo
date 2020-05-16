#include "Monovolum.h"

Monovolum::Monovolum(double lungime, double volum, std::string data): Automobil(lungime,volum,4),data(data)
{
//    delete this;
}

std::string Monovolum::DataFabricarii() const
{
    return data;
}

void Monovolum::Afisare(std::ostream& g) const
{
    g<<ToString();
}

std::string Monovolum::ToString() const
{
    return ("{ lungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\n data fabricarii: " + data + " }");
}
