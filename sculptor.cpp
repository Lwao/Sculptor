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
    bool ss=true;
    //Construção de Box 1x1x1
    lista.push_back(new Box(x-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, 0, 0, 0, R, G, B, trans, ss));
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::cutVoxel(int x, int y, int z)
{    
    bool ss=false;
    //Construção de Box 1x1x1
    lista.push_back(new Box(x-0.5, x+0.5, y-0.5, y+0.5, z-0.5, z+0.5, 0, 0, 0, R, G, B, trans, ss));
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    bool ss=true;
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, 0, 0, 0, R, G, B, trans, ss)); 
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    cout<<"1"<< endl;
    itt = lista.end();
    cout<<"2"<< endl;
    Tela.inserirForma(*itt);
    cout<<"3"<< endl;
    
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    bool ss=false;
    lista.push_back(new Box(x0, x1, y0, y1, z0, z1, 0, 0, 0, R, G, B, trans, ss)); 
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::putSphere(int xc, int yc, int zc, int r)
{
    bool ss=true;
    lista.push_back(new Sphere(xc, yc, zc, r, 0, 0, 0, R, G, B, trans, ss));
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::cutSphere(int xc, int yc, int zc, int r)
{
    bool ss=false;
    lista.push_back(new Sphere(xc, yc, zc, r, 0, 0, 0, R, G, B, trans, ss)); 
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::putEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    bool ss=true;
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr, 0, 0, 0, R, G, B, trans, ss)); 
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::cutEllipsoid(int xc, int yc, int zc, int xr, int yr, int zr)
{
    bool ss=false;
    lista.push_back(new Ellipsoid(xc, yc, zc, xr, yr, zr, 0, 0, 0, R, G, B, trans, ss)); //estado
    
    //MANDANDO A FORMA PARA SER INSERIDA
    it_lista itt;
    itt = lista.end();
    Tela.inserirForma(*itt);
}
void Sculptor::cleanVoxels()
{
}
void Sculptor::write(const char* Arq)
{
    unsigned tamX, tamY, tamZ;
    
    tamX = Tela.getX();
    tamY = Tela.getY();
    tamZ = Tela.getZ();
    
    ofstream arquivo(Arq);
    Coordenada corrente;
    
    corrente.X = -0.5;
    corrente.Y = -0.5;
    corrente.Z = -0.5;

    arquivo << "OFF" << endl;
    arquivo << Tela.getNvertices() << " " << Tela.getNfaces() << " " << 0 << endl;

    for (int i = 0; i < tamX + 1; i++) 
    {
        for (int j = 0; j < tamY + 1; j++) 
        {
            for (int k = 0; k < tamZ + 1; k++) 
            {
                corrente.X += i;
                corrente.Y += j;
                corrente.Z += k;
                
                arquivo << corrente << endl;
            }
        }
    }

    
    for (int i = 0; i < tamX; ++i) 
    {
        for (int j = 0; j < tamY; ++j) 
        {
            for (int k = 0; k < tamZ; ++k) 
            {
                //tamX*i + j + tamX*tamY*k

                // Vértices da face X da esquerda
                unsigned P0 = ((tamX+1)*i + j + (tamX+1)*(tamY+1)*(k+1));
                unsigned P1 = ((tamX+1)*i + j + (tamX+1)*(tamY+1)*k);
                unsigned P2 = ((tamX+1)*i + (j+1) + (tamX+1)*(tamY+1)*(k+1));
                unsigned P3 = ((tamX+1)*i + (j+1) + (tamX+1)*(tamY+1)*(k+1));
                unsigned P4 = ((tamX+1)*(i+1) + j + (tamX+1)*(tamY+1)*(k+1));
                unsigned P5 = ((tamX+1)*(i+1) + j + (tamX+1)*(tamY+1)*k);
                unsigned P6 = ((tamX+1)*(i+1) + (j+1) + (tamX+1)*(tamY+1)*k);
                unsigned P7 = ((tamX+1)*(i+1) + (j+1) + (tamX+1)*(tamY+1)*(k+1));
                        
                // Pega o voxel da posição corrente
                Voxel v = getAT(tamX*i + j + tamX*tamY*k);

                if (v.is_on)
                {
                    // Face da esquerda
                    if (i==0 || (getAT(tamX*i + j + tamX*tamY*k).is_on))
                    arquivo << 4 << " " << P0 << " " << P1 << " " << P2 << " " << P3 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    // Face da frente
                    if (k==0 || (getAT(tamX*i + j + tamX*tamY*k).is_on))
                    arquivo << 4 << " " << P1 << " " << P2 << " " << P6 << " " << P5 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    // Face de cima
                    if (j==0 || (getAT(tamX*i + j + tamX*tamY*k).is_on))
                    arquivo << 4 << " " << P0 << " " << P1 << " " << P5 << " " << P4 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    
                    // Face da direita
                    //if ((Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P4 << " " << P5 << " " << P6 << " " << P7 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    
                    // Face de baixo
                    //if ((Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P2 << " " << P3 << " " << P7 << " " << P6 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                    
                    // Face de trás
                    //if ((Tela[tamX*i + j + tamX*tamY*k].is_on))
                    arquivo << 4 << " " << P0 << " " << P4 << " " << P7 << " " << P3 << " " << v.r << " " << v.g << " " << v.b << " " << v.a << endl;
                }
            }
        }
    }
}
void Sculptor::Esculpir()
{
    it_lista itt;
    
    for (itt = lista.begin(); itt != lista.end(); itt++) Tela.discretizar(*itt);
                    
}
