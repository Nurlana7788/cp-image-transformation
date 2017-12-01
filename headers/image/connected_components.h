#ifndef __COMPONENTS_INC__
#define __COMPONENTS_INC__


#include "pixel.h"
#include "color.h"
#include "brightness_histogram.h"
#include "image.h"
#include<algorithm>
#include<vector>
using namespace std;

class ConnectedComponents{
    //Image I;
public:
    ConnectedComponents( );

    int getmedian(const Image& I );
    int issafe(Image I,int **status,int i,int j,bool **visited);
    void DFS(Image& I,int i,int j,bool **visited,int **status,Color col);
    Image formcomponents(const Image &I);
};

#endif
