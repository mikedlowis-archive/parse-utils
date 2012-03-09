#include "ivisitor.h"
#include <list>

using namespace std;

IVisitor::IVisitor()
{
}

IVisitor::~IVisitor()
{
}

void IVisitor::visit(AST* cur, int depth)
{
    list<AST*>* children;
    list<AST*>::iterator it;

    if (cur != NULL)
    {
        // Execute or pre-walk actions
        if(depth == 0) beforeVisit( cur, depth );

        // Setup our locals
        children = cur->children();
        it = children->begin();

        // Visit the tree
        beforeChildren(cur,depth);
        depth++;
        for(; it != children->end(); it++)
        {
            beforeChild( *it, depth );
            visit( *it, depth );
            afterChild( *it, depth );
        }
        afterChildren(cur,depth);

        // Execute our post-walk actions
        if(depth == 1) afterVisit( cur, depth );
    }
}

