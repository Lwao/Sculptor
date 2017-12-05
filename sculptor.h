#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_
#include <iostream>
#include <vector>
#include <list>
#include "shapes.h"
#include "s_matrix.h"

using namespace std;



typedef list <ptr_Shape>::iterator it_lista; //iterador para a lista

class Sculptor
{
private:
    list<ptr_Shape> lista; //lista de formas
    Hipermatriz Tela; //matriz para armazenar as formas
    double R, G, B, trans; //cores a serem modificadas no setColor()
public:
    //construtores e destrutores
    explicit inline Sculptor(double red=0, double green=0, double blue=0, double opacity=1): R(red), G(green), B(blue), trans(opacity) {}
    
    //métodos 
    inline void setColor(float red, float green, float blue, float alpha) {this->R=red, this->G=green, this->B=blue, this->trans=alpha;}
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xc, int yc, int zc, int r);
    void cutSphere(int xc, int yc, int zc, int r);
    void putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr);
    void cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr);
    void cleanVoxels(); //chama após discretizar todas as formas na matriz
    void write();
    
    
    void Esculpir(); //Manda todas as formas para terem os voxels colocados na matriz
    
    /* CASO HAJA NECESSIDADE DE DEIXAR COM OS ÂNGULOS AQUI
    void putVoxel(int x, int y, int z, double teta-y=0, double alfa-z=0, double beta-x=0);
    void cutVoxel(int x, int y, int z, double teta-y=0, double alfa-z=0, double beta-x=0);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1, double teta-y=0, double alfa-z=0, double beta-x=0);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1, double teta-y=0, double alfa-z=0, double beta-x=0);
    void putSphere(int xc, int yc, int zc, int r, double teta-y=0, double alfa-z=0, double beta-x=0);
    void cutSphere(int xc, int yc, int zc, int r, double teta-y=0, double alfa-z=0, double beta-x=0);
    void putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr, double teta-y=0, double alfa-z=0, double beta-x=0);
    void cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr, double teta-y=0, double alfa-z=0, double beta-x=0);
    */
};


#endif // _SCULPTOR_H_
