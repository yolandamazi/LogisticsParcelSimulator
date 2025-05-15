#ifndef LISTA_H
#define LISTA_H
#include "../header.h"

const int ASCENDENTE = 0;
const int DESCENDENTE = 1;

struct Nodo {
        Paquete dato;
        Nodo *sig;
        Nodo *ant;
};

class Lista {
    private:
        Nodo* cabecera;
        Nodo* fin;
        Nodo* actual;
    public:
        Lista();
        ~Lista();
        void insertar(Paquete p);
        Paquete eliminar();
        bool listaVacia();
        int tamano();
        bool buscarPaquete(string id);
        bool eliminarPaquete(string id, int cp);
        void reasignarPaquete(int CP);
        Paquete devolverPaquete(string id);
        void recorrer(int orden);
        Nodo* getCabecera() {return cabecera; };
};

#endif // LISTA_H
