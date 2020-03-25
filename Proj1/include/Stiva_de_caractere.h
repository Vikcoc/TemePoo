#ifndef STIVA_DE_CARACTERE_H
#define STIVA_DE_CARACTERE_H
#include "Nod.h"
#include <iostream>

class Stiva_de_caractere
{
    public:
        Stiva_de_caractere();
        Stiva_de_caractere(const Stiva_de_caractere&);
        virtual ~Stiva_de_caractere();
        void Push(const char&);
        void Pop();
        char Top();
        bool IsEmpty();
        friend std::ostream& operator << (std::ostream&, Stiva_de_caractere&);
//        friend std::ostream& operator << (std::ostream&, const Stiva_de_caractere&);
        friend std::istream& operator >> (std::istream&, Stiva_de_caractere&);
//        friend Stiva_de_caractere operator - (const Stiva_de_caractere&,const Stiva_de_caractere&);
        friend Stiva_de_caractere operator - (Stiva_de_caractere& , Stiva_de_caractere&);
        const Stiva_de_caractere& operator= (const Stiva_de_caractere&);
//        std::string ReverseString(const std::string&);

    protected:
//        void Auxiliar(Nod * const &);

    private:
        Nod* varf;
};

#endif // STIVA_DE_CARACTERE_H
