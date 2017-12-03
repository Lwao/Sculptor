#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <iostream>
#include <vector>


using namespace std;



struct Coordenada
{
    double X, Y, Z;
}

struct Coordenada operator-(const Coordenada sec) const;
struct Coordenada operator+(const Coordenada sec) const;
struct Coordenada operator*(const double op) const;
struct Coordenada operator/(const double op) const;


class Shape;
typedef Shape *ptr_Shape;

class Shape
{
private:
    //TALVEZ NÃO PRECISE DESSAS VARIÁVEIS POIS BASTA UTILIZAR OS MÉTODOS DE CONSULTA
    
    //Coordenada centro;
    //Coordenada MAX; //extremos para a matriz envolvente
    //Coordenada MIN;
    //Coordenada Tamanho; //tamanho do Box circundante (variação)
    //Coordenada Origem;
        
    double teta-y, alfa-z, beta-x;
    double red, green, blue, alpha;
    bool state;
    
    vector <Coordenada> vert; //coordenadas do cubo envolvente
    Coordenada EXT[2]; //EXTREMOS, primeira entrada o ponto mínimo, segunda entrada o ponto máximo
public:
    Shape(): teta-y(0), alfa-z(0), beta-x(0), red(0), green(0), blue(0), alpha(1), state(false){}
    inline ~Shape() {teta-y=0, alfa-z=0, beta-x=0, red=0, green=0, blue=0, alpha=0, state=false;}
         
    virtual ptr_Shape clone() const = 0;
    
    
    virtual Coordenada getMAX() const = 0;
    virtual Coordenada getMIN() const = 0;
    virtual Coordenada getCentro() const = 0;
    virtual Coordenada getOrigem() const =0;
    virtual Coordenada getSize() const = 0;
    virtual Coordenada getVertice() const =0; //retor
    
}

class Box: public Shape
{
private:
    double x0, x1, y0, y1, z0, z1;
public:
    Box(): x0(0), x1(0), y0(0), y1(0), z0(0), z1(0), Shape() {}
    explicit Box(double x0, double x1, double y0, double y1, double z0, double z1, double teta=0, double alfa=0, double beta=0);
    Box(const Box &form);
    inline ~Box() {x0=0, x1=0, y0=0, y1=0, z0=0, z1=0, teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Box &form);
    ptr_Shape clone() const {return new Box(*this);}
    
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getOrigem() const;
    Coordenada getSize() const;
    Coordenada getVertice() const;
}

class Sphere: public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double r; //raio
public:
    Sphere(): x_c(0), y_c(0), z_c(0), r(0), Shape() {}
    explicit Sphere(double xc, double yc, double zc, double radius, double teta=0, double alfa=0, double beta=0);
    Sphere(const Sphere &form);
    inline ~Sphere() {x_c=0, y_c=0, z_c=0, teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Sphere &form);
    ptr_Shape clone() const {return new Sphere(*this);}
    
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getOrigem() const;
    Coordenada getSize() const;
    Coordenada getVertice() const;
}

class Ellipsoid: public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double x_r, y_r, z_r; //raios
    
public:
    Ellipsoid(): x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0), Shape() {}
    explicit Ellipsoid(double x_c, double y_c, double z_c, double x_r, double y_r, double z_r, double teta=0, double alfa=0, double beta=0);
    Ellipsoid(const Ellipsoid &form);
    inline ~Ellipsoid() {x_c=0, y_c=0, z_c=0, x_r=0, y_r=0, z_r=0, teta-y=0, alfa-z=0, beta-x=0;}
    
    void operator=(const Ellipsoid &form);
    ptr_Shape clone() const {return new Ellipsoid(*this);}
    
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getOrigem() const;
    Coordenada getSize() const;
    Coordenada getVertice() const;
}





#endif // _SHAPES_H_
