#include "nododobleenlazada.h"

//NODO PADRE
NodoDobleEnlazada::NodoDobleEnlazada()
{
    this->anterior = NULL;
    this->siguiente = NULL;
}

NodoDobleEnlazada* NodoDobleEnlazada::getSiguiente(){return this->siguiente;}
NodoDobleEnlazada* NodoDobleEnlazada::getAnterior(){return this->anterior;}

void NodoDobleEnlazada::setSiguiente(NodoDobleEnlazada *siguiente){this->siguiente=siguiente;}
void NodoDobleEnlazada::setAnterior(NodoDobleEnlazada *anterior){this->anterior=anterior;}


//NODO HIJO
NodoDobleNivel::NodoDobleNivel(NivelProyecto* nivelProyecto) : NodoDobleEnlazada(){
    this->nivelProyecto=nivelProyecto;
}

NivelProyecto* NodoDobleNivel::getNivelProyecto(){return this->nivelProyecto;}
void NodoDobleNivel::setNivelProyecto(NivelProyecto* nivelProyecto){this->nivelProyecto=nivelProyecto;}
