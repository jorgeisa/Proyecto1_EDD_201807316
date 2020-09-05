#include "arbolbb.h"

ArbolBB::ArbolBB()
{
    this->raizBB = NULL;
}

ArbolBB::~ArbolBB(){
    //Aqui debe de ir el metodo para recorrer un
}


//Metodos Privados
nodoBinario* ArbolBB::buscarNodo(nodoBinario* raiz, int identificador)
{
    if(raiz == NULL){
        return NULL;
    }else if(identificador == raiz->getIdentificador()){
        return raiz;
    }else if(identificador < raiz->getIdentificador()){
        return buscarNodo(raiz->getIzquierda(), identificador);
    }else{
        return buscarNodo(raiz->getDerecha(), identificador);
    }
}

nodoBinario* ArbolBB::insertarNodo(nodoBinario* raiz, nodoBinario* nodoNuevo)
{
    if(raiz == NULL){
        raiz = nodoNuevo;
    }else if(nodoNuevo->getIdentificador() < raiz->getIdentificador()){
        nodoBinario *izquierdo;
        izquierdo = insertarNodo(raiz->getIzquierda(), nodoNuevo);
        raiz->setIzquierda(izquierdo);
    }else if(nodoNuevo->getIdentificador() > raiz->getIdentificador()){
        nodoBinario* derecho;
        derecho = insertarNodo(raiz->getDerecha(), nodoNuevo);
        raiz->setDerecha(derecho);
    }
    return raiz;
}

nodoBinario* ArbolBB::eliminarNodo(nodoBinario *raiz, int identificador){
    if(raiz == NULL){
        return NULL;
    }else if(identificador < raiz->getIdentificador()){
        nodoBinario* izquierda;
        izquierda = eliminarNodo(raiz->getIzquierda(), identificador);
        raiz->setIzquierda(izquierda);
    }else if(identificador > raiz->getIdentificador()){
        nodoBinario* derecha;
        derecha = eliminarNodo(raiz->getDerecha(), identificador);
        raiz->setDerecha(derecha);
    }else{
        nodoBinario* temporal = raiz;
        if(temporal->getDerecha() == NULL && temporal->getIzquierda() == NULL){
            raiz = NULL;
        }else if(temporal->getIzquierda() == NULL){
            raiz = temporal->getDerecha();
        }else if(temporal->getDerecha() == NULL){
            raiz = temporal->getIzquierda();
        }else{
            temporal = reemplazo(temporal);
        }

        delete(temporal);
    }
    return raiz;
}

nodoBinario* ArbolBB::reemplazo(nodoBinario *nodoActual){
    nodoBinario *primero, *segundo;

    primero = nodoActual;
    segundo = primero->getIzquierda();
    while(segundo->getDerecha() != NULL){
        primero = segundo;
        segundo = segundo ->getDerecha();
    }

    nodoActual->setIdentificador(segundo->getIdentificador());
    if(primero==nodoActual){
        primero->setIzquierda(segundo->getIzquierda());
    }else{
        primero->setDerecha(segundo->getIzquierda());
    }
    return segundo;
}

//Metodos Publicos
nodoBinario* ArbolBB::buscarNodo(int identificador){
    return buscarNodo(this->raizBB, identificador);
}

void ArbolBB::insertarNodo(nodoBinario *nodoNuevo){
    this->raizBB = insertarNodo(this->raizBB, nodoNuevo);
    cout<<"Nodo ingresado correctamente!"<<endl;
}

void ArbolBB::eliminarNodo(int identificador){
    this->raizBB = eliminarNodo(this->raizBB, identificador);
}

