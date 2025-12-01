#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "../models/Boleto.h"

namespace ZooManagement {
    namespace Controllers {

        struct ReporteVentas {
            double totalVentas;
            int totalBoletos;
            int boletosAdulto;
            int boletosNino;
            int boletosAdultoMayor;
            int boletosEstudiante;
            std::string fecha;
        };

        class BoletoController {
        private:
            std::vector<Models::Boleto> boletos;
            std::string archivoBoletos;
            int siguienteId;

            void cargarBoletos();
            void guardarBoletos();
            int generarId();
            std::string obtenerFechaActual();

        public:
            BoletoController(const std::string& archivo = "data/boletos.dat");
            ~BoletoController();

            // Venta de boletos
            bool venderBoleto(Models::TipoBoleto tipo, int cantidad, int usuarioVendedorId);
            Models::Boleto crearBoleto(Models::TipoBoleto tipo, int cantidad, int usuarioVendedorId);

            // Consultas
            std::vector<Models::Boleto> listarBoletos();
            std::vector<Models::Boleto> listarBoletosPorFecha(const std::string& fecha);
            std::vector<Models::Boleto> listarBoletosPorVendedor(int usuarioId);

            // Reportes
            ReporteVentas generarReporteDiario(const std::string& fecha);
            ReporteVentas generarReporteGeneral();
            double calcularTotalVentas();
            int contarBoletos();

            // Utilidades
            static double obtenerPrecioBoleto(Models::TipoBoleto tipo);
        };
    }
}
