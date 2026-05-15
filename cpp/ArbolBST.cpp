#include "ArbolBST.h"
#include <iostream>
#include <algorithm>
using namespace std;

// ---- constructor ----

// inicializa el arbol con la raiz en null (arbol vacio)
ArbolBST::ArbolBST() {
    raiz = nullptr;
}

// ---- metodos privados ----

// inserta recursivamente el estudiante en el subarbol
// el criterio de orden es la cedula del estudiante
Nodo* ArbolBST::insertar(Nodo* nodo, Estudiante e) {
    // caso base: posicion vacia, crear nuevo nodo aqui
    if (nodo == nullptr) {
        return new Nodo(e);
    }

    // si la cedula es menor, insertar en el subarbol izquierdo
    if (e.cedula < nodo->dato.cedula) {
        nodo->izquierdo = insertar(nodo->izquierdo, e);
    }
    // si la cedula es mayor, insertar en el subarbol derecho
    else if (e.cedula > nodo->dato.cedula) {
        nodo->derecho = insertar(nodo->derecho, e);
    }
    // si la cedula ya existe, no se inserta duplicado
    else {
        cout << "ya existe un estudiante con cedula: " << e.cedula << endl;
    }

    return nodo;
}

// busca recursivamente un nodo por cedula
Nodo* ArbolBST::buscar(Nodo* nodo, string cedula) {
    // caso base: no encontrado o encontrado
    if (nodo == nullptr || nodo->dato.cedula == cedula) {
        return nodo;
    }

    // si la cedula buscada es menor, ir al subarbol izquierdo
    if (cedula < nodo->dato.cedula) {
        return buscar(nodo->izquierdo, cedula);
    }
    // si es mayor, ir al subarbol derecho
    else {
        return buscar(nodo->derecho, cedula);
    }
}

// retorna el nodo con la cedula minima del subarbol
// se ubica siempre en el nodo mas a la izquierda
Nodo* ArbolBST::encontrarMinimo(Nodo* nodo) {
    while (nodo->izquierdo != nullptr) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

// elimina recursivamente el nodo con la cedula dada
Nodo* ArbolBST::eliminar(Nodo* nodo, string cedula) {
    // caso base: nodo no encontrado
    if (nodo == nullptr) {
        cout << "estudiante no encontrado" << endl;
        return nullptr;
    }

    if (cedula < nodo->dato.cedula) {
        // buscar en el subarbol izquierdo
        nodo->izquierdo = eliminar(nodo->izquierdo, cedula);
    } else if (cedula > nodo->dato.cedula) {
        // buscar en el subarbol derecho
        nodo->derecho = eliminar(nodo->derecho, cedula);
    } else {
        // nodo encontrado: manejar los 3 casos de eliminacion

        // caso 1: nodo hoja (sin hijos), simplemente eliminar
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
            delete nodo;
            return nullptr;
        }

        // caso 2a: solo tiene hijo derecho, reemplazar con ese hijo
        if (nodo->izquierdo == nullptr) {
            Nodo* temp = nodo->derecho;
            delete nodo;
            return temp;
        }

        // caso 2b: solo tiene hijo izquierdo, reemplazar con ese hijo
        if (nodo->derecho == nullptr) {
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }

        // caso 3: tiene dos hijos
        // reemplazar con el sucesor inorden (minimo del subarbol derecho)
        Nodo* sucesor = encontrarMinimo(nodo->derecho);
        nodo->dato = sucesor->dato; // copiar los datos del sucesor
        // eliminar el sucesor del subarbol derecho
        nodo->derecho = eliminar(nodo->derecho, sucesor->dato.cedula);
    }

    return nodo;
}

// recorrido inorden: izquierdo -> nodo -> derecho
// produce los estudiantes ordenados por cedula
void ArbolBST::inorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inorden(nodo->izquierdo);
    nodo->dato.mostrar();
    inorden(nodo->derecho);
}

// recorrido preorden: nodo -> izquierdo -> derecho
void ArbolBST::preorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    nodo->dato.mostrar();
    preorden(nodo->izquierdo);
    preorden(nodo->derecho);
}

// recorrido postorden: izquierdo -> derecho -> nodo
void ArbolBST::postorden(Nodo* nodo) {
    if (nodo == nullptr) return;
    postorden(nodo->izquierdo);
    postorden(nodo->derecho);
    nodo->dato.mostrar();
}

// cuenta recursivamente todos los nodos del subarbol
int ArbolBST::contarNodos(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    // 1 (nodo actual) + nodos del subarbol izquierdo + nodos del subarbol derecho
    return 1 + contarNodos(nodo->izquierdo) + contarNodos(nodo->derecho);
}

// calcula recursivamente la altura maxima del subarbol
int ArbolBST::calcularAltura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    int altIzq = calcularAltura(nodo->izquierdo);
    int altDer = calcularAltura(nodo->derecho);
    // la altura es 1 + la mayor de las alturas de los subarboles
    return 1 + max(altIzq, altDer);
}

