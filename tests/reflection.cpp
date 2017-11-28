#include "image.cpp"

int main(int argv, char *argc[]){
    Image a(argc[1]);
    a.horizontalReflection().writeTo("horRef.ppm");
    a.verticalReflection().writeTo("verRef.ppm");

    return 0;
}

