#include "proyectopcad.h"
#include <iostream>

using namespace std;

ProyectoPCAD::ProyectoPCAD(string nombreP)
{
    this->nombreP=nombreP;
    this->nombreAscii=this->getValorAscii();
}

int ProyectoPCAD::getValorAscii(){
    int longitud = this->nombreP.length();
    int codigo = 0;
    for (int i = 0; i < longitud; i++)
    {
        char x = this->nombreP.at(i);
        codigo += int(x);
    }
    return codigo;
}

