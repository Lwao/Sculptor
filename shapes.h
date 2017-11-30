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
    Coordenada MAX; //extremos para a matriz envolvente
    Coordenada MIN;
    Coordenada Tamanho; //tamanho do Box circudnante (variação)
    Coordenada Origem;
    vector <Coordenada> vert; //vértices
public:
    Shape(): teta-y(0), alfa-z(0), beta-x(0), 
         centro.axisX(0), centro.axisY(0), centro.axisZ(0),
         MAX.axisX(0), MAX.axisY(0), MAX.axisZ(0),
         MIN.axisX(0), MIN.axisY(0), MIN.axisZ(0){}
    inline ~Shape() {teta-y=0, alfa-z=0, beta-x=0, 
         centro.axisX=0, centro.axisY=0, centro.axisZ=0,
         MAX.axisX=0, MAX.axisY=0, MAX.axisZ=0,
         MIN.axisX=0, MIN.axisY=0, MIN.axisZ=0}
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
    Box(): x0(0), x1(0), y0(0), y1(0), z0(0), z1(0), Shape() {}
    explicit Box(double x0, double x1, double y0, double y1, double z0, double z1, teta-y=0, alfa-z=0, beta-x=0);
    Box(const Box &form);
    inline ~Box() {x0(0), x1(0), y0(0), y10(0), z0(0), z1(0), teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Box &form);
    
    getSize();
    getOrigem();
    getVertice();
    getMax();
    getMin();
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
    
    getSize();
    getOrigem();
    getVertice();
    getMax();
    getMin();
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
    
    getSize();
    getOrigem();
    getVertice();
    getMax();
    getMin();
}





#endif // _SHAPES_H_
