#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
using namespace std;

// clase que representa los datos de un estudiante
class Estudiante {
public:
    string cedula;    // identificador unico del estudiante
    string apellidos; // apellidos del estudiante
    string nombres;   // nombres del estudiante
    float notaFinal;  // nota final entre 0 y 10
    string carrera;   // carrera a la que pertenece
    string nivel;     // nivel o semestre en curso

    // constructor por defecto
    Estudiante();

    // constructor con parametros para inicializar todos los campos
    Estudiante(string cedula, string apellidos, string nombres,
               float notaFinal, string carrera, string nivel);

    // muestra los datos del estudiante en consola
    void mostrar() const;
};

#endif
