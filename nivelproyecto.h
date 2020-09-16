#ifndef NIVELPROYECTO_H
#define NIVELPROYECTO_H
#include <iostream>
#include "matrizdispersa.h"
#include "arbolbb.h"

using namespace std;

class NivelProyecto
{
public:
    NivelProyecto(int numeroNivel);
    ~NivelProyecto();

    int getNumeroNivel();
    MatrizDispersa* getMatrizDispersa();
    ArbolBB* getArbolBBObjetos();

    void setNumeroNivel(int numeroNivel);
    void setMatrizDispersa(MatrizDispersa* matrizDispersa);
    void setArbolBBObjetos(ArbolBB* arbolBB);
private:
    int numeroNivel;
    MatrizDispersa* matrizDispersa;
    ArbolBB* arbolBBObjetos;
};

#endif // NIVELPROYECTO_H
