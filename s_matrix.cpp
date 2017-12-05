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
        origem = vertices[1];
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
void Hipermatriz::Redimensionar(ptr_Shape &form)//experimental
{
    unsigned tX, tY, tZ;
    

    //ARREDONDANDO PARA INT
    tX = (form->getMAX().X-origem.X+0.5);
    tY = (form->getMAX().Y-origem.Y+0.5);
    tZ = (form->getMAX().Z-origem.Z+0.5); 
    
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
    
    //OBS, tem que ver com base na origem
    //Decidir quais eixos devem aumentar
    //Se a posição MAX da forma em questão for maior do que o tamanho da matriz
    //
    if(tX>tamX) tamX=tX//redimensionar
    else{} //não redimensionar
    if(tY>tamY) tamY=tY //redimensionar
    else{} //não redimensionar
    if(tZ>tamZ) tamZ=tZ //redimensionar
    else{} //não redimensionar
    
    
    //Muda o tamanho da matriz (sempre crescendo)
    H.resize(dimX*dimY*dimZ);
}
void Hipermatriz::inserirForma(ptr_Shape &form)//experimental
{
    vector <Coordenada> temp;
    Coordenada tamanho;
    
    //Determinar cubo envolvente da forma
    temp = form->getCuboEnv();
    
    //Ver quantos voxels equivale à forma no tamanho máximo
    tamanho = form->getMAX();
    
    //Definir a origem se a forma for aditiva
    if(form->getState()) definirOrigem(temp);
    
    //Dimensionar matriz para caber os voxels, se a forma for aditiva
    if(form->getState()) Redimensionar(form);        
}
void Hipermatriz::discretizar(const ptr_Shape& form)
{
    Voxel temp;
    unsigned ix, iy, iz, fx, fy, fz;
    unsigned i, j, k; //pega o cubo envolvente da forma
    
    //Ver se essa forma em questão está na origem
    //if(origem == temp[1]) 
        
    //Definir a distância que deve percorrer com a forma (de onde para onde na matriz)
    //OBS: O valor é arredondado para cima por meio da soma com 0.5
    ix = (form->getMIN().X-origem.X+0.5);
    iy = (form->getMIN().Y-origem.Y+0.5);
    iz = (form->getMIN().Z-origem.Z+0.5);
    fx = (form->getMAX().X-origem.X+0.5);
    fy = (form->getMAX().Y-origem.Y+0.5);
    fz = (form->getMAX().Z-origem.Z+0.5);
        
    //TIPO DE VOXEL A SER PREENCHIDO
    temp.a = form->getTransparency();
    temp.r = form->getRed();
    temp.g = form->getGreen();
    temp.b = form->getBlue();
    temp.is_on = form->getState();
    
    //PREENCHENDO NA MATRIZ
    for(unsigned i=ix; i<fx; i++)
    {
        for(unsigned j=iy; j<fy; j++)
        {
            for(unsigned k=iz; k<fz; k++) 
            {
                //O voxel a ser inserido pode estar ligado ou não
                //A função Verificar() vai pegar a forma e ver se a partir da Coordenada inteira (i, j, k) o Voxel pertence à forma
                //Se pertencer, ele retorna um bool true e liga, se não, o contrário
                temp.is_on = form.Verificar(i, j, k);
                //Recebe o voxel na posição, ligado ou não
                H[tamX*i+j+tamX*tamY*k] = temp; 
            }
        }
    }
}
unsigned int Hipermatriz::getNfaces() const
{
}




