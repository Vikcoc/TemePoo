#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H
#include <string>
#include <fstream>
#include "piraterie.h"

class Automobil
{
    public:
        Automobil(double = 0, double = 0, int = -1);
        Automobil(const Automobil&)=default;
        virtual ~Automobil() = 0;

        virtual Automobil& operator= (const Automobil&) = default;

        virtual std::string GetTip() const;
        virtual std::string ToString() const = 0;
        friend std::ostream& operator<< (std::ostream&,const Automobil&);
        friend std::istream& operator>> (std::istream&,const Automobil&);

    protected:
        const double lungime, volum;
        const int tip;

        static int GiveTip(std::string);
        virtual void Afisare(std::ostream&) const = 0;
};

#endif // AUTOMOBIL_H
