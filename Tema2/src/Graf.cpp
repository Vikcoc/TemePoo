#include "Graf.h"
//#include <iostream>

Graf::Graf():nr_noduri(0)
{
}

Graf::Graf(int const & noduri):nr_noduri(noduri)
{
}

const int& Graf::size() const
{
    return nr_noduri;
}
void Graf::Citire(std::istream& f)
{
    f>>this->nr_noduri;
}

void Graf::Afisare(std::ostream & g) const
{
    g<<this->nr_noduri;
}

std::istream& operator>> (std::istream& f, Graf& x)
{
//    std::cout<<"ma-ta\n";
    x.Citire(f);
//    std::cout<<"are pula\n";
    return f;
}

std::ostream& operator<< (std::ostream& g, const Graf& x)
{
    x.Afisare(g);
    return g;
}

void Graf::SetNod(const int& x)
{
    nr_noduri=x;
}

Graf::operator== (const Graf& x) const
{
    return (nr_noduri==x.nr_noduri);
}

Graf::operator!= (const Graf& x) const
{
    return (nr_noduri!=x.nr_noduri);
}

//Graf& Graf::operator= (Graf const & x)
//{
//    nr_noduri=x.nr_noduri;
//    return (*this);
//}
