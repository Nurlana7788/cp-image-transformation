#ifndef __IMAGE_INC__
#define __IMAGE_INC__

#include<iostream>

class Pixel;

class Image{
    int _width, _height;
    float _maxColorVal;

protected:
    Pixel **_pix;
    void _deallocatePix();

public:
    // Constructor and Destructor
    Image();
    Image(const char *fileName);
    Image(int width, int height);
    virtual ~Image();
    Image(const Image &a);

    // Methods, Getters and Setters
    int getWidth() const;
    int getHeight() const;
    int getMaxColorVal() const;
    void writeTo(const char *fileName);

    // Operator Overloads
    Pixel* operator[](int index) const;
    Image& operator=(const Image &a);
    Image& operator+=(const Image &a);
    Image& operator*=(float a);

    friend Image operator+(const Image &a, const Image &b);
    friend Image operator*(const Image &a, float b);
    friend Image operator*(float b, const Image &a);

    friend std::ostream& operator<<(std::ostream &os, const Image &a);
    friend std::istream& operator>>(std::istream &is, Image &a);
};

#endif
