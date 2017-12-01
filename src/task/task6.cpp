#include "task/task.h"
#include "task/task6.h"
#include "image/color.h"
#include "image/pixel.h"
#include "image/image.h"
#include "image/brightness_histogram.h"
#include "image/connected_components.h"
#include<vector>

Task6::Task6(){

} 

Task6::Task6(const char *fileName) : Task(fileName){

}

Task6::~Task6(){

}

void Task6::operator()(const Image &a) const{
    ConnectedComponents Task6;
    Image out6 = Task6.formcomponents(a);
    out6.writeTo(getOutputFileName());
}

void Task6::doneMssg() const{
    std::cout<<"Task 6 Completed! Output file: "<<getOutputFileName();
}
