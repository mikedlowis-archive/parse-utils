#include "llnlexer.h"
#include "exception.h"

LLNLexer::LLNLexer(std::istream& in) : ILexer(in), cur_idx(0)
{
}

LLNLexer::~LLNLexer()
{
}

void LLNLexer::consume(void)
{
    cur_idx++;
    if(cur_idx == la_buffer.size())
    {
        cur_idx = 0;
        la_buffer.clear();
    }
    sync(1);
}

void LLNLexer::match(char match)
{
    if( lookahead(1) == match )
    {
        consume();
    }
    else
    {
        Exception ex(line,column);
        ex << "Unexpected character. Expected '" << match << "', received '" << lookahead(1) << "'.";
        throw ex;
    }
}

void LLNLexer::sync(unsigned int i)
{
    unsigned int next_index = cur_idx + i - 1;
    unsigned int max_index = (la_buffer.size() == 0) ? 0 : (la_buffer.size() - 1);
    if( next_index >= max_index )
    {
        fill( next_index - max_index);
    }
}

void LLNLexer::fill(unsigned int n)
{
    unsigned int i = 0;
    for (i = 0; i <= n; i++)
    {
        la_buffer.push_back( in_stream.get() );
    }
}

char LLNLexer::lookahead(unsigned int i)
{
    sync(i);
    return la_buffer.at( cur_idx + i - 1 );
}



