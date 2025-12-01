#include "BoletoController.h"
#include <algorithm>
#include <iomanip>

namespace ZooManagement {
    namespace Controllers {

        BoletoController::BoletoController(const std::string& archivo)
            : archivoBoletos(archivo), siguienteId(1) {
            cargarBoletos();
        }

        BoletoController::~BoletoController() {
            guardarBoletos();
        }

        void BoletoController::cargarBoletos() {
            std::ifstream archivo(archivoBoletos);
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
                    Models::Boleto boleto(
                        id,
                        static_cast<Models::TipoBoleto>(std::stoi(campos[1])),
                        std::stod(campos[2]),
                        campos[3],
                        std::stoi(campos[4]),
                        std::stoi(campos[5])
                    );
                    boletos.push_back(boleto);
                    if (id >= siguienteId) siguienteId = id + 1;
                }
            }
            archivo.close();
        }

        void BoletoController::guardarBoletos() {
            std::ofstream archivo(archivoBoletos);
            if (!archivo.is_open()) return;

            for (const auto& boleto : boletos) {
                archivo << boleto.getId() << "|"
                    << static_cast<int>(boleto.getTipo()) << "|"
                    << boleto.getPrecio() << "|"
                    << boleto.getFechaVenta() << "|"
                    << boleto.getUsuarioVendedorId() << "|"
                    << boleto.getCantidad() << "\n";
            }
            archivo.close();
        }

        int BoletoController::generarId() {
            return siguienteId++;
        }

        std::string BoletoController::obtenerFechaActual() {
            time_t now = time(0);
            tm* ltm = localtime(&now);
            std::ostringstream oss;
            oss << std::setfill('0') << std::setw(4) << (1900 + ltm->tm_year) << "-"
                << std::setw(2) << (1 + ltm->tm_mon) << "-"
                << std::setw(2) << ltm->tm_mday;
            return oss.str();
        }

        bool BoletoController::venderBoleto(Models::TipoBoleto tipo, int cantidad, int usuarioVendedorId) {
            if (cantidad <= 0) return false;

            Models::Boleto boleto = crearBoleto(tipo, cantidad, usuarioVendedorId);
            boletos.push_back(boleto);
            guardarBoletos();
            return true;
        }

        Models::Boleto BoletoController::crearBoleto(Models::TipoBoleto tipo, int cantidad, int usuarioVendedorId) {
            double precio = obtenerPrecioBoleto(tipo);
            return Models::Boleto(
                generarId(),
                tipo,
                precio,
                obtenerFechaActual(),
                usuarioVendedorId,
                cantidad
            );
        }

        std::vector<Models::Boleto> BoletoController::listarBoletos() {
            return boletos;
        }

        std::vector<Models::Boleto> BoletoController::listarBoletosPorFecha(const std::string& fecha) {
            std::vector<Models::Boleto> resultado;
            for (const auto& boleto : boletos) {
                if (boleto.getFechaVenta() == fecha) {
                    resultado.push_back(boleto);
                }
            }
            return resultado;
        }

        std::vector<Models::Boleto> BoletoController::listarBoletosPorVendedor(int usuarioId) {
            std::vector<Models::Boleto> resultado;
            for (const auto& boleto : boletos) {
                if (boleto.getUsuarioVendedorId() == usuarioId) {
                    resultado.push_back(boleto);
                }
            }
            return resultado;
        }

        ReporteVentas BoletoController::generarReporteDiario(const std::string& fecha) {
            ReporteVentas reporte = { 0, 0, 0, 0, 0, 0, fecha };

            for (const auto& boleto : boletos) {
                if (boleto.getFechaVenta() == fecha) {
                    reporte.totalVentas += boleto.getTotal();
                    reporte.totalBoletos += boleto.getCantidad();

                    switch (boleto.getTipo()) {
                    case Models::TipoBoleto::ADULTO:
                        reporte.boletosAdulto += boleto.getCantidad();
                        break;
                    case Models::TipoBoleto::NINO:
                        reporte.boletosNino += boleto.getCantidad();
                        break;
                    case Models::TipoBoleto::ADULTO_MAYOR:
                        reporte.boletosAdultoMayor += boleto.getCantidad();
                        break;
                    case Models::TipoBoleto::ESTUDIANTE:
                        reporte.boletosEstudiante += boleto.getCantidad();
                        break;
                    }
                }
            }
            return reporte;
        }

        ReporteVentas BoletoController::generarReporteGeneral() {
            ReporteVentas reporte = { 0, 0, 0, 0, 0, 0, "General" };

            for (const auto& boleto : boletos) {
                reporte.totalVentas += boleto.getTotal();
                reporte.totalBoletos += boleto.getCantidad();

                switch (boleto.getTipo()) {
                case Models::TipoBoleto::ADULTO:
                    reporte.boletosAdulto += boleto.getCantidad();
                    break;
                case Models::TipoBoleto::NINO:
                    reporte.boletosNino += boleto.getCantidad();
                    break;
                case Models::TipoBoleto::ADULTO_MAYOR:
                    reporte.boletosAdultoMayor += boleto.getCantidad();
                    break;
                case Models::TipoBoleto::ESTUDIANTE:
                    reporte.boletosEstudiante += boleto.getCantidad();
                    break;
                }
            }
            return reporte;
        }

        double BoletoController::calcularTotalVentas() {
            double total = 0;
            for (const auto& boleto : boletos) {
                total += boleto.getTotal();
            }
            return total;
        }

        int BoletoController::contarBoletos() {
            int total = 0;
            for (const auto& boleto : boletos) {
                total += boleto.getCantidad();
            }
            return total;
        }

        double BoletoController::obtenerPrecioBoleto(Models::TipoBoleto tipo) {
            return Models::Boleto::getPrecioPorTipo(tipo);
        }
    }
}
