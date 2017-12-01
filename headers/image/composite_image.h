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
    // Generalized to copy any image
    CompositeImage(const Image &a);

    // Virtual destructor
    virtual ~CompositeImage();

    // White Substitution
    // During composition all white pixels of a
    // are replaced with pixels of b
    // Should be called in the following manner:
    //      CompositeImage::whiteSubstitution(a, b)
    static CompositeImage whiteSubstitution(const Image &a, const Image &b);
};

#endif
