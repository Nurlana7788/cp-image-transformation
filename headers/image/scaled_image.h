#ifndef __SCALED_INC__
#define __SCALED_INC__

#include "image.h"

class ScaledImage : public Image{
public:
  //default Constructor
ScaledImage();
ScaledImage(int height, int width);
//takes an image and a number and scales it down to give one image at one corner
//ScaledImage(Image const &a,int n);
ScaledImage(ScaledImage const &s);//copy constructor
virtual ~ScaledImage();
void scaleImage(Image const &a,int n);
void clipImage(Image const &a);
};
#endif
