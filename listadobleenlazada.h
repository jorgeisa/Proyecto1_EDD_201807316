#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include <iostream>
#include <string.h>
#include "nododobleenlazada.h"
#include <string>
#include <sstream>

using namespace std;

class ListaDobleEnlazada
{
public:
    ListaDobleEnlazada();
    ~ListaDobleEnlazada();

    void insertarAlFinal(NodoDobleEnlazada*  nuevoNodo);\
    string generar();
    string generar(NodoDobleEnlazada* aux);
    void imprimir();
private:
    NodoDobleEnlazada* cabeza;
    NodoDobleEnlazada* final;
};

#endif // LISTADOBLEENLAZADA_H
