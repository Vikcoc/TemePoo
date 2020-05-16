#ifndef NAVEM_H
#define NAVEM_H
#include <exception>

class navem : public std::exception
{
    public:
        navem () throw() = default;
        navem(const navem&) throw() = default;
        navem& operator= (const navem&) throw() = default;
        virtual ~navem() throw() = default;
        virtual const char* what() const throw();

};

#endif // NAVEM_H
