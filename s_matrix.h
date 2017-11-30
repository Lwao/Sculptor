#ifndef _S_MATRIZ_H_
#define _S_MATRIZ_H_
#include <iostream>
#include <vector>
#include <list>
#include "sculptor.h"
#include "shapes.h"

// M(i, j) = V(NC*i+j)    

using namespace std;

class Hipermatriz
{
private:
    vector<Voxel>::iterator var;
    vector <Voxels> H;
    unsigned x, y, z //coordenadas ou tamanho
public:
    Hipermatriz(): x(0), y(0), z(0) {}
    explicit Hipermatriz();
    ~Hipermatriz();
    
    inserirForma();
    Redimensionar(); //inserir forma 
    definirOrigem(); //primeira forma (vértice com menor 
    
    
    
}

#endif // _S_MATRIZ_H_
