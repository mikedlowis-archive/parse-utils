#include "ast.h"
#include <sstream>
#include <string.h>
#include <iostream>

using namespace std;

AST::AST(ASTNodeType type)
{
    node_type = type;
    node_text = "";
    node_children = new list<AST*>();
}

AST::AST(Token tok)
{
    node_type = tok.type();
    node_text = tok.text();
    node_children = new list<AST*>();
}

AST::AST(ASTNodeType type, const char* text)
{
    node_type = type;
    node_text = string(text);
    node_children = new list<AST*>();
}

AST::AST(ASTNodeType type, std::string text)
{
    node_type = type;
    node_text = text;
    node_children = new list<AST*>();
}

AST::AST(ASTNodeType type, int child_count, ...)
{
    va_list arg_list;
    int i = 0;
    node_type = type;
    node_text = "";
    node_children = new list<AST*>();
    va_start (arg_list, child_count);
    for (i = 0; i < child_count ; i++)
    {
        node_children->push_back( (AST*)va_arg(arg_list, AST*) );
    }
    va_end(arg_list);
}

AST::~AST()
{
    list<AST*>::iterator it = node_children->begin();
    for(; it != node_children->end(); it++)
    {
        delete *(it);
    }
    delete node_children;
}

AST& AST::operator = (AST& rhs)
{
    list<AST*>::iterator it = rhs.children()->begin();
    node_type = rhs.type();
    node_text = rhs.text();
    node_children->clear();

    for(; it != rhs.children()->end(); it++)
    {
        node_children->push_back( (*it)->clone() );
    }

    return *this;
}

ASTNodeType AST::type(void) const
{
    return node_type;
}

void AST::type(ASTNodeType typ)
{
    node_type = typ;
}

list<AST*>* AST::children(void)
{
    return node_children;
}

string AST::text(void) const
{
    return node_text;
}

void AST::text(std::string& txt)
{
    node_text = txt;
}

void AST::addChild(AST* node)
{
    node_children->push_back(node);
}

AST* AST::clone(void) const
{
    AST* new_clone = new AST( node_type, node_text );
    list<AST*>::iterator it = node_children->begin();
    for(; it != node_children->end(); it++)
    {
        new_clone->addChild( (*it)->clone() );
    }
    return new_clone;
}

