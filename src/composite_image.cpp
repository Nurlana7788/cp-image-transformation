#include "composite_image.h"
#include "image.h"
#include "pixel.h"
#include "color.h"

// Call the Image copy constructor to create the object
// We use operator overloading to simplify the code
// 
CompositeImage::CompositeImage(const Image &a, const Image &b, float alpha) :
    Image((a * (1 - alpha)) + (alpha * b))
{
    // Empty
}

// Default Constructor
CompositeImage::CompositeImage(){

}
