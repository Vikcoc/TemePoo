#ifndef PIRATERIE_H
#define PIRATERIE_H
#include <exception>

class piraterie : public std::exception
{
    public:
        piraterie () throw() = default;
        piraterie(const piraterie&) throw() = default;
        piraterie& operator= (const piraterie&) throw() = default;
        virtual ~piraterie() throw() = default;
        virtual const char* what() const throw();

};

#endif // PIRATERIE_H
