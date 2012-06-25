#ifndef ISTREAM_H
#define ISTREAM_H

#include <vector>

class IMarker
{
    protected:
        unsigned int cur_location;
        std::vector<unsigned int> markers;
    public:
        IMarker();
        virtual ~IMarker();
        void advance(void);
        unsigned int location(void);
        void location(unsigned int index);
        unsigned int mark(void);
        void release(void);
        void seek(unsigned int index);
        bool isMarked(void);
};

#endif
