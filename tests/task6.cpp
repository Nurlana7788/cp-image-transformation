#include<stdio.h>
#include "image/color.h"
#include "image/pixel.h"
#include "image/image.h"
#include "image/brightness_histogram.h"
#include "image/connected_components.h"
#include<algorithm>
#include<vector>

void task6(Image& in6){
    ConnectedComponents Task6;
    Image out6 = Task6.formcomponents(in6);
    out6.writeTo("task6.ppm");
}

int main(int argv, char *argc[]){
    Image a(argc[1]);
    task6(a);
    return 0;
}
