#include "image/color.h"
#include "image/pixel.h"
#include "image/image.h"
#include "image/brightness_histogram.h"
#include "image/composite_image.h"
#include<vector>
#include<algorithm>

// indexT1 and indexT2 correspond to the indices for thresholds
// to obtain binary images
void task5(const Image &a, int indexT1, int indexT2){
    // Create default images to compose afterwards
    Image c, d;
    // Get brightness histogram for a
    BrightnessHistogram hist(a);

    // Declaration of Color constants
    const Color BLUE(0, 0, 255), WHITE(255, 255, 255), YELLOW(255, 255, 0);

    std::vector<int> thresholds(hist.getThresholds());
    // If thresholds are lesser than 2 take reflections
    if(thresholds.size() < std::max(indexT1, indexT2)){
        c = a.horizontalReflection();
        d = a.verticalReflection();
    }
    else{
        c = a.getBinaryImage(thresholds[indexT1], BLUE, WHITE);
        d = a.getBinaryImage(thresholds[indexT2], YELLOW, WHITE);
    }

    // Compose image and write the result to file
    CompositeImage(d, c, 0.2).writeTo("task5.ppm");
}

int main(int argv, char *argc[]){
    Image a(argc[1]);
    int ind1 = atoi(argc[2]), ind2 = atoi(argc[3]);
    task5(a, ind1, ind2);

    return 0;
}
