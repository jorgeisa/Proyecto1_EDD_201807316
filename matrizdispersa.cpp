#include "matrizdispersa.h"


MatrizDispersa::MatrizDispersa()
{
    this->horizontal=NULL;
    this->vertical=NULL;
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
void MatrizDispersa::agregar(NodoObjeto* objeto){
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

//** Metodo para CREAR una CABECERA SI esta NO EXISTE **

//Nos crea una cabecera
NodoCabecera* MatrizDispersa::crearHorizontal(int id){ //Le pasaremos el id (posicion) cabecera
    if(this->horizontal==NULL){
        NodoCabecera* nueva = new NodoCabecera(id);
        this->horizontal=nueva;
        return nueva;
    }
    //Si hay mas nodos
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
        if((id > aux->getId()) && (id < ((NodoCabecera*)aux->getDerecha())->getId())){
            NodoCabecera* nueva = new NodoCabecera(id);
            NodoCabecera* temp = ((NodoCabecera*)aux->getDerecha()); //temp= derecha del actual
            temp->setIzquierda(nueva); //izquierda de la derecha del actual es la nueva
            nueva->setDerecha(temp); //derecha de la nueva es temp
            aux->setDerecha(nueva);  //derecha del actual(aux) es la nueva
            nueva->setIzquierda(aux); //izquierda de la nueva es la actual(aux)
            return nueva;
        }
        aux = ((NodoCabecera*)aux->getDerecha());
    }

    //Si llego a null, es mayor a todos los id
    NodoCabecera *nuevo = new NodoCabecera(id);
    aux->setDerecha(nuevo); //derecha del actual es la nueva
    nuevo->setIzquierda(aux); //izquierda de la nueva es el actual
    return nuevo;
}

NodoCabecera* MatrizDispersa::crearVertical(int id){ //Ingresamos la posicion en Y que no existe
    //Si el this.vertical (inicio de verticales) aun esta NULL
    if(this->vertical==NULL){
        NodoCabecera* nueva = new NodoCabecera(id);
        this->vertical=nueva;
        return nueva;
    }
    //Si ya hay mas nodos
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
        if((id > aux->getId()) && (id < ((NodoCabecera*)aux->getAbajo())->getId())){
            NodoCabecera* nueva = new NodoCabecera(id);
            NodoCabecera* temp = ((NodoCabecera*)aux->getAbajo()); //temp= derecha del actual
            temp->setArriba(nueva); //izquierda de la derecha del actual es la nueva
            nueva->setAbajo(temp); //derecha de la nueva es temp
            aux->setAbajo(nueva);  //derecha del actual(aux) es la nueva
            nueva->setArriba(aux); //izquierda de la nueva es la actual(aux)
            return nueva;
        }
       aux = ((NodoCabecera*)aux->getAbajo());
    }

    //Si llego a null, es mayor a todos los id
    NodoCabecera *nuevo = new NodoCabecera(id);
    aux->setAbajo(nuevo); //derecha del actual es la nueva
    nuevo->setArriba(aux); //izquierda de la nueva es el actual
    return nuevo;
}

//************************************************************************************

//**Metodos para RETORNAR NULL o CABECERA con la posicion x,y que se quiere insertar**

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

//*****************************************************************************************


