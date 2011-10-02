/******************************************************************************
 *  Copyright (C) 2001  Michael D. Lowis
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/
/******************************************************************************
 * Includes and Prototypes
 *****************************************************************************/
#include <stdio.h>
#include "parser.h"

using namespace std;

#ifdef PURE_PARSER
typedef void* yyscan_t;
extern int yyparse(ParseContext_T* context);
extern int yylex_init(yyscan_t* ptr_yy_globals);
extern void yyset_in (FILE*  in_str , yyscan_t yyscanner);
#else
#endif

/******************************************************************************
 * Public Functions
 *****************************************************************************/
Parser::~Parser()
{
	delete factory;
}

void Parser::parseInput(FILE* in_file)
{
	if ( in_file != NULL )
	{
		#ifdef PURE_PARSER
		ParseContext_T context = { NULL, this};
		yylex_init( &(context.lexinfo) );
		yyset_in( in_file, context.lexinfo );
		yyparse( &context );
		#else
		#endif
	}
}

void Parser::parseFile(string* in_file)
{
	FILE* input_file = fopen( in_file->c_str() ,"r");
	parseInput( input_file );
	delete in_file;
}

void Parser::processAST(AST* root)
{
	Visitor* translator = factory->createVisitor(root);
	translator->visit();
	cout << translator->str();
	delete translator;
}

