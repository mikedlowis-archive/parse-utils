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
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "ast.h"
#include "visitor.h"

using namespace std;

class Parser {
	protected:
		VisitorFactory* factory;
	private:
	public:
		Parser(VisitorFactory* trans_fact) : factory(trans_fact) {}
		~Parser();
		void parseFile(string* in_file);
		void parseInput(FILE* in_file);
		void processAST(AST* root);
};

#ifdef PURE_PARSER
typedef struct 
{
	void*   lexinfo;
	Parser* parser;
} ParseContext_T;
#endif

#endif
