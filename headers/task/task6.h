#ifndef __TASK6_INC__
#define __TASK6_INC__

class Image;

#include "task.h"

// Task6 implementation
class Task6 : public Task{

public:
    Task6();
    Task6(const char *fileName);
    virtual ~Task6();
    
    virtual void operator()(const Image &a) const;
    virtual void doneMssg() const;
};

#endif
