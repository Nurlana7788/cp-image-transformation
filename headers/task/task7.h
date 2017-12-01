#ifndef __TASK7_INC__
#define __TASK7_INC__

class Image;

#include "task.h"

// Task7 implementation
class Task7 : public Task{

public:
    Task7();
    Task7(const char *fileName);
    virtual ~Task7();
    
    virtual void operator()(const Image &a) const;
    virtual void doneMssg() const;
};

#endif
