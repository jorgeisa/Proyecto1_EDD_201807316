#ifndef NODOBINARIO_H
#define NODOBINARIO_H
#include <iostream>
#include "libreria.h"
#include "objeto.h"

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


//******************  HERENCIA  ******************

//CLASE NODO PARA GUARDAR UNA LIBRERIA
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

//CLASE NODO PARA GUARDAR UN OBJETO
class nodoBBObjeto : public nodoBinario
{
public:
    nodoBBObjeto(Objeto objeto);
    Objeto getObjeto();
    void setObjeto(Objeto objeto);
private:
    Objeto objeto;
};

#endif // NODOBINARIO_H
