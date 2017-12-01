#ifndef Noise_Image_h_
#define Noise_Image_h_
#include<iostream>
#include "image.h"
#include "composite_image.h"

class Noise_Image:public Image{

public:
   Noise_Image();
  //constructor
    Noise_Image(int width,int height);
//destructor
    ~Noise_Image();
//copy constructor
    Noise_Image(const Noise_Image & n);
//adding Noise_Image to a image
  //  Image noise_image();
//composing the image
  //  Image* compose(Image in,float alpha);

};

#endif
