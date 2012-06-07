#ifndef AST_H
#define AST_H

#include <stdarg.h>
#include <list>
#include <string>
#include "token.h"

typedef unsigned int ASTNodeType;

// This is defined elsewhere. We need to declare it here so we can use it
class IVisitor;

class AST
{
    protected:
        ASTNodeType node_type;
        std::string node_text;
        std::list<AST*>* node_children;
    public:
        AST(ASTNodeType type);
        AST(Token tok);
        AST(ASTNodeType type, const char* text);
        AST(ASTNodeType type, std::string text);
        AST(ASTNodeType type, int child_count, ...);
        AST(ASTNodeType type, std::string text, int child_count, ...);
        virtual ~AST();
        AST& operator = (AST& rhs);
        ASTNodeType type(void) const;
        void type(ASTNodeType typ);
        std::string text(void) const;
        void text(std::string& txt);
        std::list<AST*>* children(void) const;
        void addChild(AST* node);
        AST* clone(void) const;
        bool operator ==(const AST &other) const;
        bool operator !=(const AST &other) const;
        void process(IVisitor& visitor);
};

#endif
