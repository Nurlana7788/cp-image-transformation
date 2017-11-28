#include "headers/image.h"
#include "headers/color.h"
#include "headers/pixel.h"
#include<fstream>
#include<string>
#include<algorithm>

/* Each image is an independent entity. Thus the implementation of the
 * class should be such that there should no dependency across images.
 * This can be achieved by creating new colour objects for each image
 * so the changes to one image aren't reflected in another. */

// Default constructor for Image
Image::Image(){
    _width = 0;
    _height = 0;
    _maxColorVal = 0;
    _pix = NULL;
}

// Function that deallocates _pix
void Image::_deallocatePix(){
    if(_pix != NULL){
        for(int i = 0; i < _height; ++i){
            delete[] _pix[i];
        }
        delete[] _pix;
    }
}

// Constructor to read from an P3 encoded image file
Image::Image(const char *fileName){
    // Open file for reading
    std::ifstream imfile(fileName);

    // Check if the file is P3
    std::string magicNumber;
    imfile>>magicNumber;
    if(magicNumber != "P3"){
        // If not P3 set to default
        std::cout<<"Hello";
        _width = 0;
        _height = 0;
        _maxColorVal = 0;
        _pix = NULL;

        return;
    }

    // Use the stream insertion operator for
    // reading the image
    imfile>>*(this); 
}

// Constructor to create an image of a given size
Image::Image(int width, int height){
    _width = width;
    _height = height;
    // The default is set to 255
    _maxColorVal = 255;

    // Allocate an array of Pixel pointers
    // This gives the height dimension
    _pix = new Pixel*[_height];
    for(int i = 0; i < _height; ++i){
        // Allocate an array of Pixel
        // This gives the width dimension
        _pix[i] = new Pixel[_width];
        for(int j = 0; j < _width; ++j){
            // Although not used anywhere
            // we set the position of each
            // pixel for consistency
            _pix[i][j].setPosition(i, j);
        }
    }
}

// Destructor
Image::~Image(){
    // Cleaning up allocated memory
   _deallocatePix();
}

Image::Image(const Image &a){
    _width = a._width;
    _height = a._height;
    _maxColorVal = a._maxColorVal;

    // Create a new set of pixel objects for this object
    // such that the values of the pixels are equal to the
    // passed object
    _pix = new Pixel*[_height];
    for(int i = 0; i < a._height; ++i){
        _pix[i] = new Pixel[_width];
        for(int j = 0; j < a._width; ++j){
            _pix[i][j] = a._pix[i][j];
        }
    }
    
}

int Image::getWidth() const{
    return _width;
}

int Image::getHeight() const{
    return _height;
}

int Image::getMaxColorVal() const{
    return _maxColorVal;
}

void Image::writeTo(const char *fileName){
    // Open stream for writing into
    // file
    std::ofstream out(fileName);

    out<<"P3\n";
    out<<_width<<' '<<_height<<'\n';
    out<<(int)_maxColorVal<<'\n';
    // Use overloaded << operator of Image
    // to write pixel values
    out<<(*this);

    out.close();
}

Image& Image::operator=(const Image &a){
    // Deallocate the current pixel objects
    _deallocatePix();

    _width = a._width;
    _height = a._height;
    _maxColorVal = a._maxColorVal;

    // Allocate a new set of pixel objects
    // such that the corresponding values are
    // equal
    _pix = new Pixel*[_height];
    for(int i = 0; i < a._height; ++i){
        _pix[i] = new Pixel[_width];

        for(int j = 0; j < a._width; ++j){
            _pix[i][j] = a._pix[i][j];
        }
    }

    return *this;
}

// This enables us to retrieve the pixel from an
// image object using "array indexing" operators
Pixel* Image::operator[](int index) const{
    // Guard against NULL
    if(_pix == NULL) return NULL;

    // Using the [] operator on an image returns
    // an array of pixels (through the pointer). Another
    // [] operator returns the individual pixel 
    // from the array.
    return _pix[index];
}

// To write to a file in P3 encoded format use
// the writeTo function
std::ostream& operator<<(std::ostream &os, const Image &a){
    for(int i = 0; i < a._height; ++i){
        for(int j = 0; j < a._width; ++j){
            os<<a[i][j]<<' ';
        }
        os<<'\n';
    }

    return os;
}

// To read an image form a P3 encoded image use the
// image constructor instead
std::istream& operator>>(std::istream &is, Image &a){
    is>>a._width>>a._height>>a._maxColorVal;

    a._pix = new Pixel*[a._height];
    for(int i = 0; i < a._height; ++i){
        a._pix[i] = new Pixel[a._width];
        for(int j = 0; j < a._width; ++j){
            a._pix[i][j].setPosition(i, j);
            is>>a._pix[i][j];
        }
    }

    return is;
}

Image& Image::operator+=(const Image &a){
    // In case the images are of unequal sizes
    // the smaller dimensions are taken
    int iterWidth = std::min(_width, a._width);
    int iterHeight = std::min(_height, a._height);

    for(int i = 0; i < iterHeight; ++i){
        for(int j = 0; j < iterWidth; ++j){
            // Make use of pixel's operator
            // overlaoding
            _pix[i][j] += a._pix[i][j];

            Color temp = _pix[i][j].getColor();

            // Update maxColorVal
            _maxColorVal = std::max(
                std::max(_maxColorVal, temp.red()),
                std::max(temp.green(), temp.blue())
            );
        }
    }

    return (*this);
}

Image operator+(const Image &a, const Image &b){
    // The copy constructor creates a new image
    // with new Pixel objects
    // We then use the already defined +=
    // operator to return the sum
    return (Image(a) += b);
}

Image& Image::operator*=(float a){
    // Iterate through the pixels and use
    // the *= operator of Pixel for changing values
    for(int i = 0; i < _height; ++i){
        for(int j = 0; j < _width; ++j){
            _pix[i][j] *= a;
        }
    }

    _maxColorVal *= a;

    return (*this);
}

Image operator*(float b, const Image &a){
    // The copy constructor creates a new image
    // with new Pixel objects
    // We then use the already defined *=
    // operator to return the sum
    return (Image(a) *= b);
}

Image operator*(const Image &a, float b){
    // The copy constructor creates a new image
    // with new Pixel objects
    // We then use the already defined *
    // operator to return the sum
    return (b * a);
}

