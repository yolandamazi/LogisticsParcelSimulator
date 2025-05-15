#include "ABB.h"
#include <../funciones.h>

void ABB::podar(Nodo *&n){
    if(n){
        podar(n->izq);
        podar(n->der);
        delete n;
        n = NULL;
    }
}

ABB::ABB(){
    raiz = NULL;
    actual = NULL;
}

ABB::~ABB(){
    podar(raiz);
}

bool ABB::buscarNodo(int CP){
    actual = raiz;
    while(actual != NULL){
        if (CP == actual->CP){
            return true;
        } else if (CP > actual->CP){
            actual = actual->der;
        } else if (CP < actual->CP){
            actual = actual->izq;
        }
    }
    return false;
};

void ABB::insertarNodo(int CP, string localidad){
    Nodo *padre = NULL;
    actual = raiz;
    while(actual != NULL && CP != actual->CP){
        padre = actual;
        if (CP > actual->CP) actual = actual->der;
        else if (CP < actual->CP) actual = actual->izq;
    }
    if (actual != NULL) return;
    if (padre == NULL){
        raiz = new Nodo();
        raiz->CP = CP;
        raiz->localidad = localidad;
    } else if (CP < padre->CP){
        padre->izq = new Nodo();
        padre->izq->CP = CP;
        padre->izq->localidad = localidad;
    } else if (CP > padre->CP){
        padre->der = new Nodo();
        padre->der->CP = CP;
        padre->der->localidad = localidad;
    }
};

void ABB::eliminarNodo(int CP){
    Nodo *padre = NULL;
    Nodo *nodo;
    char aux;
    actual = raiz;
    while (actual != NULL){
        if (CP == actual->CP){
            if (!actual->der && !actual->izq){
                if (padre){
                    if (padre->der == actual) padre->der = NULL;
                    else if (padre->izq == actual) padre->izq = NULL;
                }
                delete actual;
                actual = NULL;
                return;
            } else {
                padre = actual;
                if (actual->der){
                    nodo = actual->der;
                    while(nodo->izq){
                        padre = nodo;
                        nodo = nodo->izq;
                    }
                } else {
                    nodo = actual->izq;
                    while(nodo->der){
                        padre = nodo;
                        nodo = nodo->der;
                    }
                }
                aux = actual->CP;
                actual->CP = nodo->CP;
                nodo->CP = aux;
                actual = nodo;
            }
        } else {
            padre = actual;
            if (CP > actual->CP) actual = actual->der;
            else if (CP<actual->CP) actual = actual->izq;
        }
    }
};

Lista ABB::recorrerNodo(int CP){
    actual = raiz;
    while(actual != NULL){
        if (CP == actual->CP){
            return actual->dato;
        } else if (CP > actual->CP){
            actual = actual->der;
        } else if (CP < actual->CP){
            actual = actual->izq;
        }
    }
    return actual->dato;
}

bool ABB::buscarPaquete(int cpPaquete, string idPaquete){
    actual = raiz;
    while(actual != NULL){
        if (cpPaquete == actual->CP){
            if (actual->dato.buscarPaquete(idPaquete)){
                return true;
            }
        } else {
            if (cpPaquete > actual->CP) actual = actual->der;
            else if (cpPaquete < actual->CP) actual = actual->izq;
        }
    }
    return false;
};

int ABB::buscarPaquetePorId(string idPaquete, Nodo *n){
    int res, resraiz, resder, resizq;
    if (n != NULL){
        if (n->dato.buscarPaquete(idPaquete)){
            resraiz = n->CP;
            resder = 0;
            resizq = 0;
        } else {
            resraiz = 0;
            resder = buscarPaquetePorId(idPaquete, n->der);
            resizq = buscarPaquetePorId(idPaquete, n->izq);
        }
    } else {
        resraiz = 0;
        resder = 0;
        resizq = 0;
    }
    res = resraiz + resder + resizq;
    return res;
}

bool ABB::insertarPaquete(Paquete p){
    actual = raiz;
    while(actual != NULL){
        if (p.CP == actual->CP){
            actual->dato.insertar(p);
            return true;
        } else {
            if (p.CP > actual->CP) actual = actual->der;
            else if (p.CP < actual->CP) actual = actual->izq;
        }
    }
    return false;
};

bool ABB::eliminarPaquete(int cpPaquete, string idPaquete){
    actual = raiz;
    while(actual != NULL){
        if (actual->dato.buscarPaquete(idPaquete) == cpPaquete){
            if (actual->dato.eliminarPaquete(idPaquete, cpPaquete)) return true;
        } else {
            if (cpPaquete > actual->CP) actual = actual->der;
            else if (cpPaquete < actual->CP) actual = actual->izq;
        }
    }
    return false;
};

int ABB::totalPaquetes(Nodo *n){
    if (n != NULL){
        return n->dato.tamano() + totalPaquetes(n->der) + totalPaquetes(n->izq);
    }
    return 0;
}

void ABB::estadisticoPostOrden(Nodo *n){
    float total = totalPaquetes(raiz);
    if (n != NULL){
        estadisticoPostOrden(n->izq);
        estadisticoPostOrden(n->der);
        cout << "| "
            << right << setw(6) << n->CP << setw(6)
            << "| "
            << left << setw(25) << n->localidad << setw(6)
            << "| "
            << left << setw(9) << n->dato.tamano() << setw(6)
            << "| "
            << left << setw(10) << float(n->dato.tamano())/total << setw(20)
            << "|" << endl;
    }
};
