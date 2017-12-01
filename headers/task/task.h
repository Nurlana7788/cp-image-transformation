#ifndef TASK_BASE_INC
#define TASK_BASE_INC

class Image;

// This serves as a base class for all specialized task class
class Task{
    const char* _outputFile;

public:
    // outputFile is set to "output.ppm"
    Task();
    // Pass file name to assign to outputFile
    Task(const char* fileName);
    
    // Destructor (virtualised to support polymorphism)
    virtual ~Task();

    // Returns outputFile
    const char* getOutputFileName() const;

    // Each task is supposed to overload this
    virtual void operator()(const Image &a) const;

    //Message to be displayed on successful completion
    virtual void doneMssg() const;
};

#endif
