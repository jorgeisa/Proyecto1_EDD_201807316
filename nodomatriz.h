#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <iostream>
#include <objeto.h>

using namespace std;

class NodoMatriz
{
public:
    NodoMatriz();
    NodoMatriz* getDerecha();
    NodoMatriz* getIzquierda();
    NodoMatriz* getArriba();
    NodoMatriz* getAbajo();

    void setDerecha(NodoMatriz* derecha);
    void setIzquierda(NodoMatriz* izquierda);
    void setArriba(NodoMatriz* arriba);
    void setAbajo(NodoMatriz* abajo);

private:
    NodoMatriz* derecha;
    NodoMatriz* izquierda;
    NodoMatriz* arriba;
    NodoMatriz* abajo;
};

//Clase cabecera usando herencia
class NodoCabecera : public NodoMatriz
{
public:
    NodoCabecera(int id);
    void setId(int id);
    int getId();
private:
    int id;
};

//Clase NodoObjeto usando herencia
class NodoObjeto : public NodoMatriz
{
public:
    NodoObjeto(Objeto* objeto);
    Objeto* getObjeto();
    int getPosicionX();
    int getPosicionY();

    void setObjeto(Objeto* objeto);
    void setPosicionX(int posicionX);
    void setPosicionY(int posicionY);
private:
    Objeto* objeto;
    int posicionX;
    int posicionY;
};

#endif // NODOMATRIZ_H
