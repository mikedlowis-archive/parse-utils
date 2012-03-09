#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "ast.h"
#include <string>
#include <iostream>

class IVisitor {
    public:
        IVisitor();
        ~IVisitor();
        void visit(AST* cur, int depth = 0);
    private:
        virtual void beforeVisit(AST* cur, int depth) = 0;
        virtual void afterVisit(AST* cur, int depth) = 0;
        virtual void beforeChildren(AST* cur, int depth) = 0;
        virtual void afterChildren(AST* cur, int depth) = 0;
        virtual void beforeChild(AST* cur, int depth) = 0;
        virtual void afterChild(AST* cur, int depth) = 0;
};

#endif
