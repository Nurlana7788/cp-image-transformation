#include "brightness_histogram.h"
#include "image.h"

int main(int argv, char *argc[]){
    Image a(argc[1]);
    BrightnessHistogram res(a);

    res.outputHistogram(10, 10).writeTo("output.ppm");

    return 0;
}
