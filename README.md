## Descripcion

Sistema academico desarrollado en C++ que permite gestionar estudiantes utilizando un Arbol Binario de Busqueda (BST) organizado por numero de cedula.

Cada estudiante contiene:
- Cedula (clave de orden)
- Apellidos
- Nombres
- Nota final (0-10)
- Carrera
- Nivel / Semestre

## Funcionalidades

| Opcion | Funcion | Descripcion |
|--------|---------|-------------|
| 1 | Insertar estudiante | Agrega un nuevo estudiante al arbol (sin cedulas duplicadas) |
| 2 | Buscar por cedula | Encuentra y muestra los datos de un estudiante |
| 3 | Eliminar estudiante | Elimina un estudiante del arbol manteniendo el orden |
| 4 | Recorrido Inorden | Muestra estudiantes ordenados por cedula (menor a mayor) |
| 5 | Recorrido Preorden | Muestra raiz -> izquierda -> derecha |
| 6 | Recorrido Postorden | Muestra izquierda -> derecha -> raiz |
| 7 | Recorrido por niveles (BFS) | Muestra el arbol nivel por nivel usando una cola |
| 8 | Contar estudiantes | Muestra el total de estudiantes registrados |
| 9 | Calcular altura | Muestra la altura del arbol (niveles desde la raiz hasta la hoja mas profunda) |
| 10 | Estudiante con mayor nota | Encuentra y muestra al estudiante con la nota mas alta |
| 11 | Estudiante con menor nota | Encuentra y muestra al estudiante con la nota mas baja |
| 12 | Mostrar aprobados | Lista estudiantes con nota >= 7 |
| 13 | Mostrar reprobados | Lista estudiantes con nota < 7 |
| 14 | Salir | Termina la ejecucion del programa |

## Estructura del Proyecto

```
prueba-practica-arboles-cpp-java/
└── cpp/
    ├── Estudiante.h      # Clase con los datos del estudiante
    ├── Estudiante.cpp
    ├── Nodo.h            # Clase nodo del arbol
    ├── Nodo.cpp
    ├── ArbolBST.h        # Clase del arbol binario de busqueda
    ├── ArbolBST.cpp
    ├── main.cpp          # Menu interactivo principal
    └── README.md
```

## Compilacion y Ejecucion


### Windows

```bash
cd cpp
g++ -o sistema.exe main.cpp Estudiante.cpp Nodo.cpp ArbolBST.cpp
sistema.exe
```


## Tecnologias Utilizadas

- C++17
- Programacion Orientada a Objetos
- Arboles Binarios de Busqueda (BST)
- Recursividad
- Cola STL para BFS
- Git y GitHub

## Datos de Prueba

El programa incluye 5 estudiantes de prueba al iniciar:

| Cedula | Apellidos | Nombres | Nota | Carrera | Nivel |
|--------|-----------|---------|------|---------|-------|
| 1804000001 | Perez Lopez | Juan Carlos | 8.5 | sistemas | 3ro |
| 1804000002 | Garcia Mora | Maria Jose | 6.0 | civil | 2do |
| 1804000003 | Torres Salas | Luis Miguel | 9.2 | mecanica | 5to |
| 1804000004 | Sanchez Rios | Ana Lucia | 4.5 | electronica | 1ro |
| 1804000005 | Flores Vega | Pedro Antonio | 7.0 | sistemas | 4to |


