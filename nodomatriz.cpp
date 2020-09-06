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


//sets
void NodoMatriz::setDerecha(NodoMatriz *derecha){this->derecha=derecha;}
void NodoMatriz::setIzquierda(NodoMatriz *izquierda){this->izquierda=izquierda;}
void NodoMatriz::setArriba(NodoMatriz *arriba){this->arriba=arriba;}
void NodoMatriz::setAbajo(NodoMatriz *abajo){this->abajo=abajo;}


//Clase NodoCabecera
NodoCabecera::NodoCabecera(int id){
    this->id=id;
}

void NodoCabecera::setId(int id){this->id=id;}
int NodoCabecera::getId(){return this->id;}


//Clase NodoObjeto
NodoObjeto :: NodoObjeto(Objeto* objeto, int posicionX, int posicionY){
    this->objeto=objeto;
    this->posicionX=posicionX;
    this->posicionY=posicionY;
}

Objeto* NodoObjeto::getObjeto(){return this->objeto;}
void NodoObjeto::setObjeto(Objeto* objeto){this->objeto=objeto;}

int NodoObjeto::getPosicionX(){return this->posicionX;}
int NodoObjeto::getPosicionY(){return this->posicionY;}

void NodoObjeto::setPosicionX(int posicionX){this->posicionX=posicionX;}
void NodoObjeto::setPosicionY(int posicionY){this->posicionY=posicionY;}

