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


void Sculptor::setColor(float red, float green, float blue, float alpha)
{
    temp.r = red;
    temp.g = green;
    temp.b = blue;
    temp.a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z)
{

}
void Sculptor::cutVoxel(int x, int y, int z)
{

}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
}
void Sculptor::putSphere(int xc, int yc, int zc, int r)
{
}
void Sculptor::cutSphere(int xc, int yc, int zc, int r)
{
}
void Sculptor::putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
}
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
}
void Sculptor::cleanVoxels()
{
}
void Sculptor::write()
{
}
