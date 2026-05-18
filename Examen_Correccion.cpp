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
int validarOpcion(int min, int max);
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
    double notasEstudiantes[max_estudiantes];
    
    // Variables de control
    int cantidadActual = 0; // variable para controlar cuantos estudiantes se han registrado
    int opcion;
    
    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        opcion = validarOpcion(1, 7); // Valida que solo elija entre 1 y 7

        switch (opcion) {
            case 1:
                cout << "\n--- REGISTRO DE ESTUDIANTES ---" << endl;
                // Llamamos a la funcion registrarEstudiantes
                registrarEstudiantesYNotas(estudiantes, notasEstudiantes, cantidadActual);

                break;
            case 2:
                cout << "\n--- LISTA DE ESTUDIANTES ---" << endl;
                // Llamamos a la funcion mostrarListado
                mostrarListado(estudiantes, notasEstudiantes, cantidadActual);
                break;
            case 3:
                cout << "\n--- PROMEDIO ---" << endl;
                // Llamamos a la funcion calcularMostrarPromedio
                calcularMostrarPromedio(notasEstudiantes, cantidadActual);
                break;
            case 4:
                cout << "\n--- NOTA MAYOR Y MENOR ---" << endl;
                // Llamamos a la funcion mostrarNotaMayorYMenor
                mostrarNotaMayorYMenor(estudiantes, notasEstudiantes, cantidadActual);
                break;
            case 5:
                cout << "\n--- APROBADOS Y REPROBADOS ---" << endl;
                // Llamamos a la funcion mostrarAprobadosyReprobados
                mostrarAprobadosReprobados(estudiantes, notasEstudiantes, cantidadActual);
                break;

            case 6:
                cout << "\n--- BUSCAR ESTUDIANTE ---" << endl;
                // Llamamos a la funcion buscarEstudiante
                buscarEstudiante(estudiantes, notasEstudiantes, cantidadActual);
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
 
    cout << "\n============= MENU =============" << endl;
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
    cout << "Ingrese el nombre (use guion bajo para espacios, ej: Mateo_Perez): ";
    cin >> nombres[cantidadActual];

    double nota;
    cout << "Ingrese la nota del estudiante: ";
    cin >> nota;
    // bucle while para validar la nota ingresada
    while (nota < 0 || nota > 20) {
        cout << "Nota invalida. Ingrese una nota entre 0 y 20: ";
        cin >> nota;
    }

    // Asignar el valor de nota en el arreglo
    notas[cantidadActual] = nota;

    cantidadActual++; // aumentar la cantidad cada vez que se registra un estudiante
    cout << "Estudiante registrado exitosamente" << endl;
}

void mostrarListado(string nombres[], double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "El listado esta vacio. Registre estudiante primero." << endl;
        return;
    }
    // Mostar el listado en forma de tabla
    cout << "ID    NOMBRE          NOTA" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < cantidadActual; i++) {
        // Se agregó el salto de línea al final (endl) para que no se imprima todo en una sola fila.
        cout << i + 1 << "      " << nombres[i] << "            " << notas[i] << endl;
    }
    cout << "---------------------------------------------\n";
}

void calcularMostrarPromedio(double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "\n No hay datos para calcular promedio." << endl;
        return;
    }
    // Ciclo para recorrer el arreglo secuencialmente
    float suma = 0;
    for (int i = 0; i < cantidadActual; i++) 
        // Acumulador de sumas de las notas
        suma = suma + notas[i];
        // Calculamos el promedio y mostramos el valor
    cout << "\nPromedio General del curso: " << (suma / cantidadActual) << endl;
}

void mostrarNotaMayorYMenor(string nombres[], double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }
    // variables para indicar la posicion inicial del arreglo y poder buscar la nota
    double mayorNota = notas[0];
    double menorNota = notas[0];
    int indiceMayor = 0;
    int indiceMenor = 0;
    // ciclo para recorrer el arreglo y encontar la nota mayor y la posicion del estudiante en el arreglo
    for (int i = 0; i < cantidadActual; i++) {
        if (notas[i] > mayorNota) {
            mayorNota = notas[i];
            indiceMayor = i;
        }
    }
    // ciclo para recorrel el arreglo y encontar la nota menor y la posicion del estudiante en el arreglo
    for (int k = 0; k < cantidadActual; k++)
    {
        if (notas[k] < menorNota)
        {
            menorNota = notas[k];
            indiceMenor = k;
        }
    }
    // Mostrar la nota mas alta con el nombre del estudiante y su nota 
    cout << "La nota mas alta es de: '" << nombres[indiceMayor] << "'" << endl;
    cout << "Nota: " << mayorNota << endl;
    cout << "La nota mas baja es de: '" << nombres[indiceMenor] << "'" << endl;
    cout << "Nota: " << menorNota << endl;

}

void mostrarAprobadosReprobados(string nombres[], double notas[], int cantidadActual){
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }
    // Variables para asignar aprobados y reporbados e indices para los arreglos
    double aprobado, reprobado;
    int indiceAprobado = 0;
    int indiceReprobado = 0;
    // ciclo para recorrer el arreglo y condicion para obtener la nota aprobada y posicion del estudiante en el arreglo
    for (int i = 0; i < cantidadActual; i++) {
        
        if (notas[i] >= Nota_Aprobada) {
            indiceAprobado = i;
            cout << "'" << nombres[indiceAprobado] << "' - Aprobado" << endl;            
        } else {
            indiceReprobado = i;
            cout << "'" << nombres[indiceReprobado] << "' - Reprobado" << endl;  
        }
    }
}

void buscarEstudiante(string nombres[], double notas[], int cantidadActual) {
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }

    string nombreBuscado;
    cout << "\nIngrese el nombre del estudiante a buscar: ";
    cin >> nombreBuscado;

    int indiceEncontrado = -1; // Usamos -1 como indicador de "no encontrado"

    // Recorremos el arreglo comparando nombres
    for (int i = 0; i < cantidadActual; i++) {
        if (nombres[i] == nombreBuscado) {
            indiceEncontrado = i; // Guardamos la posicion donde lo encontramos
            break; // Salimos del ciclo porque ya lo encontramos
        }
    }

    // Evaluamos el resultado
    if (indiceEncontrado != -1) {
        // Caso 4: Encontrado
        cout << "\nEstudiante encontrado:" << endl;
        cout << "Nombre: " << nombres[indiceEncontrado] << endl;
        cout << "Nota: " << notas[indiceEncontrado] << endl;
        
        // Determinamos el estado basado en la nota
        if (notas[indiceEncontrado] >= Nota_Aprobada) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
    } else {
        // Caso 5: Inexistente
        cout << "\nError: El estudiante '" << nombreBuscado << "' no fue encontrado en el sistema." << endl;
    }
}

/*
    Funcion que busca estudiante por ID y no por nombre tambien funciona
    void buscarEstudiante(string nombres[], double notas[], int cantidadActual){
    if (cantidadActual == 0) {
        cout << "No hay datos registrados en el sistema." << endl;
        return;
    }

    cout << "\nIngrese el ID del estudiante: ";
    int id = validarOpcion(1, cantidadActual);
    int indice_ID = id - 1; // restamos menos uno para ubicar la posicion en el arreglo
    
    cout << "Estudiante buscado ID: " << id << " | Nombre: '" << nombres[indice_ID] << "' | Nota: " << notas[indice_ID] << endl;
}
*/
