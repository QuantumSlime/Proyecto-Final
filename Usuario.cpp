#include "Usuario.h"
using namespace std;

// Definiciones de los métodos
int Usuario::getId() const {
    return id;
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getCorreo() const {
    return correo;
}

string Usuario::getContrasena() const {
    return contrasena;
}

bool Usuario::isActivo() const {
    return activo;
}

void Usuario::setActivo(bool activo) {
    this->activo = activo;
}
