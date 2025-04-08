#pragma once  
#include "IShape.h"  
#include <cmath>  

class Sphere : public IShape {  
   double radius;  
public:  
   static const double PI; 

   Sphere(double r);  
   double surface_area() const override;  
};
