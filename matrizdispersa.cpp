#include "matrizdispersa.h"


MatrizDispersa::MatrizDispersa()
{
    this->horizontal=NULL;
    this->vertical=NULL;
}

MatrizDispersa::~MatrizDispersa(){
    NodoMatriz *aux,*aux2,*temp,*temp2,*extra,*extra2;
    aux = this->vertical;  //aux=inicio vertical
    temp = this->horizontal; //temp = inicio horizontal

    while(aux!=NULL){ //Recorremos las cabeceras verticalmente
        extra=aux->getAbajo(); //Obtener abajo de cabeza vertical
        aux2=aux->getDerecha(); //Obtener derecha de cabeza vertical

        while(aux2!=NULL){//mientras la derecha no sea null
            extra2=aux2->getDerecha(); //extra2 es la derecha de la derecha
            delete aux2; //eliminamos la primera derecha
            aux2=extra2; //primera derecha esta donde la segunda derecha
        }
        delete aux; //eliminamos la cabecera vertical
        aux=extra; //aux ahora es el de abajo
    }
    while(temp!=NULL){ //mientras la cabecera horizontal no sea null
        temp2=temp->getDerecha(); //temp2 es la derecha del actual horizontal
        delete temp;  //eliminamos el actual horizontal
        temp=temp2;   //temp se mueve hacia la derecha del eliminado.
    }
}

void MatrizDispersa::agregar(NodoObjeto *objeto){
    NodoCabecera* vertical = this->getVertical(objeto->getObjeto()->getId());
    NodoCabecera* horizontal = this->getHorizontal(objeto->getObjeto()->getId());

    if(vertical == NULL){
        vertical=crearVertical(objeto->getObjeto()->getId());
    }
    if(horizontal==NULL){
        horizontal = crearHorizontal(objeto->getObjeto()->getId());
    }

    NodoMatriz* izquierda = obtenerUltimoH(vertical,objeto->getObjeto()->getId());
    NodoMatriz* superior = obtenerUltimoV(horizontal, objeto->getObjeto()->getId());

    if(izquierda->getDerecha()==NULL){
        izquierda->setDerecha(objeto);
        objeto->setIzquierda(izquierda);
    }else{
        NodoMatriz* temp = izquierda->getDerecha();
        izquierda->setDerecha(objeto);
        objeto->setIzquierda(izquierda);
        temp->setIzquierda(objeto);
        objeto->setDerecha(temp);
    }
    if(superior->getAbajo()==NULL){
        superior->setAbajo(objeto);
        objeto->setArriba(superior);
    }else{
        NodoMatriz* temp=superior->getAbajo();
        superior->setAbajo(objeto);
        objeto->setArriba(superior);
        temp->setArriba(objeto);
        objeto->setAbajo(temp);
    }

}

NodoCabecera* MatrizDispersa::crearHorizontal(int id){
    if(this->horizontal==NULL){
        NodoCabecera* nueva = new NodoCabecera(id);
        this->horizontal=nueva;
        return nueva;
    }
    //Si esta lleno
    NodoCabecera *aux=this->horizontal;
    //Si el id ingresado es menor
    if(id <= aux->getId()){
        NodoCabecera* nueva = new NodoCabecera(id);
        nueva->setDerecha(aux);
        this->horizontal->setIzquierda(nueva);
        this->horizontal=nueva;
        return nueva;
    }
    //Si el id ingresado es mayor
    while(aux->getDerecha()!=NULL){
        //Si el id esta entre dos nodos [Mayor a < idIngresado < Menor a]
        if(id > aux->getId() && id < (((NodoCabecera*)aux->getDerecha()))->getId()){
            NodoCabecera* nueva = new NodoCabecera(id);
            NodoCabecera* temp=(NodoCabecera*)aux->getDerecha(); //temp= derecha del actual
            temp->setIzquierda(nueva); //izquierda de la derecha del actual es la nueva
            nueva->setDerecha(temp); //derecha de la nueva es temp
            aux->setDerecha(nueva);  //derecha del actual(aux) es la nueva
            nueva->setIzquierda(aux); //izquierda de la nueva es la actual(aux)
            return nueva;
        }
    }

    //Si llego a null, es mayor a todos los id
    NodoCabecera *nuevo = new NodoCabecera(id);
    aux->setDerecha(nuevo); //derecha del actual es la nueva
    nuevo->setIzquierda(aux); //izquierda de la nueva es el actual
    return nuevo;
}

