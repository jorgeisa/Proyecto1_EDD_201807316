#include "nodomatriz.h"

NodoMatriz::NodoMatriz()
{
    this->derecha=NULL;
    this->izquierda=NULL;
    this->abajo=NULL;
    this->arriba=NULL;
}

//gets
NodoMatriz* NodoMatriz::getDerecha(){return this->derecha;}
NodoMatriz* NodoMatriz::getIzquierda(){return this->izquierda;}
NodoMatriz* NodoMatriz::getArriba(){return this->arriba;}
NodoMatriz* NodoMatriz::getAbajo(){return this->abajo;}
int NodoMatriz::getPosicionX(){return this->posicionX;}
int NodoMatriz::getPosicionY(){return this->posicionY;}

//sets
void NodoMatriz::setDerecha(NodoMatriz *derecha){this->derecha=derecha;}
void NodoMatriz::setIzquierda(NodoMatriz *izquierda){this->izquierda=izquierda;}
void NodoMatriz::setArriba(NodoMatriz *arriba){this->arriba=arriba;}
void NodoMatriz::setAbajo(NodoMatriz *abajo){this->abajo=abajo;}
void NodoMatriz::setPosicionX(int posicionX){this->posicionX=posicionX;}
void NodoMatriz::setPosicionY(int posicionY){this->posicionY=posicionY;}

//Clase NodoCabecera
NodoCabecera::NodoCabecera(int id){
    this->id=id;
}

void NodoCabecera::setId(int id){this->id=id;}
int NodoCabecera::getId(){return this->id;}


//Clase NodoObjeto
NodoObjeto :: NodoObjeto(Objeto* objeto){
    this->objeto=objeto;
}

Objeto* NodoObjeto::getObjeto(){return this->objeto;}
void NodoObjeto::setObjeto(Objeto* objeto){this->objeto=objeto;}

