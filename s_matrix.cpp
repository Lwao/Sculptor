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

void Hipermatriz::inserirForma()//experimental
{
    Coordenada cubo_env; //em coordenadas do mundo
    ptr_Shape temp;
    
    it_lista = &(lista.end()->clone()); // transforma o iterador da lista no último elemento inserido na lista
    
    temp = 
    *temp.detCuboenv();
    
    
    Redimensionar(cubo_env);
    definirOrigem(cubo_env);
    
    
    
}
void Hipermatriz::Redimensionar(const Coordenada &cubo_real)//experimental
{
    unsigned tX, tY, tZ;
    
    
    
    //ARREDONDANDO PARA INT
    tX = (abs(cubo_real.X)+0.5);
    tY = (abs(cubo_real.Y)+0.5);
    tZ = (abs(cubo_real.Z)+0.5);
    
    dimX
    
    //CONVERTER AS COORDENADAS DE CUBO_REAL PARA INTEIRO
    
    //...
    
    
    if(cubo_real.X>dimX)
    {
        
    }
    else
    {
        
    }
    if(cubo_real.Y>dimY)
    {
        
    }
    else
    {
        
    }
    if(cubo_real.Z>dimZ)
    {
        
    }
    else
    {
        
    }
}
void Hipermatriz::definirOrigem(const Coordenada &cubo_real)//experimental
{
    //REDEFINIÇÃO DA ORIGEM
    if(cubo_real.X<origem.X) origem.X = cubo_real.X;
    if(cubo_real.Y<origem.Y) origem.Y = cubo_real.Y;
    if(cubo_real.Z<origem.Z) origem.Z = cubo_real.Z;
    
}


