#ifndef MINI_H
#define MINI_H
#include "Automobil.h"
#include <vector>

class Mini: public virtual Automobil
{
    public:
        Mini(double = 0, double = 0, int = -1, double = 10, std::vector<int> = std::vector<int>());
        virtual ~Mini() = default;

        virtual std::string ToString() const;
        virtual std::string GetParcare() const;

        static Mini stom(std::string);
    protected:
        const double consum;
        const std::vector<int> asistenta_parcare;

        virtual void Afisare(std::ostream&) const;

        static std::string GetAParcare(int);
        static int GiveAparcare(std::string);
};

#endif // MINI_H
