#ifndef _S_MATRIZ_H_
#define _S_MATRIZ_H_
#include <iostream>
#include <vector>
#include <list>
#include "sculptor.h"
#include "shapes.h"

// M(i, j, k) = tamX*i + j + tamX*tamY*k

using namespace std;

typedef vector<Voxel>::iterator it_matriz;

class Hipermatriz
{
private:
    vector <Voxels> H;
    unsigned tamX, tamY, tamZ //coordenadas ou tamanho em voxels
    Coordenada origem; //coordenadas da origem no mundo
    Coordenada MAX, MIN; //máximo e mínimo
public:
    inline explicit Hipermatriz(unsigned x, unsigned y, unsigned z): tamX(x), tamY(y), tamZ(z) {}
    ~Hipermatriz();
    
    void inserirForma(); //discretizar ou esculpir a forma na matriz
    
    //Redimensionar ao inserir uma forma na lista
    void Redimensionar(const Coordenada &cubo_real); //ao inserir uma forma (aditivamente), redimensionar 
    void definirOrigem(const Coordenada &cubo_real); //ao inserir uma forma (aditivamente ou subtrativamente), recalcular a origem 
    
    void getNvertices();
    void getNfaces();
    
    
}

#endif // _S_MATRIZ_H_