NodoCabecera* MatrizDispersa::crearVertical(int id){
    if(this->vertical==NULL){
        NodoCabecera* nueva = new NodoCabecera(id);
        this->vertical=nueva;
        return nueva;
    }
    //Si esta lleno
    NodoCabecera *aux=this->vertical;
    //Si el id ingresado es menor
    if(id <= aux->getId()){
        NodoCabecera* nueva = new NodoCabecera(id);
        nueva->setAbajo(aux);
        this->vertical->setArriba(nueva);
        this->vertical=nueva;
        return nueva;
    }
    //Si el id ingresado es mayor
    while(aux->getAbajo()!=NULL){
        //Si el id esta entre dos nodos [Mayor a < idIngresado < Menor a]
        if(id > aux->getId() && id < (((NodoCabecera*)aux->getAbajo()))->getId()){
            NodoCabecera* nueva = new NodoCabecera(id);
            NodoCabecera* temp=(NodoCabecera*)aux->getAbajo(); //temp= derecha del actual
            temp->setArriba(nueva); //izquierda de la derecha del actual es la nueva
            nueva->setAbajo(temp); //derecha de la nueva es temp
            aux->setAbajo(nueva);  //derecha del actual(aux) es la nueva
            nueva->setArriba(aux); //izquierda de la nueva es la actual(aux)
            return nueva;
        }
    }

    //Si llego a null, es mayor a todos los id
    NodoCabecera *nuevo = new NodoCabecera(id);
    aux->setAbajo(nuevo); //derecha del actual es la nueva
    nuevo->setArriba(aux); //izquierda de la nueva es el actual
    return nuevo;
}

NodoMatriz* MatrizDispersa::obtenerUltimoH(NodoCabecera *cabecera, int id){
    if (cabecera->getDerecha()==NULL){return cabecera;}
    NodoMatriz* aux=cabecera->getDerecha();
    if(id<=((NodoObjeto*)aux)->getPosicionX()){return cabecera;}

    while(aux->getDerecha()!=NULL){
        if(id <= ((NodoObjeto*)aux)->getObjeto()->getId()){
            return aux;
        }
        aux = aux->getDerecha();
    }

    if(id <= ((NodoObjeto*)aux)->getObjeto()->getId()){
        return aux->getIzquierda();
    }
    return aux;
}

NodoMatriz* MatrizDispersa::obtenerUltimoV(NodoCabecera *cabecera, int id){
    if (cabecera->getAbajo()==NULL){return cabecera;}
    NodoMatriz* aux=cabecera->getAbajo();

    while(aux->getAbajo()!=NULL){
        if(id <= ((NodoObjeto*)aux)->getObjeto()->getId()){
            return aux;
        }
        aux = aux->getAbajo();
    }

    if(id > ((NodoObjeto*)aux)->getObjeto()->getId()){
        return aux->getArriba();
    }
    return aux;
}


NodoCabecera* MatrizDispersa::getVertical(int id){
    if(this->vertical==NULL){return NULL;}
    NodoCabecera* aux = this->vertical;
    while(aux!=NULL){
        if(aux->getId() == id){
            return aux;
        }
        aux = (NodoCabecera*)aux->getAbajo();
    }
    return aux;
}

NodoCabecera* MatrizDispersa::getHorizontal(int id){
    if(this->horizontal==NULL){return NULL;}
    NodoCabecera* aux = this->horizontal;
    while(aux!=NULL){
        if(aux->getId() == id){
            return aux;
        }
        aux = (NodoCabecera*)aux->getDerecha();
    }
    return aux;
}

