/*
Nombre del estudiante: Sebastian Guayaquil
Curso: Bootcamp Programación Cero a POO
Clase: 10 - Examen 1 (C++)
Fecha: 13/05/2026

Tema:
Sistema de registro y análisis de notas de estudiantes

E/P/S
Entrada:
- Cantidad de estudiantes
- Nombres de estudiantes
- Nota de cada estudiante

Proceso:
- Validar datos ingresados
- Almacenar información en arreglos
- Calcular promedio general
- Buscar una nota mayor y una nota menor
- Mostrar reporte de aprobados y reprobados
- Permitir consultar un estudiante por nombre

Salida:
- Listado de estudiantes y notas
- Promedio general
- Nota mayor y nota menor
- Cantidad de aprobados y reprobados
- Resultado de búsqueda por nombre

ENUNCIADO DEL PROBLEMA: Una academia desea llevar un control básico de las notas de un grupo de estudiantes mediante un programa en C++. Se requiere desarrollar un sistema que permita registrar y analizar las calificaciones de un grupo pequeño de estudiantes usando arreglos unidimensionales y
funciones.

*/

/*
PSEUDOCODIGO

Algoritmo ControlDeNotasEstudiantes
    Definir estudiantes como entero
    Definir nombres como cadena de caracteres
    Definir nota como double

    Mostrar un menu
    Registrar estudiantes y Notas
    Mostrar listado completo
    Calcualr Promedio
    Mostrar Nota Mayor y menor
    Mostrar aprobados y reprobados
    Buscar Estudiante por nombre

    Funcion mostrarMenu
    Funcion registrarEstudiantesYNotas
    Funcion mostrarListado
    Funcion calcularPromedio
    Funcion mostrarNotaMayorMenor
    Funcion mostrarAprobadosyReprobados
    Funcion buscarEstudianteNombre
FinAlgoritmo

*/

#include <iostream>
using namespace std;


//
int max_estudiantes = 20; // maximo de estudiantes
float Nota_Aprobada = 14.0; // nota minima de aprobacion

// Ptototipos de funciones

int mostrarMenu();
int registrarEstudiantes(string nombres[]);
void registrarNotas(const string nombres[], float notas[], int cantidad);
void mostrarListado(const string nombres[], const float notas[], int cantidad);
void calcularMostrarPromedio(const float notas[], int cantidad);
void mostrarNotaMayorMenor(const string nombres[], const float notas[], int cantidad);
void mostrarAprobadosReprobados(const float notas[], int cantidad);
void buscarEstudiante(const string nombres[], const float notas[], int cantidad);

int main() {
    string listaNombres[max_estudiantes];
    float listaNotas[max_estudiantes];
    int cantidadActual = 0;
    int opcion;

    do {
        opcion = mostrarMenu(); // Llamada a la función del menú

        switch (opcion) {
            case 1:
                // Primero registramos nombres y obtenemos la cantidad
                cantidadActual = registrarEstudiantes(listaNombres);
                // Luego registramos las notas para esos nombres
                registrarNotas(listaNombres, listaNotas, cantidadActual);
                break;
            case 2:
                mostrarListado(listaNombres, listaNotas, cantidadActual);
                break;
            case 3:
                calcularMostrarPromedio(listaNotas, cantidadActual);
                break;
            case 4:
                mostrarNotaMayorMenor(listaNombres, listaNotas, cantidadActual);
                break;
            case 5:
                mostrarAprobadosReprobados(listaNotas, cantidadActual);
                break;
            case 6:
                buscarEstudiante(listaNombres, listaNotas, cantidadActual);
                break;
            case 7:
                cout << "\nSaliendo del programa\n";
                break;
            default:
                cout << "\n[!] Opcion invalida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 7);

    return 0;
}


int mostrarMenu() {
    int op;
    cout << "\n=========== MENU DE GESTION DE ESTUDIANTES ===========" << endl;
    cout << "1. Registrar estudiantes y notas" << endl;
    cout << "2. Mostrar listado completo" << endl;
    cout << "3. Mostrar promedio general" << endl;
    cout << "4. Mostrar nota mayor y nota menor" << endl;
    cout << "5. Mostrar aprobados y reprobados" << endl;
    cout << "6. Buscar estudiante por nombre" << endl;
    cout << "7. Salir" << endl;
    cout << "=======================================" << endl;
    cout << "Seleccione una opcion: ";

    return op;
}
 
// Funciones

// Función que registra los estudiantes 
int registrarEstudiantes(string nombres[]) {
    int cantidad = 0;

    // 1. Validación de la cantidad de estudiantes (entre 1 y 20)
    do {
        cout << "Ingrese la cantidad de estudiantes a registrar (1 - " << max_estudiantes << "): ";
        cin >> cantidad;

        if (cantidad < 1 || cantidad > max_estudiantes) {
            cout << "Error: La cantidad debe estar estrictamente entre 1 y " << max_estudiantes << endl;
        }
    } while (cantidad < 1 || cantidad > max_estudiantes);

    cout << "--- Ingreso de Nombres ---" << endl;
    
    // Bucle para ingresar los nombres en el arreglo
    for (int i = 0; i < cantidad; i++) {
        string nombreEstudiante;

        // Guardamos el nombre validado en el arreglo
        nombres[i] = nombreEstudiante;
    }

    return cantidad; // Retornamos cuántos estudiantes se registraron
}

void registrarNotas(const string nombres[], float notas[], int cantidad) {
    cout << "\n--- Registro de Calificaciones ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        do {
            cout << "Nota para " << nombres[i] << " (0-20): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 20)
                cout << "Error: La nota debe estar entre 0 y 20.\n";
        } while (notas[i] < 0 || notas[i] > 20);
    }
    cout << "Datos guardados correctamente." << endl;
}

void mostrarListado(const string nombres[], const float notas[], int cantidad) {
    if (cantidad == 0) {
        cout << " No hay estudiantes registrados." << endl;
        return;
    }
    cout << "\n--- LISTADO COMPLETO ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}

void calcularMostrarPromedio(float notas[], int cantidad) {
    if (cantidad == 0) {
        cout << "\n No hay datos para calcular promedio." << endl;
        return;
    }
    float suma = 0;
    for (int i = 0; i < cantidad; i++) suma += notas[i];
    cout << "\nPromedio General del curso: " << (suma / cantidad) << endl;
}


