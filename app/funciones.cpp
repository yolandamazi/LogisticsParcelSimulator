#include "header.h"
#include "funciones.h"

using namespace std;

string generarID(){
    string id;
    for (int i = 0; i<=6; i++) {
            if (i==2){
                int randomInt_letra = rand() % 27;
                string letras[27] = {"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "Ñ", "L", "K", "J", "H", "G", "F", "D", "S", "A", "Z", "X", "C", "V", "B", "N", "M"};
                id.append(letras[randomInt_letra]);
            } else {
                int randomInt_numero = rand() % 10;
                string numeros[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
                id.append(numeros[randomInt_numero]);
            };
        };
    return id;
};

string generarNIF(){
    string nif;
    for (int i=0; i<9; i++){
            if(i==8){
                int randomInt_letra= rand() % 27;
                string letras[27] = {"Q","W","E","R","T","Y","U","I","O","P","Ñ","L","K","J","H","G","F","D","S","A","Z","X","C","V","B","N","M"};
                nif.append(letras[randomInt_letra]);
            }else{
                int randomInt_numero = rand() % 10;
                string numeros[10] = {"0","1","2","3","4","5","6","7","8","9"};
                nif.append(numeros[randomInt_numero]);
            };
    };
    return nif;
};

Coordenada generarCoordenadaLatitud(){
    Coordenada latitud;
    int segundos;

    int grados = 40;
    int minutos = 6 + rand() % (7-34);
    if (minutos==34){
        segundos = 0;
    } else {
        segundos = rand() % 60;
    };

    latitud.grado = grados;
    latitud.minuto = minutos;
    latitud.segundo = segundos;

    return latitud;
};

Coordenada generarCoordenadaLongitud(){
    Coordenada longitud;
    int segundos;

    int grados = -3;
    int minutos = 5 + rand() % (6-34);
    if (minutos==34){
        segundos = 0 + rand() % (1-30);
    } else if (minutos==5){
        segundos = 30 + rand() % (31-60);
    } else {
        segundos = rand() % 60;
    };

    longitud.grado = grados;
    longitud.minuto = minutos;
    longitud.segundo = segundos;

    return longitud;
};


Paquete generarPaquete(int CPs[N1]){
    Paquete paquete;

    paquete.nif = generarNIF();
    paquete.longitud = generarCoordenadaLongitud();
    paquete.latitud = generarCoordenadaLatitud();
    paquete.id = generarID();
    paquete.CP = elegirCP(CPs);

    return paquete;
};

int elegirCP(int CPs[N1]){
    int randomInt_CP = rand() % N1;
    return CPs[randomInt_CP];
};

int generarCP(){
    int CP = 1000 + rand() % (1001-9999);
    return CP;
};

string generarLocalidad(){
    int randomInt_localidad = rand() % 14;
    string localidades[14] = {"Ajalvir",
                            "Daganzo",
                            "Alcalá de Henares",
                            "Mejorada del Campo",
                            "Nuevo Baztán",
                            "Arganda del Rey",
                            "Carabaña",
                            "Chinchón",
                            "Villarejo",
                            "Camarma de Esteruelas",
                            "Meco",
                            "Cobeña",
                            "Torres de la Alameda",
                            "Los Santos de la Humosa"};
    return localidades[randomInt_localidad];
}
