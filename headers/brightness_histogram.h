#ifndef __HISTOGRAM_INC__
#define __HISTOGRAM_INC__

#include<vector>

class Image;

class BrightnessHistogram{
    std::vector<int> _frequency;

public:

    // Default Constructor
    BrightnessHistogram();

    // Takes an image and constructs the brightness
    // histogram for it
    BrightnessHistogram(const Image &a);

    // Returns an image of the histogram i.e. this function
    // can be used to visualize the hisotgram through an image
    // Parameters:
    //      window: The size of the window for which minimum is checked
    //      scaleHeight: The ratio of frequency to pixel
    //      markThresholds: True if the threshholds should be marked in the image
    //                      using a red line
    Image outputHistogram(int window = 10, int scaleHeight = 10, bool markThresholds = true) const;

    // Returns a vector which contains the threshold values.
    // The values of the vecotr correspond to the brightness values
    // at which local minimum occurs
    // Parameters:
    //      window: The size of the window for which minimum is checked
    std::vector<int> getThresholds(int window = 10) const;

    // Returns the frequency counts of brightness.
    // The frequency values correspond to brightness
    // values starting from 0 and increasng by 1.
    std::vector<int> getFrequencyList() const;

    // An easy way to access the frequency of a 
    // particular brightness value, using the []
    // operator on the BrightnessHistogram
    int operator[](int index) const;
};

#endif
