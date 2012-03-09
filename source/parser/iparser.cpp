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
#include "iparser.h"

using namespace std;

/******************************************************************************
 * Public Functions
 *****************************************************************************/
IParser::IParser() : result(NULL), lexer(NULL)
{
}

IParser::IParser(ILexer* lxr) : result(NULL), lexer(lxr)
{
}

IParser::~IParser()
{
    if(lexer != NULL)
    {
        delete lexer;
    }

    if(result != NULL)
    {
        delete result;
    }
}

void IParser::input(ILexer* lxr)
{
    lexer = lxr;
}

const AST* IParser::ast() const
{
    return result;
}

void IParser::process(IVisitor& visitor)
{
    visitor.visit(result);
}
