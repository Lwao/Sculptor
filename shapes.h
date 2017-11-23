#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <iostream>
#include <vector>


using namespace std;



struct Coordenada
{
    double axisX, axisY, axisZ;
}

class Shape;
typedef Shape *ptr_Shape;

class Shape
{
private:
    int 
    int angulo;
    double centro;
    double xmax, xmin, ymax, ymin, zmax, zmin //Extremos
    double Dx, Dy, Dz //tamanho da forma (cubo circundante)
    double origem[3]; //origem
    vector <Coordenada> v;
public:
    virtual getSize();
    virtual getOrigem();
    virtual getVertice();
    virtual getMax();
    virtual getMin();
    
}

class Box public Shape
{
private:
    double x0, x1, y0, y1, z0, z1;
public:
    Box(): x0(0), x1(0), y0(0), y10(0), z0(0), z1(0) {}
    explicit Box(double x0, double x1, double y0, double y1, double z0, double z1);
    Box(const Box &form);
    inline ~Box() {x0(0), x1(0), y0(0), y10(0), z0(0), z1(0);}
    
    void operator=(const Box &form);
}

class Sphere public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double r; //raio
public:
    Sphere(): x_c(0), y_c(0), z_c(0) {}
    explicit Sphere(double x_c, double y_c, double z_c);
    Sphere(const Sphere &form);
    inline ~Sphere() {x_c(0), y_c(0), z_c(0)}
    
    void operator=(const Sphere &form);
}

class Ellipsoid public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double x_r, y_r, z_r; //raios
    
public:
    Ellipsoid(): x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0) {}
    explicit Ellipsoid(double x_c, double y_c, double z_c, double x_r, double y_r, double z_r);
    Ellipsoid(const Ellipsoid &form);
    inline ~Ellipsoid() {x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0)}
    
    void operator=(const Ellipsoid &form);
}





#endif // _SHAPES_H_
