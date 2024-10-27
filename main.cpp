#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <locale.h>
#include "Administrador.h"
#include "Acudiente.h"
#include "Estudiante.h"
#include "RegistroNotas.h"
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

void mostrarMenu(const string& titulo, const vector<string>& opciones) {
    cout << "\n" << CYAN << "==========================================\n";
    cout << "         " << BOLD << titulo << RESET << "\n";
    cout << "==========================================\n" << RESET;
    for (size_t i = 0; i < opciones.size(); ++i) {
        cout << GREEN << (i + 1) << ". " << WHITE << opciones[i] << "\n" << RESET;
    }
    cout << YELLOW << "Opcion: " << RESET;
}

void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menuPrincipal(){
    Administrador admin(1, "Administrador", "admin@example.com", "contrasena123");
    vector<Acudiente> acudientes;
    vector<Estudiante> estudiantes;
    RegistroNotas registroNotas;
    bool salir = false;

    while (!salir) {
        mostrarMenu("Seleccione el tipo de usuario", {"Administrador", "Acudiente", "Estudiante", "Salir"});
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1: { // Administrador
                bool salirAdmin = false;
                while (!salirAdmin) {
                    mostrarMenu("Menu Administrador", {"Crear Acudiente", "Crear Estudiante", "Editar Usuario", "Eliminar Usuario", "Agregar Nota", "Salir"});
                    int adminOpcion;
                    cin >> adminOpcion;

                    switch (adminOpcion) {
                        case 1: { // Crear Acudiente
                            int id, idEstudiante;
                            string nombre, correo, contrasena, relacion;

                            cout << GREEN << "Ingrese ID del Acudiente: " << RESET;
                            cin >> id;
                            cout << GREEN << "Ingrese Nombre del Acudiente: " << RESET;
                            limpiarBuffer();
                            getline(cin, nombre);
                            cout << GREEN << "Ingrese Correo del Acudiente: " << RESET;
                            getline(cin, correo);
                            cout << GREEN << "Ingrese Contraseña del Acudiente: " << RESET;
                            getline(cin, contrasena);
                            cout << GREEN << "Ingrese Relacion con el Estudiante: " << RESET;
                            getline(cin, relacion);
                            cout << GREEN << "Ingrese ID del Estudiante asociado: " << RESET;
                            cin >> idEstudiante;

                            bool estudianteEncontrado = false;
                            for (const Estudiante& est : estudiantes) {
                                if (est.getId() == idEstudiante) {
                                    estudianteEncontrado = true;
                                    break;
                                }
                            }

                            if (estudianteEncontrado) {
                                Acudiente nuevoAcudiente(id, nombre, correo, contrasena, relacion, idEstudiante);
                                admin.crearUsuario(nuevoAcudiente);
                                acudientes.push_back(nuevoAcudiente);
                                cout << GREEN << "Acudiente creado correctamente.\n" << RESET;
                            } else {
                                cout << RED << "No se encontro un Estudiante con el ID proporcionado.\n" << RESET;
                            }
                            break;
                        }
                        case 2: { // Crear Estudiante
                            int id;
                            string nombre, correo, contrasena, grado, horario;

                            cout << GREEN << "Ingrese ID del Estudiante: " << RESET;
                            cin >> id;
                            cout << GREEN << "Ingrese Nombre del Estudiante: " << RESET;
                            limpiarBuffer();
                            getline(cin, nombre);
                            cout << GREEN << "Ingrese Correo del Estudiante: " << RESET;
                            getline(cin, correo);
                            cout << GREEN << "Ingrese Contraseña del Estudiante: " << RESET;
                            getline(cin, contrasena);
                            cout << GREEN << "Ingrese Grado del Estudiante: " << RESET;
                            getline(cin, grado);
                            cout << GREEN << "Ingrese Seccion del Estudiante: " << RESET;
                            getline(cin, horario);

                            Estudiante nuevoEstudiante(id, nombre, correo, contrasena, grado, horario);
                            admin.crearUsuario(nuevoEstudiante);
                            estudiantes.push_back(nuevoEstudiante);
                            cout << GREEN << "Estudiante creado correctamente.\n" << RESET;
                            break;
                        }
                        case 3: { // Editar Usuario
                            int tipoUsuario, idUsuario;
                            cout << GREEN << "Seleccione el tipo de usuario a editar:\n1. Acudiente\n2. Estudiante\n" << RESET;
                            cin >> tipoUsuario;
                            cout << GREEN << "Ingrese el ID del usuario a editar: " << RESET;
                            cin >> idUsuario;

                            bool usuarioEncontrado = false;
                            if (tipoUsuario == 1) {
                                for (Acudiente& acu : acudientes) {
                                    if (acu.getId() == idUsuario) {
                                        admin.editarUsuario(acu);
                                        usuarioEncontrado = true;
                                        cout << GREEN << "Acudiente editado correctamente.\n" << RESET;
                                        break;
                                    }
                                }
                            } else if (tipoUsuario == 2) {
                                for (Estudiante& est : estudiantes) {
                                    if (est.getId() == idUsuario) {
                                        admin.editarUsuario(est);
                                        usuarioEncontrado = true;
                                        cout << GREEN << "Estudiante editado correctamente.\n" << RESET;
                                        break;
                                    }
                                }
                            } else {
                                cout << RED << "Tipo de usuario invalido.\n" << RESET;
                            }

                            if (!usuarioEncontrado) {
                                cout << RED << "No se encontro un usuario con el ID proporcionado.\n" << RESET;
                            }
                            break;
                        }
                        case 4: { // Eliminar Usuario
                            int tipoUsuario, idUsuario;
                            cout << GREEN << "Seleccione el tipo de usuario a eliminar:\n1. Acudiente\n2. Estudiante\n" << RESET;
                            cin >> tipoUsuario;
                            cout << GREEN << "Ingrese ID del usuario a eliminar: " << RESET;
                            cin >> idUsuario;
                            admin.eliminarUsuario(acudientes, estudiantes, idUsuario, tipoUsuario);
                            break;
                        }
                        case 5: { // Agregar Nota
                            int idEstudiante;
                            double nota;

                            cout << GREEN << "Ingrese ID del Estudiante: " << RESET;
                            cin >> idEstudiante;
                            cout << GREEN << "Ingrese Nota: " << RESET;
                            cin >> nota;

                            registroNotas.agregarNota(idEstudiante, nota);
                            cout << GREEN << "Nota agregada correctamente.\n" << RESET;
                            break;
                        }
                        case 6:
                            salirAdmin = true;
                            break;
                        default:
                            cout << RED << "Opcion invalida. Intente de nuevo.\n" << RESET;
                            break;
                    }
                }
                break;
            }
            case 2: { // Acudiente
                bool salirAcudiente = false;
                while (!salirAcudiente) {
                    mostrarMenu("Menu Acudiente", {"Ver Notas del Estudiante", "Comunicarse con Docentes", "Salir"});
                    int acudienteOpcion;
                    cin >> acudienteOpcion;

                    switch (acudienteOpcion) {
                        case 1: {
                            int idAcudiente;
                            cout << GREEN << "Ingrese ID del Acudiente: " << RESET;
                            cin >> idAcudiente;

                            bool acudienteEncontrado = false;
                            for (const Acudiente& acu : acudientes) {
                                if (acu.getId() == idAcudiente) {
                                    acudienteEncontrado = true;
                                    int idEstudiante = acu.getIdEstudiante();
                                    cout << "Notas del Estudiante ID " << idEstudiante << ":\n";
                                    registroNotas.mostrarNotas(idEstudiante);
                                    break;
                                }
                            }

                            if (!acudienteEncontrado) {
                                cout << RED << "No se encontro un Acudiente con el ID proporcionado.\n" << RESET;
                            }
                            break;
                        }
                        case 2: {
                            cout << GREEN << "Correo electronico para comunicarse con docentes: docente@gmail.com\n" << RESET;
                            break;
                        }
                        case 3:
                            salirAcudiente = true;
                            break;
                        default:
                            cout << RED << "Opcion invalida. Intente de nuevo.\n" << RESET;
                            break;
                    }
                }
                break;
            }
            case 3: { // Estudiante
                bool salirEstudiante = false;
                while (!salirEstudiante) {
                    mostrarMenu("Menu Estudiante", {"Consultar Notas", "Calcular Promedio", "Salir"});
                    int opcionEstudiante;
                    cin >> opcionEstudiante;

                    switch (opcionEstudiante) {
                        case 1: { // Consultar Notas
                            int idEstudiante;
                            cout << GREEN << "Ingrese ID del Estudiante: " << RESET;
                            cin >> idEstudiante;
                            registroNotas.mostrarNotas(idEstudiante);
                            break;
                        }
                        case 2: { // Calcular Promedio
                            int idEstudiante;
                            cout << GREEN << "Ingrese ID del Estudiante: " << RESET;
                            cin >> idEstudiante;
                            float promedio = registroNotas.calcularPromedio(idEstudiante);
                            cout << GREEN << "El promedio del Estudiante ID " << idEstudiante << " es: " << promedio << RESET << endl;
                            break;
                        }
                        case 3:
                            salirEstudiante = true;
                            break;
                        default:
                            cout << RED << "Opcion invalida. Intente de nuevo.\n" << RESET;
                            break;
                    }
                }
                break;
            }
            case 4:
                salir = true;
                break;
            default:
                cout << RED << "Opcion invalida. Intente de nuevo.\n" << RESET;
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "spanish");
    menuPrincipal();
    return 0;
}
