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
    Libreria* l2 = new Libreria(2, "E2", "R", "T");
    Objeto* o1 = new Objeto(13, l1);
    Objeto* o2 = new Objeto(25, l2);
    Objeto* o3 = new Objeto(75, l1);
    Objeto* o4 = new Objeto(100, l1);
    Objeto* o5 = new Objeto(125, l1);
    Objeto* o6 = new Objeto(150, l1);
    Objeto* o7 = new Objeto(175, l1);
    Objeto* o8 = new Objeto(200, l1);
    Objeto* o9 = new Objeto(225, l1);
    Objeto* o10 = new Objeto(250, l1);

    //HAY ERROR EN HORIZONTALES, insertando entre un valor mayor y menor
    NodoObjeto* nodoM1 = new NodoObjeto(o1->getId(), o1->getLibreria()->getColor(), o1->getLibreria()->getLetra(), 100, 20);
    NodoObjeto* nodoM2 = new NodoObjeto(o2->getId(), o2->getLibreria()->getColor(), o2->getLibreria()->getLetra(), 100, 20);
    NodoObjeto* nodoM3 = new NodoObjeto(o3->getId(), o3->getLibreria()->getColor(), o3->getLibreria()->getLetra(), 120, 10);
    NodoObjeto* nodoM4 = new NodoObjeto(o4->getId(), o4->getLibreria()->getColor(), o4->getLibreria()->getLetra(), 90, 15);
    NodoObjeto* nodoM5 = new NodoObjeto(o5->getId(), o5->getLibreria()->getColor(), o5->getLibreria()->getLetra(), 95, 40);
    NodoObjeto* nodoM6 = new NodoObjeto(o6->getId(), o6->getLibreria()->getColor(), o6->getLibreria()->getLetra(), 2, 45);
    NodoObjeto* nodoM7 = new NodoObjeto(o7->getId(), o7->getLibreria()->getColor(), o7->getLibreria()->getLetra(), 1, 50);
    NodoObjeto* nodoM8 = new NodoObjeto(o8->getId(), o8->getLibreria()->getColor(), o8->getLibreria()->getLetra(), 170, 1);
    NodoObjeto* nodoM9 = new NodoObjeto(o9->getId(), o9->getLibreria()->getColor(), o9->getLibreria()->getLetra(), 180, 60);
    NodoObjeto* nodoM10 = new NodoObjeto(o10->getId(),o10->getLibreria()->getColor(), o10->getLibreria()->getLetra(), 190, 65);
    m->agregar(nodoM1);
    m->agregar(nodoM2);
    m->agregar(nodoM3);
    m->agregar(nodoM4);
    m->agregar(nodoM5);
    m->agregar(nodoM6);
    m->agregar(nodoM7);
    m->agregar(nodoM8);
    m->agregar(nodoM9);
    m->agregar(nodoM10);
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
