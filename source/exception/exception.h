#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
#include "token.h"

class Exception : public std::exception
{
    protected:
        int ex_line;
        int ex_column;
        std::string ex_msg;
    public:
        Exception() throw();
        Exception(const Token& tok) throw();
        Exception(int line, int column) throw();
        virtual ~Exception() throw() {};
        virtual const char* what() const throw();
        void message(const std::string& msg) throw();
        const std::string& message(void) const throw();

        friend Exception& operator<< (Exception& ex, const std::string& rhs);
        friend Exception& operator<< (Exception& ex, unsigned int rhs);
};

#endif