// busca el nodo con la nota mas alta recorriendo todo el arbol
void ArbolBST::buscarNotaMayor(Nodo* nodo, Nodo*& mejor) {
    if (nodo == nullptr) return;
    // si no hay mejor aun, o este nodo tiene nota mayor, actualizar
    if (mejor == nullptr || nodo->dato.notaFinal > mejor->dato.notaFinal) {
        mejor = nodo;
    }
    buscarNotaMayor(nodo->izquierdo, mejor);
    buscarNotaMayor(nodo->derecho, mejor);
}

// busca el nodo con la nota mas baja recorriendo todo el arbol
void ArbolBST::buscarNotaMenor(Nodo* nodo, Nodo*& menor) {
    if (nodo == nullptr) return;
    if (menor == nullptr || nodo->dato.notaFinal < menor->dato.notaFinal) {
        menor = nodo;
    }
    buscarNotaMenor(nodo->izquierdo, menor);
    buscarNotaMenor(nodo->derecho, menor);
}

// muestra todos los estudiantes con nota >= 7 (aprobados)
void ArbolBST::mostrarAprobados(Nodo* nodo) {
    if (nodo == nullptr) return;
    mostrarAprobados(nodo->izquierdo);
    if (nodo->dato.notaFinal >= 7.0f) {
        nodo->dato.mostrar();
    }
    mostrarAprobados(nodo->derecho);
}

// muestra todos los estudiantes con nota < 7 (reprobados)
void ArbolBST::mostrarReprobados(Nodo* nodo) {
    if (nodo == nullptr) return;
    mostrarReprobados(nodo->izquierdo);
    if (nodo->dato.notaFinal < 7.0f) {
        nodo->dato.mostrar();
    }
    mostrarReprobados(nodo->derecho);
}

// ---- metodos publicos ----

// llama al insertar privado desde la raiz
void ArbolBST::insertarEstudiante(Estudiante e) {
    raiz = insertar(raiz, e);
    cout << "estudiante insertado correctamente" << endl;
}

// busca el estudiante y lo muestra, o indica que no existe
void ArbolBST::buscarEstudiante(string cedula) {
    Nodo* encontrado = buscar(raiz, cedula);
    if (encontrado != nullptr) {
        cout << "estudiante encontrado:" << endl;
        encontrado->dato.mostrar();
    } else {
        cout << "no se encontro ningun estudiante con cedula: " << cedula << endl;
    }
}

// llama al eliminar privado desde la raiz
void ArbolBST::eliminarEstudiante(string cedula) {
    raiz = eliminar(raiz, cedula);
}

// muestra todos los estudiantes en orden por cedula
void ArbolBST::recorridoInorden() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    cout << "=== recorrido inorden ===" << endl;
    inorden(raiz);
}

// muestra todos los estudiantes en preorden
void ArbolBST::recorridoPreorden() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    cout << "=== recorrido preorden ===" << endl;
    preorden(raiz);
}

// muestra todos los estudiantes en postorden
void ArbolBST::recorridoPostorden() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    cout << "=== recorrido postorden ===" << endl;
    postorden(raiz);
}

// recorre el arbol nivel por nivel usando una cola (BFS - breadth first search)
void ArbolBST::recorridoPorNiveles() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    cout << "=== recorrido por niveles (BFS) ===" << endl;

    queue<Nodo*> cola; // cola para gestionar el orden de visita
    cola.push(raiz);
    int nivel = 1;

    while (!cola.empty()) {
        // procesar todos los nodos del nivel actual
        int tamano = cola.size();
        cout << "--- nivel " << nivel++ << " ---" << endl;

        for (int i = 0; i < tamano; i++) {
            Nodo* actual = cola.front();
            cola.pop();
            actual->dato.mostrar();

            // encolar los hijos para el siguiente nivel
            if (actual->izquierdo != nullptr) cola.push(actual->izquierdo);
            if (actual->derecho != nullptr) cola.push(actual->derecho);
        }
    }
}

// imprime la cantidad total de nodos en el arbol
void ArbolBST::contarEstudiantes() {
    int total = contarNodos(raiz);
    cout << "total de estudiantes registrados: " << total << endl;
}

// imprime la altura actual del arbol
void ArbolBST::mostrarAltura() {
    int altura = calcularAltura(raiz);
    cout << "altura del arbol: " << altura << endl;
}

// imprime el estudiante con la nota mas alta
void ArbolBST::buscarNotaMayor() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    Nodo* mejor = nullptr;
    buscarNotaMayor(raiz, mejor);
    cout << "estudiante con mayor nota:" << endl;
    mejor->dato.mostrar();
}

// imprime el estudiante con la nota mas baja
void ArbolBST::buscarNotaMenor() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    Nodo* menor = nullptr;
    buscarNotaMenor(raiz, menor);
    cout << "estudiante con menor nota:" << endl;
    menor->dato.mostrar();
}

// imprime todos los estudiantes con nota >= 7
void ArbolBST::mostrarAprobados() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    cout << "=== estudiantes aprobados (nota >= 7) ===" << endl;
    mostrarAprobados(raiz);
}

// imprime todos los estudiantes con nota < 7
void ArbolBST::mostrarReprobados() {
    if (raiz == nullptr) {
        cout << "el arbol esta vacio" << endl;
        return;
    }
    cout << "=== estudiantes reprobados (nota < 7) ===" << endl;
    mostrarReprobados(raiz);
}
