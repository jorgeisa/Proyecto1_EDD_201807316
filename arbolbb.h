#ifndef ARBOLBB_H
#define ARBOLBB_H
#include <nodobinario.h>
#include <iostream>

class ArbolBB
{
public:
    ArbolBB();
    ~ArbolBB();
    nodoBinario* buscarNodo(int identificador); //Buscar elementos
    void insertarNodo(nodoBinario* nodoNuevo);
    void eliminarNodo(int identificador);

private:
    nodoBinario *raizBB;
    nodoBinario* buscarNodo(nodoBinario *raiz, int identificador);
    nodoBinario* insertarNodo(nodoBinario* raiz, nodoBinario* nodoNuevo);
    nodoBinario* eliminarNodo(nodoBinario* raiz,int identificador);
    nodoBinario* reemplazo(nodoBinario* nodoActual);
};

#endif // ARBOLBB_H
