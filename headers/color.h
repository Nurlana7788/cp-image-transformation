#ifndef __COLOR_INC__
#define __COLOR_INC__

#include<iostream>

class Color{
    float _red, _green, _blue;

public:
    // Constructors and Destructors
    Color();
    Color(float red, float green, float blue);    
    ~Color();
    Color(const Color &a);

    // Methods, Setters and Getters
    void setColor(float red, float green, float blue);
    float red() const;
    float green() const;
    float blue() const;

    // Operator overloads
    Color& operator+=(const Color &a);
    Color& operator*=(float a);
    Color& operator=(const Color &a);

    friend Color operator+(const Color &a, const Color &b); 
    friend Color operator*(const Color &a, float b);
    friend Color operator*(float b, const Color &a);
    friend bool operator==(Color a, Color b);

    friend std::ostream& operator<<(std::ostream &os, const Color &a);
    friend std::istream& operator>>(std::istream &is, Color &a);    
};

#endif

