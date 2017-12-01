# Group 3

## Members:
    1. IMT2015513 - Manoj Kulkarni
    2. IMT2016026 - Manideep Nizam
    3. IMT2016054 - Aditya Shridhar Hegde
    4. IMT2016077 - Ashish Singh
    5. IMT2016097 - Hrishikesh Reddy
    6. IMT2016116 - Sushma Bhandaru

## Individual Contribution

RollNumber      Name                    Task    Contribution

IMT2015513      Manoj Kulakrni         3       -

IMT2016026      Manideep Nizam          6       Connected Components class
                                                Tests for task 6
                                                Task6 class

IMT2016054      Aditya Hegde            5       Base Classes (Color, Pixel, Image, Task)
                                                Setting up CMake
                                                Brightness Histogram Class
                                                Task5 class
                                                Tests for task 5 and base classes
                                                                                                
IMT2016077      Ashish Singh            8       Noise class
                                                Tests for task 8
                                                Task8 class

IMT2016097      Hrishikesh Reddy        2       -

IMT2016116      Sushma Bhandaru         7       ScaledImage class
                                                Tests for task 7
                                                Task7 class
 
## File Structure

1. headers contain header files split into image header files and task header files.
2. src contains implementation for headers again split up into image and task folders.
3. tests contains code that is used to generate executables for testing certain parts of the code.
4. Main.cpp contains the code to generate the main executable.
5. bin contains the executables of tests (bin is created by make).
6. build is used for generating make files and compilation.
7. output contains the output of the main executable

## Compiling and Usage

The project uses CMAKE to generate the MAKE files which inturn is used to
build the system. 

To compile run the following commands:
    cd build (create directory if not present)
    cmake ..
    make

Executables generated from tests will be placed in bin and the executable
generated from main will be placed in the project root directory.

To run "main" executable run:
    ./main <path to ppm image input file>

The output of "main" is placed in "output".


