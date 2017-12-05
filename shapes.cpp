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
    
    prov.X = X-sec.X;
    prov.Y = Y-sec.Y;
    prov.Z = Z-sec.Z;
    
    return prov;
}
struct Coordenada operator+(const struct Coordenada sec)
{
    Coordenada prov;
    
    prov.X = X+sec.X;
    prov.Y = Y+sec.Y;
    prov.Z = Z+sec.Z;
    
    return prov;
}
struct Coordenada operator*(const double op)
{
    Coordenada prov;
    
    prov.X = op*X;
    prov.Y = op*Y;
    prov.Z = op*Z;
    
    return prov;
}
struct Coordenada operator/(const double op)
{
    Coordenada prov;
    
    prov.X = X/op;
    prov.Y = Y/op;
    prov.Z = Z/op;
    
    return prov;
}
friend bool operator==(const Coordenada op1, const Coordenada op2)
{
    if ((op1.X==op2.X)&&(op1.Y==op2.Y)&&(op1.Z==op2.Z) return true;
    else return false;    
}

//SHAPE

void Shape::operator=(const Shape& form)
{
    tetay = form.tetay;
    alfaz = form.alfaz;
    betax = form.betax;
    red = form.red;
    green = form.green;
    blue = form.blue;
    alpha = form.alpha;
    state = form.state;  
}

vector <Coordenada>  Shape::getCuboEnv() const //preenche o vetor de vértices na ordem da figura da especificação
{
    Coordenada EXT[2];
    vector <Coordenada> vert;
    Coordenada temp;
    
    EXT[0] = getMIN(); //preenche com a coordenada mínima
    EXT[1] = getMAX(); //preenche com a coordenada máxima
    
    /* VÉRTICES
                      0                 4
                       . . . . . . . . .
                    .  .            .  .
               1 . . . . . . . . . 5   .
                 .     .         .     .
                 .     .         .     .
                 .     .         .     .
                 .   3 . . . . . . . . . 7
                 .  .            .  .
               2 . . . . . . . . . 6

    */
    //P0 (MIN.x, MAX.y, MIN.z)
    //P1 (MIN.x, MAX.y, MAX.z)
    //P2 (MIN.x, MIN.y, MAX.z)
    //P3 (MIN.x, MIN.y, MIN.z)
    //P4 (MAX.x, MAX.y, MIN.z) 
    //P5 (MAX.x, MAX.y, MAX.z)
    //P6 (MAX.x, MIN.y, MAX.z) 
    //P7 (MAX.x, MIN.y, MIN.z)
    
    //O algoritmo abaixo irá passar pelos vértices do cubo envolvente de acordo com os ponts dados acima
    
    unsigned count(0);

    for (unsigned i=0; i<=1; i++)
    {
        for (unsigned j=1; j>=0; j--)
        {
            if(count==2)
            {
                for(unsigned k=1; k>=0; k--)
                {
                    temp.X = EXT[i].X;
                    temp.Y = EXT[j].Y;
                    temp.Z = EXT[k].Z
                    vert.push_back(temp); 
                    count--;
                }
            }
            if(count==0)
            {
                for(unsigned k=0; k<=1; k++)
                {
                    temp.X = EXT[i].X;
                    temp.Y = EXT[j].Y;
                    temp.Z = EXT[k].Z
                    vert.push_back(temp); 
                    count++;
                }
            }
        }
    }
    return vert;
}



//BOX

Box::Box(double xi, double xf, double yi, double yf, double zi, double zf, double teta, double alfa, double beta)
{
    Shape();
    
    x0 = xi;
    x1 = xf;
    y0 = yi;
    y1 = yf;
    z0 = zi;
    z1 = zf;
    
    tetay = teta;
    alfaz = alfa;
    betax = beta;
}
void Box::operator=(const Box& form)
{
    x0 = form.x0;
    x1 = form.x1;
    y0 = form.y0;
    y1 = form.y1;
    z0 = form.z0;
    z1 = form.z1;
}
Box::Box(const Box& form)
{
    *this = form;
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
    
    prov = (getMAX()+getMIN())/2;
    
    return prov;
}
Coordenada Box::getSize() const
{
    Coordenada prov;
    
    prov = getMAX()-getMIN();
    
    return prov;
}

            bool Box::Verificar(unsigned int i, unsigned int j, unsigned int k){
   bool status(false);
            if(i>= getMIN().X && i<=getMAX.X && j>=getMIN.Y && j<=getMAX.Y && k>=getMIN.Z && k>=getMAX.Z){
            status = true;
            
}
            return status;

}



//SPHERE

Sphere::Sphere(double xc, double yc, double zc, double radius, double teta, double alfa, double beta, double reed, double g, double, double trans, bool estado)
{
    Shape();
    
    x_c = xc;
    y_c = yc;
    z_c = zc;
    r = radius;
}
Sphere::Sphere(const Sphere& form)
{
    *this = form;
}
void Sphere::operator=(const Sphere& form)
{
    x_c = form.x_c;
    y_c = form.y_c;
    z_c = form.z_c;
    r = form.r;
}
Sphere::Sphere(const Sphere& form)
{
    *this = form;
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
Coordenada Sphere::getSize() const
{
    Coordenada prov;
    
    prov = getMAX()-getMIN();
    
    return prov;
}
  bool Sphere::Verificar(unsigned int i, unsigned int j, unsigned int k)
    {   // i^2+j^2+k^2<=r^2
            bool status(false);
            if((pow(i-getCentro.X, 2)+pow(j-getCentro.Y, 2)+ pow(k-getCentro.Z, 2))<= pow(getRaio, 2)){
            status=true;
}
}






//ELLIPSOID

Ellipsoid::Ellipsoid(double xc, double yc, double zc, double xr, double yr, double zr, double teta, double alfa, double beta, double r, double g, double, double trans, bool estado)
{
    Shape();
    
    x_c = xc;
    y_c = yc;
    z_c = zc;
    x_r = xr;
    y_r = yr;
    z_r = zr;
    
    tetay = teta;
    alfaz = alfa;
    betax = beta;
}
Ellipsoid::Ellipsoid(const Ellipsoid& form)
{
}
void Ellipsoid::operator=(const Ellipsoid& form)
{
    x_c = form.x_c;
    y_c = form.y_c;
    z_c = form.z_c;
    x_r = form.x_r;
    y_r = form.y_r;
    z_r = form.z_r;
}
Ellipsoid::Ellipsoid(const Ellipsoid& form)
{
    *this = form;
}
         Coordenada Ellipsoid::getRaio() const
    {Coordenada prov;
            prov.X=x_r;
            prov.Y=y_r;
            prov.Z=z_r;
            return prov;
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
Coordenada Ellipsoid::getSize() const
{
    Coordenada prov;
    
    prov = getMAX()-getMIN();
    
    return prov;
}
  bool Ellipsoid::Verificar(unsigned int i, unsigned int j, unsigned int k)
    {
bool status(false);
            if(pow(i/getRaio.X, 2)+pow(j/getRaio.Y, 2)+ pow(k/getRaio.Z, 2)<=1){
            status=true;
}
            return status;
}
















