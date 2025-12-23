#pragma once
#include <string>
#include <ctime>

namespace ZooManagement {
    namespace Models {

        enum class TipoBoleto {
            ADULTO = 1,
            NINO = 2,
            ADULTO_MAYOR = 3,
            ESTUDIANTE = 4
        };

        class Boleto {
        private:
            int id;
            TipoBoleto tipo;
            double precio;
            std::string fechaVenta;
            int usuarioVendedorId;
            int cantidad;

        public:
            Boleto();
            Boleto(int id, TipoBoleto tipo, double precio, const std::string& fechaVenta,
                int usuarioVendedorId, int cantidad = 1);

            // Getters
            int getId() const;
            TipoBoleto getTipo() const;
            double getPrecio() const;
            std::string getFechaVenta() const;
            int getUsuarioVendedorId() const;
            int getCantidad() const;
            std::string getTipoString() const;
            double getTotal() const;

            // Setters
            void setId(int id);
            void setTipo(TipoBoleto tipo);
            void setPrecio(double precio);
            void setFechaVenta(const std::string& fechaVenta);
            void setUsuarioVendedorId(int usuarioVendedorId);
            void setCantidad(int cantidad);

            // Obtener precios predefinidos por tipo
            static double getPrecioPorTipo(TipoBoleto tipo);
        };
    }
}
