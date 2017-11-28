#include "headers/pixel.h"
#include "headers/color.h"
#include<iostream>

Pixel::Pixel(){
    _x = 0;
    _y = 0;
}

Pixel::Pixel(int x, int y, Color _col){
    _x = x;
    _y = y;
    _col = _col;
}

Pixel::~Pixel(){

}

Pixel::Pixel(const Pixel &a){
    _x = a._x;   
    _y = a._y;
    _col = a._col;
}

Color Pixel::getColor() const{
    return _col;
}

void Pixel::setColor(Color c){
    _col = c;
}

void Pixel::setColor(float red, float green, float blue){
    _col.setColor(red, green, blue);
}

void Pixel::setPosition(int x, int y){
    _x = x;
    _y = y;
}

Pixel& Pixel::operator=(const Pixel &a){
    _x = a._x;   
    _y = a._y;
    _col = a._col;

    return *this;
}

Pixel& Pixel::operator+=(const Pixel &a){
    _col += a._col;

    return (*this);
}

Pixel& Pixel::operator*=(float a){
    _col *= a;

    return (*this);
}

Pixel operator+(const Pixel &a, const Pixel &b){
    return (Pixel(a) += b);
}

Pixel operator*(const Pixel &a, float b){
    return (Pixel(a) *= b);
}

Pixel operator*(float b, const Pixel &a){
    return (a * b);
}

std::ostream& operator<<(std::ostream &os, const Pixel &a){
    os<<a._col;
    return os;
}

std::istream& operator>>(std::istream &is, Pixel &a){
    is>>a._col;

    return is;
}

