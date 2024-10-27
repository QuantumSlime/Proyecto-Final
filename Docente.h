#ifndef DOCENTE_H
#define DOCENTE_H

#include "Usuario.h"
using namespace std;

class Docente : public Usuario {
private:
    std::string materia;

public:
    Docente(int id, const std::string& nombre, const std::string& correo, const std::string& contrasena, const std::string& materia)
        : Usuario(id, nombre, correo, contrasena), materia(materia) {}

    void mostrarMenu() override;
};

#endif // DOCENTE_H
