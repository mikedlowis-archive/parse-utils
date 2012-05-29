#include <stdio.h>
#include "token.h"

Token::Token() : tok_type(EOF), tok_text(""), tok_line(-1), tok_col(-1)
{
}

Token::Token(TokenType_T ttype, const std::string& ttext, int line, int col) : tok_type(ttype), tok_text(ttext), tok_line(line), tok_col(col)
{
}

Token::Token(TokenType_T ttype, int line, int col) : tok_type(ttype), tok_line(line), tok_col(col)
{
}

void Token::type(TokenType_T typ)
{
    tok_type = typ;
}

TokenType_T Token::type() const
{
    return tok_type;
}

void Token::text(std::string txt)
{
    tok_text = txt;
}

std::string Token::text() const
{
    return tok_text;
}

void Token::line(int ln)
{
    tok_line = ln;
}

int Token::line() const
{
    return tok_line;
}

void Token::column(int col)
{
    tok_col = col;
}

int Token::column() const
{
    return tok_col;
}

bool Token::operator ==(const Token& rhs) const
{
    return ( (tok_type == rhs.type())   &&
             (tok_line == rhs.line())   &&
             (tok_col  == rhs.column()) &&
             (tok_text.compare( rhs.text() ) == 0) );
}

bool Token::operator !=(const Token& rhs) const
{
    return !( *this == rhs );
}
