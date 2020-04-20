#ifndef LISTA_H
#define LISTA_H
#include "Liniuta.h"
#include <fstream>

class Lista
{
    public:
//        Lista();
//        Lista(Liniuta const&);
        Lista(Liniuta const * const& = 0, int const & = 0);
        Lista(Lista const&);
        ~Lista();
        void push_back(Liniuta const&);
        void pop_back();
        int const& size() const;
        Liniuta const& operator[](int const &) const;
        friend std::istream& operator>>(std::istream& ,Lista& );
        friend std::ostream& operator<<(std::ostream& ,Lista const& );
        Lista const& operator= (Lista const&);
        bool operator== (Lista const&) const;
        bool operator!= (Lista const&) const;


    protected:

    private:
        Liniuta * substanta;
        int dim,capat;
};

#endif // LISTA_H
