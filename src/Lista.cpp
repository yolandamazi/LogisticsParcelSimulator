#include "Lista.h"

Lista::Lista(){
    cabecera = NULL;
    fin = NULL;
    actual = NULL;
}

Lista::~Lista(){
    Nodo* aux;
    actual = cabecera;
    while(cabecera){
        aux = cabecera;
        cabecera = cabecera->sig;
        delete aux;
    }
    cabecera=NULL;
    fin=NULL;
    actual=NULL;
}

void Lista::insertar(Paquete p){ //Insertar paquete
    Nodo* aux = new Nodo();

    aux->dato = p;
    aux->ant = NULL;
    aux->sig = NULL;
    if(listaVacia()){
        cabecera = aux;
        fin = aux;
    } else {
        aux->sig = cabecera;
        cabecera->ant = aux;
        cabecera = aux;
    }
}

Paquete Lista::eliminar(){ //Eliminar con metodo FIFO
    Nodo* aux=NULL;
    if (cabecera==fin){
        aux = fin;
        cabecera = NULL;
        fin = NULL;
        return aux->dato;
        delete aux;
    } else {
        aux = fin;
        fin = fin->ant;
        aux->ant = NULL;
        fin->sig = NULL;
        return aux->dato;
        delete aux;
    }
};

bool Lista::listaVacia(){
    return cabecera==NULL;
}

bool Lista::buscarPaquete(string id){ //Buscar paquete por id
    Nodo *aux;
    actual = cabecera;
    aux = cabecera;
    while(aux != NULL){
        if(aux->dato.id == id){
            return true;
        } else {
            aux = aux->sig;
        }
    }
    return false;
}

bool Lista::eliminarPaquete(string id, int cp){ // Eliminar un paquete concreto
    Nodo* aux = NULL;
    Paquete paquete;
    actual = cabecera;
    while(actual != NULL || paquete.CP != cp){
        paquete = actual->dato;
        if (paquete.id == id){
            if (cabecera==fin){
                aux = fin;
                cabecera = NULL;
                fin = NULL;
                delete aux;
            } else if (actual->sig == NULL){
                aux = fin;
                fin = fin->ant;
                aux->ant = NULL;
                fin->sig = NULL;
                delete aux;
            } else if (actual->ant == NULL){
                aux = cabecera;
                cabecera = cabecera->sig;
                aux->sig = NULL;
                cabecera->ant = NULL;
                delete aux;
            } else {
                aux = actual;;
                actual->ant->sig = actual->sig;
                aux->ant = NULL;
                actual->sig->ant = actual->ant;
                aux->sig = NULL;
                delete aux;
            }
            return true;
        } else {
            actual = actual->sig;
        }
    }
    return false;
}

Paquete Lista::devolverPaquete(string id){
    Nodo* aux;
    actual = cabecera;
    aux = cabecera;
    while(aux != NULL){
        if(aux->dato.id != id){
            aux = aux->sig;
        } else {
            return aux->dato;
        }
    }
    return aux->dato;
};

void Lista::reasignarPaquete(int CP) {
    Nodo *aux;
    int nuevoCP;
    actual = cabecera;
    aux = cabecera;
    while (aux->dato.CP == CP){
        aux = aux->sig;
    }
    nuevoCP = aux->dato.CP;
    aux = cabecera;
    while(aux != NULL){
        if(aux->dato.CP == CP){
            aux->dato.CP = nuevoCP;
        } else {
            aux = aux->sig;
        }
    }
};

int Lista::tamano(){
    int t = 0;
    actual = cabecera;
    while (actual != NULL){
        t++;
        actual = actual->sig;
    }
    return t;
}

void Lista::recorrer(int orden){ //Recorrer toda la lista
    Nodo* aux;

    cout << "| "
         << left << setw(15) << "ID" << setw(7)
         << "|"
         << left << setw(14) << "Latitud" << setw(7)
         << "| "
         << left << setw(15) << "Longitud" << setw(9)
         << "| "
         << left << setw(11) << "NIF" << setw(5)
         << "|"
         << right << setw(3) << "CP" << setw(7)
         << "|" << endl
         << setw(96) << setfill('-') << '\n' << setfill( ' ' );
    if (orden==ASCENDENTE){
        actual = cabecera;
        aux = cabecera;
        while(aux != NULL){
            cout << "| "
            << left << setw(15) << aux->dato.id
            << "|"
            << right << setw(6) << aux->dato.latitud.grado << "º ";
            if (aux->dato.latitud.minuto < 10) {
                cout << "0";
            }
            cout << aux->dato.latitud.minuto << "' ";
            if (aux->dato.latitud.segundo < 10) {
                cout << "0";
            }
            cout << aux->dato.latitud.segundo << "''" << setw(6)
            << "| "
            << right << setw(6) << aux->dato.longitud.grado << "º ";
            if (aux->dato.longitud.minuto < 10) {
                cout << "0";
            }
            cout << aux->dato.longitud.minuto << "' ";
            if (aux->dato.longitud.segundo < 10) {
                cout << "0";
            }
            cout << aux->dato.longitud.segundo << "''" << setw(6)
            << "| "
            << right << setw(14) << aux->dato.nif << setw(6)
            << "| "
            << right << setw(7) << aux->dato.CP << setw(6)
            << "|" << endl;
            aux = aux->sig;
        }
    } else {
        actual = fin;
        aux = fin;
        while(aux != NULL){
            cout << "| "
            << left << setw(15) << aux->dato.id
            << "|"
            << right << setw(6) << aux->dato.latitud.grado << "º ";
            if (aux->dato.latitud.minuto < 10) {
                cout << "0";
            }
            cout << aux->dato.latitud.minuto << "' ";
            if (aux->dato.latitud.segundo < 10) {
                cout << "0";
            }
            cout << aux->dato.latitud.segundo << "''" << setw(6)
            << "| "
            << right << setw(6) << aux->dato.longitud.grado << "º ";
            if (aux->dato.longitud.minuto < 10) {
                cout << "0";
            }
            cout << aux->dato.longitud.minuto << "' ";
            if (aux->dato.longitud.segundo < 10) {
                cout << "0";
            }
            cout << aux->dato.longitud.segundo << "''" << setw(6)
            << "| "
            << right << setw(14) << aux->dato.nif << setw(6)
            << "| "
            << right << setw(7) << aux->dato.CP << setw(6)
            << "|" << endl;
            aux = aux->ant;
        }
    }
}

