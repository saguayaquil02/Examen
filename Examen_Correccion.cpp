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

    Funcion mostrarMenu()
    Funcion registrarEstudiantesYNotas()
    Funcion mostrarListado()
    Funcion calcularPromedio()
    Funcion mostrarNotaMayorYMenor()
    Funcion mostrarAprobadosyReprobados()
    Funcion buscarEstudianteNombre()
FinAlgoritmo

Inicio
    mostrarMenu()
    registrarEstudiantesYNotas(...)
    mostrarListado(...)
    calcularPromedio(...)
    mostrarNotaMayorYMenor(...)
    mostrarAprobadosyReprobados(...)
    buscarEstudianteNombre(...)
*/

#include <iostream>
#include <string>
using namespace std;


//
const int max_estudiantes = 20; // maximo de estudiantes
const double Nota_Aprobada = 14.0; // nota minima de aprobacion

// Ptototipos de funciones

void mostrarMenu();
void registrarEstudiantesYNotas(string nombres[], double notas[], int &cantidadActual);
void mostrarListado(string nombres[], double notas[], int cantidadActual);
void calcularMostrarPromedio(double notas[], int cantidadActual);
void mostrarNotaMayorYMenor(string nombres[], double notas[], int cantidadActual);
void mostrarAprobadosReprobados(string nombres[], double notas[], int cantidadActual);
void buscarEstudiante(string nombres[], double notas[], int cantidadActual);

// Funcion principal
int main(){
    // Declaramos los arreglos para ingresar los estudiantes y notas
    string estudiantes[max_estudiantes]; // cadena de texto
    double notas[max_estudiantes];
    
    // Variables de control
    int cantidadActual = 0; // Cuantos productos se han registrado realmente
    int opcion;
    
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        opcion = validarOpcion(1, 7); // Valida que solo elija entre 1 y 7

        switch (opcion) {
            case 1:
                cout << "\n--- REGISTRO DE ESTUDIANTES ---" << endl;
                // Llamamos a registrarEstudiantes

                break;
            case 2:
                cout << "\n--- LISTA DE ESTUDAINTES ---" << endl;
                // Llamamos a mostrarListado

                break;
            case 3:
                cout << "\n--- PROMEDIO ---" << endl;
                // Llamamos a calcularMostrarPromedio

                break;
            case 4:
                cout << "\n--- NOTA MAYOR Y MENOR ---" << endl;
                // Llamamos a la funcion mostrarNotaMayorYMenor
                break;
            case 5:
                cout << "\n--- APROBADOS Y REPROBADOS ---" << endl;
                // Llamamos a la funcion mostrarAprobadosyReprobados
                cout << "\nGracias por usar el sistema Saliendo..." << endl;
                break;

            case 6:
                cout << "\n--- BUSCAR ESTUDIANTE ---" << endl;
                // Llamamos a la funcion buscarEstudiante
                cout << "\nGracias por usar el sistema Saliendo..." << endl;
                break;
            case 7:
                cout << "\nGracias por usar el sistema Saliendo..." << endl;
                break;
        }
    } while (opcion != 7);

    return 0;
}


// Funciones
void mostrarMenu() {
 
    cout << "===== MENU ======" << endl;
    cout << "1. Registrar estudiantes y notas" << endl;
    cout << "2. Mostrar listado completo" << endl;
    cout << "3. Mostrar promedio general" << endl;
    cout << "4. Mostrar nota mayor y nota menor" << endl;
    cout << "5. Mostrar aprobados y reprobados" << endl;
    cout << "6. Buscar estudiante por nombre" << endl;
    cout << "7. Salir" << endl;
}

int validarOpcion(int min, int max) {
    int entrada;
    cin >> entrada;

    // Bucle while para controlar los datos ingresados por si ingresan un número fuera de rango
    while (entrada < min || entrada > max) {
        cout << "Opcion invalida. Ingrese un numero entre " << min << " y " << max << ": ";
        cin >> entrada; // Volver a pedir el dato
    }
    return entrada;
}

// Funcion para ingresar a los estudiantes
void registrarEstudiantesYNotas(string nombres[], double notas[], int &cantidadActual) {
    if (cantidadActual >= max_estudiantes) {
        cout << "Error: El registro esta lleno." << endl;
        return; 
    }

    // Ingresar el texto como una sola palabra
    cout << "Ingrese el nombre (use guion bajo para espacios, ej: Sebastian_Alvear): ";
    cin >> nombres[cantidadActual];

    double nota;
    cout << "Ingrese la nota del estudiante: ";
    cin >> nota;

    notas[cantidadActual] = validarOpcion(0, 20);

    cantidadActual++;
    cout << "Estudiante registrado exitosamente" << endl;
}

void mostrarListado(string nombres[], double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "El listado esta vacio. Registre estudiante primero." << endl;
        return;
    }

    cout << "ID     NOMBRE          NOTA" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < cantidadActual; i++) {
        cout << i + 1 << "      " << nombres[i];
        cout << "            " << notas[i];
    }
    cout << "---------------------------------------------\n";
}

void calcularMostrarPromedio(double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "\n No hay datos para calcular promedio." << endl;
        return;
    }

    float suma = 0;
    for (int i = 0; i < cantidadActual; i++) 
        suma = suma + notas[i];
    cout << "\nPromedio General del curso: " << (suma / cantidadActual) << endl;
}

void mostrarNotaMayorYMenor(string nombres[], double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }

    double mayorNota = notas[0];
    double menorNota = notas[0];
    int indiceMayor = -1;
    int indiceMenor = -1;

    for (int i = 0; i < cantidadActual; i++) {
        if (notas[i] > mayorNota) {
            mayorNota = notas[i];
            indiceMayor = i;
        }
    }

    for (int k = 0; k < cantidadActual; k++)
    {
        if (notas[k] < menorNota)
        {
            menorNota = notas[k];
            indiceMenor = k;
        }
    }
    
    cout << "La nota mas alta es de: '" << nombres[indiceMayor] << "'" << endl;
    cout << "Nota: " << mayorNota << endl;
    cout << "La nota mas baja es de: '" << nombres[indiceMenor] << "'" << endl;
    cout << "Nota: " << mayorNota << endl;

}

void mostrarAprobadosReprobados(string nombres[], double notas[], int cantidadActual){
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }
    
    double aprobado, reprobado;
    int indiceAprobado = -1;
    int indiceReprobado = -1;
    for (int i = 0; i < cantidadActual; i++)
    {
        if (notas[i] >= Nota_Aprobada)
        {
            aprobado = notas[i];
            indiceAprobado = i;
            cout << "'" << nombres[indiceAprobado] << "'" << "Aprobado" << endl;            
        }else if (notas[i] < Nota_Aprobada)
        {
            reprobado = notas[i];
            indiceReprobado = i;
            cout << "'" << nombres[indiceReprobado] << "'" << "Reprobado" << endl;  
        }
    }
}

void buscarEstudiante(string nombres[], double notas[], int cantidadActual){
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }

    cout << "\nIngrese el ID del estudiante: ";
    int id = validarOpcion(1, cantidadActual);
    int indice_ID = id - 1; // restamos menos uno para ubicar la posicion en el arreglo
    
    cout << "Estudiante buscado ID: " << id << "'" << nombres[indice_ID] << "'";
}

