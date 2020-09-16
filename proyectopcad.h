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

    //Retorna el valor Ascii del nombre del proyecto
    int getValorAscii();

    string getNombreP();
    int getnombreAscii();
    void setNombreP(string nombreP);
    void setNombreAscii(int nombreAscii);

private:
    string nombreP;
    int nombreAscii;
};
#endif // PROYECTOPCAD_H
