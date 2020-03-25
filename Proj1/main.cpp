#include <iostream>
#include "Stiva_de_caractere.h"
#include <vector>

std::string ReverseString(const std::string& cuv)
{
    Stiva_de_caractere p;
    std::string aux=cuv;
    for (std::string::const_iterator e = cuv.begin();e!=cuv.end();++e)
        p.Push(*e);
    for (unsigned i=0;i<cuv.size();++i)
    {
        aux[i]=p.Top();
        p.Pop();
    }
    return aux;
}

void Ionut_Cercel()
{
    int n;
    std::vector <Stiva_de_caractere> A;
//    std::cin>>n;
//    A.resize(n);
//    std::cout<<A.size()<<std::endl;
    Stiva_de_caractere aux;
    std::cin>>aux;
    std::cout<<"citit aux\n";
    A.push_back(aux);
    std::cout<<"pus aux in vector\n";

    std::cin>>aux;
    std::cout<<"citit aux\n";
    A.push_back(aux);
    std::cout<<"pus aux in vector\n";

    std::cin>>aux;
    std::cout<<"citit aux\n";
    A.push_back(aux);
    std::cout<<"pus aux in vector\n";

    for(auto i : A)
    {
        std::cout<<"i primit aux nu afisat\n";
        std::cout<<i<<std::endl;
        std::cout<<"i a afisat aux\n\n";
    }

}
void Nicolae()
{
    int n;
    std::cin>>n;
    Stiva_de_caractere d[n], aux;
    for (int i=0;i<n;++i)
    {
        std::cin>>aux;
        d[i]=aux;
    }
    for (int i=0;i<n;++i)
    {
        aux=d[i];
        std::cout<<aux<<std::endl;

    }
}

void Florin()
{
    std::vector<int> a;
    int n;
    std::cin>>n;
    a.resize(n);
    a.push_back(5);
    std::cout<<a.size();
    std::cout<<a[n];
}

void Salam()
{
    std::vector<Stiva_de_caractere> a;
    int n;
    std::cin>>n;
    a.resize(n);
    Stiva_de_caractere aux;
    std::cin>>aux;
    a.push_back(aux);
    std::cout<<a.size();
    std::cout<<a[n]<<std::endl;
}

int main()
{
    ///din cerinta pt operatorul - inteleg ca varful stivei se afla in dreapta pe exemplu
//    Stiva_de_caractere da;
//    std::cin>>da;
//    Stiva_de_caractere dumla, eh;
//    std::cin>>dumla;
////    std::cout<<dumla<<std::endl<<da;
////    da = dumla = dumla =da;
//    eh=da-dumla;
//    std::cout<<dumla<<std::endl<<da<<std::endl<<eh;
////    std::string a;
////    std::cin>>a;
////    std::cout<<ReverseString(a);
//    Ionut_Cercel();
//    Nicolae();
//    Florin();
//    Salam();
    return 0;
}
