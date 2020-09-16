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


//********************* HERENCIA *********************

//CLASE NODO CABECERA
class NodoCabecera : public NodoMatriz
{
public:
    NodoCabecera(int id);
    void setId(int id);
    int getId();
private:
    int id;
};

//CLASE NODO OBJETO
class NodoObjeto : public NodoMatriz
{
public:
    NodoObjeto(int idObjeto, string color, string letra, int posicionX, int posicionY);
    int getIdObjeto();
    string getColor();
    string getLetra();
    int getPosicionX();
    int getPosicionY();

    void setIdObjeto(int idObjeto);
    void setColor(string color);
    void setLetra(string letra);
    void setPosicionX(int posicionX);
    void setPosicionY(int posicionY);
private:
    int idObjeto;
    string color;
    string letra;
    int posicionX;
    int posicionY;
};

#endif // NODOMATRIZ_H
