#ifndef MONOVOLUM_H
#define MONOVOLUM_H
#include "Automobil.h"

class Monovolum : public Automobil
{
    public:
        Monovolum(double = 0,double = 0, std::string = "2000 01 01");
        Monovolum(const Monovolum&) = default;
        virtual ~Monovolum() = default;

        virtual Monovolum& operator= (const Monovolum&) = default;

        virtual std::string DataFabricarii() const;
        virtual std::string ToString() const;
    protected:
        std::string data;
        virtual void Afisare(std::ostream&) const;
};

#endif // MONOVOLUM_H
