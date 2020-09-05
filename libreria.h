#ifndef LIBRERIA_H
#define LIBRERIA_H
#include <iostream>

using namespace std;

class Libreria
{
public:
    Libreria();
    Libreria(int identificador, string nombre, string letra, string color);

    //gets
    int getIdentificador();
    string getNombre();
    string getColor();
    string getLetra();

    //sets
    void setIdentificador(int identificador);
    void setNombre(string nombre);
    void setLetra(string letra);
    void setColor(string color);
private:
    int identificador;
    string nombre;
    string letra;
    string color;
    //lista puntos
};

#endif // LIBRERIA_H
