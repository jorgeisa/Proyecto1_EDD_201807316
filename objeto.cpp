#include "objeto.h"


Objeto :: Objeto(){}

Objeto::Objeto(int id, Libreria* libreria)
{
    this->id=id;
    this->libreria=libreria;
}

//gets
int Objeto::getId(){return this->id;};
Libreria* Objeto::getLibreria(){return this->libreria;}

//sets
void Objeto::setId(int id){this->id=id;}
void Objeto::setLibreria(Libreria* libreria){this->libreria=libreria;}
