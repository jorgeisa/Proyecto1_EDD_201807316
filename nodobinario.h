#ifndef NODOBINARIO_H
#define NODOBINARIO_H
#include <iostream>
#include "libreria.h"

using namespace std;

class nodoBinario
{
public:
    nodoBinario(int identificador);
    ~nodoBinario();

    //gets
    nodoBinario* getDerecha();
    nodoBinario* getIzquierda();
    int getIdentificador();

    //sets
    void setDerecha(nodoBinario* derecha);
    void setIzquierda(nodoBinario* izquierda);
    void setIdentificador(int identificador);
private:
    nodoBinario* derecha;
    nodoBinario* izquierda;
    int identificador;
};




//Uso de herencia para guardar los nodos
class nodoBBLibreria : public nodoBinario
{
public:
    nodoBBLibreria(Libreria libreria);
    //get
    Libreria getLibreria();
    //sets
    void setLibreria(Libreria libreria);
private:
    Libreria libreria;
};

#endif // NODOBINARIO_H
