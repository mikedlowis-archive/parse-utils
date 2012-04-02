#include "ilexer.h"
#include "exception.h"

using namespace std;

ILexer::ILexer(istream& in) : line(-1), column(-1), in_stream(in)
{
}

ILexer::~ILexer()
{
}

bool ILexer::eof(void)
{
    return in_stream.eof();
}

