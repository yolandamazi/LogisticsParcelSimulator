#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <vector>
#define N1 8
#define N2 100
#define N3 12
#define N4 72

using namespace std;

struct Coordenada{
        int grado;
        int minuto;
        int segundo;
};

struct Paquete{
        string id;
        Coordenada latitud;
        Coordenada longitud;
        string nif;
        int CP;
};

#endif // HEADER_H_INCLUDED
