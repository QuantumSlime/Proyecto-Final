#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Usuario.h"
using namespace std;

class Estudiante : public Usuario {
private:
    string grado;
    string seccion;

public:
    Estudiante(int id, string nombre, string correo, string contrasena, string grado, string seccion);

    void mostrarMenu() override;

    string getNombre() const { return nombre; }
    void setGrado(const string& nuevoGrado) { grado = nuevoGrado; }
    void setSeccion(const string& nuevaSeccion) { seccion = nuevaSeccion; }
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setCorreo(const string& nuevoCorreo) { correo = nuevoCorreo; }
    void setContrasena(const string& nuevaContrasena) { contrasena = nuevaContrasena; }
};

#endif // ESTUDIANTE_H
