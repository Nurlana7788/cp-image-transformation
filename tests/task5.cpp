#include "color.h"
#include "pixel.h"
#include "image.h"
#include "brightness_histogram.h"
#include "composite_image.h"
#include<vector>

Image getBinaryImage(const Image &a, int threshold, Color lower, Color higher){
    // binary will be transformed into binary image
    Image binary(a.getWidth(), a.getHeight());

    // Iterate through pixels, find brightness
    // if brightness is lower than threshold set color to lower
    // else set it to higher
    for(int i = 0; i < a.getHeight(); ++i){
        for(int j = 0; j < a.getWidth(); ++j){
            if(a[i][j].brightness() > threshold){
                binary[i][j].setColor(higher);
            }
            else{
                binary[i][j].setColor(lower);
            }
        }
    }

    return binary;
}

void task5(const Image &a){
    // Create default images to compose afterwards
    Image c, d;
    // Get brightness histogram for a
    BrightnessHistogram hist(a);

    // Declaration of Color constants
    const Color BLUE(0, 0, 255), WHITE(255, 255, 255), YELLOW(255, 255, 0);

    std::vector<int> thresholds(hist.getThresholds());
    // If thresholds are lesser than 2 take reflections
    if(thresholds.size() < 2){
        c = a.horizontalReflection();
        d = a.verticalReflection();
    }
    else{
        c = getBinaryImage(a, thresholds[0], BLUE, WHITE);
        d = getBinaryImage(a, thresholds[1], YELLOW, WHITE);
    }

    // Compose image and write the result to file
    CompositeImage(d, c, 0.2).writeTo("task5.ppm");
}

int main(int argv, char *argc[]){
    Image a(argc[1]);
    task5(a);

    return 0;
}
