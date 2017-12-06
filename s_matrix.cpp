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



void Hipermatriz::definirOrigem(const Coordenada vertices[])//experimental
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
    if(vertices[1].Y<origem.Y) origem.Y = vertices[1].Y;
    if(vertices[1].Z<origem.Z) origem.Z = vertices[1].Z;
    
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
    if(tX>tamX) tamX=tX; //redimensionar
    if(tY>tamY) tamY=tY; //redimensionar
    if(tZ>tamZ) tamZ=tZ; //redimensionar
    
    
    //Muda o tamanho da matriz (sempre crescendo)
    H.resize(tamX*tamY*tamZ);
}
void Hipermatriz::inserirForma(ptr_Shape &form)//experimental
{
    //vector <Coordenada> temp;
    //Coordenada *temp;
    Coordenada tamanho;
    cout<<"11"<< endl;
    
    
    //Determinar cubo envolvente da forma
    //Ponteiro aponta para o endereço dos vértices
    //temp = form->getCuboEnv();
    
    
    //DETERMINANDO O CUBO envolvente
    Coordenada EXT[2];
    Coordenada vert[8];
    Coordenada temp;
    
    cout<<"123231"<< endl;
    //EXT[0] = (*form).getMIN(); //preenche com a coordenada mínima
    EXT[0].X = (*form).getMIN().X;
    cout<<"123231"<< endl;
    EXT[0].Y = (*form).getMIN().Y;
    cout<<"123231"<< endl;
    EXT[0].Z = (*form).getMIN().Z;
    cout<<"dd11"<< endl;
    EXT[1] = (*form).getMAX(); //preenche com a coordenada máxima
    cout<<"12222"<< endl;
    unsigned count(0);
    unsigned pos(0);

    for (int i=0; i<=1; i++)
    {
        //for (int j=1; j>=0; j--)
        for (int j=0; j<=1; j++)
        {
            if(count==2)
            {
                for(int k=1; k>=0; k--)
                {
                    temp.X = EXT[i].X;
                    temp.Y = EXT[j+1].Y;
                    temp.Z = EXT[k].Z;
                    vert[pos]=temp; 
                    pos++;
                    count--;
                }
            }
            if(count==0)
            {
                for(int k=0; k<=1; k++)
                {
                    temp.X = EXT[i].X;
                    temp.Y = EXT[j+1].Y;
                    temp.Z = EXT[k].Z;
                    vert[pos]=temp; 
                    pos++;
                    count++;
                }
            }
        }
    }
    cout<<"122221"<< endl;
    
    
    //Ver quantos voxels equivale à forma no tamanho máximo
    //tamanho = form->getMAX();
    cout<<"111"<< endl;
    //Definir a origem se a forma for aditiva
    if(form->getState()) definirOrigem(vert);
    cout<<"12"<< endl;
    //Dimensionar matriz para caber os voxels, se a forma for aditiva
    if(form->getState()) Redimensionar(form); 
    cout<<"13"<< endl;
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
                temp.is_on = form->Verificar(i, j, k);
                //Recebe o voxel na posição, ligado ou não
                H.at(tamX*i+j+tamX*tamY*k) = temp; 
            }
        }
    }
}
unsigned int Hipermatriz::getNfaces() const
{
    unsigned qtd(0);
    for (int i = 0; i < tamX; ++i) 
    {
        for (int j = 0; j < tamY; ++j) 
        {
            for (int k = 0; k < tamZ; ++k) 
            {
    
                // Verifica se o voxel está ativo
                if ( H.at(tamX*i + j + tamX*tamY*k).is_on ) 
                {
                qtd += 6;
                }
            }
        }
    }
    return qtd;    
}




