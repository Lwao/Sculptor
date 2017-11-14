#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <iomanip>
#include "sculptor.h"


void Sculptor::setColor(float red, float green, float blue, float alpha)
{
    temp.r = red;
    temp.g = green;
    temp.b = blue;
    temp.a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z)
{
    H[x][y][z] = temp;
    H[x][y][z].is_on = true;
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    H[x][y][z] = temp;
    H[x][y][z].is_on = false;
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int xz, int z1)
{
    
    for (var = H.begin(); var!=H.end(); var++)
    {
        
    }
    H.push_back(putVoxel())
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int xz, int z1)
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
