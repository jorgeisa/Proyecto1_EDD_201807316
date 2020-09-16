#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include <nodomatriz.h>
#include <iostream>

using namespace std;

class MatrizDispersa
{
public:
    MatrizDispersa();
    ~MatrizDispersa();

    void agregar(NodoObjeto* objeto);
    void generar();
    void codigo();
private:
    NodoCabecera* horizontal;
    NodoCabecera* vertical;
    NodoCabecera* getVertical(int id);
    NodoCabecera* getHorizontal(int id);
    NodoCabecera* crearVertical(int id);
    NodoCabecera* crearHorizontal(int id);

    NodoMatriz* obtenerUltimoV(NodoCabecera* cabecera, int id);
    NodoMatriz* obtenerUltimoH(NodoCabecera* cabecera, int id);
    string generar(NodoMatriz* aux);
};

#endif // MATRIZDISPERSA_H
