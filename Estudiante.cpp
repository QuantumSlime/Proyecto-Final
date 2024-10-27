#include "Estudiante.h"
#include <iostream>
using namespace std;

Estudiante::Estudiante(int id, string nombre, string correo, string contrasena, string grado, string seccion)
    : Usuario(id, nombre, correo, contrasena), grado(grado), seccion(seccion) {}

void Estudiante::mostrarMenu() {
    cout << "Menu Estudiante:\n";
    cout << "1. Consultar Notas\n";
    cout << "2. Calcular Promedio\n";
    cout << "3. Salir\n";
}
