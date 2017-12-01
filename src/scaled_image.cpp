#include "scaled_image.h"
#include "composite_image.h"
#include "image.h"
#include "pixel.h"
#include "color.h"

//default constructor,sets the ppm to white
ScaledImage::ScaledImage():Image(){
  
}

//constructor, with height and width
ScaledImage::ScaledImage(int height,int width):Image(width, height, Color(255, 255, 255)){

}

//copy constructor
ScaledImage::ScaledImage(ScaledImage const &s):
    Image(s.getWidth(),s.getHeight(), Color(255, 255, 255))
{
  
}

//destructor
ScaledImage::~ScaledImage(){}

//scales image,depending on n, positions the scaled image on four quadrants
void ScaledImage::scaleImage(Image const &a,int n){
  if(n==1){
    int i1=0,j1=0;//start from 0,0
    for(int i =0;i<a.getHeight();i+=2){
      for(int j=0;j<a.getWidth();j+=2){
        //taking avaerage of four pixels near the particular pixel
         Color col1(a[i][j].getColor()+a[i][j+1].getColor()+a[i+1][j].getColor()+a[i+1][j+1].getColor());
         int red = col1.red()/4;
         int green = col1.green()/4;
         int blue = col1.blue()/4;
         col1.setColor(red,green,blue);
        _pix[i1][j1].setColor(col1);
        j1++;
      }
      j1=0;
      i1++;
    }
  }
  if(n==2){
   int i2=0;
   int j2=a.getWidth()/2;//starts from top half
   Image ref1 = a.horizontalReflection();
   for(int i=0;i<ref1.getHeight();i+=2){
     for(int j=0;j<ref1.getWidth();j+=2){
       Color col2(ref1[i][j].getColor()+ref1[i][j+1].getColor()+ref1[i+1][j].getColor()+ref1[i+1][j+1].getColor());
       int red = col2.red()/4;
       int green = col2.green()/4;
       int blue = col2.blue()/4;
       col2.setColor(red,green,blue);
       _pix[i2][j2].setColor(col2);
      j2++;
     }
     j2=a.getWidth()/2;
     i2++;
   }
 }
 if(n==3){
   Image ref2 = a.verticalReflection();
   int i3 =getHeight()/2;
   int j3 =0;//starts from 3rd quadrant
   for(int i=0;i<ref2.getHeight();i+=2){
     for(int j=0;j<ref2.getWidth();j+=2){
       Color col3(ref2[i][j].getColor()+ref2[i][j+1].getColor()+ref2[i+1][j].getColor()+ref2[i+1][j+1].getColor());
       int red = col3.red()/4;
       int green = col3.green()/4;
       int blue = col3.blue()/4;
       col3.setColor(red,green,blue);
       _pix[i3][j3].setColor(col3);
       j3++;
     }
     j3=0;
     i3++;
   }
 }
  if(n==4){

   Image ref3 = a.horizontalReflection().verticalReflection();
   int i4 = getHeight()/2;
   int j4 = getWidth()/2;//fourthquadrant
   for(int i=0;i<getHeight();i+=2){
     for(int j=0;j<getWidth();j+=2){
       Color col4(ref3[i][j].getColor()+ref3[i][j+1].getColor()+ref3[i+1][j].getColor()+ref3[i+1][j+1].getColor());
       int red = col4.red()/4;
       int green = col4.green()/4;
       int blue = col4.blue()/4;
       col4.setColor(red,green,blue);
       _pix[i4][j4].setColor(col4);
       j4++;
    }
     j4=a.getWidth()/2-1;
     i4++;
    }
  }
}

void ScaledImage::clipImage(Image const &a){
  //clips the picture in a square with white border
  for(int i=0;i<a.getWidth();i++){
    for(int j=0;j<a.getHeight();j++){
      if(i<=a.getWidth()/4 || j<=a.getHeight()/4 || i>=(a.getWidth()*3)/4 || j>=(a.getHeight()*3)/4){
        _pix[i][j].setColor(Color(255,255,255));//white
      }
      else
        _pix[i][j]=a[i][j];//or the picture
    }
  }
}
