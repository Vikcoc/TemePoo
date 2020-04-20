#ifndef GRAF_NEORIENTAT_H
#define GRAF_NEORIENTAT_H
#include "Graf.h"
#include "Lista.h"


class Graf_Neorientat: public Graf
{
    public:
        Graf_Neorientat() = default;
        Graf_Neorientat(Lista const& );
        virtual ~Graf_Neorientat() = default;
        virtual Liniuta Tati(const int &) const;
        virtual int NrMuchii() const;
//        virtual Graf_Neorientat& operator= (Graf_Neorientat const &);
        virtual operator== (const Graf_Neorientat&) const;
        virtual operator!= (const Graf_Neorientat&) const;

    protected:
        virtual void Citire(std::istream&);
        virtual void Afisare(std::ostream&) const;
    private:
        Lista L;
};

#endif // GRAF_NEORIENTAT_H
