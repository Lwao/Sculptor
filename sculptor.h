#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_
#include <iostream>
#include <vector>
#include <list>
#include "shapes.h"
#include "s_matrix.h"

using namespace std;

struct Voxel
{
    float r,g,b; // Colors
    float a; // Transparency
    bool is_on; // Included or not
};



class Sculptor
{
private:
    //Voxel temp;
    //int x, y, x;
    //vector<Voxel>::iterator var;
    //vector <Voxels> H;
    ptr_Shape *pformas;
    list<Shape> x;
    list<Shape>::iterator k;

public:
    
    void setColor(float red, float green, float blue, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void putSphere(int xc, int yc, int zc, int r);
    void cutSphere(int xc, int yc, int zc, int r);
    void putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr);
    void cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr);
    void cleanVoxels();
    void write();

}


#endif // _SCULPTOR_H_
