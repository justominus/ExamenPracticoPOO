#include "Usuario.h"

namespace ZooManagement {
    namespace Models {

        Usuario::Usuario() : id(0), nombre(""), username(""), password(""),
            tipo(TipoUsuario::CAJERO), activo(true) {}

        Usuario::Usuario(int id, const std::string& nombre, const std::string& username,
            const std::string& password, TipoUsuario tipo, bool activo)
            : id(id), nombre(nombre), username(username), password(password),
            tipo(tipo), activo(activo) {}

        // Getters
        int Usuario::getId() const { return id; }
        std::string Usuario::getNombre() const { return nombre; }
        std::string Usuario::getUsername() const { return username; }
        std::string Usuario::getPassword() const { return password; }
        TipoUsuario Usuario::getTipo() const { return tipo; }
        bool Usuario::isActivo() const { return activo; }

        std::string Usuario::getTipoString() const {
            switch (tipo) {
            case TipoUsuario::DUENO: return "Dueño";
            case TipoUsuario::ADMINISTRADOR: return "Administrador";
            case TipoUsuario::CAJERO: return "Cajero";
            default: return "Desconocido";
            }
        }

        // Setters
        void Usuario::setId(int id) { this->id = id; }
        void Usuario::setNombre(const std::string& nombre) { this->nombre = nombre; }
        void Usuario::setUsername(const std::string& username) { this->username = username; }
        void Usuario::setPassword(const std::string& password) { this->password = password; }
        void Usuario::setTipo(TipoUsuario tipo) { this->tipo = tipo; }
        void Usuario::setActivo(bool activo) { this->activo = activo; }

        // Validación de acceso por perfil
        bool Usuario::tieneAccesoCompleto() const {
            return tipo == TipoUsuario::DUENO;
        }

        bool Usuario::tieneAccesoGestion() const {
            return tipo == TipoUsuario::DUENO || tipo == TipoUsuario::ADMINISTRADOR;
        }

        bool Usuario::tieneAccesoVentas() const {
            return activo; // Todos los usuarios activos pueden acceder a ventas
        }
    }
}
