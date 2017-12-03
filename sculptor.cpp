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


void Sculptor::putVoxel(int x, int y, int z)
{
    //Box 1x1x1
    lista.push_back(new Box(x-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true); //estado
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    //Box 1x1x1
    lista.push_back(new Box(x-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false); //estado
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true); //estado
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false); //estado
}
void Sculptor::putSphere(int xc, int yc, int zc, int r)
{
    lista.push_back(new Sphere(xc, yc, zc, r, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true); //estado
}
void Sculptor::cutSphere(int xc, int yc, int zc, int r)
{
    lista.push_back(new Sphere(xc, yc, zc, r, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false); //estado
}
void Sculptor::putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true); //estado
}
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false); //estado
}
void Sculptor::cleanVoxels()
{
}
void Sculptor::write()
{
}
