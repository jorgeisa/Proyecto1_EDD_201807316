#include "listadobleenlazada.h"

ListaDobleEnlazada::ListaDobleEnlazada()
{
    this->cabeza = NULL;
}

ListaDobleEnlazada::~ListaDobleEnlazada(){
    NodoDobleEnlazada* aux=this->cabeza;
    NodoDobleEnlazada* tempo;
    while(aux != NULL){
        tempo = aux->getSiguiente();
        aux->setAnterior(NULL);
        aux->setSiguiente(NULL);
        delete aux;
        aux=tempo;
    }
}

void ListaDobleEnlazada::insertarAlFinal(NodoDobleEnlazada *nuevoNodo){
    if (this->cabeza == NULL){
        this->cabeza = nuevoNodo;
        this->final = nuevoNodo;
    }else{
        this->final->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(this->final);
        this->final = nuevoNodo;
    }
}

string ListaDobleEnlazada::generar(){
    ostringstream cadena;
    cadena<<"digraph G{"<<endl<<"node[shape=\"record\"];"<<endl;
    cadena<<"rankdir=BT;"<<endl; //Se usa para que salga de abajo para arriba
    cadena<<generar(this->cabeza)<<endl;
    cadena<<"}"<<endl;
    return cadena.str();
}

string ListaDobleEnlazada::generar(NodoDobleEnlazada* aux){
    ostringstream cadena;
    if(aux!=NULL){
        cadena<<"nodo"<<&(*aux)<<"[label=\""<<((NodoDobleNivel*)aux)->getNivelProyecto()->getNumeroNivel()<<"\"];"<<endl;
        NodoDobleEnlazada* siguiente = aux->getSiguiente();

        cadena<< (siguiente==NULL?"":generar(siguiente));

        if(siguiente!=NULL){
            cadena<<"nodo"<<&(*siguiente)<<"->nodo"<<&(*aux)<<";"<<endl;
            cadena<<"nodo"<<&(*aux)<<"->nodo"<<&(*siguiente)<<";"<<endl;
        }
    }
    cout<<"entro"<<endl;
    return cadena.str();
}


void ListaDobleEnlazada::imprimir(){
    NodoDobleEnlazada* aux=this->cabeza;
    cout<<((NodoDobleNivel*)this->cabeza)->getNivelProyecto()->getNumeroNivel()<<endl;
    cout<<((NodoDobleNivel*)this->final)->getNivelProyecto()->getNumeroNivel()<<endl;
    while(aux!=NULL){
        cout<<"Nivel de proyecto : "<<((NodoDobleNivel*)aux)->getNivelProyecto()->getNumeroNivel()<<endl;
        aux=aux->getSiguiente();
    }
    cout<<"------------------------------"<<endl;
}


