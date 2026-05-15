# prueba-practica-arboles-cpp-java

sistema de gestion de estudiantes usando arboles binarios de busqueda (BST)
desarrollado para la asignatura estructura de datos - universidad tecnica de ambato

---

## descripcion

este proyecto implementa un sistema academico que permite gestionar estudiantes
mediante un arbol binario de busqueda organizado por cedula

cada estudiante tiene: cedula, apellidos, nombres, nota final, carrera y nivel

---

## estructura del proyecto

```
prueba-practica-arboles-cpp-java/
└── cpp/
    ├── Estudiante.h      # clase con los datos del estudiante
    ├── Estudiante.cpp
    ├── Nodo.h            # clase nodo del arbol
    ├── Nodo.cpp
    ├── ArbolBST.h        # clase del arbol binario de busqueda
    ├── ArbolBST.cpp
    └── main.cpp          # menu interactivo principal
```

---

## funciones implementadas

- `insertarEstudiante()` - inserta un nuevo estudiante en el arbol
- `buscarEstudiante()` - busca por cedula
- `eliminarEstudiante()` - elimina un estudiante
- `recorridoInorden()` - inorden (izq -> raiz -> der)
- `recorridoPreorden()` - preorden (raiz -> izq -> der)
- `recorridoPostorden()` - postorden (izq -> der -> raiz)
- `recorridoPorNiveles()` - BFS nivel por nivel
- `contarNodos()` - total de estudiantes
- `calcularAltura()` - altura del arbol
- `buscarNotaMayor()` - estudiante con nota maxima
- `buscarNotaMenor()` - estudiante con nota minima
- `mostrarAprobados()` - nota >= 7
- `mostrarReprobados()` - nota < 7

---

## compilacion y ejecucion en linux/mac

```bash
cd cpp
g++ -o sistema main.cpp Estudiante.cpp Nodo.cpp ArbolBST.cpp
./sistema
```

## compilacion y ejecucion en windows

```bash
cd cpp
g++ -o sistema.exe main.cpp Estudiante.cpp Nodo.cpp ArbolBST.cpp
sistema.exe
```

---

## tecnologias usadas

- c++17
- programacion orientada a objetos (clases, encapsulamiento, punteros)
- arboles binarios de busqueda (BST)
- recursividad
- cola STL para BFS

---

## autor

estudiante - estructura de datos - uta
