#ifndef FRAUDA_H
#define FRAUDA_H
#include <exception>

class frauda : public std::exception
{
    public:
        frauda () throw() = default;
        frauda(const frauda&) throw() = default;
        frauda& operator= (const frauda&) throw() = default;
        virtual ~frauda() throw() = default;
        virtual const char* what() const throw();
};

#endif // FRAUDA_H
