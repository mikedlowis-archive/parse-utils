#ifndef BT_PARSER_H
#define BT_PARSER_H

#include <exception>
#include <vector>
#include "iparser.h"

class BTParser : public IParser
{
    protected:
        unsigned int current;
        std::vector<unsigned int> markers;
        std::vector<Token> lookahead;
    public:
        BTParser();
        ~BTParser();

        void consume(void);
        void sync(unsigned int i);
        void fill(unsigned int n);
        void match(TokenType_T type);
        Token& lookaheadToken(unsigned int i);
        TokenType_T lookaheadType(unsigned int i);
        unsigned int mark(void);
        void release(void);
        void seek(unsigned int index);
        bool isSpeculating(void);
};

#endif
