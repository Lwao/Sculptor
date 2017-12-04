#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <iostream>
#include <vector>


using namespace std;



struct Coordenada
{
    double X, Y, Z;
}

struct Coordenada operator-(const Coordenada sec) const; //permite subtrair coordenadas
struct Coordenada operator+(const Coordenada sec) const; //permite adicionar coordenadas
struct Coordenada operator*(const double op) const; //multiplicar por número à direita
struct Coordenada operator/(const double op) const;//dividir coordenadas por número


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
        
    double tetay, alfaz, betax; //ângulos
    double red, green, blue, alpha; //cores
    bool state; //estado, se está ligado ou não 
    
    //vector <Coordenada> vert; //coordenadas dos vértices do cubo envolvente (calculado por detCuboEnv()
    Coordenada EXT[2]; //EXTREMOS, primeira entrada o ponto mínimo, segunda entrada o ponto máximo
public:
    //construtores e destrutores
    Shape(): red(0), green(0), blue(0), alpha(1), state(false){} 
    inline ~Shape() {red=0, green=0, blue=0, alpha=0, state=false;}
         
    //operadores
    void operator=(const Shape &form);
    virtual ptr_Shape clone() const = 0;
    
    //métodos virtuais abstratos
    virtual Coordenada getMAX() const = 0;
    virtual Coordenada getMIN() const = 0;
    virtual Coordenada getCentro() const = 0;
    virtual Coordenada getOrigem() const =0;
    virtual Coordenada getSize() const = 0;
    
    //métodos
    vector <Coordenada> getCuboEnv() const; //retor
    inline bool getState() {return *this->state;}
    
}

class Box: public Shape
{
private:
    double x0, x1, y0, y1, z0, z1; //coordenadas típicas de um paralelepípedo
public:
    //construtores e destrutores
    Box(): x0(0), x1(0), y0(0), y1(0), z0(0), z1(0), Shape() {}
    explicit Box(double xi, double xf, double yi, double yf, double zi, double zf, double teta=0, double alfa=0, double beta=0);
    Box(const Box &form);
    inline ~Box() {x0=0, x1=0, y0=0, y1=0, z0=0, z1=0, tetay=0, alfaz=0, betax=0;}
    
    //operadores
    void operator=(const Box &form);
    ptr_Shape clone() const {return new Box(*this);}
    
    //métodos virtuais
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getOrigem() const;
    Coordenada getSize() const;
}

class Sphere: public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double r; //raio
public:
    //construtores e destrutores
    Sphere(): x_c(0), y_c(0), z_c(0), r(0), Shape() {}
    explicit Sphere(double xc, double yc, double zc, double radius, double teta=0, double alfa=0, double beta=0);
    Sphere(const Sphere &form);
    inline ~Sphere() {x_c=0, y_c=0, z_c=0, tetay=0, alfaz=0, betax=0;}
    
    //operadores
    void operator=(const Sphere &form);
    ptr_Shape clone() const {return new Sphere(*this);}
    
    //métodos virtuais
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getOrigem() const;
    Coordenada getSize() const;
}

class Ellipsoid: public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double x_r, y_r, z_r; //raios
    
public:
    //construtores e destrutores
    Ellipsoid(): x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0), Shape() {}
    explicit Ellipsoid(double xc, double yc, double zc, double xr, double yr, double zr, double teta=0, double alfa=0, double beta=0);
    Ellipsoid(const Ellipsoid &form);
    inline ~Ellipsoid() {x_c=0, y_c=0, z_c=0, x_r=0, y_r=0, z_r=0, tetay=0, alfaz=0, betax=0;}
    
    //operadores
    void operator=(const Ellipsoid &form);
    ptr_Shape clone() const {return new Ellipsoid(*this);}
    
    //métodos virtuais
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getOrigem() const;
    Coordenada getSize() const;
}





#endif // _SHAPES_H_
