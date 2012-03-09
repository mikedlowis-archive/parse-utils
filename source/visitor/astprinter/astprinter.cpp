#include <iostream>
#include "astprinter.h"


void ASTPrinter::beforeVisit(AST* cur, int depth)
{
}

void ASTPrinter::afterVisit(AST* cur, int depth)
{
    std::cout << endl;
}

void ASTPrinter::beforeChildren(AST* cur, int depth)
{
    std::cout << "(" << cur->type() << " " << cur->text();
}

void ASTPrinter::afterChildren(AST* cur, int depth)
{
    std::cout << ")";
}

void ASTPrinter::beforeChild(AST* cur, int depth)
{
    std::cout << endl;
    for(int i = 0; i< depth; i++)
    {
        std::cout << "  ";
    }
}

void ASTPrinter::afterChild(AST* cur, int depth)
{
}

