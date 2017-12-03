#ifndef _S_MATRIZ_H_
#define _S_MATRIZ_H_
#include <iostream>
#include <vector>
#include <list>
#include "sculptor.h"
#include "shapes.h"

// M(i, j, k) = tamX*i + j + tamX*tamY*k

using namespace std;

class Hipermatriz
{
private:
    vector<Voxel>::iterator var;
    vector <Voxels> H;
    unsigned tamX, tamY, tamZ //coordenadas ou tamanho
public:
    inline explicit Hipermatriz(unsigned x, unsigned y, unsigned z): tamX(x), tamY(y), tamZ(z) {}
    ~Hipermatriz();
    
    void inserirForma(); //discretizar ou esculpir a forma na matriz
    void Redimensionar(); //ao inserir uma forma (aditivamente), redimensionar 
    void definirOrigem(); //ao inserir uma forma (aditivamente ou subtrativamente), recalcular a origem 
    
    
    
}

#endif // _S_MATRIZ_H_
