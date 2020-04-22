#ifndef PESTELIMITE_H
#define PESTELIMITE_H
#include <exception>


class PesteLimite : public std::exception
{
    public:
        PesteLimite(const int &, const int & = 0) noexcept;
        PesteLimite(PesteLimite const &)noexcept;
        PesteLimite & operator= (PesteLimite const &)noexcept;
        virtual ~PesteLimite();
        virtual const char* what() const noexcept;

    protected:

    private:
        int vreau,am;
        char* fu;
};

#endif // PESTELIMITE_H
