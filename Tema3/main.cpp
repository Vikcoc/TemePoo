#include <iostream>
#include <vector>
#include "Mini.h"
#include "GT.h"
#include "Famelie.h"
#include <set>
#include "Monovolum.h"
#include "navem.h"
#include "piraterie.h"
#include "frauda.h"
using namespace std;

template <class T>
class Vanzare
{
    static int praduitori;

//    int nr_stoc,nr_vandute;
    set<pair<T*,int>> stoc,vandute;
public:
    Vanzare(set<pair<T*,int>> = set<pair<T*,int>>());
    Vanzare(const Vanzare &);
    virtual ~Vanzare();
    Vanzare& operator= (const Vanzare &);

    set<pair<T*,int>> Selectie();
    Vanzare& operator -=(pair<T*,int>);
    Vanzare& operator +=(pair<T*,int>);
};

template <class T>
int Vanzare<T>::praduitori = 0;

template <class T>
Vanzare<T>::Vanzare(set<pair<T*,int>> masini):stoc(masini)
{++praduitori;}

template <class T>
Vanzare<T>::Vanzare(const Vanzare<T>& x)
{throw frauda();}

template <class T>
Vanzare<T>::~Vanzare()
{
    for (auto x : stoc)
        delete (x.first);
    for (auto x : vandute)
        delete (x.first);
    --praduitori;
}

template <class T>
Vanzare<T>& Vanzare<T>::operator= (const Vanzare<T>& x)
{throw frauda();return *this;}

template <class T>
set<pair<T*,int>> Vanzare<T>::Selectie()
{
    return stoc;
}

template <class T>
Vanzare<T>& Vanzare<T>::operator -=(pair<T*,int> x)
{
    if(stoc.find(x)!=stoc.end())
    {
        stoc.erase(x);
        vandute.insert(x);
        return *this;
    }
    else
        throw navem();
}

template <class T>
Vanzare<T>& Vanzare<T>::operator +=(pair<T*,int> x)
{
    stoc.insert(x);
}



template <>
class Vanzare<Monovolum>
{
    static int praduitori;

//    int nr_stoc,nr_vandute;
    set<pair<Monovolum*,bool>> stoc,vandute;
    std::string cand;
public:
    Vanzare(set<pair<Monovolum*,bool>> = set<pair<Monovolum*,bool>>(), std::string = "2000 01 01");
    Vanzare(const Vanzare<Monovolum>& );
    virtual ~Vanzare();
    Vanzare& operator= (const Vanzare &);

    set<pair<Monovolum*,bool>> Selectie();
    Vanzare& operator -=(pair<Monovolum*,bool>);
    Vanzare& operator +=(pair<Monovolum*,bool>);
    int GivePret(pair<Monovolum*,bool>) const;

};

int Vanzare<Monovolum>::praduitori = 0;

Vanzare<Monovolum>::Vanzare(set<pair<Monovolum*,bool>> masini, std::string data):stoc(masini), cand(data)
{++praduitori;}

Vanzare<Monovolum>::Vanzare(const Vanzare<Monovolum>& x)
{throw frauda();}

Vanzare<Monovolum>::~Vanzare()
{
    for (auto x : stoc)
        delete (x.first);
    for (auto x : vandute)
        delete (x.first);
    --praduitori;
}

Vanzare<Monovolum>& Vanzare<Monovolum>::operator= (const Vanzare<Monovolum>& x)
{throw frauda();return *this;}

set<pair<Monovolum*,bool>> Vanzare<Monovolum>::Selectie()
{
    return stoc;
}

Vanzare<Monovolum>& Vanzare<Monovolum>::operator -=(pair<Monovolum*,bool> x)
{
    if(stoc.find(x)!=stoc.end())
    {
        stoc.erase(x);
        vandute.insert(x);
        return *this;
    }
    else
        throw navem();
}

Vanzare<Monovolum>& Vanzare<Monovolum>::operator +=(pair<Monovolum*,bool> x)
{
    stoc.insert(x);
    return *this;
}

int Vanzare<Monovolum>::GivePret(pair<Monovolum*,bool> x) const
{
    int an = stoi(x.first->DataFabricarii());
    int an2= stoi(cand);
    bool vara = stoi(cand.substr(5)) > 5  && stoi(cand.substr(5)) < 9;
    return vara ? (50000/(an2-an+1) - 5000/(an2-an+1)) : 50000/(an2-an+1);
}

int main()
{
//    Vanzare<Monovolum> a(set<pair<Monovolum*,bool>>(),"2000 07 03");
//    a+={0,1};
//    a-={0,1};
//    Monovolum *b = new Monovolum();
//    cin>>*b;
//    a+={b,1};
//    cout<<a.GivePret({b,1});
//    a-={0,0};
//    Vanzare<Monovolum> a(set<pair<Monovolum*,bool>>(),"2000 07 03");
//    Vanzare<Monovolum> b;
//    b=a;
//    GT a,b;
//    b=a;
    return 0;
}
