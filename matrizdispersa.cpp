#include "matrizdispersa.h"


MatrizDispersa::MatrizDispersa()
{
    this->horizontal=NULL;
    this->vertical=NULL;
}

void MatrizDispersa::codigo(){
    NodoMatriz *aux,*aux2,*temp,*temp2,*extra,*extra2;
    aux = this->vertical;
    temp = this->horizontal;

    //aux y temp son cabezas V y H
    while(aux!=NULL){
        extra=aux->getAbajo(); //Extra es un NodoCabecera
        cout<<((NodoCabecera*)aux)->getId()<<" - ";
        aux2=aux->getDerecha(); //aux2 es un NodoObjeto

        while(aux2!=NULL){
            extra2 = aux2->getDerecha(); //Extra 2 es NodoObjeto
            cout<<((NodoObjeto*)aux2)->getObjeto()->getId()<<" ("<<((NodoObjeto*)aux2)->getPosicionX()<<" , "<<((NodoObjeto*)aux2)->getPosicionY()<<" ) ";
            aux2=extra2; //NodosObjetos
        }
        cout<<"\n";
        aux = extra; //aux es Cabecera
    }

    while(temp!=NULL){ //Temp es cabecera
        temp2=temp->getDerecha(); //Temp es cabecera H
        cout<<((NodoCabecera*)temp)->getId()<<" ";
        temp = temp2;
    }
}



//Borrar matriz dispersa
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

//Agregar nuevo nodo con posiciones X y Y YA LISTAS
void MatrizDispersa::agregar(NodoObjeto *objeto){
    NodoCabecera* vertical = this->getVertical(objeto->getPosicionY());
    NodoCabecera* horizontal = this->getHorizontal(objeto->getPosicionX());

    if(vertical == NULL){
        vertical=crearVertical(objeto->getPosicionY());
    }
    if(horizontal==NULL){
        horizontal = crearHorizontal(objeto->getPosicionX());
    }

    NodoMatriz* izquierda = obtenerUltimoH(vertical,objeto->getPosicionX());
    NodoMatriz* superior = obtenerUltimoV(horizontal, objeto->getPosicionY());

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

//Nos crea una cabecera
NodoCabecera* MatrizDispersa::crearHorizontal(int id){ //Le pasaremos el id (posicion) cabecera
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
        if(id > aux->getId() && id < ((NodoCabecera*)aux)->getId()){
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

NodoCabecera* MatrizDispersa::crearVertical(int id){ //Ingresamos la posicion en Y que no existe
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

//Obtener el ultimo nodo Horizontal. En donde se insertara el objeto (Posicion X)
NodoMatriz* MatrizDispersa::obtenerUltimoH(NodoCabecera *cabecera, int id){ //Cabecera vertical y posicion X
    if (cabecera->getDerecha()==NULL){return cabecera;} //Si a la derecha no hay ningun nodo

    NodoMatriz* aux=cabecera->getDerecha();
    //Si hay un nodo crearemos un auxiliar para guardar la derecha
    //Este nodo sera de tipo NodoObjeto

    if(id<=((NodoObjeto*)aux)->getPosicionX()){return cabecera;} //Si la posicion es menor a la que ya hay

    while(aux->getDerecha()!=NULL){ //Recorrer hacia la derecha
        if(id > ((NodoObjeto*)aux)->getPosicionX() && id <=((NodoObjeto*)aux->getDerecha())->getPosicionX()){
            return aux;
        }
        aux = aux->getDerecha();
    }

    //Evaluar la ultima posicion
    if(id <= ((NodoObjeto*)aux)->getPosicionX()){
        return aux->getIzquierda();
    }
    return aux;
}

//Obtener el ultimo nodo vertical para añadir el nodo en la posicion Y
NodoMatriz* MatrizDispersa::obtenerUltimoV(NodoCabecera *cabecera, int id){ //Cabecera Horizontal, posicion vertical
    if (cabecera->getAbajo()==NULL){return cabecera;} //Si no hay nodo aun en la cabecera
    NodoMatriz* aux=cabecera->getAbajo(); //Si hay al menos un nodo creamos un auxiliar que guarde abajo
    if (id<=((NodoObjeto*)aux)->getPosicionY()){return cabecera;} //Si la posicion en y sigue siendo menor a la que ya esta

    while(aux->getAbajo()!=NULL){//Si encuentra uno en medio
        if(id > ((NodoObjeto*)aux)->getPosicionY() && id <= ((NodoObjeto*)aux->getAbajo())->getPosicionY()){
            return aux;
        }
        aux = aux->getAbajo();
    }

    //Si encuentra que el final es mayor a la posicion Y a ingresar
    if(id <= ((NodoObjeto*)aux)->getPosicionY()){
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



