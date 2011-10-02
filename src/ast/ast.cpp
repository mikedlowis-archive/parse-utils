#include "ast.h"
#include <sstream>
#include <string.h>

AST::AST(ASTNodeType type)
{
	node_type = type;
	node_text = NULL;
	node_children = new list<AST*>();
}

AST::~AST()
{
	list<AST*>::iterator it = node_children->begin();
	for(; it != node_children->end(); it++)
	{
		delete *(it);
	}
	delete node_children;
	delete node_text;
}

AST::AST(ASTNodeType type, char* text)
{
	node_type = type;
	node_text = new string(text);
	node_children = new list<AST*>();
}

AST::AST(ASTNodeType type, int child_count, ...)
{
	va_list arg_list;
	int i = 0;
	node_type = type;
	node_text = NULL;
	node_children = new list<AST*>();
	va_start (arg_list, child_count); 
	for (i = 0; i < child_count ; i++)
	{
		node_children->push_back( (AST*)va_arg(arg_list, AST*) );
	}
	va_end(arg_list);
}

ASTNodeType AST::type()
{
	return node_type;
}

list<AST*>* AST::children()
{
	return node_children;
}

string AST::text()
{
	ostringstream oss;
	if(node_text != NULL)
	{
		oss << node_text->c_str();
	}
	return oss.str();
}

void AST::addChild(AST* node)
{
	node_children->push_back(node);
}

