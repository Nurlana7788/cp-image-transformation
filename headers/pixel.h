#ifndef __PIXEL_INC__
#define __PIXEL_INC__

#include "color.h"

#include<iostream>

class Pixel{
    int _x, _y;
    Color _col;

public:
    // Constructors and Destructors
    Pixel();
    Pixel(int x, int y, Color _col);
    ~Pixel();
    Pixel(const Pixel &a);

    // Methods, Getters and Setters
    Color getColor() const;
    void setColor(Color c);
    void setColor(float red, float green, float blue);    
    void setPosition(int x, int y);

    // Operator Overloads
    Pixel& operator=(const Pixel &a);
    Pixel& operator+=(const Pixel &a);
    Pixel& operator*=(float a);

    friend Pixel operator+(const Pixel &a, const Pixel &b);
    friend Pixel operator*(const Pixel &a, float b);
    friend Pixel operator*(float b, const Pixel &a);

    friend std::ostream& operator<<(std::ostream &os, const Pixel &a);
    friend std::istream& operator>>(std::istream &is, Pixel &a); 
};

#endif
