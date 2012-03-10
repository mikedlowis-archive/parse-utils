#include <exception>
#include "ilexer.h"
#include "exception.h"

using namespace std;

ILexer::ILexer(istream& in) : line(-1), column(-1), in_stream(in), current(in_stream.get())
{
}

ILexer::~ILexer()
{
}

bool ILexer::eof(void)
{
    return in_stream.eof();
}

void ILexer::consume(void)
{
    if(in_stream.eof())
    {
        current = EOF;
    }
    else
    {
        current = in_stream.get();
        if(current == '\n')
        {
            line++;
            column = 0;
        }
        else
        {
            column++;
        }
    }
}

void ILexer::match(char x) {
    if ( current == x)
    {
        consume();
    }
    else
    {
        ostringstream oss;
        oss << "Unexpected character. Expected " << x << ", received " << current << ".";
        Exception ex(line,column);
        ex.setMessage(oss.str());
        throw ex;
    }
}


