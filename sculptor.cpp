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
    //Construção de Box 1x1x1
    lista.push_back(new Box(x/1.0-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true)); //estado
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    //Subtração de Box 1x1x1
    lista.push_back(new Box(x-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false)); //estado
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true)); //estado
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false)); //estado
}
void Sculptor::putSphere(int xc, int yc, int zc, int r)
{
    lista.push_back(new Sphere(xc, yc, zc, r, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true)); //estado
}
void Sculptor::cutSphere(int xc, int yc, int zc, int r)
{
    lista.push_back(new Sphere(xc, yc, zc, r, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false)); //estado
}
void Sculptor::putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            true)); //estado
}
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            false)); //estado
}
void Sculptor::cleanVoxels()
{
}
void Sculptor::write()
{
    ofstream arquivo(Arq);
    Coordenada corrente;
    
    corrente.X = -0.5;
    corrente.Y = -0.5;
    corrente.Z = -0.5;

    arquivo << "OFF" << endl;
    arquivo << getNVertices() << " " << getNFaces() << " " << 0 << endl;

    for (int i = 0; i < dimX + 1; i++) 
    {
        for (int j = 0; j < dimY + 1; j++) 
        {
            for (int k = 0; k < dimZ + 1; k++) 
            {
                corrente.X += i;
                corrente.Y += j;
                corrente.Z += k;
                
                arquivo << corrente << endl;
            }
        }
    }

    
    for (int i = 0; i < dimX; ++i) 
    {
        for (int j = 0; j < dimY; ++j) 
        {
            for (int k = 0; k < dimZ; ++k) 
            {
                //tamX*i + j + tamX*tamY*k

                // Vértices da face X da esquerda
            unsigned P0 = ((Tela.tamX)*i + j + (Tela.tamX)*(Tela.tamY)*(k+1));
            unsigned P1 = ((Tela.tamX)*i + j + (Tela.tamX)*(Tela.tamY)*k);
            unsigned P2 = ((Tela.tamX)*i + (j+1) + (Tela.tamX)*(Tela.tamY)*(k+1));
            unsigned P3 = ((Tela.tamX)*i + (j+1) + (Tela.tamX)*(Tela.tamY)*(k+1));
            unsigned P4 = ((Tela.tamX)*(i+1) + j + (Tela.tamX)*(Tela.tamY)*(k+1));
            unsigned P5 = ((Tela.tamX)*(i+1) + j + (Tela.tamX)*(Tela.tamY)*k);
            unsigned P6 = ((Tela.tamX)*(i+1) + (j+1) + (Tela.tamX)*(Tela.tamY)*k);
            unsigned P7 = ((Tela.tamX)*(i+1) + (j+1) + (Tela.tamX)*(Tela.tamY)*(k+1));
                    
            // Pega o voxel da posição corrente
            Voxel v = H[tamX*i + j + tamX*tamY*k];

            if (v.is_on)
            {
                // Face da esquerda
                if (pos.y == 0 or !at(pos.x, pos.y - 1, pos.z).is_on )
                fout << 4 << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                // Face da esquerda
                if (pos.y == 0 or !at(pos.x, pos.y - 1, pos.z).is_on )
                fout << 4 << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
                // Face de dentro
                if (pos.x == 0 or !at(pos.x - 1, pos.y, pos.z).is_on )
                fout << 4 << " " << P0 << " " << P3 << " " << P4 << " " << P5 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
                // Face de baixo
                if (pos.z == 0 or !at(pos.x, pos.y, pos.z - 1).is_on )
                fout << 4 << " " << P0 << " " << P5 << " " << P6 << " " << P1 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;

                // Face da direita
                fout << 4 << " " << P5 << " " << P4 << " " << P7 << " " << P6 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
                // Face de fora
                fout << 4 << " " << P1 << " " << P6 << " " << P7 << " " << P2 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
                // Face de cima
                fout << 4 << " " << P3 << " " << P2 << " " << P7 << " " << P4 << " " << v.R << " " << v.G << " " << v.B << " " << v.alpha << endl;
            }
            }
        }
    }
}
void Sculptor::Esculpir();
{
    it_lista itt;
    
    for (itt = lista.begin(); itt != lista.end(); itt++) Tela.discretizar(*itt);
                    
}
