#ifndef IBUFFER_H
#define IBUFFER_H

#include <vector>
#include "imarker.h"

class IBuffer : public IMarker
{
    public:
        IBuffer();
        virtual ~IBuffer();
        void consume(void);
        void sync(unsigned int i);
        void fill(unsigned int n);
        virtual unsigned int size() = 0;
        virtual void clear() = 0;
        virtual void load() = 0;
};

#endif
