#ifndef ACUDIENTE_H
#define ACUDIENTE_H

#include <string>
#include "Usuario.h"
using namespace std;

class Acudiente : public Usuario {
private:
    string relacion;
    int idEstudiante;

public:
    Acudiente(int id, const string& nombre, const string& correo, const string& contrasena,
              const string& relacion, int idEstudiante)
        : Usuario(id, nombre, correo, contrasena), relacion(relacion), idEstudiante(idEstudiante) {}


    void mostrarMenu() override;

    string getNombre() const { return nombre; } // Solo una definición
    int getId() const { return id; }
    string getCorreo() const { return correo; }
    string getContrasena() const { return contrasena; }
    string getRelacion() const { return relacion; }
    int getIdEstudiante() const { return idEstudiante; }
    void setRelacion(const string& nuevaRelacion) { relacion = nuevaRelacion; }
    void setIdEstudiante(int nuevoIdEstudiante) { idEstudiante = nuevoIdEstudiante; }
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    void setCorreo(const string& nuevoCorreo) { correo = nuevoCorreo; }
    void setContrasena(const string& nuevaContrasena) { contrasena = nuevaContrasena; }
};

#endif // ACUDIENTE_H
