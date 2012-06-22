#ifndef BT_PARSER_H
#define BT_PARSER_H

#include <exception>
#include <vector>
#include "imarker.h"
#include "iparser.h"

class BTParser : public IMarker, public IParser
{
    protected:
        std::vector<Token> lookahead;
    public:
        BTParser();
        virtual ~BTParser();

        void consume(void);
        void sync(unsigned int i);
        void fill(unsigned int n);
        void match(TokenType_T type);
        Token& lookaheadToken(unsigned int i);
        TokenType_T lookaheadType(unsigned int i);
};

#endif
