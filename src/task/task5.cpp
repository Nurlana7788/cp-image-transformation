#include "task/task5.h"
#include "task/task.h"
#include "image/color.h"
#include "image/pixel.h"
#include "image/image.h"
#include "image/brightness_histogram.h"
#include "image/composite_image.h"
#include<vector>

Task5::Task5(){

} 

Task5::Task5(const char *fileName) : Task(fileName){

}

Task5::~Task5(){

}

void Task5::operator()(const Image &a) const{
    // Create default images to compose afterwards
    Image c, d;
    // Get brightness histogram for a
    BrightnessHistogram hist(a);

    // Declaration of Color constants
    const Color BLUE(0, 0, 255), WHITE(255, 255, 255), YELLOW(255, 255, 0);

    std::vector<int> thresholds(hist.getThresholds());

    // If thresholds are lesser than 3 take reflections
    if(thresholds.size() < 3){
        c = a.horizontalReflection();
        d = a.verticalReflection();
    }
    else{
        c = a.getBinaryImage(thresholds[1], BLUE, WHITE);
        d = a.getBinaryImage(thresholds[2], YELLOW, WHITE);
    }

    // Compose image and write the result to file
    CompositeImage(d, c, 0.2).writeTo(getOutputFileName());
}

void Task5::doneMssg() const{
    std::cout<<"Task 5 Completed! Output file: "<<getOutputFileName();
}
