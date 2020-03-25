#include "Nod.h"
#include <iostream>

Nod::Nod()
{
    this->info=0;
    this->next=NULL;
}

Nod::Nod(const char& info, Nod* &next )
{
    this->info=info;
    this->next=next;
    next=this;
}

Nod::Nod(const char& info)
{
    this->info=info;
    this->next=NULL;
}

char Nod::GetInfo()
{
    return this->info;
}

Nod::~Nod()
{

}

Nod* Nod::GetNext()
{
    return this->next;
}

void Nod::SetNext(Nod* const& a)
{
    this->next=a;
}
