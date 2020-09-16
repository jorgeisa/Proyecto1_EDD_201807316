#include "nodobinario.h"

//***************  NODO PADRE nodoBinario ***************
nodoBinario::nodoBinario(int identificador)
{
    this->identificador=identificador;
    this->derecha = NULL;
    this->izquierda = NULL;
}

nodoBinario::~nodoBinario(){
    cout<<"Nodo Eliminado"<<endl;
}

nodoBinario* nodoBinario::getDerecha(){return this->derecha;}
nodoBinario* nodoBinario::getIzquierda(){return this->izquierda;}
int nodoBinario::getIdentificador(){return this->identificador;}
void nodoBinario::setDerecha(nodoBinario *derecha){this->derecha = derecha;}
void nodoBinario::setIzquierda(nodoBinario *izquierda){this->izquierda = izquierda;}
void nodoBinario::setIdentificador(int identificador){this->identificador=identificador;}

//*************** HERENCIA nodoBBLibreria ***************
nodoBBLibreria::nodoBBLibreria(Libreria libreria) : nodoBinario(libreria.getIdentificador()){
    this->libreria = libreria;
}

//gets
Libreria nodoBBLibreria::getLibreria(){return this->libreria;}
//sets
void nodoBBLibreria::setLibreria(Libreria libreria){this->libreria = libreria;}


//*************** HERENCIA nodoBBObjeto ***************
nodoBBObjeto::nodoBBObjeto(Objeto objeto) : nodoBinario(objeto.getLibreria()->getIdentificador()){
    this->objeto = objeto;
}

Objeto nodoBBObjeto::getObjeto(){
    return this->objeto;
}

void nodoBBObjeto::setObjeto(Objeto objeto){
    this->objeto = objeto;
}


