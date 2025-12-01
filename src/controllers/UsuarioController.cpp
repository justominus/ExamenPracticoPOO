#include "UsuarioController.h"
#include <algorithm>

namespace ZooManagement {
    namespace Controllers {

        UsuarioController::UsuarioController(const std::string& archivo)
            : archivoUsuarios(archivo), siguienteId(1) {
            cargarUsuarios();
            if (usuarios.empty()) {
                inicializarUsuarioPorDefecto();
            }
        }

        UsuarioController::~UsuarioController() {
            guardarUsuarios();
        }

        void UsuarioController::cargarUsuarios() {
            std::ifstream archivo(archivoUsuarios);
            if (!archivo.is_open()) return;

            std::string linea;
            while (std::getline(archivo, linea)) {
                std::istringstream ss(linea);
                std::string campo;
                std::vector<std::string> campos;

                while (std::getline(ss, campo, '|')) {
                    campos.push_back(campo);
                }

                if (campos.size() >= 6) {
                    int id = std::stoi(campos[0]);
                    Models::Usuario usuario(
                        id,
                        campos[1],
                        campos[2],
                        campos[3],
                        static_cast<Models::TipoUsuario>(std::stoi(campos[4])),
                        campos[5] == "1"
                    );
                    usuarios.push_back(usuario);
                    if (id >= siguienteId) siguienteId = id + 1;
                }
            }
            archivo.close();
        }

        void UsuarioController::guardarUsuarios() {
            std::ofstream archivo(archivoUsuarios);
            if (!archivo.is_open()) return;

            for (const auto& usuario : usuarios) {
                archivo << usuario.getId() << "|"
                    << usuario.getNombre() << "|"
                    << usuario.getUsername() << "|"
                    << usuario.getPassword() << "|"
                    << static_cast<int>(usuario.getTipo()) << "|"
                    << (usuario.isActivo() ? "1" : "0") << "\n";
            }
            archivo.close();
        }

        int UsuarioController::generarId() {
            return siguienteId++;
        }

        bool UsuarioController::crearUsuario(const Models::Usuario& usuario) {
            if (existeUsername(usuario.getUsername())) {
                return false;
            }

            Models::Usuario nuevoUsuario = usuario;
            nuevoUsuario.setId(generarId());
            usuarios.push_back(nuevoUsuario);
            guardarUsuarios();
            return true;
        }

        Models::Usuario* UsuarioController::leerUsuario(int id) {
            for (auto& usuario : usuarios) {
                if (usuario.getId() == id) {
                    return &usuario;
                }
            }
            return nullptr;
        }

        Models::Usuario* UsuarioController::leerUsuarioPorUsername(const std::string& username) {
            for (auto& usuario : usuarios) {
                if (usuario.getUsername() == username) {
                    return &usuario;
                }
            }
            return nullptr;
        }

        std::vector<Models::Usuario> UsuarioController::listarUsuarios() {
            return usuarios;
        }

        bool UsuarioController::actualizarUsuario(const Models::Usuario& usuario) {
            for (auto& u : usuarios) {
                if (u.getId() == usuario.getId()) {
                    u = usuario;
                    guardarUsuarios();
                    return true;
                }
            }
            return false;
        }

        bool UsuarioController::eliminarUsuario(int id) {
            auto it = std::remove_if(usuarios.begin(), usuarios.end(),
                [id](const Models::Usuario& u) { return u.getId() == id; });

            if (it != usuarios.end()) {
                usuarios.erase(it, usuarios.end());
                guardarUsuarios();
                return true;
            }
            return false;
        }

        Models::Usuario* UsuarioController::autenticar(const std::string& username, const std::string& password) {
            for (auto& usuario : usuarios) {
                if (usuario.getUsername() == username &&
                    usuario.getPassword() == password &&
                    usuario.isActivo()) {
                    return &usuario;
                }
            }
            return nullptr;
        }

        bool UsuarioController::existeUsername(const std::string& username) {
            for (const auto& usuario : usuarios) {
                if (usuario.getUsername() == username) {
                    return true;
                }
            }
            return false;
        }

        int UsuarioController::contarUsuarios() {
            return static_cast<int>(usuarios.size());
        }

        void UsuarioController::inicializarUsuarioPorDefecto() {
            // Crear usuario dueño por defecto
            Models::Usuario dueno(
                generarId(),
                "Propietario del Zoo",
                "admin",
                "admin123",
                Models::TipoUsuario::DUENO,
                true
            );
            usuarios.push_back(dueno);
            guardarUsuarios();
        }
    }
}
