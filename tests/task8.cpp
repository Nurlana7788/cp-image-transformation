#include "image/brightness_histogram.h"
#include "image/composite_image.h"
#include "image/connected_components.h"
#include "image/color.h"
#include "image/image.h"
#include "image/noise.h"
#include<stdlib.h>

void task8(const Image &a){
  Noise_Image n(a.getWidth(), a.getHeight());
  CompositeImage comp(a, n, 0.2);
  BrightnessHistogram hist(comp);
  std::vector<int> threshold(hist.getThresholds());
  Image res= comp.getBinaryImage(threshold[1], Color(255, 255, 0), Color(255, 255, 255));
  ConnectedComponents conn;
  Image b=conn.formcomponents(a);
  
  b.writeTo("task8.ppm");
  // res.writeTo("binImage.ppm");
  // comp.writeTo("CompNoise.ppm");
  // hist.outputHistogram().writeTo("histNoise.ppm");
  // n.writeTo("Noise.ppm");
}

int main(int argv, char *argc[]){
  Image a(argc[1]);
  task8(a);

  return 0;
}
