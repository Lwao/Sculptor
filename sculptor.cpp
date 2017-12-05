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
                            1)); //estado
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    //Subtração de Box 1x1x1
    lista.push_back(new Box(x-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            0)); //estado
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            1)); //estado
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            0)); //estado
}
void Sculptor::putSphere(int xc, int yc, int zc, int r)
{
    lista.push_back(new Sphere(xc, yc, zc, r, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            1)); //estado
}
void Sculptor::cutSphere(int xc, int yc, int zc, int r)
{
    lista.push_back(new Sphere(xc, yc, zc, r, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            0)); //estado
}
void Sculptor::putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            1)); //estado
}
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr, //posição
                            0, 0, 0, //ângulos
                            R, G, B, trans, //cores
                            0)); //estado
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
                unsigned P0 = ((Tela.tamX+1)*i + j + (Tela.tamX+1)*(Tela.tamY+1)*(k+1));
                unsigned P1 = ((Tela.tamX+1)*i + j + (Tela.tamX+1)*(Tela.tamY+1)*k);
                unsigned P2 = ((Tela.tamX+1)*i + (j+1) + (Tela.tamX+1)*(Tela.tamY+1)*(k+1));
                unsigned P3 = ((Tela.tamX+1)*i + (j+1) + (Tela.tamX+1)*(Tela.tamY+1)*(k+1));
                unsigned P4 = ((Tela.tamX+1)*(i+1) + j + (Tela.tamX+1)*(Tela.tamY+1)*(k+1));
                unsigned P5 = ((Tela.tamX+1)*(i+1) + j + (Tela.tamX+1)*(Tela.tamY+1)*k);
                unsigned P6 = ((Tela.tamX+1)*(i+1) + (j+1) + (Tela.tamX+1)*(Tela.tamY+1)*k);
                unsigned P7 = ((Tela.tamX+1)*(i+1) + (j+1) + (Tela.tamX+1)*(Tela.tamY+1)*(k+1));
                        
                // Pega o voxel da posição corrente
                Voxel v = Tela[tamX*i + j + tamX*tamY*k];

                if (v.is_on)
                {
                    // Face da esquerda
                    if (i==0 || (Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    // Face da frente
                    if (z==0 || (Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P1 << " " << P2 << " " << P6 << " " << P5 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    // Face de cima
                    if (y==0 || (Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P0 << " " << P1 << " " << P5 << " " << P4 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    
                    // Face da direita
                    //if ((Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P4 << " " << P5 << " " << P6 << " " << P7 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    
                    // Face de baixo
                    //if ((Tela[tamX*i + j + tamX*tamY*k].is_on))
                    fout << 4 << " " << P2 << " " << P3 << " " << P7 << " " << P6 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    
                    // Face de trás
                    //if ((Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P0 << " " << P4 << " " << P7 << " " << P3 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
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
