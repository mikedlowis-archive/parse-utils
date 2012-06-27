// Unit Test Framework Includes
#include "UnitTest++.h"

// Supporting Includes
#include <iostream>
#include <fstream>
#include <vector>

// File To Test
#include "token.h"
#include "ibuffer.h"

using namespace UnitTest;

//-----------------------------------------------------------------------------
// Helper Functions and Classes
//-----------------------------------------------------------------------------
class CharBuffer : public IBuffer
{
    private:
        std::istream& input_ref;
        std::vector<char> buffer;
    public:
        CharBuffer(std::istream& input) : input_ref(input)
        {
            sync(1);
        }

        unsigned int size()
        {
            return buffer.size();
        }

        void clear()
        {
            buffer.clear();
        }

        void load()
        {
            buffer.push_back( (char)input_ref.get() );
        }

        char lookahead(unsigned int index)
        {
            index = (index == 0) ? 1 : index;
            sync( index );
            return buffer.at( index - 1 );
        }
};

//-----------------------------------------------------------------------------
// Lexer Class
//-----------------------------------------------------------------------------
class Lexer
{
    protected:
        Lexer* lex_sibling;
        Lexer* lex_child;
    public:
        // Construction/Destruction
        Lexer() : lex_sibling(0), lex_child(0)
        {
        }

        Lexer(const Lexer& lxr) : lex_sibling(0), lex_child(0)
        {
        }

        virtual ~Lexer()
        {
        }

        // Accessors
        Lexer* sibling()
        {
            return lex_sibling;
        }

        void sibling(Lexer* lxr)
        {
            lex_sibling = lxr;
        }

        Lexer* child()
        {
            return lex_child;
        }

        void child(Lexer* lxr)
        {
            lex_sibling = lxr;
        }

        // Action methods
        Lexer* clone() const
        {
            return new Lexer(*this);
        }

        void addSibling(Lexer* lxr)
        {
        }

        void addChild(Lexer* lxr)
        {
        }

        // Operators
        Token operator() (CharBuffer& input)
        {
            std::cout << this << " ";
            if( NULL != sibling() )
            {
                (*sibling())( input );
            }
            std::cout << std::endl;
            return Token();
        }

        Lexer& operator+ (const Lexer& rhs)
        {
            addSibling( rhs.clone() );
            return *this;
        }

        Lexer& operator| (const Lexer& rhs)
        {
            addChild( rhs.clone() );
            return *this;
        }
};

//-----------------------------------------------------------------------------
// Begin Unit Tests
//-----------------------------------------------------------------------------
namespace {
    //-------------------------------------------------------------------------
    // Test consume() method
    //-------------------------------------------------------------------------
    TEST(Do_Cool_Stuff)
    {
        std::ifstream file;
        file.open( "input.txt" );
        CharBuffer input( file );
        Lexer& lexer = (Lexer() + Lexer() + Lexer());
        lexer( input );
    }
}
