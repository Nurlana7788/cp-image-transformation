#include "brightness_histogram.h"
#include "image.h"
#include "pixel.h"
#include "color.h"
#include<algorithm>
#include<vector>

// Default Constructor
BrightnessHistogram::BrightnessHistogram(){

}

// Constructs brightness histogram from image
// Range of frequency vector is from 0 to maximum brightness
// of a. Thus the size of _frequency is a.getMaxColorVal()
BrightnessHistogram::BrightnessHistogram(const Image &a) :
    _frequency(a.getMaxColorVal())
{
    // Iterate through each pixel to find brightness value
    for(int i = 0; i < a.getHeight(); ++i){
        for(int j = 0; j < a.getWidth(); ++j){
            // Brightness is average of RGB components
            Color temp = a[i][j].getColor();
            int brightness = (temp.red() + temp.green() + temp.blue()) / 3;
            _frequency[brightness]++;
        }
    }
}

// Returns an image that is a visualisation of the histogram
Image BrightnessHistogram::outputHistogram(int window, int scaleHeight, bool markThresholds) const{
    // Height of image is the scaled maximum frequency
    int heightOfImage = *std::max_element(
        _frequency.begin(),
        _frequency.end()
    );
    heightOfImage /= scaleHeight;

    // Create image object for storing histogram
    Image histogram(_frequency.size(), heightOfImage);

    // Some color constants
    const Color BLACK(0, 0, 0), WHITE(255, 255, 255), RED(255, 0, 0);

    // Iterate throught the pixels of the histogram
    // and color them appropriately
    for(int i = 0; i < heightOfImage; ++i){
        for(int j = 0; j < _frequency.size(); ++j){
            if(i <= heightOfImage - (_frequency[j] / scaleHeight)){
                histogram[i][j].setColor(WHITE);
            }
            else{
                histogram[i][j].setColor(BLACK);
            }
        }
    }

    // If markThesholds is true then
    // mark thresholds values with a red line
    if(markThresholds){
        std::vector<int> thresholds(getThresholds(window));
        for(int i = 0; i < heightOfImage; ++i){
            for(int j = 0; j < thresholds.size(); ++j){
                histogram[i][thresholds[j]].setColor(RED);
            }
        }
    }

    return histogram;
}

std::vector<int> BrightnessHistogram::getThresholds(int window) const{
    // This will be populated with the threshold values
    std::vector<int> thresholds;

    // For each value of the brightness value
    // check window values on left and right of it
    // This value is threshold if it is minimum in this window
    // Zero frequencies are ignored
    for(int i = 0, j; i < _frequency.size(); ++i){
        if(_frequency[i] == 0) continue;

        for(j = 1; j <= window; ++j){
            if(
                i-j >= 0 &&
                _frequency[i-j] != 0 &&
                _frequency[i-j] < _frequency[i]
            ){
                break;
            }

            if(
                i+j < _frequency.size() &&
                _frequency[i+j] != 0 &&
                _frequency[i+j] < _frequency[i]
            ){
                break;
            }
        }

        if(j > window){
            thresholds.push_back(i);
        }
    }

    return thresholds;
}


std::vector<int> BrightnessHistogram::getFrequencyList() const{
    return _frequency;
}

int BrightnessHistogram::operator[](int index) const{
    // For out of range values return 0
    if(index > _frequency.size()) return 0;

    return _frequency[index];
}
