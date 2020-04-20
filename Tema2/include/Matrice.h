#ifndef MATRICE_H
#define MATRICE_H
#include "Liniuta.h"
#include <fstream>

class Matrice
{
    public:
//        Matrice();
        Matrice(int ** const& = 0, int const& = 0);
        Matrice(Matrice const&);
        ~Matrice();
        Liniuta const& operator[](int const &) const;
        friend std::istream& operator>>(std::istream& ,Matrice& );
        friend std::ostream& operator<<(std::ostream& ,Matrice const& );
        Matrice const& operator= (Matrice const&);
        int const& size() const;
        bool operator== (Matrice const&) const;
        bool operator!= (Matrice const&) const;

    protected:

    private:
        int dimensiune;
        Liniuta * substanta;
};

#endif // MATRICE_H
