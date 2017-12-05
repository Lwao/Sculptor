#ifndef _SHAPES_H_
#define _SHAPES_H_
#include <iostream>
#include <vector>


using namespace std;


struct Coordenada
{
    double X, Y, Z;
    
    inline friend ostream & operator << (ostream & saida, const Coordenada & pos) { saida << pos.X << " " << pos.Y << " " << pos.Z; return saida; }
    struct Coordenada operator-(const Coordenada sec) const; //permite subtrair coordenadas
    struct Coordenada operator+(const Coordenada sec) const; //permite adicionar coordenadas
    struct Coordenada operator*(const double op) const; //multiplicar por número à direita
    struct Coordenada operator/(const double op) const;//dividir coordenadas por número
    friend bool operator==(const Coordenada op1, const Coordenada op2);
    
};

class Shape;
typedef Shape *ptr_Shape;

class Shape
{
private:        
    double tetay, alfaz, betax; //ângulos
    double red, green, blue, alpha; //cores
    bool state; //estado, se está ligado ou não 
public:
    //construtores e destrutores
    inline explicit Shape(double teta=0, double alfa=0, double beta=0, double r=0, double g=0, double b=0, double a=0, bool s=false ) {tetay=teta, alfaz=alfa, betax=beta,red=r, green=g, blue=b, alpha=a, state=s;} 
    inline ~Shape() {tetay=0, alfaz=0, betax=0, red=0, green=0, blue=0, alpha=0, state=false;}
         
    //operadores
    void operator=(const Shape &form);
    //virtual ptr_Shape clone() const = 0;
    
    //métodos virtuais abstratos
    virtual Coordenada getMAX() const = 0;
    virtual Coordenada getMIN() const = 0;
    virtual Coordenada getCentro() const = 0;
    virtual Coordenada getSize() const = 0;
    
    //métodos de consulta
    vector <Coordenada> getCuboEnv() const; //retor
    inline bool getState() {return state;}
    inline double getRed() {return red;}
    inline double getGreen() {return green;}
    inline double getBlue() {return blue;}
    inline double getTransparency() {return alpha;}
    inline void setColor(float r, float g, float b) { red= r; green = g; blue = b;}
    inline void setState(bool Estado) {state = Estado;}
    
    virtual bool Verificar(unsigned i, unsigned j, unsigned k) const = 0;

};

class Box: public Shape
{
private:
    double x0, x1, y0, y1, z0, z1; //coordenadas típicas de um paralelepípedo
public:
    //construtores e destrutores
    Box(): x0(0), x1(0), y0(0), y1(0), z0(0), z1(0), Shape() {}
    explicit Box(double xi, double xf, double yi, double yf, double zi, double zf, double teta=0, double alfa=0, double beta=0, double r=0, double g=0, double b=0, double trans=0, bool estado=false);
    Box(const Box &form);
    inline ~Box() {x0=0, x1=0, y0=0, y1=0, z0=0, z1=0;}
    
    //operadores
    void operator=(const Box &form);
    //ptr_Shape clone() const {return (*this);}
    
    //métodos virtuais
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getSize() const;
    
    bool Verificar(unsigned i, unsigned j, unsigned k);
};

class Sphere: public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double r; //raio
public:
    //construtores e destrutores
    Sphere(): x_c(0), y_c(0), z_c(0), r(0), Shape() {}
    explicit Sphere(double xc, double yc, double zc, double radius, double teta=0, double alfa=0, double beta=0, double r=0, double g=0, double =0, double trans=0, bool estado=false);
    Sphere(const Sphere &form);
    inline ~Sphere() {x_c=0, y_c=0, z_c=0;}
    
    //operadores
    void operator=(const Sphere &form);
    //ptr_Shape clone() const {return *this;}
     inline double getRaio()const {return r;}
    //métodos virtuais
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getSize() const;
    
    bool Verificar(unsigned i, unsigned j, unsigned k);
};

class Ellipsoid: public Shape
{
private:
    double x_c, y_c, z_c; //centros
    double x_r, y_r, z_r; //raios
    
public:
    //construtores e destrutores
    Ellipsoid(): x_c(0), y_c(0), z_c(0), x_r(0), y_r(0), z_r(0), Shape() {}
    Ellipsoid(double xc, double yc, double zc, double xr, double yr, double zr, double teta, double alfa, double beta, double reed, double g, double b, double trans, bool estado);
    Ellipsoid(const Ellipsoid &form);
    inline ~Ellipsoid() {x_c=0, y_c=0, z_c=0, x_r=0, y_r=0, z_r=0;}
    
    //operadores
    void operator=(const Ellipsoid &form);
    //ptr_Shape clone() const {return *this);}
    
     Coordenada getRaio() const;
    //métodos virtuais
    Coordenada getMAX() const;
    Coordenada getMIN() const;
    Coordenada getCentro() const;
    Coordenada getSize() const;
    
    bool Verificar(unsigned i, unsigned j, unsigned k);
};





#endif // _SHAPES_H_
