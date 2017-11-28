#ifndef __COMPIMG_INC__
#define __COMPIMG_INC__

#include "image.h"

class CompositeImage : public Image{
   
public:
    // Constructors and Destructors
    CompositeImage();
    CompositeImage(const Image &a, const Image &b, float alpha);
};

#endif
