#include <iostream>
#include "header.h"
#include "funciones.h"
#include <Lista.h>
#include <ABB.h>

using namespace std;

int main(){
    Paquete primerPaquete;
    Lista CAE;
    ABB centralesPaq;
    int cpGenerados[N1];
    int contadorMenu = 0;

    srand(time(NULL));
    setlocale(LC_ALL, "spanish");

    //Generar las centrales de paqueteria
    cout << setw(41) << setfill('-') << '\n' << setfill( ' ' );
    cout << "CENTRALES DE PAQUETERIA \n";
    cout << setw(41) << setfill('-') << '\n' << setfill( ' ' );
    cout << "| "
        << right << setw(5) << "CP" << setw(7)
        << "| "
        << left << setw(25) << "Localidad"
        << "|";
    cout << setw(41) << setfill('-') << '\n' << setfill( ' ' ) << endl;
    for(int i = 0; i < N1; i++){
        int cp = generarCP();
        string localidad = generarLocalidad();
        cpGenerados[i] = cp;
        centralesPaq.insertarNodo(cp, localidad);
        cout << "| "
            << right << setw(6) << cp << setw(6)
            << "| "
            << left << setw(25) << localidad
            << "|" << endl;
    }
    cout << setw(41) << setfill(' ') << '\n' << setfill( ' ' );

    // Generar los paquetes
    primerPaquete.nif = "53801566N";
    primerPaquete.longitud = generarCoordenadaLongitud();
    primerPaquete.latitud = generarCoordenadaLatitud();
    primerPaquete.id = generarID();
    primerPaquete.CP = elegirCP(cpGenerados);
    CAE.insertar(primerPaquete);

    for(int i = 1;i < N2; i++){
        Paquete nuevoPaquete = generarPaquete(cpGenerados);
        CAE.insertar(nuevoPaquete);
    }

    cout << setw(96) << setfill('-') << '\n' << setfill( ' ' ) << endl;
    cout << "CENTRO DE ALMACENAMIENTO ESTE";
    cout << setw(96) << setfill('-') << '\n' << setfill( ' ' ) << endl;
    CAE.recorrer(1);
    cout << setw(96) << setfill('-') << '\n' << setfill( ' ' ) << endl;

    int i = 1;
    int tecla;
    cout << "Pulse enter para empezar" << endl;

    while(!CAE.listaVacia()){
        i++;
        tecla = getchar();
        if (tecla == 10){
            if (contadorMenu < N4){
                for(int iter = 0; iter < N3; iter++){
                    centralesPaq.insertarPaquete(CAE.eliminar());
                    contadorMenu++;
                }
                cout << setw(96) << setfill('-') << '\n' << setfill( ' ' );
                cout << "CENTRO DE ALMACENAMIENTO ESTE \n";
                cout << setw(96) << setfill('-') << '\n' << setfill( ' ' );
                CAE.recorrer(1);
                cout << setw(96) << setfill('-') << '\n' << setfill( ' ' ) << endl;
            } else {
                int c;
                cout << "\n";
                cout << "ELIGA UNA DE LAS SIGUIENTES OPCIONES: \n";
                cout << "1. Insertar una Central de Paquetería \n";
                cout << "2. Borrar una Central de Paquetería \n";
                cout << "3. Mostrar paquetes de una Central de Paquetería \n";
                cout << "4. Estadística de las Centrales de Paquetería de la empresa \n";
                cout << "5. Buscar paquete según su ID \n";
                cout << "6. Extraer paquete concreto de una Central de Paquetería \n";
                cout << "7. Llevar un paquete concreto del CAE a una Central de Paquetería \n";
                cout << "8. Llevar un paquete concreto de una Central de Paquetería a otra \n";
                cout << "9. Continuar la distribución de paquetes \n";
                cout << "0. Salir del programa" << endl;
                cout << "Opción: "; cin >> c;
                if (c > 9){
                    cout << "Eliga una opción correcta: "; cin >> c;
                }
                switch(c) {
                    case 0:
                         return 0;
                         break;
                    case 1:
                         int nuevaCentral;
                         cout << "Introduzca el código postal de la nueva central de paquetería: "; cin >> nuevaCentral;
                         while (nuevaCentral > 9999 || nuevaCentral < 999 || centralesPaq.buscarNodo(nuevaCentral)){
                            if(nuevaCentral > 9999 || nuevaCentral < 999){
                                cout << "Debe introducir un código postal de 4 cifras: "; cin >> nuevaCentral;
                            } else if(centralesPaq.buscarNodo(nuevaCentral)){
                                cout << "Esta central ya existe, introduzca una nueva: "; cin >> nuevaCentral;
                            }
                         }
                         centralesPaq.insertarNodo(nuevaCentral, generarLocalidad());

                         int anadirPaquetes;
                         int nPaquetes;
                         cout << "¿Desea asignarle paquetes a la Central de Paquetería creada? \n";
                         cout << "0. SÍ \n";
                         cout << "1. NO" << endl;
                         cout << "Opción: "; cin >> anadirPaquetes;
                         if (anadirPaquetes > 1){
                            cout << "Eliga una opción correcta: "; cin >> anadirPaquetes;
                         }
                         if (anadirPaquetes == 0){
                            cout << "¿Cuántos paquetes desea asignarle?: "; cin >> nPaquetes;
                            for (int i = 0; i < nPaquetes; i++){
                                Paquete p;
                                p.CP = nuevaCentral;
                                p.id = generarID();
                                p.latitud = generarCoordenadaLatitud();
                                p.longitud = generarCoordenadaLongitud();
                                p.nif = generarNIF();
                                centralesPaq.insertarPaquete(p);
                            }
                         }
                         break;
                    case 2:
                         int eliminarCp;
                         cout << "Introduzca el CP que desee eliminar: "; cin >> eliminarCp;
                         if(centralesPaq.buscarNodo(eliminarCp)){
                            centralesPaq.eliminarNodo(eliminarCp);
                            CAE.reasignarPaquete(eliminarCp);
                            cout << "La CP ha sido eliminada correctamente" << endl;
                         } else {
                            cout << "No se ha encontrado la CP que desea eliminar" << endl;
                         }
                         break;
                    case 3:
                         int mostrarCp;
                         cout << "Introduzca el CP para observar sus paquetes: "; cin >> mostrarCp;
                         if(centralesPaq.buscarNodo(mostrarCp)){
                             cout << setw(96) << setfill('-') << '\n' << setfill( ' ' );
                             centralesPaq.recorrerNodo(mostrarCp).recorrer(0);
                         } else {
                             cout << "No se ha encontrado la CP que desea observar" << endl;
                         }
                         break;
                    case 4:
                         cout << setw(72) << setfill('-') << '\n' << setfill( ' ' )
                            << "| "
                            << right << setw(6) << "CP" << setw(6)
                            << "| "
                            << left << setw(25) << "Localidad" << setw(3)
                            << "| "
                            << right << setw(3) << "F Absoluta" << setw(4)
                            << "| "
                            << right << setw(8) << "F Relativa" << setw(6)
                            << "|\n"
                            << setw(72) << setfill('-') << '\n' << setfill( ' ' );
                         centralesPaq.estadisticoPostOrden(centralesPaq.getRaiz());
                         break;
                    case 5:{
                         string idPaquete;
                         cout << "Introduzca el ID del paquete que desee buscar: "; cin >> idPaquete;
                         int cpPaquete = centralesPaq.buscarPaquetePorId(idPaquete, centralesPaq.getRaiz());
                         if (CAE.buscarPaquete(idPaquete)){
                            cout << "El paquete aún se encuentra en el CAE" << endl;
                         } else if (cpPaquete != 0){
                            cout << "El paquete se encuentra en la central de paquetería con CP: " << cpPaquete << endl;
                         } else {
                            cout << "Este paquete no esta en nuestra CAE o no existe";
                         }
                         break;
                    }
                    case 6:{
                         string eliminarIdPaquete;
                         int eliminarCpPaquete;
                         cout << "Introduzca el ID del paquete que desee eliminar: "; cin >> eliminarIdPaquete;
                         cout << "Introduzca el CP del paquete que desee eliminar: "; cin >> eliminarCpPaquete;
                         if (centralesPaq.buscarNodo(eliminarCpPaquete)){
                            if (centralesPaq.buscarPaquete(eliminarCpPaquete, eliminarIdPaquete)){
                                if (centralesPaq.eliminarPaquete(eliminarCpPaquete, eliminarIdPaquete)) cout << "Paquete eliminado correctamente \n";
                                else cout << "No se ha eliminado el paquete correctamente \n";
                            } else {
                                cout << "El paquete que desea eliminar aún no ha sido trasladado a su CP todavía o no existe \n";
                            }
                         } else {
                            cout << "La CP introducida no existe \n";
                         }
                         break;
                    }
                    case 7:{
                         string moverIdPaquete;
                         int moverCpPaquete;
                         cout << "Introduzca el ID del paquete que desee trasladar: "; cin >> moverIdPaquete;
                         cout << "Introduzca el CP al que lo desee trasladar: "; cin >> moverCpPaquete;
                         if (CAE.buscarPaquete(moverIdPaquete)){
                            if (centralesPaq.buscarNodo(moverCpPaquete)){
                                Paquete moverPaquete;
                                moverPaquete = CAE.devolverPaquete(moverIdPaquete);
                                moverPaquete.CP = moverCpPaquete;
                                if (CAE.eliminarPaquete(moverIdPaquete, moverCpPaquete) && centralesPaq.insertarPaquete(moverPaquete)) cout << "El paquete se ha introducido correctamente \n";
                                else cout << "No se ha introducido el paquete correctamente \n";
                            } else {
                                cout << "Esta CP no existe" << endl;
                            }
                         } else {
                            cout << "Este paquete no está en en el CAE o no existe" << endl;
                         }

                         break;
                    }
                    case 8:{
                         int trasladarCpAntiguo;
                         int trasladarCpNuevo;
                         string trasladarId;
                         cout << "Introduzca el CP al que desee extraer un paquete: "; cin >> trasladarCpAntiguo;
                         cout << "Introduzca el CP al que lo desee trasladar: "; cin >> trasladarCpNuevo;
                         cout << "Introduzca el ID del Paquete que desee trasladar: "; cin >> trasladarId;
                         Lista listaCpAntiguo = centralesPaq.recorrerNodo(trasladarCpAntiguo);
                         if (centralesPaq.buscarNodo(trasladarCpAntiguo) && centralesPaq.buscarNodo(trasladarCpNuevo)){
                            if (listaCpAntiguo.buscarPaquete(trasladarId)){
                                Paquete trasladarPaquete = listaCpAntiguo.devolverPaquete(trasladarId);
                                trasladarPaquete.CP = trasladarCpNuevo;
                                if (centralesPaq.insertarPaquete(trasladarPaquete)){
                                    cout << "El paquete se ha introducido correctamente \n";
                                } else {
                                    cout << "No se ha introducido el paquete correctamente \n";
                                }
                            } else {
                                cout << "El paquete introducido no pertenece a la CP indicada o no existe \n";
                            }
                         } else {
                            cout << "Alguno de los CPs introducido no existe \n" << endl;
                         }
                         break;
                    }
                    case 9:
                         for(int iter = 0; iter < N3; iter++){
                            if (CAE.listaVacia()) break;
                            else centralesPaq.insertarPaquete(CAE.eliminar());
                         }
                         if (!CAE.listaVacia()){
                         cout << setw(96) << setfill('-') << '\n' << setfill( ' ' );
                         cout << "CENTRO DE ALMACENAMIENTO ESTE" << endl;
                         cout << setw(96) << setfill('-') << '\n' << setfill( ' ' );
                         CAE.recorrer(1);
                         cout << setw(96) << setfill('-') << '\n' << setfill( ' ' ) << endl;
                         }
                         break;
                };
            };
            cout << "Pulse enter para continuar" << endl;
        };
    };

    cout << "TODOS LOS PAQUETES HAN SIDO TRASLADADOS A SU CORRESPONDIENTE CENTRAL DE PAQUETERÍA" << endl;
    return 0;
}
