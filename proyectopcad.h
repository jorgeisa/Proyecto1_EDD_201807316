#ifndef PROYECTOPCAD_H
#define PROYECTOPCAD_H
#include <iostream>
#include <string.h>

using namespace std;

class ProyectoPCAD
{
public:
    ProyectoPCAD(string nombreP);
    ~ProyectoPCAD();

    int getValorAscii();
private:
    string nombreP;
    int nombreAscii;
};
#endif // PROYECTOPCAD_H
