#include "Graf_Neorientat.h"
#include <queue>

Graf_Neorientat::Graf_Neorientat(Lista const& L):Graf(L.size()),L(L){}

Liniuta Graf_Neorientat::Tati(const int & tatal) const
{
    bool x[L.size()] = {0};
    int ey[L.size()];
    std::queue <int> aj;
    int hu;
    aj.push(tatal);
    ey[tatal]=-1;
    while(!aj.empty())
    {
        hu=aj.front();
        aj.pop();
        if(!x[hu])
        {
            x[hu]=1;
            for(int i = 0;i<L[hu].size();++i)
                ey[L[hu][i]]=hu;
        }
    }
    Liniuta jig(ey,L.size());
    return jig;

}

int Graf_Neorientat::NrMuchii()const
{
    int aux(0);
    for (int i = 0;i<L.size();++i)
        aux+=L[i].size();
    return aux/2;
}

void Graf_Neorientat::Afisare(std::ostream& g)const
{
//    Graf::Afisare(g);
    g<<L;
}

void Graf_Neorientat::Citire(std::istream& f)
{
    f>>L;
    Graf::SetNod(L.size());
}

Graf_Neorientat::operator== (const Graf_Neorientat& x) const
{
    return (Graf::operator==(x) && L==x.L);
}

Graf_Neorientat::operator!= (const Graf_Neorientat& x) const
{
    return (Graf::operator!=(x) || L!=x.L);
}

//Graf_Neorientat& Graf_Neorientat::operator= (Graf_Neorientat const & x)
//{
//    Graf::operator=(x);
//    L=x.L;
//    return (*this);
//}
