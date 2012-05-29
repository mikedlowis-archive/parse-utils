#ifndef TOKEN_H
#define TOKEN_H

#include <string>

typedef int TokenType_T;

class Token
{
    private:
        TokenType_T tok_type;
        std::string tok_text;
        int tok_line;
        int tok_col;
    public:
        Token();
        Token(TokenType_T ttype, int line, int col);
        Token(TokenType_T ttype, const std::string& ttext, int line, int col);

        void type(TokenType_T typ);
        TokenType_T type() const;
        void text(std::string txt);
        std::string text() const;
        void line(int ln);
        int line() const;
        void column(int col);
        int column() const;
        bool operator ==(const Token &other) const;
        bool operator !=(const Token &other) const;
};

#endif
