#ifndef ASTPRINTER_H
#define ASTPRINTER_H

#include "ivisitor.h"
#include <iostream>
#include <sstream>

class ASTPrinter : public IVisitor {
    protected:
        ostringstream stream;
    public:
        ASTPrinter(AST* root) : IVisitor(root) {};
        string str();
    private:
        void beforeVisit(AST* cur, int depth);
        void afterVisit(AST* cur, int depth);
        void beforeChildren(AST* cur, int depth);
        void afterChildren(AST* cur, int depth);
        void beforeChild(AST* cur, int depth);
        void afterChild(AST* cur, int depth);
};

#endif
