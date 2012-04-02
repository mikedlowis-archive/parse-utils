#ifndef LLNLEXER_H
#define LLNLEXER_H

#include <vector>
#include "ilexer.h"

class LLNLexer : public ILexer
{
    protected:
        unsigned int cur_idx;
        std::vector<char> la_buffer;

    public:
        LLNLexer(std::istream& in);
        virtual ~LLNLexer();

        void consume(void);
        void match(char type);
        void sync(unsigned int i);
        void fill(unsigned int n);
        char lookahead(unsigned int i);

        Token next(void) = 0;
};

#endif
