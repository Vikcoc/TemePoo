#include <iostream>
#include <typeinfo>
#include "Liniuta.h"
#include "Matrice.h"
#include "Lista.h"
#include "Graf.h"
#include "Graf_Neorientat.h"
#include "Graf_Orientat.h"
#include "PesteLimite.h"


using namespace std;

int main()
{
    int a[]{2,4,5};
    Liniuta x(a,3);
    try{
        x[-1];
    }
    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }

//    int dam = x.size();
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
//    x.push_back(6);x.push_back(8);x.push_back(10);x.push_back(12);x.push_back(14);x.push_back(16);x.push_back(18);
//    x.push_back(7);x.push_back(9);x.push_back(11);x.push_back(13);x.push_back(15);x.push_back(17);x.push_back(19);
////    x[2]=8;
////    dam = 5;
//    cout << x[110] <<' '<<dam<< endl;
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();x.pop_back();
//    cout<<dam;

//    Matrice *x,y;
//    cout<<x[3][4];
//    int **aux;
//    aux=new int* [2];
//    aux[0]=new int [2];
//    aux[1]=new int [2];
//    aux[0][0]=0;
//    aux[0][1]=1;
//    aux[1][0]=2;
//    aux[1][1]=3;
//    x=new Matrice();
//    cin>>(*x);
//    y=*x;
//    delete x;
//    cout<<y;

//    Lista x;
//    cin>>x;
//    cout<<x;
//    Graf_Orientat* a = new Graf_Orientat();//, *b = new Graf_Neorientat() ;
//    cin>>(*a);//>>(*b);
//    cout<<(*a).Conex();
//    cout<<(((*(Graf_Neorientat*) b))==(*((Graf_Neorientat*)a)))<<endl;
//    cout<<((*b)==(*((Graf_Neorientat*)a)))<<endl;
//    cout<<endl;
//    throw 7;
//    cout<<(*b);

    return 0;
}
