#ifndef NODO_H
#define NODO_H

#include "Estudiante.h"

// clase que representa un nodo dentro del arbol binario de busqueda
class Nodo {
public:
    Estudiante dato;  // informacion del estudiante almacenada en el nodo
    Nodo* izquierdo;  // puntero al hijo izquierdo (cedulas menores)
    Nodo* derecho;    // puntero al hijo derecho (cedulas mayores)

    // constructor que recibe un estudiante e inicializa los hijos en null
    Nodo(Estudiante e);
};

#endif
