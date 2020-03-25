#include "Stiva_de_caractere.h"
#include <vector>

Stiva_de_caractere::Stiva_de_caractere()
{
    this->varf=NULL;
//    std::cout<<this<<std::endl<<this->varf<<std::endl;
}

//Stiva_de_caractere::Stiva_de_caractere(const Stiva_de_caractere& a)
//{
//    Auxiliar(a.varf);
//}
//
//void Stiva_de_caractere::Auxiliar(Nod * const & a)
//{
//    if (a==NULL)
//        return;
//    Auxiliar(a->GetNext());
//    this->Push (a->GetInfo());
//}

Stiva_de_caractere::Stiva_de_caractere(const Stiva_de_caractere& a)
{
    Nod *unu, *doi, *trei;
    unu=a.varf;
//    std::cout<<this<<' '<<&a<<std::endl;
    if (unu!=NULL)
    {
//        std::cout<<"copiere1\n";
        doi=new Nod(unu->GetInfo());
        this->varf=doi;
        unu=unu->GetNext();
        while(unu!=NULL)
        {
            trei=doi;
            doi=new Nod(unu->GetInfo());
            trei->SetNext(doi);
            unu=unu->GetNext();
        }
    }
    else
        this->varf=NULL;
//    std::cout<<"copiata\n";
}

Stiva_de_caractere::~Stiva_de_caractere()
{
//    std::cout<<this<<' '<<this->varf<<std::endl;
    Nod* aux;
    while (this->varf != NULL)
    {
        aux=this->varf;
        this->varf=this->varf->GetNext();
        delete aux;
    }
//    std::cout<<"stearsa\n";
}

void Stiva_de_caractere::Push(const char& val)
{
    this->varf=new Nod(val, varf);
}

void Stiva_de_caractere::Pop()
{
    if (this->varf==NULL)
        return;
    Nod* aux;
    aux=this->varf;
    this->varf=this->varf->GetNext();
    delete aux;
}

char Stiva_de_caractere::Top()
{
    return this->varf->GetInfo();
}

bool Stiva_de_caractere::IsEmpty()
{
    return (this->varf == NULL);
}

//std::ostream& operator << (std::ostream& g, Stiva_de_caractere& stiv)
//{
//    Nod* aux;
//    while(stiv.varf != NULL)
//    {
//        aux=stiv.varf;
//        g<<aux->GetInfo();
//        stiv.varf=stiv.varf->GetNext();
//        delete aux;
//    }
//    return g;
//}
//
//std::ostream& operator << (std::ostream& g, const Stiva_de_caractere& stiv)
//{
//    Nod* aux;
//    aux=stiv.varf;
//    while(aux != NULL)
//    {
//        g<<aux->GetInfo();
//        aux=aux->GetNext();
//    }
//    return g;
//}

std::ostream& operator << (std::ostream& g, Stiva_de_caractere& stiv)
{
    while(!stiv.IsEmpty())
    {
        g<<stiv.Top();
        stiv.Pop();
    }
    return g;
}

std::istream& operator >> (std::istream& f, Stiva_de_caractere& stiv)
{
    std::string aux;
    f>>aux;
    for (std::string::iterator e = aux.begin();e!=aux.end();++e)
        stiv.Push(*e);
    return f;
}

//std::string Stiva_de_caractere::ReverseString(const std::string& cuv)
//{
//    std::string aux=cuv;
//    for (std::string::const_iterator e = cuv.begin();e!=cuv.end();++e)
//        this->Push(*e);
//    for (unsigned i=0;i<cuv.size();++i)
//    {
//        aux[i]=this->Top();
//        this->Pop();
//    }
//    return aux;
//
//}

//Stiva_de_caractere operator - (const Stiva_de_caractere& s1,const Stiva_de_caractere& s2)
//{
//    Stiva_de_caractere s3,s4;
//    Nod *a,*b;
//    a=s1.varf;
//    b=s2.varf;
//    while(a!=NULL && b!=NULL)
//    {
//        s3.Push((a->GetInfo() > b->GetInfo()) ? a->GetInfo() : b->GetInfo());
//        a=a->GetNext();
//        b=b->GetNext();
//    }
//    while(a!=NULL)
//    {
//        s3.Push(a->GetInfo());
//        a=a->GetNext();
//    }
//    a=s3.varf;
//    while(a!=NULL)
//    {
//        s4.Push(a->GetInfo());
//        a=a->GetNext();
//    }
//    return s4;
//}

//Stiva_de_caractere operator - (const Stiva_de_caractere& s1,const Stiva_de_caractere& s2)
//{
//    Stiva_de_caractere s3;
//    Nod *a,*b,*c,*d;
//    a=s1.varf;
//    b=s2.varf;
//    if(a!=NULL && b!=NULL)
//    {
//        c=new Nod((a->GetInfo() > b->GetInfo()) ? a->GetInfo() : b->GetInfo());
//        s3.varf=c;
//        a=a->GetNext();
//        b=b->GetNext();
//    }
//    while(a!=NULL && b!=NULL)
//    {
//        d=c;
//        c=new Nod((a->GetInfo() > b->GetInfo()) ? a->GetInfo() : b->GetInfo());
//        a=a->GetNext();
//        b=b->GetNext();
//        d->SetNext(c);
//    }
//    while(a!=NULL)
//    {
//        s3.Push(a->GetInfo());
//        a=a->GetNext();
//    }
//    return s3;
//}

Stiva_de_caractere operator - (Stiva_de_caractere& s1,Stiva_de_caractere& s2)
{
    Stiva_de_caractere s3,s4;
    while(!s1.IsEmpty())
    {
        s3.Push((s1.Top() > s2.Top()) ? s1.Top() : s2.Top());
        s1.Pop();
        s2.Pop();
    }
    while(!s3.IsEmpty())
    {
        s4.Push(s3.Top());
        s3.Pop();
    }
    return s4;
}

const Stiva_de_caractere& Stiva_de_caractere::operator= (const Stiva_de_caractere& a)
{
    if(this==&a)
        return (*this);
    Nod *prev,*ult,*tranz;
    while(!this->IsEmpty())
        this->Pop();
    if(a.varf != NULL)
    {
        ult=new Nod(a.varf->GetInfo());
        tranz=a.varf->GetNext();
        this->varf=ult;
        while(tranz!=NULL)
        {
            prev=ult;
            ult=new Nod(tranz->GetInfo());
            prev->SetNext(ult);
            tranz=tranz->GetNext();
        }
    }
    else
    {
        this->varf=NULL;
    }
    return (*this);
}
