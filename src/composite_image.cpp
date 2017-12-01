#include "composite_image.h"
#include "image.h"
#include "pixel.h"
#include "color.h"

// Call the Image copy constructor to create the object
// We use operator overloading to simplify the code
CompositeImage::CompositeImage(const Image &a, const Image &b, float alpha) :
    Image((a * (1 - alpha)) + (alpha * b))
{
    // Empty
}

// Default Constructor
CompositeImage::CompositeImage(){

}

// Copy Constructor
// Use base class constructor for copying
CompositeImage::CompositeImage(const Image &a) :
    Image(a)
{

}

CompositeImage::~CompositeImage(){

}

CompositeImage CompositeImage::whiteSubstitution(const Image &a, const Image &b){
    // Will contain result
    CompositeImage res(a);
    const Color WHITE(255, 255, 255);

    for(int i = 0; i < res.getHeight(); ++i){
        for(int j = 0; j < res.getWidth(); ++j){
            // If color is white replace it with b's color
            if(res[i][j].getColor() == WHITE){
                res[i][j].setColor(b[i][j].getColor());
            }
        }
    }

    return res;
}
