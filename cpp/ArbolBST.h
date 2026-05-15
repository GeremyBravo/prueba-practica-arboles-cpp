#ifndef ARBOLBST_H
#define ARBOLBST_H

#include "Nodo.h"
#include <queue>
using namespace std;

// clase principal del arbol binario de busqueda
// organiza los estudiantes por cedula de menor a mayor
class ArbolBST {
private:
    Nodo* raiz; // puntero a la raiz del arbol

    // --- metodos privados auxiliares recursivos ---

    // inserta un estudiante en el subarbol con raiz en 'nodo'
    Nodo* insertar(Nodo* nodo, Estudiante e);

    // busca un nodo por cedula en el subarbol con raiz en 'nodo'
    Nodo* buscar(Nodo* nodo, string cedula);

    // elimina el nodo con la cedula dada del subarbol
    Nodo* eliminar(Nodo* nodo, string cedula);

    // retorna el nodo con el valor minimo del subarbol (el mas a la izquierda)
    Nodo* encontrarMinimo(Nodo* nodo);

    // recorre el arbol en orden: izquierdo -> raiz -> derecho
    void inorden(Nodo* nodo);

    // recorre el arbol en preorden: raiz -> izquierdo -> derecho
    void preorden(Nodo* nodo);

    // recorre el arbol en postorden: izquierdo -> derecho -> raiz
    void postorden(Nodo* nodo);

    // retorna el numero de nodos del subarbol
    int contarNodos(Nodo* nodo);

    // retorna la altura del subarbol (numero de niveles)
    int calcularAltura(Nodo* nodo);

    // busca el estudiante con la nota mas alta en el subarbol
    void buscarNotaMayor(Nodo* nodo, Nodo*& mejor);

    // busca el estudiante con la nota mas baja en el subarbol
    void buscarNotaMenor(Nodo* nodo, Nodo*& menor);

    // muestra todos los estudiantes con nota >= 7 (aprobados)
    void mostrarAprobados(Nodo* nodo);

    // muestra todos los estudiantes con nota < 7 (reprobados)
    void mostrarReprobados(Nodo* nodo);

public:
    // constructor: inicializa el arbol vacio
    ArbolBST();

    // --- metodos publicos del menu ---

    // inserta un nuevo estudiante en el arbol
    void insertarEstudiante(Estudiante e);

    // busca e imprime un estudiante por cedula
    void buscarEstudiante(string cedula);

    // elimina un estudiante por cedula
    void eliminarEstudiante(string cedula);

    // imprime todos los estudiantes en orden por cedula
    void recorridoInorden();

    // imprime los estudiantes en preorden
    void recorridoPreorden();

    // imprime los estudiantes en postorden
    void recorridoPostorden();

    // recorre el arbol nivel por nivel usando una cola (BFS)
    void recorridoPorNiveles();

    // imprime la cantidad total de estudiantes registrados
    void contarEstudiantes();

    // imprime la altura del arbol
    void mostrarAltura();

    // imprime el estudiante con la nota mas alta
    void buscarNotaMayor();

    // imprime el estudiante con la nota mas baja
    void buscarNotaMenor();

    // imprime todos los estudiantes aprobados (nota >= 7)
    void mostrarAprobados();

    // imprime todos los estudiantes reprobados (nota < 7)
    void mostrarReprobados();
};

#endif
