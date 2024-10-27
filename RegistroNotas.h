#ifndef REGISTRO_NOTAS_H
#define REGISTRO_NOTAS_H

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class RegistroNotas {
private:
    unordered_map<int, vector<float>> notas; // ID del estudiante -> Notas

public:
    // Método para agregar una nota a un estudiante
    void agregarNota(int idEstudiante, float nota);

    // Método para obtener las notas de un estudiante
    vector<float> obtenerNotas(int idEstudiante) const;

    // Método para calcular el promedio de las notas de un estudiante
    float calcularPromedio(int idEstudiante) const;

    // Método para mostrar todas las notas de un estudiante
    void mostrarNotas(int idEstudiante) const;
};

#endif // REGISTRO_NOTAS_H
