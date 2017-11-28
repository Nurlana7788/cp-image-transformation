#ifndef __IMAGE_INC__
#define __IMAGE_INC__

#include<iostream>

class Pixel;

class Image{
    int _width, _height;

protected:
    Pixel **_pix;

    // Deallocates pixel values and sets
    // _pix to NULL
    void _deallocatePix();

public:
    // Default constructor
    Image();

    // Opens a ppm file of P3 type and
    // retrieves data from it. If the file is not
    // of P3 type it sets the values to 0 and NULL
    // appropriately.
    Image(const char *fileName);

    // Allocates memory for new image of size
    // width and height. The pixel values are set 
    // through the default Pixel constructor
    Image(int width, int height);

    // Destructor for Image
    virtual ~Image();

    // Copy Constructor
    Image(const Image &a);

    // Getter for _width
    int getWidth() const;
    
    // Getter for _height
    int getHeight() const;

    // Returns the max value of any component (RGB)
    // among all colors values present in the image
    int getMaxColorVal() const;

    // Writes the contents of the image into the
    // file as descibed by fileName in ppm (P3)
    // format
    void writeTo(const char *fileName);

    // Returns new image that is the reflection
    // of the curent image along the height
    // i.e. the topmost row becomes the last one
    // and so on.
    Image verticalReflection() const;

    // Returns new image that is the reflection
    // of the curent image along the width
    // i.e. the first column becomes the last one
    // and so on.
    Image horizontalReflection() const;

    // Operator Overloads
    Image& operator=(const Image &a);
    Image& operator+=(const Image &a);
    Image& operator*=(float a);

    // Returns the index numbered row.
    // To retrieve an individual pixel value
    // chain [] i.e. img[row][column]
    Pixel* operator[](int index) const;

    friend Image operator+(const Image &a, const Image &b);
    friend Image operator*(const Image &a, float b);
    friend Image operator*(float b, const Image &a);

    // Basic I/O operations. 
    // Use writeTo and constructor for file based I/O
    friend std::ostream& operator<<(std::ostream &os, const Image &a);
    friend std::istream& operator>>(std::istream &is, Image &a);
};

#endif
