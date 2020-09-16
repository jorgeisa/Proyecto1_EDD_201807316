#include "nivelproyecto.h"

NivelProyecto::NivelProyecto(int numeroNivel)
{
    this->numeroNivel = numeroNivel;
    this->matrizDispersa = new MatrizDispersa();
    this->arbolBBObjetos = new ArbolBB();
}

int NivelProyecto::getNumeroNivel(){return this->numeroNivel;}
MatrizDispersa* NivelProyecto::getMatrizDispersa(){return this->matrizDispersa;}
ArbolBB* NivelProyecto::getArbolBBObjetos(){return this->arbolBBObjetos;}

void NivelProyecto::setNumeroNivel(int numeroNivel){this->numeroNivel=numeroNivel;}
void NivelProyecto::setMatrizDispersa(MatrizDispersa *matrizDispersa){this->matrizDispersa=matrizDispersa;}
void NivelProyecto::setArbolBBObjetos(ArbolBB *arbolBB){this->arbolBBObjetos=arbolBB;}


