#include "task/task.h"
#include<iostream>

Task::Task(){
    _outputFile = "output.ppm";
}

Task::Task(const char *fileName){
    _outputFile = fileName;
}

Task::~Task(){

}

const char* Task::getOutputFileName() const{
    return _outputFile;
}

void Task::operator()(const Image &a) const{
    // Simple message to denote base class constructor is called
    std::cout<<"This task does not exist";
}

void Task::doneMssg() const{
    // Empty for base class
}
