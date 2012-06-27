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

class Lexer
{
    public:
        Token operator() (CharBuffer& input)
        {
            return Token();
        }
};

class Parser
{
    public:
        //AST* operator() (CharBuffer& input) = 0;
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
        Lexer lexer;
        lexer(input);
    }
}
