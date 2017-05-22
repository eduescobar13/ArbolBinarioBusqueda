//|-----------------------------------------------------------------------|
//| Author   : EDUARDO ESCOBAR ALBERTO                                    |
//| Date     : 12/05/2016                                                 |
//| Comments : Algoritmos y Estructuras de Datos Avanzadas                |
//|            Escuela Técnica Superior de Ingeniería Informática         |
//|            Universidad de La Laguna                                   |
//|                                                                       |
//| Compiling: g++ -g main.cpp DNI.cpp -o arbolBB                         |
//|-----------------------------------------------------------------------|

#define MIN 999999
#define MAX 0

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

#include "DNI.hpp"
#include "ArbolBB.hpp"

using namespace std;

int main(int argc, const char * argv[]) { //-----> FUNCIÓN PRINCIPAL.
 
    int opcion = 50; // Variable para almacenar la opción. Inicializada en un valor diferente de 0.
    int opciondemos = 50; // Variable para almacenar la opción de demostración. Inicializada en un valor diferente de 0.
    int valor_demostracion = 0; // Varible de tipo DNI para realizar operaciones con el árbol.
    char ficheroabb[50]; // Array para almacenar el nombre del fichero.
    ArbolBB<int>* arbol; // Instancia de la clase ArbolBB de tipo int.
    ArbolBB<DNI>* arbol_estadistico; // Instancia de la clase ArbolBB de tipo DNI.

    system("clear");

    cout << endl << "  ___|PRÁCTICA 6: ALGORITMO Y ESTRUCTURAS DE DATOS AVANZADAS|___" << endl;
    
    while (opcion != 0) {

        cout << "---------------- ÁRBOL BINARIO DE BÚSQUEDA -----------------" << endl;
        cout << "[1] MODO DEMOSTRACIÓN" << endl;
        cout << "[2] MODO ESTADÍSTICO" << endl;
        cout << "[0] FIN DEL PROGRAMA" << endl;
        
        cout << "Seleccione el modo deseado: ";
        cin >> opcion; // Lectura de la opción introducida por el usuario.
        
        switch(opcion) {
                
            case 1:{

                system("clear");
                
                arbol = new ArbolBB<int>(); // Creamos un nuevo árbol cada vez que entremos en el menú de demostración.

                while (opciondemos != 0) { // Menú alternativo para la demostración.

                cout << "------------------------------------------------------------" << endl;
                cout << "                 __|MODO DEMOSTRACIÓN|__" << endl;
                cout << "[1] INSERTAR UN ÁRBOL MEDIANTE FICHERO" << endl;
                cout << "[2] INSERTAR UN VALOR EN EL ÁRBOL" << endl;
                cout << "[3] ELIMINAR UN VALOR EN EL ÁRBOL" << endl;
                cout << "[4] MOSTRAR ÁRBOL" << endl;
                cout << "[0] VOLVER EL MENÚ PRINCIPAL" << endl;
                cout << "Seleccione la acción deseada: ";
                cin >> opciondemos;
                    
                    switch (opciondemos) {

                        case 1:{

                            system("clear");

                            cout << "Introduzca el fichero que contiene el árbol [.abb]: ";
                            cin >> ficheroabb; // Lectura del fichero que contine el ejercicio.

                            arbol->insertar_fichero(ficheroabb);

                            break;}
                            
                        case 2:{

                            system("clear");

                            cout << "Introduzca el elemento a insertar: ";
                            cin >> valor_demostracion;

                            arbol->insertar(valor_demostracion);

                            break;}

                        case 3:{

                            system("clear");

                            cout << "Introduzca el elemento a eliminar: ";
                            cin >> valor_demostracion;

                            arbol->eliminar(valor_demostracion);

                            cout << "¡Elemento eliminado!" << endl;

                            break;}

                        case 4:{

                            system("clear");

                            cout << "----------- ÁRBOL BINARIO DE BÚSQUEDA -----------" << endl;
                            arbol->recorre(arbol->get_raiz());

                            break;}
              
                            
                        default:{
                            
                            if (opciondemos != 0) {
                                cout << "¡ERROR! Introduzca una opción correcta" << endl; // Opción incorrecta del usuario.
                            }
                            
                            break;}
                    }
                }
                
                opciondemos = 50; // Reiniciar el valor de opciondemos para evitar conflictos ante una nueva entrada.
                break;}
                
            case 2:{

                int N = 0; // Variables para almacenar el número de nodos.
                int numero_pruebas = 0; // Variable para almacenar el número de pruebas.
                arbol_estadistico = new ArbolBB<DNI>(); // Creamos un nuevo árbol cada vez que entremos en el menú de demostración.
                DNI *banco_pruebas;
                int contador_buscar = 0; // Contador para el número de busquedas.
                int contador_busqueda_max = MAX;
                int contador_busqueda_min = MIN;
                
                cout << "------------------------------------------------------------" << endl;
                cout << "                   __|MODO ESTADÍSTICO|__" << endl;
 
                cout << "Introduzca el número de nodos del árbol: ";
                cin >> N;
                cout << "Introduzca el número de pruebas a realizar: ";
                cin >> numero_pruebas;

                banco_pruebas = new DNI[2 * N]; // Creación de un vector de tipo DNI para generar el banco de pruebas.
                
                for(int i = 0; i < (2 * N); i++) {
                    banco_pruebas[i] = (rand() % 50000000) + 30000000;
                }

                for(int i = 0; i < N; i++) { // Insertamos en el árbol N valores para poder realizar las búsquedas.
                    arbol_estadistico->insertar(banco_pruebas[i]);
                }

                cout << endl << "----------------------- ESTADÍSTICAS ----------------------- " << endl;
                cout << setw(20) << "Mínimo" << setw(10) << "Medio" << setw(10) << "Máximo" << endl;

                //------------------ PRUEBAS PARA LA BÚSQUEDA DE numero_pruebas VALORES INSERTADOS.

                for(int i = 0; i < numero_pruebas; i++) { // Buscamos en el árbol los primeros N valores del banco de pruebas, que están en el árbol.
                    NodoBB<DNI>* nodo = arbol_estadistico->buscar(banco_pruebas[i], contador_buscar);
                }

                if (contador_buscar < contador_busqueda_min) {
                    contador_busqueda_min = contador_buscar;
                }
                if(contador_buscar > contador_busqueda_max) {
                    contador_busqueda_max = contador_buscar;
                }

                cout << "BÚSQUEDA:" << setw(7) << contador_busqueda_min << setw(11) << (contador_busqueda_min + contador_busqueda_max) / 2 << setw(9) << contador_busqueda_max << endl;

                //------------------ PRUEBAS PARA LA BÚSQUEDA DE numero_pruebas VALORES NO INSERTADOS.

                // Reiniciamos los valores de los contadores.
                contador_buscar = 0; // Contador para el número de busquedas.
                contador_busqueda_max = MAX;
                contador_busqueda_min = MIN;
                
                for(int i = 0; i < numero_pruebas; i++) { // Buscamos en el árbol los segundos N valores del banco de pruebas, que no están en el árbol.
                    NodoBB<DNI>* nodo = arbol_estadistico->buscar(banco_pruebas[i + N], contador_buscar);
                }
                
                if (contador_buscar < contador_busqueda_min) {
                    contador_busqueda_min = contador_buscar;
                }
                if(contador_buscar > contador_busqueda_max) {
                    contador_busqueda_max = contador_buscar;
                }

                cout << "INSERCIÓN:" << setw(6) << contador_busqueda_min << setw(11) << (contador_busqueda_min + contador_busqueda_max) / 2 << setw(9) << contador_busqueda_max << endl << endl;

                break;}
                
            default:
                
                if (opcion != 0) {
                    cout << "¡ERROR! Introduzca una opción correcta" << endl; // Mostrar error ante una opción incorrecta del usuario.
                }
                
                break;

        }
    }
    
    cout << "Saliendo del programa..." << endl;
    return(0); // Salida correcta del programa.
}
