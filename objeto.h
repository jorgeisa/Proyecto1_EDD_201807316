#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include "libreria.h"

using namespace std;

class Objeto
{
public:
    Objeto();
    Objeto(int id, Libreria* libreria);

    //gets
    int getId();
    Libreria* getLibreria();

    //sets
    void setId(int id);
    void setLibreria(Libreria* libreria);
private:
    int id;
    Libreria* libreria;
    //Puntos de objeto en matriz
};

#endif // OBJETO_H
