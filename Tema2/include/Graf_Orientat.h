#ifndef GRAF_ORIENTAT_H
#define GRAF_ORIENTAT_H
#include "Graf.h"
#include "Matrice.h"


class Graf_Orientat : public Graf
{
    public:
        Graf_Orientat() = default;
        Graf_Orientat(const Matrice&);
        virtual ~Graf_Orientat()=default;
        virtual bool Conex() const;
        virtual int NrMuchii() const;
//        virtual Graf_Orientat& operator= (Graf_Orientat const &) = default;
        virtual operator== (const Graf_Orientat&) const;
        virtual operator!= (const Graf_Orientat&) const;

    protected:
        virtual void Citire(std::istream&);
        virtual void Afisare(std::ostream&) const;
    private:
        Matrice A;
};

#endif // GRAF_ORIENTAT_H
