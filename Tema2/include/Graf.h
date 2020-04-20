#ifndef GRAF_H
#define GRAF_H
#include "Liniuta.h"
#include <fstream>


class Graf
{
    public:
        Graf();
        Graf(int const &);
        virtual ~Graf() = default;
//        virtual Graf& operator= (Graf const &);
/// da, nu cred ca merge, pt ca nu se ocupa de obiectele care nu sunt this pt a vedea ca ce sunt
//        ///probabil fara virtual, pt ca sunt forme diferite din cauza tipului diferit
//        ///probabil ca ca la exceptii
//        ///ai putea sa faci ca la citire si afisare?
//        ///sau nu pt ca nu mai vorbim de obiectul this
        virtual int NrMuchii() const = 0;
        virtual const int& size() const;
        friend std::istream& operator>> (std::istream& , Graf&);
        friend std::ostream& operator<< (std::ostream& , const Graf&);
        virtual operator== (const Graf&) const;
        virtual operator!= (const Graf&) const;
/// la fel si astea 2

    protected:
        virtual void Citire(std::istream&);
        virtual void Afisare(std::ostream&) const;
        void SetNod(const int& );
    private:
        int nr_noduri;
};

#endif // GRAF_H
