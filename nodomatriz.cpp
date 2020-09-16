#include "nodomatriz.h"

//***************  NODO PADRE nodoBinario ***************
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


//*************** HERENCIA nodoCabecera ***************
NodoCabecera::NodoCabecera(int id){
    this->id=id;
}

void NodoCabecera::setId(int id){this->id=id;}
int NodoCabecera::getId(){return this->id;}


//*************** HERENCIA nodoObjeto ***************
NodoObjeto :: NodoObjeto(int idObjeto, string color, string letra, int posicionX, int posicionY){
    this->idObjeto = idObjeto;
    this->color = color;
    this->letra = letra;
    this->posicionX=posicionX;
    this->posicionY=posicionY;
}

int NodoObjeto::getIdObjeto(){return this->idObjeto;}
void NodoObjeto::setIdObjeto(int idObjeto){this->idObjeto=idObjeto;}

string NodoObjeto::getColor(){return this->color;}
void NodoObjeto::setColor(string color){this->color=color;}

string NodoObjeto::getLetra(){return this->letra;}
void NodoObjeto::setLetra(string letra){this->letra=letra;}

int NodoObjeto::getPosicionX(){return this->posicionX;}
int NodoObjeto::getPosicionY(){return this->posicionY;}

void NodoObjeto::setPosicionX(int posicionX){this->posicionX=posicionX;}
void NodoObjeto::setPosicionY(int posicionY){this->posicionY=posicionY;}

