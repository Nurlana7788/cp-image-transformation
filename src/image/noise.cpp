#include<iostream>
#include "image/image.h"
#include "image/composite_image.h"
#include "image/noise.h"
#include "image/color.h"
#include "image/pixel.h"
using namespace std;

Noise_Image::Noise_Image(int width,int height):
  Image(width, height)
{
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      int r=rand()%256;
      int g=rand()%256;
      int b=rand()%256;
      Color *c=new Color(r,g,b);
      _pix[i][j].setColor(*c);
    }
  }
}

Noise_Image::Noise_Image(const Noise_Image & n):
  Image(n)
{

}

Noise_Image::~Noise_Image(){
  //Empty
}
