#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <arbolbb.h>
#include <nodobinario.h>
#include <libreria.h>
#include <matrizdispersa.h>
#include <listadobleenlazada.h>
#include <nododobleenlazada.h>
#include <proyectopcad.h>
#include <nivelproyecto.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


void mostrarInformacion();
void menu();


int main()
{

//******************* PRUEBA LISTA DOBLE NIVELES *******************

//    ListaDobleEnlazada* listaD = new ListaDobleEnlazada();

//    NivelProyecto* n1p1 = new NivelProyecto(1);
//    NivelProyecto* n2p1 = new NivelProyecto(2);
//    NivelProyecto* n3p1 = new NivelProyecto(200);

//    NodoDobleNivel *a, *b, *c;
//    a = new NodoDobleNivel(n1p1);
//    b = new NodoDobleNivel(n2p1);
//    c = new NodoDobleNivel(n3p1);

//    listaD->insertarAlFinal(a);
//    listaD->insertarAlFinal(b);
//    listaD->insertarAlFinal(c);

//    listaD->imprimir();

//    ofstream file("salida.dot");
//    file<<listaD->generar();
//    file.close();
//    system("dot -Tpng salida.dot -o imagenPe.png");

//    delete listaD;

//*******************************************************

//******************* PRUEBA DISPERSA *******************
    MatrizDispersa* m = new MatrizDispersa();
    Libreria* l1 = new Libreria(1, "E1", "S", "C");
    Objeto* o1 = new Objeto(13, l1);
    Objeto* o2 = new Objeto(25, l1);
    Objeto* o3 = new Objeto(75, l1);
    Objeto* o4 = new Objeto(100, l1);

    NodoObjeto* nodoM1 = new NodoObjeto(o1->getId(), o1->getLibreria()->getColor(), o1->getLibreria()->getLetra(), 1, 4);
    NodoObjeto* nodoM2 = new NodoObjeto(o2->getId(), o2->getLibreria()->getColor(), o2->getLibreria()->getLetra(), 3, 3);
    NodoObjeto* nodoM3 = new NodoObjeto(o3->getId(), o3->getLibreria()->getColor(), o3->getLibreria()->getLetra(), 10, 11);
    NodoObjeto* nodoM4 = new NodoObjeto(o4->getId(), o4->getLibreria()->getColor(), o4->getLibreria()->getLetra(), 2, 51);
    m->agregar(nodoM1);
    m->agregar(nodoM2);
    cout<<"gg\n";
    m->agregar(nodoM3);
    m->agregar(nodoM4);
    cout<<"\n\n";
    m->mostrar_Posiciones();
    cout<<"\n\nMostrando Punteros: \n";
    m->mostrar_Punteros();
    m->generar2();
    delete m;
    cout<<"\n\n";
//*******************************************************


//    ArbolBB* arbol = new ArbolBB();
//    //Libreria* l1 = new Libreria(1, "l1", "l", "color");
//    nodoBBLibreria *Libreria1 = new nodoBBLibreria(Libreria(1,"l1","l","color"));
//    arbol->insertarNodo(Libreria1);
//    nodoBinario* nodoBuscado = arbol->buscarNodo(1);
//    string id = ((nodoBBLibreria*)nodoBuscado)->getLibreria().getColor();
//    cout<<id<<endl;
    //mostrarInformacion();
    //menu();
//    string nombre1 = "Marvin222";
//    string nombre2 = "Marvin22";
//    if(nombre1.compare(nombre2)<0){
//        cout<<"Nombre 1"<<endl;
//    }
    //getch();
    return 0;
}

void mostrarInformacion(){
    cout<<"\nEsta es la funcion que muestra la informacion.\n";
    cout<<"\n~~~~~~~~~~~ Informacion de Estudiante ~~~~~~~~~~~\n";
    cout<<"* UNIVERSIDAD SAN CARLOS DE GUATEMALA\n";
    cout<<"* CURSO: Estructuras de Datos. :)\n";
    cout<<"* SECCION: A.\n";
    cout<<"* ESTUDIANTE: Jorge Isaac Xicol Vicente. :D\n";
    cout<<"* CARNET: 201807316  !!\n";
    system("pause");
    system("cls");
}

void menu(){
    int opcion;

    do{
        cout<<"~~~~~~~~~~ MENU ~~~~~~~~~~\n";
        cout<<"1. Cargar Librerias.\n";
        cout<<"2. Cargar Proyectos.\n";
        cout<<"3. Editar Proyecto.\n";
        cout<<"4. Ver Proyectos.\n";
        cout<<"5. Guardar Proyecto.\n";
        cout<<"6. Graficar Proyecto.\n";
        cout<<"7. Mostrar informacion.\n";
        cout<<"8. Salir.\n";
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:

                system("pause");
                break;
            case 2:

                system("pause");
                break;
            case 3:
                system("pause");
                break;
            case 4:
                system("pause");
                break;
            case 5:
                system("pause");
                break;
            case 6:
                system("pause");
                break;
            case 7:
                mostrarInformacion();
                system("pause");
                break;
            case 8:
                cout<<"Usted Ha salido del programa. :)";
                break;
            default:
                cout<<"No es valido! :o";
        }
        system("cls");
    }while(opcion != 8);
}
