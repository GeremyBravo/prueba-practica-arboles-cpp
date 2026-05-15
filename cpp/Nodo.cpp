#include "Nodo.h"

// inicializa el nodo con el estudiante dado y los punteros hijos en null
Nodo::Nodo(Estudiante e) {
    dato = e;
    izquierdo = nullptr;
    derecho = nullptr;
}
