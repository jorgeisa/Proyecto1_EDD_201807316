#ifndef NODODOBLEENLAZADA_H
#define NODODOBLEENLAZADA_H
#include <iostream>
#include <string.h>
#include <nivelproyecto.h>

using namespace std;

class NodoDobleEnlazada
{
public:
    NodoDobleEnlazada();

    NodoDobleEnlazada* getSiguiente();
    NodoDobleEnlazada* getAnterior();

    void setSiguiente(NodoDobleEnlazada* siguiente);
    void setAnterior(NodoDobleEnlazada* anterior);

private:
    NodoDobleEnlazada* siguiente;
    NodoDobleEnlazada* anterior;
};

//********************* HERENCIA *********************

//CLASE NODO DOBLE PARA NIVEL
class NodoDobleNivel : public NodoDobleEnlazada
{
public:
    NodoDobleNivel(NivelProyecto* nivelProyecto);
    void setNivelProyecto(NivelProyecto* nivel);
    NivelProyecto* getNivelProyecto();

private:
    NivelProyecto* nivelProyecto;
};



#endif // NODODOBLEENLAZADA_H
