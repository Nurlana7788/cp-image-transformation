#include "task/task.h"
#include "task/task8.h"
#include "image/brightness_histogram.h"
#include "image/composite_image.h"
#include "image/connected_components.h"
#include "image/color.h"
#include "image/image.h"
#include "image/noise.h"

Task8::Task8(){

} 

Task8::Task8(const char *fileName) : Task(fileName){

}

Task8::~Task8(){

}

void Task8::operator()(const Image &a) const{
    Noise_Image n(a.getWidth(), a.getHeight());
    CompositeImage comp(a, n, 0.2);
    BrightnessHistogram hist(comp);
    std::vector<int> threshold(hist.getThresholds());
    Image res= comp.getBinaryImage(threshold[1], Color(255, 255, 0), Color(255, 255, 255));
    ConnectedComponents conn;
    Image b=conn.formcomponents(a);

    b.writeTo(getOutputFileName());
}

void Task8::doneMssg() const{
    std::cout<<"Task 8 Completed! Output file: "<<getOutputFileName();
}
