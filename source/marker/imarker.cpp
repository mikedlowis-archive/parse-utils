#include "imarker.h"

void IMarker::advance(void)
{
    cur_location++;
}

unsigned int IMarker::location(void)
{
    return cur_location;
}

void IMarker::location(unsigned int index)
{
    cur_location = index;
}

unsigned int IMarker::mark(void)
{
    unsigned int index = location();
    markers.push_back( index );
    return index;
}

void IMarker::release(void)
{
    unsigned int marker = markers.back();
    markers.pop_back();
    seek(marker);
}

void IMarker::seek(unsigned int index)
{
    location( index );
}

bool IMarker::isMarked(void)
{
    return (markers.size() > 0);
}

