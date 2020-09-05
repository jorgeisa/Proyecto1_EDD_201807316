#include "libreria.h"

Libreria::Libreria(){}

Libreria::Libreria(int identificador, string nombre, string letra, string color){
    this->identificador = identificador;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
}

//gets
int Libreria::getIdentificador(){return this->identificador;}
string Libreria::getNombre(){return this->nombre;}
string Libreria::getColor(){return this->color;}
string Libreria::getLetra(){return this->letra;}

//sets
void Libreria::setIdentificador(int identificador){this->identificador=identificador;}
void Libreria::setNombre(string nombre){this->nombre=nombre;}
void Libreria::setLetra(string letra){this->letra=letra;}
void Libreria::setColor(string color){this->color=color;}
