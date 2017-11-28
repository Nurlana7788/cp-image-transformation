#include "color.h"
#include<iostream>

Color::Color(){
    _red = 0;
    _green = 0;
    _blue = 0;
}

Color::Color(float red, float green, float blue){
    _red = red;
    _green = green;
    _blue = blue;
}

Color::~Color(){

}

Color::Color(const Color &a){
    _red = a._red;
    _green = a._green;
    _blue = a._blue;
}

void Color::setColor(float red, float green, float blue){
    _red = red;
    _green = green;
    _blue = blue;
}


Color& Color::operator=(const Color &a){
    _red = a._red;
    _green = a._green;
    _blue = a._blue;

    return *this;
}

float Color::red() const{
    return _red;
}

float Color::green() const{
    return _green;
}

float Color::blue() const{
    return _blue;
}

Color& Color::operator+=(const Color &a){
    _red += a._red;
    _green += a._green;
    _blue += a._blue;

    return (*this);
}

Color& Color::operator*=(float a){
    _red *= a;
    _green *= a;
    _blue *= a;

    return (*this);
}
Color operator+(const Color &a, const Color &b){
    return (Color(a) += b);
}

Color operator*(const Color &a, float b){
    return (Color(a) *= b);
}

Color operator*(float b, const Color &a){
    return a * b;
}

bool operator==(Color a, Color b){
    return (a._red == b._red) && (a._green == b._green) && (a._blue == b._blue);
}

std::ostream& operator<<(std::ostream &os, const Color &a){
    os<<(int)a._red<<' '<<(int)a._green<<' '<<(int)a._blue;

    return os;
}

std::istream& operator>>(std::istream &is, Color &a){
    is>>a._red>>a._green>>a._blue;

    return is;
}
