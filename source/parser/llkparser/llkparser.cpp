#include "llkparser.h"
#include "exception.h"

LLKParser::LLKParser(int k_val, ILexer* lxer) : k(k_val), next(0), lexer(lxer)
{
    if ( lexer != NULL )
    {
        lookahead = new Token[k];
    }
    else
    {
        Exception ex(-1,-1);
        ex << "Failed to initialize parser. No lexer was provided.";
        throw ex;
    }
}

LLKParser::~LLKParser()
{
    if (lookahead != NULL)
    {
        delete[] lookahead;
    }
}

void LLKParser::consume(void)
{
    if ( lookahead != NULL )
    {
        lookahead[next] = lexer->next();
        next = (next + 1) % k;
    }
}

void LLKParser::match(TokenType_T type)
{
    if( lookaheadType(1) == type )
    {
        consume();
    }
    else
    {
        Exception ex( lookaheadToken(1) );
        ex << "Unexpected token. Expected " << type << ", received " << lookaheadType(1);
        throw ex;
    }
}

Token& LLKParser::lookaheadToken(int i)
{
    Token& ret = lookahead[(next + i - 1) % k];
    return ret;
}

TokenType_T LLKParser::lookaheadType(int i)
{
    TokenType_T ret = EOF;
    if( lookahead != NULL )
    {
        ret = lookaheadToken(i).type();
    }
    return ret;
}

