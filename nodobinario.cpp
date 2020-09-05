#include "nodobinario.h"

//Nodo Padre
nodoBinario::nodoBinario(int identificador)
{
    this->identificador=identificador;
    this->derecha = NULL;
    this->izquierda = NULL;
}

nodoBinario::~nodoBinario(){
    cout<<"Nodoo Eliminado"<<endl;
}

nodoBinario* nodoBinario::getDerecha(){return this->derecha;}
nodoBinario* nodoBinario::getIzquierda(){return this->izquierda;}
int nodoBinario::getIdentificador(){return this->identificador;}
void nodoBinario::setDerecha(nodoBinario *derecha){this->derecha = derecha;}
void nodoBinario::setIzquierda(nodoBinario *izquierda){this->izquierda = izquierda;}
void nodoBinario::setIdentificador(int identificador){this->identificador=identificador;}

//Nodo con Herencia
nodoBBLibreria::nodoBBLibreria(Libreria libreria) : nodoBinario(libreria.getIdentificador()){
    this->libreria = libreria;
}

//gets
Libreria nodoBBLibreria::getLibreria(){return this->libreria;}
//sets
void nodoBBLibreria::setLibreria(Libreria libreria){this->libreria = libreria;}


