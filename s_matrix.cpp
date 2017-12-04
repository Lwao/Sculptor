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



void Hipermatriz::definirOrigem(const vector <Coordenada> &vertices)//experimental
{
    //DEFINIÇÃO DA ORIGEM
    if(qtd_formas==0)
    {
        //Se não possuía nenhuma forma até aí, definir a origem no vértice P1
        origem = vertice[1];
        qtd_formas++;
    }
    
    
    //REDEFINIÇÃO DA ORIGEM
    //Mas caso já possui alguma forma (qtd_formas>=1
    qtd_formas++;
    
    if(vertices[1].X<origem.X) origem.X = vertices[1].X;
    else {}
    if(vertices[1].Y<origem.Y) origem.Y = vertices[1].Y;
    else {}
    if(vertices[1].Z<origem.Z) origem.Z = vertices[1].Z;
    else {}
    
}
void Hipermatriz::Redimensionar(const vector <Coordenada> &vertices, const Coordenada &size)//experimental
{
    unsigned tX, tY, tZ;
    
    
    
    //ARREDONDANDO PARA INT
    tX = (abs(size.X)+0.5);
    tY = (abs(size.Y)+0.5);
    tZ = (abs(size.Z)+0.5);
    
    /* VÉRTICES
                      0                 4
                       . . . . . . . . .
                    .  .            .  .
               1 . . . . . . . . . 5   .
                 .     .         .     .
        y        .     .         .     .
                 .     .         .     .
                 .   3 . . . . . . . . . 7
                 .  .            .  .             z
               2 . . . . . . . . . 6

                       x
    */
    //P0 (MIN.x, MAX.y, MIN.z)
    //P1 (MIN.x, MAX.y, MAX.z)
    //P2 (MIN.x, MIN.y, MAX.z)
    //P3 (MIN.x, MIN.y, MIN.z)
    //P4 (MAX.x, MAX.y, MIN.z) 
    //P5 (MAX.x, MAX.y, MAX.z)
    //P6 (MAX.x, MIN.y, MAX.z) 
    //P7 (MAX.x, MIN.y, MIN.z)
    
    
    //Decidir quais eixos devem aumentar
    if(tX>dimX) dimX=tX//redimensionar
    else{} //não redimensionar
    if(tY>dimY) dimY=tY //redimensionar
    else{} //não redimensionar
    if(tZ>dimZ) dimZ=tZ //redimensionar
    else{} //não redimensionar
    
    
    //Muda o tamanho da matriz (sempre crescendo)
    H.resize(dimX*dimY*dimZ);
    
    //Redefinir a origem
    definirOrigem(vertices, size);
}
void Hipermatriz::inserirForma(ptr_Shape &form)//experimental
{
    vector <Coordenada> temp;
    Coordenada tamanho;
    
    //Determinar cubo envolvente da forma
    temp = form->getCuboEnv();
    
    //Ver quantos voxels equivale à forma
    tamanho = form->getSize();
    
    
    //Dimensionar matriz para caber os voxels, se a forma for aditiva
    if(form->getState()) Redimensionar(temp, tamanho);
}
void Hipermatriz::discretizar(const ptr_Shape& form)
{
    Voxel temp;
    
    //TIPO DE VOXEL A SER PREENCHIDO
    temp.a = form.getTransparency();
    temp.r = form.getRed();
    temp.g = form.getGreen();
    temp.b = form.getBlue();
    temp.is_on = form.getState();
    
    
    //PREENCHENDO NA MATRIZ
    for(unsigned i=0; i<dimX; i)
    {
        for(unsigned j=0; j<dimY; j)
        {
            for(unsigned k=0; k<dimZ; k) H[tamX*i+j+tamX*tamY*k] = temp; //recebe o voxel
        }
    }
}
void Hipermatriz::getNvertices()
{
}
void Hipermatriz::getNfaces()
{
}



