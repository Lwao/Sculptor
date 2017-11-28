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
    double teta-y, alfa-z, beta-x;
    Coordenada centro;
    Coordenada MAX; //extremos
    Coordenada MIN;
    Coordenada Tamanho; //tamanho do Box circudnante (variação)
    Coordenada Origem;
    vector <Coordenada> v;
public:
    Shape(double teta-y=0, double alfa-z=0, double beta-x=0);
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
    Box(): x0(0), x1(0), y0(0), y10(0), z0(0), z1(0), Shape() {}
    explicit Box(double x0, double x1, double y0, double y1, double z0, double z1, teta-y=0, alfa-z=0, beta-x=0);
    Box(const Box &form);
    inline ~Box() {x0(0), x1(0), y0(0), y10(0), z0(0), z1(0), teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Box &form);
}

class Sphere public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double r; //raio
public:
    Sphere(): x_c(0), y_c(0), z_c(0), Shape() {}
    explicit Sphere(double x_c, double y_c, double z_c, teta-y=0, alfa-z=0, beta-x=0);
    Sphere(const Sphere &form);
    inline ~Sphere() {x_c(0), y_c(0), z_c(0), teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Sphere &form);
}

class Ellipsoid public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double x_r, y_r, z_r; //raios
    
public:
    Ellipsoid(): x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0), Shape() {}
    explicit Ellipsoid(double x_c, double y_c, double z_c, double x_r, double y_r, double z_r, teta-y=0, alfa-z=0, beta-x=0);
    Ellipsoid(const Ellipsoid &form);
    inline ~Ellipsoid() {x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0), teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Ellipsoid &form);
}





#endif // _SHAPES_H_
