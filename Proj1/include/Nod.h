#ifndef NOD_H
#define NOD_H


class Nod
{
    public:
        Nod();
        Nod(const char&,Nod* &);
        Nod(const char&);
        virtual ~Nod();

        char GetInfo();
        Nod* GetNext();
        void SetNext(Nod* const&);

    protected:

    private:
        char info;
        Nod* next;
};

#endif // NOD_H
