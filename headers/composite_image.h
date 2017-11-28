#ifndef __COMPIMG_INC__
#define __COMPIMG_INC__

#include "image.h"

class CompositeImage : public Image{
   
public:
    // Default Constructor
    CompositeImage();

    // Combines images a and b in the following way:
    //      (a * (1 - alpha)) + (b * alpha)
    CompositeImage(const Image &a, const Image &b, float alpha);

    // Copy Constructor
    CompositeImage(const CompositeImage &a);
};

#endif
