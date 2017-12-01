#include "image/brightness_histogram.h"
#include "image/image.h"

int main(int argv, char *argc[]){
    Image a(argc[1]);
    BrightnessHistogram res(a, 0);

    res.outputHistogram(10, 10).writeTo("histogram.ppm");

    return 0;
}
