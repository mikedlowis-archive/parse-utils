#include "ibuffer.h"

IBuffer::IBuffer()
{
}

IBuffer::~IBuffer()
{
}

void IBuffer::consume(void)
{
    advance();
    if((location() == size()) && !isMarked())
    {
        seek(0);
        clear();
    }
    sync(1);
}

void IBuffer::sync(unsigned int i)
{
    unsigned int next_index = location() + i - 1;
    unsigned int max_index = (size() - 1);

    if( size() == 0 )
    {
        fill(i);
    }
    else if( next_index >= max_index )
    {
        fill( next_index - max_index);
    }
}

void IBuffer::fill(unsigned int n)
{
    unsigned int i = 0;
    for (i = 0; i < n; i++)
    {
        load();
    }
}


