#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include "sculptor.h"
#include "shapes.h"
#include "s_matrix.h"

using namespace std;

struct Coordenada operator-(const struct Coordenada sec)
{
    Coordenada prov;
    
    prov.X = this->X-sec.X;
    prov.Y = this->Y-sec.Y;
    prov.Z = this->Z-sec.Z;
    
    return prov;
}
struct Coordenada operator+(const struct Coordenada sec)
{
    Coordenada prov;
    
    prov.X = this->X+sec.X;
    prov.Y = this->Y+sec.Y;
    prov.Z = this->Z+sec.Z;
    
    return prov;
}
struct Coordenada operator*(const double op)
{
    Coordenada prov;
    
    prov.X = op*this->X;
    prov.Y = op*this->Y;
    prov.Z = op*this->Z;
    
    return prov;
}
struct Coordenada operator/(const double op)
{
    Coordenada prov;
    
    prov.X = this->X/op;
    prov.Y = this->Y/op;
    prov.Z = this->Z/op;
    
    return prov;
}

//BOX

Coordenada Box::Box(const Box& form)
{
}

Coordenada Box::getMAX() const
{
    Coordenada prov;
    
    prov.X = x1;
    prov.Y = y1;
    prov.Z = z1;
    
    return prov;
}
Coordenada Box::getMIN() const
{
    Coordenada prov;
    
    prov.X = x0;
    prov.Y = y0;
    prov.Z = z0;
    
    return prov;
}
Coordenada Box::getCentro() const
{
    Coordenada prov;
    
    prov = (*this.getMAX()+*this.getMIN())/2;
    
    return prov;
}
Coordenada Box::getOrigem() const
{
}
Coordenada Box::getSize() const
{
    Coordenada prov;
    
    prov = *this.getMAX()-*this.getMIN();
    
    return prov;
}
Coordenada Box::getVertice() const
{
}


//SPHERE

Sphere::Sphere(const Sphere& form)
{
}
Coordenada Sphere::getMAX() const
{
    Coordenada prov;
    
    prov.X = x_c+r;
    prov.Y = y_c+r;
    prov.Z = z_c+r;
    
    return prov;
}
Coordenada Sphere::getMIN() const
{
    Coordenada prov;
    
    prov.X = x_c-r;
    prov.Y = y_c-r;
    prov.Z = z_c-r;
    
    return prov;
}
Coordenada Sphere::getCentro() const
{
    Coordenada prov;
    
    prov.X = x_c;
    prov.Y = y_c;
    prov.Z = z_c;
    
    return prov;
}
Coordenada Sphere::getOrigem() const
{

}
Coordenada Sphere::getSize() const
{
    Coordenada prov;
    
    prov = *this.getMAX()-*this.getMIN();
    
    return prov;
}
Coordenada Sphere::getVertice() const
{
}



//ELLIPSOID


Ellipsoid::Ellipsoid(const Ellipsoid& form)
{
}
Coordenada Ellipsoid::getMAX() const
{
    Coordenada prov;
    
    prov.X = x_c+x_r;
    prov.Y = y_c+y_r;
    prov.Z = z_c+z_r;
    
    return prov;
}
Coordenada Ellipsoid::getMIN() const
{
    Coordenada prov;
    
    prov.X = x_c-x_r;
    prov.Y = y_c-y_r;
    prov.Z = z_c-z_r;
    
    return prov;
}
Coordenada Ellipsoid::getCentro() const
{
    Coordenada prov;
    
    prov.X = x_c;
    prov.Y = y_c;
    prov.Z = z_c;
    
    return prov;
}
Coordenada Ellipsoid::getOrigem() const
{
}
Coordenada Ellipsoid::getSize() const
{
    Coordenada prov;
    
    prov = *this.getMAX()-*this.getMIN();
    
    return prov;
}
Coordenada Ellipsoid::getVertice() const
{
}
















