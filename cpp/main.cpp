#include <iostream>
#include <limits>
#include "ArbolBST.h"
using namespace std;

// muestra el menu principal en consola
void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "  sistema de gestion de estudiantes     " << endl;
    cout << "  universidad tecnica de ambato          " << endl;
    cout << "========================================" << endl;
    cout << "  1.  insertar estudiante               " << endl;
    cout << "  2.  buscar estudiante por cedula      " << endl;
    cout << "  3.  eliminar estudiante               " << endl;
    cout << "  4.  recorrido inorden                 " << endl;
    cout << "  5.  recorrido preorden                " << endl;
    cout << "  6.  recorrido postorden               " << endl;
    cout << "  7.  recorrido por niveles (BFS)       " << endl;
    cout << "  8.  contar estudiantes                " << endl;
    cout << "  9.  calcular altura del arbol         " << endl;
    cout << " 10.  estudiante con mayor nota         " << endl;
    cout << " 11.  estudiante con menor nota         " << endl;
    cout << " 12.  mostrar aprobados                 " << endl;
    cout << " 13.  mostrar reprobados                " << endl;
    cout << " 14.  salir                             " << endl;
    cout << "========================================" << endl;
    cout << "seleccione una opcion: ";
}

// lee una nota valida entre 0 y 10
float leerNota() {
    float nota;
    while (true) {
        cout << "nota final (0-10): ";
        cin >> nota;
        if (cin.fail() || nota < 0.0f || nota > 10.0f) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "nota invalida, ingrese un valor entre 0 y 10" << endl;
        } else {
            cin.ignore();
            return nota;
        }
    }
}

int main() {
    // crear el arbol binario de busqueda para los estudiantes
    ArbolBST arbol;

    // cargar algunos datos de prueba para facilitar las pruebas iniciales
    arbol.insertarEstudiante(Estudiante("1804000001", "Perez Lopez", "Juan Carlos", 8.5f, "sistemas", "3ro"));
    arbol.insertarEstudiante(Estudiante("1804000002", "Garcia Mora", "Maria Jose", 6.0f, "civil", "2do"));
    arbol.insertarEstudiante(Estudiante("1804000003", "Torres Salas", "Luis Miguel", 9.2f, "mecanica", "5to"));
    arbol.insertarEstudiante(Estudiante("1804000004", "Sanchez Rios", "Ana Lucia", 4.5f, "electronica", "1ro"));
    arbol.insertarEstudiante(Estudiante("1804000005", "Flores Vega", "Pedro Antonio", 7.0f, "sistemas", "4to"));

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // limpiar el buffer despues de leer el entero

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "opcion invalida" << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                // leer los datos del nuevo estudiante
                Estudiante e;
                cout << "cedula    : "; getline(cin, e.cedula);
                cout << "apellidos : "; getline(cin, e.apellidos);
                cout << "nombres   : "; getline(cin, e.nombres);
                e.notaFinal = leerNota();
                cout << "carrera   : "; getline(cin, e.carrera);
                cout << "nivel     : "; getline(cin, e.nivel);
                arbol.insertarEstudiante(e);
                break;
            }
            case 2: {
                string cedula;
                cout << "cedula a buscar: "; getline(cin, cedula);
                arbol.buscarEstudiante(cedula);
                break;
            }
            case 3: {
                string cedula;
                cout << "cedula a eliminar: "; getline(cin, cedula);
                arbol.eliminarEstudiante(cedula);
                break;
            }
            case 4:
                arbol.recorridoInorden();
                break;
            case 5:
                arbol.recorridoPreorden();
                break;
            case 6:
                arbol.recorridoPostorden();
                break;
            case 7:
                arbol.recorridoPorNiveles();
                break;
            case 8:
                arbol.contarEstudiantes();
                break;
            case 9:
                arbol.mostrarAltura();
                break;
            case 10:
                arbol.buscarNotaMayor();
                break;
            case 11:
                arbol.buscarNotaMenor();
                break;
            case 12:
                arbol.mostrarAprobados();
                break;
            case 13:
                arbol.mostrarReprobados();
                break;
            case 14:
                cout << "saliendo del sistema..." << endl;
                break;
            default:
                cout << "opcion invalida, intente de nuevo" << endl;
        }

    } while (opcion != 14);

    return 0;
}
