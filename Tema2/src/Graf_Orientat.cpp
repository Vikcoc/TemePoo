#include "Graf_Orientat.h"
#include <queue>

Graf_Orientat::Graf_Orientat(const Matrice& x): Graf(x.size()),A(x)
{
}

void Graf_Orientat::Citire(std::istream& f)
{
    f>>A;
    Graf::SetNod(A.size());
}

void Graf_Orientat::Afisare(std::ostream& g) const
{
    g<<A;
}

bool Graf_Orientat::Conex() const
{
    bool hi[A.size()]={0};
    std::queue <int> ha;
    ///stiu ca nu face ce trebuie pt conex dar asta e
    ha.push(0);
//    hi[0]=1;
    while(!ha.empty())
    {
        auto x = A[ha.front()];
        for (int i = 0; i < x.size(); ++i)
        {
            if(x[i] && !hi[i])
            {
                hi[i]=1;
                ha.push(i);
            }
        }
        ha.pop();
    }
    hi[0] = 0;
    for (int i = 1; i<A.size(); ++i)
        hi[0]|=A[i][0];
    bool fin=1;
    for(auto x : hi)
        fin&=x;
    return fin;
}

int Graf_Orientat::NrMuchii() const
{
    int heehee = 0;
    for(int i=0;i<A.size(); ++i)
        for(int j = 0; j<A.size(); ++j)
            if(A[i][j])
                ++heehee;
    return heehee;
}

Graf_Orientat::operator== (const Graf_Orientat& x) const
{
    return (Graf::operator==(x) && A==x.A);
}

Graf_Orientat::operator!= (const Graf_Orientat& x) const
{
    return (Graf::operator!=(x) || A!=x.A);
}
