#ifndef ABB_H
#define ABB_H
#include <../header.h>
#include <Lista.h>

class ABB{
    struct Nodo {
        int CP;
        string localidad;
        Lista dato;
        Nodo *izq;
        Nodo *der;
    };

    private:
        Nodo* raiz;
        Nodo* actual;
        int contador;
        int altura;
        void podar (Nodo *&n);

    public:
        ABB();
        ~ABB();
        bool buscarNodo(int CP);
        void insertarNodo(int CP, string localidad);
        void eliminarNodo(int CP);
        Lista recorrerNodo(int CP);
        bool buscarPaquete(int cpPaquete, string idPaquete);
        int buscarPaquetePorId(string idPaquete, Nodo *n);
        bool insertarPaquete(Paquete p);
        bool eliminarPaquete(int cpPaquete, string idPaquete);
        int totalPaquetes(Nodo *n);
        Nodo* getRaiz() {return raiz; };
        void estadisticoPostOrden(Nodo *n);
};

#endif // ABB_H
