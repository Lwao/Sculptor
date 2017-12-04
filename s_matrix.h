#ifndef _S_MATRIZ_H_
#define _S_MATRIZ_H_
#include <iostream>
#include <vector>
#include <list>
#include "sculptor.h"
#include "shapes.h"

// M(i, j, k) = tamX*i + j + tamX*tamY*k

using namespace std;

struct Voxel
{
    float r,g,b; // Cores
    float a; // Transparência
    bool is_on; // Incluir ou não
};

typedef vector<Voxel>::iterator it_matriz;

class Hipermatriz
{
private:
    vector <Voxels> H; //matriz de voxels
    unsigned tamX, tamY, tamZ //coordenadas ou tamanho em voxels (int)
    Coordenada origem; //coordenadas da origem no mundo (double)
    Coordenada MAX, MIN; //máximo e mínimo nas coordenadas do mundo (double)
public:
    inline explicit Hipermatriz(unsigned x, unsigned y, unsigned z): tamX(x), tamY(y), tamZ(z) {}
    ~Hipermatriz();
    
    void inserirForma(); //discretizar ou esculpir a forma na matriz
    void Redimensionar(const Coordenada &cubo_real); //ao inserir uma forma (aditivamente), redimensionar 
    void definirOrigem(const Coordenada &cubo_real); //ao inserir uma forma (aditivamente ou subtrativamente), recalcular a origem 
    
    //PARA A IMPRESSÃO
    void getNvertices(); //pega o número de vértices de todos os voxels
    void getNfaces(); //pega o número de faces de todos os voxels
    
    
}

#endif // _S_MATRIZ_H_
