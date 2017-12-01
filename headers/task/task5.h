#ifndef __TASK5_INC__
#define __TASK5_INC__

class Image;

#include "task.h"

// Task5 implementation
class Task5 : public Task{

public:
    Task5();
    Task5(const char *fileName);
    virtual ~Task5();
    
    virtual void operator()(const Image &a) const;
    virtual void doneMssg() const;
};

#endif
