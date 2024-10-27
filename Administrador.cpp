#include "Administrador.h"
#include <iostream>

#include "Administrador.h"
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

void Administrador::editarUsuario(Usuario& usuario) {
    int opcion = 0;
    while (opcion != 6) {
        cout << "Seleccione el atributo a editar para el usuario " << usuario.getNombre() << ":\n";
        cout << "1. Nombre\n";
        cout << "2. Correo\n";
        cout << "3. Contraseña\n";

        if (dynamic_cast<Acudiente*>(&usuario)) {
            cout << "4. Relacion\n";
            cout << "5. ID del Estudiante\n";
            cout << "6. Salir\n";
        } else if (dynamic_cast<Estudiante*>(&usuario)) {
            cout << "4. Grado\n";
            cout << "5. Seccion\n";
            cout << "6. Salir\n";
        }

        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                string nuevoNombre;
                cout << "Ingrese el nuevo nombre: ";
                getline(cin, nuevoNombre);
                usuario.setNombre(nuevoNombre);
                break;
            }
            case 2: {
                string nuevoCorreo;
                cout << "Ingrese el nuevo correo: ";
                getline(cin, nuevoCorreo);
                usuario.setCorreo(nuevoCorreo);
                break;
            }
            case 3: {
                string nuevaContrasena;
                cout << "Ingrese la nueva contraseña: ";
                getline(cin, nuevaContrasena);
                usuario.setContrasena(nuevaContrasena);
                break;
            }
            case 4: {
                if (Acudiente* acu = dynamic_cast<Acudiente*>(&usuario)) {
                    string nuevaRelacion;
                    cout << "Ingrese la nueva relacion: ";
                    getline(cin, nuevaRelacion);
                    acu->setRelacion(nuevaRelacion);
                } else if (Estudiante* est = dynamic_cast<Estudiante*>(&usuario)) {
                    string nuevoGrado;
                    cout << "Ingrese el nuevo grado: ";
                    getline(cin, nuevoGrado);
                    est->setGrado(nuevoGrado);
                }
                break;
            }
            case 5: {
                if (Acudiente* acu = dynamic_cast<Acudiente*>(&usuario)) {
                    int nuevoIdEstudiante;
                    cout << "Ingrese el nuevo ID del estudiante: ";
                    cin >> nuevoIdEstudiante;
                    acu->setIdEstudiante(nuevoIdEstudiante);
                } else if (Estudiante* est = dynamic_cast<Estudiante*>(&usuario)) {
                    string nuevaSeccion;
                    cout << "Ingrese la nueva seccion: ";
                    cin.ignore(); // Limpiar buffer
                    getline(cin, nuevaSeccion);
                    est->setSeccion(nuevaSeccion);
                }
                break;
            }
            case 6:
                cout << "Saliendo de edicion...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }
    }
}

template <typename T>
bool eliminarUsuarioPorID(vector<T>& usuarios, int id) {
    auto it = remove_if(usuarios.begin(), usuarios.end(), [id](const T& usuario) {
        return usuario.getId() == id;
    });
    if (it != usuarios.end()) {
        usuarios.erase(it, usuarios.end());
        return true;
    }
    return false;
}

void Administrador::eliminarUsuario(vector<Acudiente>& acudientes, vector<Estudiante>& estudiantes, int idUsuario, int tipo) {
    bool eliminado = false;
    if (tipo == 1) { // Tipo 1 para Acudiente
        eliminado = eliminarUsuarioPorID(acudientes, idUsuario);
    } else if (tipo == 2) { // Tipo 2 para Estudiante
        eliminado = eliminarUsuarioPorID(estudiantes, idUsuario);
    }

    if (eliminado) {
        cout << "Usuario eliminado con exito.\n";
    } else {
        cout << "Usuario con el ID proporcionado no encontrado.\n";
    }
}

void Administrador::mostrarMenu() {
    cout << "Menu Administrador:\n1. Crear Acudiente\n2. Crear Estudiante\n3. Editar Usuario\n4. Eliminar Usuario\n";
}

void Administrador::crearUsuario(Acudiente& usuario) {
    // Logica para crear un nuevo Acudiente
    cout << "Acudiente creado con exito: " << usuario.getNombre() << "\n";
}

void Administrador::crearUsuario(Estudiante& usuario) {
    // Logica para crear un nuevo Estudiante
    cout << "Estudiante creado con exito: " << usuario.getNombre() << "\n";
}

