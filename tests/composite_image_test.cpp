#include "composite_image.h"
#include "image.h"
#include<fstream>
#include<stdlib.h>
#include<iostream>

int main(int argv, char *argc[]){
    Image a(argc[1]), b(argc[2]);
    CompositeImage res(a, b, atof(argc[3]));

    res.writeTo("output.ppm");

    return 0;
}

