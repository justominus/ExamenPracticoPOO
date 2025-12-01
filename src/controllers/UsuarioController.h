#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "../models/Usuario.h"

namespace ZooManagement {
    namespace Controllers {

        class UsuarioController {
        private:
            std::vector<Models::Usuario> usuarios;
            std::string archivoUsuarios;
            int siguienteId;

            void cargarUsuarios();
            void guardarUsuarios();
            int generarId();

        public:
            UsuarioController(const std::string& archivo = "data/usuarios.dat");
            ~UsuarioController();

            // CRUD Operations
            bool crearUsuario(const Models::Usuario& usuario);
            Models::Usuario* leerUsuario(int id);
            Models::Usuario* leerUsuarioPorUsername(const std::string& username);
            std::vector<Models::Usuario> listarUsuarios();
            bool actualizarUsuario(const Models::Usuario& usuario);
            bool eliminarUsuario(int id);

            // Authentication
            Models::Usuario* autenticar(const std::string& username, const std::string& password);

            // Utilities
            bool existeUsername(const std::string& username);
            int contarUsuarios();
            void inicializarUsuarioPorDefecto();
        };
    }
}
