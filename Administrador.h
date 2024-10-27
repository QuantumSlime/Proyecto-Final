#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Usuario.h"
#include "Acudiente.h"
#include "Estudiante.h"
#include <vector>
using namespace std;

class Administrador : public Usuario {
public:
    Administrador(int id, const string& nombre, const string& correo, const string& contrasena)
        : Usuario(id, nombre, correo, contrasena) {}

    void mostrarMenu() override;

    void crearUsuario(Acudiente& usuario);
    void crearUsuario(Estudiante& usuario);
    void editarUsuario(Usuario& usuario);
    void eliminarUsuario(vector<Acudiente>& acudientes, vector<Estudiante>& estudiantes, int idUsuario, int tipo);

};

#endif // ADMINISTRADOR_H
