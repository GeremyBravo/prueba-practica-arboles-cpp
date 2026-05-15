#include "Estudiante.h"
#include <iostream>
using namespace std;

// constructor por defecto
Estudiante::Estudiante() {
    cedula = "";
    apellidos = "";
    nombres = "";
    notaFinal = 0.0f;
    carrera = "";
    nivel = "";
}

// constructor con todos los campos del estudiante
Estudiante::Estudiante(string cedula, string apellidos, string nombres,
                       float notaFinal, string carrera, string nivel) {
    this->cedula = cedula;
    this->apellidos = apellidos;
    this->nombres = nombres;
    this->notaFinal = notaFinal;
    this->carrera = carrera;
    this->nivel = nivel;
}

// imprime en consola la informacion completa del estudiante
void Estudiante::mostrar() const {
    cout << "--------------------------------" << endl;
    cout << "cedula   : " << cedula << endl;
    cout << "apellidos: " << apellidos << endl;
    cout << "nombres  : " << nombres << endl;
    cout << "nota     : " << notaFinal << endl;
    cout << "carrera  : " << carrera << endl;
    cout << "nivel    : " << nivel << endl;
    cout << "--------------------------------" << endl;
}
