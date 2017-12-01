#include "task/task7.h"
#include "task/task.h"
#include "image/brightness_histogram.h"
#include "image/composite_image.h"
#include "image/scaled_image.h"
#include "image/color.h"
#include "image/image.h"

Task7::Task7(){

} 

Task7::Task7(const char *fileName) : Task(fileName){

}

Task7::~Task7(){

}

void Task7::operator()(const Image &a) const{
    //creates 4 objects of scaled image for 4 diff scaling
    ScaledImage s1(a.getHeight(),a.getWidth());
    ScaledImage s2(a.getHeight(),a.getWidth());
    ScaledImage s3(a.getHeight(),a.getWidth());
    ScaledImage s4(a.getHeight(),a.getWidth());

    s1.scaleImage(a,1);
    s2.scaleImage(a,2);
    s3.scaleImage(a,3);
    s4.scaleImage(a,4);
    
    //composing with s1 and s2 and compositing s3 and s4
    CompositeImage c1 = CompositeImage::whiteSubstitution(s1,s2);
    CompositeImage c2 = CompositeImage::whiteSubstitution(s3,s4);

    //composing with c1 and c2 to give Image AB
    CompositeImage c3 = CompositeImage::whiteSubstitution(c1,c2);

    ScaledImage s5(a.getHeight(),a.getWidth());

    //Cliping the image to give Image C
    s5.clipImage(c3);
    s5.writeTo(getOutputFileName());
}

void Task7::doneMssg() const{
    std::cout<<"Task 7 Completed! Output file: "<<getOutputFileName();
}
