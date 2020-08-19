#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;


void mostrarInformacion();
void menu();


int main()
{
    mostrarInformacion();
    menu();
    getch();
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
