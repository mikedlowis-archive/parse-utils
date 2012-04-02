#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <sstream>
#include <cstdio>
#include "token.h"

class ILexer
{
    protected:
        int line;
        int column;
        std::istream& in_stream;

    public:
        ILexer(std::istream& in);
        virtual ~ILexer();
        virtual void consume(void) = 0;
        virtual void match(char x) = 0;
        virtual bool eof(void);
        virtual Token next(void) = 0;
};

#endif
