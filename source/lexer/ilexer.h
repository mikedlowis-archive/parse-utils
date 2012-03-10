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
        char current;

    public:
        ILexer(std::istream& in);
        virtual ~ILexer();
        void consume(void);
        void match(char x);
        bool eof(void);
        virtual Token next(void) = 0;
};

#endif
