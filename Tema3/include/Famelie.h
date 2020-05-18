#ifndef FAMELIE_H
#define FAMELIE_H
#include "Mini.h"
#include "GT.h"

class Famelie : public Mini, public GT
{
    public:
        Famelie(double = 0, double = 0, int = -1, double = 10, int = 200, int = 300, std::vector<int> = std::vector<int>(),std::vector<int> = std::vector<int>());
        Famelie(const Famelie&) = default;
        virtual ~Famelie();

        virtual Famelie& operator= (const Famelie&) = default;

        virtual std::string ToString() const;
    protected:

        virtual void Afisare(std::ostream&) const;

};

#endif // FAMELIE_H
