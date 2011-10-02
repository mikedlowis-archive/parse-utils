#ifndef AST_H
#define AST_H 

#include <stdarg.h>
#include <list>
#include <string>

using namespace std;

typedef unsigned int ASTNodeType;

class AST {
	protected:
		ASTNodeType node_type;
		string* node_text;
		list<AST*>* node_children;
	public:
		AST(ASTNodeType type);
		~AST();
		AST(ASTNodeType type, char* text);
		AST(ASTNodeType type, int child_count, ...);
		ASTNodeType type();
		string text();
		list<AST*>* children();
		void addChild(AST* node);
};

#endif
