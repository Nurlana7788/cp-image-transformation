#include "task/task.h"
#include "task/task5.h"
#include "task/task7.h"
#include "image/image.h"
#include<iostream>

int main(int argv, char *argc[]){
    if(argv < 2){
        std::cout<<"Please provide image file as input.\n";
    }

    // Read image from file
    Image input(argc[1]);

    Task defObject;

    Task *taskCallables[] = {
        &defObject, // 1
        &defObject, // 2
        &defObject, // 3
        &defObject, // 4
        new Task5("5_IMT2016054.ppm"), // 5
        &defObject, // 6
        new Task7("7_IMT2016116.ppm"), // 7
        &defObject // 6
    };

    int taskIdList[] = {2, 3, 5, 6, 7, 8};

    std::cout<<"Our group task ID combination is: ";
    for(int i = 0; i < sizeof(taskIdList) / sizeof(int); ++i){
        std::cout<<taskIdList[i]<<' ';
    }
    std::cout<<"\n\n";

    for(int i = 0; i < sizeof(taskIdList) / sizeof(int); ++i){
        std::cout<<"Starting Task "<<taskIdList[i]<<std::endl;
        (*taskCallables[taskIdList[i] - 1])(input);
        taskCallables[taskIdList[i] - 1]->doneMssg();
        std::cout<<"\n\n";
    }
}
