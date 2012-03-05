#include "astprinter.h"

using namespace std;

string ASTPrinter::str()
{
    return stream.str();
}

void ASTPrinter::beforeVisit(AST* cur, int depth)
{
}

void ASTPrinter::afterVisit(AST* cur, int depth)
{
    stream << endl;
}

void ASTPrinter::beforeChildren(AST* cur, int depth)
{
    stream << "(" << cur->type() << " " << cur->text();
}

void ASTPrinter::afterChildren(AST* cur, int depth)
{
    stream << ")";
}

void ASTPrinter::beforeChild(AST* cur, int depth)
{
    stream << endl;
    for(int i = 0; i< depth; i++)
    {
        stream << "  ";
    }
}

void ASTPrinter::afterChild(AST* cur, int depth)
{
}

