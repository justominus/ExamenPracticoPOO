#pragma once
#include <string>

namespace ZooManagement {
    namespace Models {

        enum class TipoUsuario {
            DUENO = 1,        // Dueño - acceso completo
            ADMINISTRADOR = 2, // Administrador - gestión
            CAJERO = 3         // Cajero - ventas
        };

        class Usuario {
        private:
            int id;
            std::string nombre;
            std::string username;
            std::string password;
            TipoUsuario tipo;
            bool activo;

        public:
            Usuario();
            Usuario(int id, const std::string& nombre, const std::string& username,
                const std::string& password, TipoUsuario tipo, bool activo = true);

            // Getters
            int getId() const;
            std::string getNombre() const;
            std::string getUsername() const;
            std::string getPassword() const;
            TipoUsuario getTipo() const;
            bool isActivo() const;
            std::string getTipoString() const;

            // Setters
            void setId(int id);
            void setNombre(const std::string& nombre);
            void setUsername(const std::string& username);
            void setPassword(const std::string& password);
            void setTipo(TipoUsuario tipo);
            void setActivo(bool activo);

            // Validación de acceso por módulo
            bool tieneAccesoCompleto() const;
            bool tieneAccesoGestion() const;
            bool tieneAccesoVentas() const;
        };
    }
}
