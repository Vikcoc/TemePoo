#ifndef LINIUTA_H
#define LINIUTA_H
#include <fstream>
//#include <iostream>


class Liniuta
{
    public:
//        Liniuta();
        Liniuta(int const * const & = 0, int const & = 0);
        Liniuta(Liniuta const&);
        ~Liniuta();
        void push_back(int const &);
        void pop_back();
        int const& size() const;
        int const& operator[] (int const&) const;
        Liniuta const& operator= (Liniuta const&);
        friend std::istream& operator>>(std::istream &,Liniuta &);
        friend std::ostream& operator<<(std::ostream &,Liniuta const &);
        bool operator== (const Liniuta&) const;
        bool operator!= (const Liniuta&) const;


    protected:

    private:
        int lungimea;
        int capat;
        int * substanta;
};

#endif // LINIUTA_H
