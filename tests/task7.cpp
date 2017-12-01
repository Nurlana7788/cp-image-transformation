#include "brightness_histogram.h"
#include "composite_image.h"
#include "scaled_image.h"
#include "color.h"
#include "image.h"
#include<stdlib.h>

void task7(Image const &a){
  //creates 4 objects of scaled image for 4 diff scaling
  ScaledImage s1(a.getHeight(),a.getWidth());
  ScaledImage s2(a.getHeight(),a.getWidth());
  ScaledImage s3(a.getHeight(),a.getWidth());
  ScaledImage s4(a.getHeight(),a.getWidth());
//alpha is not necessary here, but it does not seem to work without it
  s1.scaleImage(a,1);
  s2.scaleImage(a,2);
  s3.scaleImage(a,3);
  s4.scaleImage(a,4);
  //can comment it out. wrote these to check if there is output coming
  // s1.writeTo("task71.ppm");
  // s2.writeTo("task72.ppm");
  // s3.writeTo("task73.ppm");
  // s4.writeTo("task74.ppm");
  
  //composting with s1 and s2 and compositing s3 and s4
  CompositeImage c1 = CompositeImage::whiteSubstitution(s1,s2);
  CompositeImage c2 = CompositeImage::whiteSubstitution(s3,s4);
  //composting with c1 and c2 to give Image AB
  CompositeImage c3 = CompositeImage::whiteSubstitution(c1,c2);

  ScaledImage s5(a.getHeight(),a.getWidth());
  // c3.writeTo("task75.ppm");
  
  //Cliping the image to give Image C
  s5.clipImage(c3);
  s5.writeTo("task7.ppm");
}

int main(int argv, char *argc[]){
    Image a(argc[1]);

    task7(a);
    return 0;
}
