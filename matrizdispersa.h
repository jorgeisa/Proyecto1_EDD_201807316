#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include <nodomatriz.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class MatrizDispersa
{
public:
    MatrizDispersa();
    ~MatrizDispersa();

    void agregar(NodoObjeto* objeto);
    void generar();
    void generar2();
    void mostrar_Posiciones();
    void mostrar_Punteros();
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
