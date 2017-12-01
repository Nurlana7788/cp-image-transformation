#ifndef __TASK8_INC__
#define __TASK8_INC__

class Image;

#include "task.h"

// Task8 implementation
class Task8 : public Task{

public:
    Task8();
    Task8(const char *fileName);
    virtual ~Task8();
    
    virtual void operator()(const Image &a) const;
    virtual void doneMssg() const;
};

#endif
