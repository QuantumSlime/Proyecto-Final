#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    int id;
    string nombre;
    string correo;
    string contrasena;
    bool activo; // Agregar un miembro para el estado activo

public:
    Usuario() : id(0), nombre(""), correo(""), contrasena(""), activo(true) {}

    Usuario(int id, const string& nombre, const string& correo, const string& contrasena)
        : id(id), nombre(nombre), correo(correo), contrasena(contrasena), activo(true) {}

    virtual void mostrarMenu() = 0; // Método virtual puro

    // Métodos de acceso
    int getId() const; // Declaración
    string getNombre() const; // Declaración
    string getCorreo() const; // Declaración
    string getContrasena() const; // Declaración
    void setNombre(const string& nombre) { this->nombre = nombre; }
    void setCorreo(const string& correo) { this->correo = correo; }
    void setContrasena(const string& contrasena) { this->contrasena = contrasena; }
    bool isActivo() const; // Declaración
    void setActivo(bool activo); // Declaración
};

#endif // USUARIO_H