void MatrizDispersa::mostrar_Posiciones(){
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
            cout<<((NodoObjeto*)aux2)->getIdObjeto()<<" ("<<((NodoObjeto*)aux2)->getPosicionX()<<" , "<<((NodoObjeto*)aux2)->getPosicionY()<<" ) ";
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

void MatrizDispersa::mostrar_Punteros(){
    NodoMatriz *aux,*aux2,*temp,*temp2,*extra,*extra2;
    aux = this->vertical;  //aux=inicio vertical
    temp = this->horizontal; //temp = inicio horizontal

    while(aux!=NULL){ //Recorremos las cabeceras verticalmente
        cout<<"\n\n";
        extra=aux->getAbajo(); //Obtener abajo de cabeza vertical
        aux2=aux->getDerecha(); //Obtener derecha de cabeza vertical

        cout<<"\nSe recorre verticalmente: "<<((NodoCabecera*)aux)->getId();

        while(aux2!=NULL){//mientras la derecha no sea null
            extra2=aux2->getDerecha(); //extra2 es la derecha de la derecha
            cout<<"\nNodo Objeto Recorrido: "<<((NodoObjeto*)aux2)->getIdObjeto();
            cout<<"\nArriba: "<<((NodoCabecera*)aux2->getArriba())->getId();
            cout<<"\nIzquierda: "<<((NodoCabecera*)aux2->getIzquierda())->getId();
            //delete aux2; //eliminamos la primera derecha
            aux2=extra2; //primera derecha esta donde la segunda derecha
        }
        //delete aux; //eliminamos la cabecera vertical
        aux=extra; //aux ahora es el de abajo
    }


    while(temp!=NULL){ //mientras la cabecera horizontal no sea null
        cout<<"\n\n";
        temp2=temp->getDerecha(); //temp2 es la derecha del actual horizontal
        cout<<"\nSe recorre horizontalmente: "<<((NodoCabecera*)temp)->getId();
        //delete temp;  //eliminamos el actual horizontal
        temp=temp2;   //temp se mueve hacia la derecha del eliminado.
    }
}

void MatrizDispersa::generar2(){
   ostringstream cadena;
   int contadorGrupos = 0;

   cadena<<"digraph G {"<<endl<<"node[shape=\"box\"];"<<endl<<"graph[splines=\"ortho\"];"<<endl;

   cadena<<"nodoo[label=\"Pivote\";group="<<contadorGrupos<<"];"<<endl;

   //Cadena a graficar

   NodoMatriz *auxVertical , *auxHorizontal;

   //CREACION Cabeceras Vertical y Horizontal
   auxVertical = this->vertical;
   auxHorizontal = this->horizontal;

   //Recorro Verticalmente para CREAR las cabeceras verticales
   while(auxVertical!=NULL){
       cadena<<"node"<<&(*auxVertical)<<"[label=\""<<((NodoCabecera*)auxVertical)->getId()<<"\" , group="<<contadorGrupos<<"];"<<endl;
       auxVertical = auxVertical->getAbajo();
   }

   contadorGrupos++;

   //Recorro Horizontalmente para CREAR las cabeceras horizontales
   while(auxHorizontal!=NULL){
       cadena<<"node"<<&(*auxHorizontal)<<"[label=\""<<((NodoCabecera*)auxHorizontal)->getId()<<"\" , group="<<contadorGrupos<<"];"<<endl;
       contadorGrupos++;
       auxHorizontal = auxHorizontal->getDerecha();
   }

   //**UNIONES de cabeceras verticales y horizontales entre ellas**

   auxVertical = this->vertical;
   auxHorizontal = this->horizontal;

   //UNION CABECERAS verticales
   while(auxVertical->getAbajo()!=NULL){
       NodoMatriz* nodoAbajo = auxVertical->getAbajo();
       cadena<<"node"<<&(*auxVertical)<<"->node"<<&(*nodoAbajo)<<";"<<endl;
       cadena<<"node"<<&(*nodoAbajo)<<"->node"<<&(*auxVertical)<<";"<<endl;
       auxVertical = auxVertical->getAbajo();
   }

   //UNION CABECERAS horiontales
   while(auxHorizontal->getDerecha()!=NULL){
       NodoMatriz* nodoDerecha = auxHorizontal->getDerecha();
       cadena<<"node"<<&(*auxHorizontal)<<"->node"<<&(*nodoDerecha)<<";"<<endl;
       cadena<<"node"<<&(*nodoDerecha)<<"->node"<<&(*auxHorizontal)<<";"<<endl;
       auxHorizontal = auxHorizontal->getDerecha();
   }

   //**CREAR Nodos Objeto - Recorro primero horizontal y luego vertical para crear grupos de "Nodos Objeto"**
   auxHorizontal = this->horizontal;
   auxVertical = this->vertical;
   contadorGrupos = 1;

   while(auxHorizontal!=NULL){

       NodoObjeto* auxObjeto = ((NodoObjeto*)auxHorizontal->getAbajo());

       while(auxObjeto!=NULL){
           string letra = ((NodoObjeto*)auxObjeto)->getLetra();
           string color = ((NodoObjeto*)auxObjeto)->getColor();
           int posicionX = ((NodoObjeto*)auxObjeto)->getPosicionX();
           int posicionY = ((NodoObjeto*)auxObjeto)->getPosicionY();
           cadena<<"node"<<&(*auxObjeto)<<"[label=\""<<letra<<" , "<<color<<" ("<<posicionX<<" , "<<posicionY<<" )"<<"\" , group="<<contadorGrupos<<"];"<<endl;
           auxObjeto = ((NodoObjeto*)auxObjeto->getAbajo());
       }
       contadorGrupos++;
       auxHorizontal = auxHorizontal->getDerecha();
   }


   //**UNIONES VERTICALES NODOS OBJETO - Recorro horizontalmente y luego verticalmente**
   auxHorizontal = this->horizontal;
   auxVertical = this->vertical;

   while(auxHorizontal!=NULL){

       NodoObjeto* auxObjeto = ((NodoObjeto*)auxHorizontal->getAbajo());

       cadena<<"node"<<&(*auxHorizontal)<<"->node"<<&(*auxObjeto)<<";"<<endl;
       cadena<<"node"<<&(*auxObjeto)<<"->node"<<&(*auxHorizontal)<<";"<<endl;

       while(auxObjeto->getAbajo()!=NULL){
           cadena<<"node"<<&(*auxObjeto)<<"->node"<<&(*auxObjeto->getAbajo())<<";"<<endl;
           cadena<<"node"<<&(*auxObjeto->getAbajo())<<"->node"<<&(*auxObjeto)<<";"<<endl;
           auxObjeto = ((NodoObjeto*)auxObjeto->getAbajo());
       }

       auxHorizontal = auxHorizontal->getDerecha();
   }

   //**UNIONES HORIZONTALES NODOS OBJETO - Recorro Verticalmente y luego Horizontalmente**

   auxHorizontal = this->horizontal;
   auxVertical = this->vertical;

   while(auxVertical!=NULL){

       NodoObjeto* auxObjeto = ((NodoObjeto*)auxVertical->getDerecha());

       cadena<<"node"<<&(*auxVertical)<<"->node"<<&(*auxObjeto)<<";"<<endl;
       cadena<<"node"<<&(*auxObjeto)<<"->node"<<&(*auxVertical)<<";"<<endl;

       while(auxObjeto->getDerecha()!=NULL){
           cadena<<"node"<<&(*auxObjeto)<<"->node"<<&(*auxObjeto->getDerecha())<<";"<<endl;
           cadena<<"node"<<&(*auxObjeto->getDerecha())<<"->node"<<&(*auxObjeto)<<";"<<endl;
           auxObjeto = ((NodoObjeto*)auxObjeto->getDerecha());
       }
       auxVertical = auxVertical->getAbajo();
   }

   cadena<<"{rank=\"same\";nodoo;";

   auxHorizontal = this->horizontal;
   auxVertical = this->vertical;

   while(auxHorizontal!=NULL){
       cadena<<"node"<<&(*auxHorizontal)<<";";
       auxHorizontal = auxHorizontal->getDerecha();
   }

   cadena<<"};"<<endl;

   auxHorizontal = this->horizontal;
   auxVertical = this->vertical;

   cadena<<"nodoo->node"<<&(*auxHorizontal)<<endl;
   cadena<<"nodoo->node"<<&(*auxVertical)<<endl;

   while(auxVertical!=NULL){
       cadena<<"{rank=\"same\";"<<"node"<<auxVertical<<";";
       NodoObjeto* auxObjeto = ((NodoObjeto*)auxVertical->getDerecha());
       while(auxObjeto!=NULL){
           cadena<<"node"<<&(*auxObjeto)<<";";
           auxObjeto = ((NodoObjeto*)auxObjeto->getDerecha());
       }

       cadena<<"};"<<endl;
       auxVertical = auxVertical->getAbajo();
   }


   //Termina Cadena a graficar
   cadena<<"}"<<endl;
   ofstream file("salida.dot");
   file<<cadena.str();


//   system("circo -Tpng salida.dot -o imagen.png");
   system("dot -Tpng salida.dot -o imagen.png");
//   system("C:\\Users\\Isaac\\Desktop\\imagen.png");
   system("\"C:\\Users\\Isaac\\Desktop\\2S2020\\Estructuras de Datos\\Laboratorio\\EDD_2S2020 - Proyectos Git\\EDD_Project1_2S2020\\build-EDD_Project1_2S2020-Desktop_Qt_5_15_0_MinGW_64_bit-Debug\\imagen.png\"");
   file.close();
   cout<<"\n\n";
   cout<<cadena.str()<<endl;
}



