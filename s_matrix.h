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
    unsigned tamX, tamY, tamZ; //coordenadas ou tamanho em voxels (int)
    Coordenada origem; //coordenadas da origem no mundo (double)
    unsigned qtd_formas;
public:
    Hipermatriz(): qtd_formas(0), tamX(0), tamY(0), tamZ(0) {}
    inline explicit Hipermatriz(unsigned x, unsigned y, unsigned z): tamX(x), tamY(y), tamZ(z) {}
    ~Hipermatriz();
    
    void definirOrigem(const vector <Coordenada> &vertices); //ao inserir uma forma (aditivamente ou subtrativamente), recalcular a origem 
    void Redimensionar(ptr_Shape &form); //ao inserir uma forma (aditivamente), redimensionar 
    void inserirForma(ptr_Shape &form); //ao inserir uma forma, redimensiona a matriz
    
    //Após dimensionar a matriz considerando todas as formas
    void discretizar(const ptr_Shape &form);
    
    
    //PARA A IMPRESSÃO
    inline unsigned getNvertices() const {return (tamX + 1) * (tamY + 1) * (tamZ + 1);} //pega o número de vértices de todos os voxels
    unsigned getNfaces() const; //pega o número de faces de todos os voxels
    
    inline Voxel & at(unsigned i, unsigned j, unsigned k) {return H.at(tamX*i + j + tamX*tamY*k);}
    
};

#endif // _S_MATRIZ_H_
