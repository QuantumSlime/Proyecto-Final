#include "RegistroNotas.h"
#include <iostream>
#include <numeric>
using namespace std;

void RegistroNotas::agregarNota(int idEstudiante, float nota) {
    notas[idEstudiante].push_back(nota);
}

vector<float> RegistroNotas::obtenerNotas(int idEstudiante) const {
    auto it = notas.find(idEstudiante);
    if (it != notas.end()) {
        return it->second; // Retorna las notas del estudiante
    }
    return {}; // Retorna un vector vacío si no hay notas
}

float RegistroNotas::calcularPromedio(int idEstudiante) const {
    auto it = notas.find(idEstudiante);
    if (it != notas.end() && !it->second.empty()) {
        float suma = accumulate(it->second.begin(), it->second.end(), 0.0);
        return suma / it->second.size(); // Retorna el promedio
    }
    return 0.0; // Retorna 0 si no hay notas
}

void RegistroNotas::mostrarNotas(int idEstudiante) const {
    auto it = notas.find(idEstudiante);
    if (it != notas.end()) {
        cout << "Notas del Estudiante ID " << idEstudiante << ": ";
        for (float nota : it->second) {
            cout << nota << " ";
        }
        cout << endl;
    } else {
        cout << "No hay notas registradas para el Estudiante ID " << idEstudiante << endl;
    }
}
