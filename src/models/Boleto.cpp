#include "Boleto.h"

namespace ZooManagement {
    namespace Models {

        Boleto::Boleto() : id(0), tipo(TipoBoleto::ADULTO), precio(0.0),
            fechaVenta(""), usuarioVendedorId(0), cantidad(1) {}

        Boleto::Boleto(int id, TipoBoleto tipo, double precio, const std::string& fechaVenta,
            int usuarioVendedorId, int cantidad)
            : id(id), tipo(tipo), precio(precio), fechaVenta(fechaVenta),
            usuarioVendedorId(usuarioVendedorId), cantidad(cantidad) {}

        // Getters
        int Boleto::getId() const { return id; }
        TipoBoleto Boleto::getTipo() const { return tipo; }
        double Boleto::getPrecio() const { return precio; }
        std::string Boleto::getFechaVenta() const { return fechaVenta; }
        int Boleto::getUsuarioVendedorId() const { return usuarioVendedorId; }
        int Boleto::getCantidad() const { return cantidad; }

        std::string Boleto::getTipoString() const {
            switch (tipo) {
            case TipoBoleto::ADULTO: return "Adulto";
            case TipoBoleto::NINO: return "Niño";
            case TipoBoleto::ADULTO_MAYOR: return "Adulto Mayor";
            case TipoBoleto::ESTUDIANTE: return "Estudiante";
            default: return "Desconocido";
            }
        }

        double Boleto::getTotal() const {
            return precio * cantidad;
        }

        // Setters
        void Boleto::setId(int id) { this->id = id; }
        void Boleto::setTipo(TipoBoleto tipo) { this->tipo = tipo; }
        void Boleto::setPrecio(double precio) { this->precio = precio; }
        void Boleto::setFechaVenta(const std::string& fechaVenta) { this->fechaVenta = fechaVenta; }
        void Boleto::setUsuarioVendedorId(int usuarioVendedorId) { this->usuarioVendedorId = usuarioVendedorId; }
        void Boleto::setCantidad(int cantidad) { this->cantidad = cantidad; }

        // Precios predefinidos por tipo de boleto
        double Boleto::getPrecioPorTipo(TipoBoleto tipo) {
            switch (tipo) {
            case TipoBoleto::ADULTO: return 150.00;
            case TipoBoleto::NINO: return 80.00;
            case TipoBoleto::ADULTO_MAYOR: return 100.00;
            case TipoBoleto::ESTUDIANTE: return 90.00;
            default: return 150.00;
            }
        }
    }
}
