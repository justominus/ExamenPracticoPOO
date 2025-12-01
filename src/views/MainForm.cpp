#include "MainForm.h"
#include <msclr/marshal_cppstd.h>

namespace ZooManagement {
    namespace Views {

        void MainForm::ConfigurarPermisos()
        {
            // Configurar barra de estado con información del usuario
            lblUsuarioActual->Text = gcnew String(("Usuario: " + usuarioActual->getNombre()).c_str());
            lblPerfilActual->Text = gcnew String(("Perfil: " + usuarioActual->getTipoString()).c_str());

            // Configurar acceso a pestañas según el perfil
            switch (usuarioActual->getTipo())
            {
            case Models::TipoUsuario::DUENO:
                // Acceso completo - todas las pestañas habilitadas
                tabUsuarios->Enabled = true;
                tabVentas->Enabled = true;
                tabReportes->Enabled = true;
                break;

            case Models::TipoUsuario::ADMINISTRADOR:
                // Acceso a gestión y reportes
                tabUsuarios->Enabled = true;
                tabVentas->Enabled = true;
                tabReportes->Enabled = true;
                // Limitar tipos de usuario que puede crear
                cmbTipoUsuario->Items->Clear();
                cmbTipoUsuario->Items->Add(L"Administrador");
                cmbTipoUsuario->Items->Add(L"Cajero");
                break;

            case Models::TipoUsuario::CAJERO:
                // Solo acceso a ventas
                tabControl->TabPages->Remove(tabUsuarios);
                tabControl->TabPages->Remove(tabReportes);
                break;
            }
        }

        void MainForm::CargarDatosIniciales()
        {
            CargarUsuarios();
            CargarVentasRecientes();
            CargarReporteGeneral();
            ActualizarTotalVenta();
        }

        // ===== EVENTOS DE MENÚ =====

        System::Void MainForm::menuCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (MessageBox::Show(L"¿Desea cerrar la sesión actual?", L"Cerrar Sesión",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
                this->Close();
            }
        }

        System::Void MainForm::menuSalir_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (MessageBox::Show(L"¿Desea salir del sistema?", L"Salir",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                Application::Exit();
            }
        }

        System::Void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
        {
            // Aquí se pueden guardar datos pendientes si es necesario
        }

        // ===== GESTIÓN DE USUARIOS =====

        void MainForm::CargarUsuarios()
        {
            dgvUsuarios->Rows->Clear();
            dgvUsuarios->Columns->Clear();

            dgvUsuarios->Columns->Add(L"Id", L"ID");
            dgvUsuarios->Columns->Add(L"Nombre", L"Nombre");
            dgvUsuarios->Columns->Add(L"Username", L"Usuario");
            dgvUsuarios->Columns->Add(L"Tipo", L"Tipo");
            dgvUsuarios->Columns->Add(L"Activo", L"Estado");

            Controllers::UsuarioController controller;
            auto usuarios = controller.listarUsuarios();

            for (const auto& usuario : usuarios)
            {
                int rowIndex = dgvUsuarios->Rows->Add();
                dgvUsuarios->Rows[rowIndex]->Cells[0]->Value = usuario.getId();
                dgvUsuarios->Rows[rowIndex]->Cells[1]->Value = gcnew String(usuario.getNombre().c_str());
                dgvUsuarios->Rows[rowIndex]->Cells[2]->Value = gcnew String(usuario.getUsername().c_str());
                dgvUsuarios->Rows[rowIndex]->Cells[3]->Value = gcnew String(usuario.getTipoString().c_str());
                dgvUsuarios->Rows[rowIndex]->Cells[4]->Value = usuario.isActivo() ? L"Activo" : L"Inactivo";
            }
        }

        System::Void MainForm::btnNuevoUsuario_Click(System::Object^ sender, System::EventArgs^ e)
        {
            modoNuevoUsuario = true;
            LimpiarFormularioUsuario();
            MostrarFormularioUsuario(true);
        }

        System::Void MainForm::btnEditarUsuario_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dgvUsuarios->SelectedRows->Count == 0)
            {
                MessageBox::Show(L"Seleccione un usuario para editar", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }

            modoNuevoUsuario = false;
            usuarioEditandoId = Convert::ToInt32(dgvUsuarios->SelectedRows[0]->Cells[0]->Value);

            Controllers::UsuarioController controller;
            Models::Usuario* usuario = controller.leerUsuario(usuarioEditandoId);

            if (usuario != nullptr)
            {
                txtNombreUsuario->Text = gcnew String(usuario->getNombre().c_str());
                txtUsernameUsuario->Text = gcnew String(usuario->getUsername().c_str());
                txtPasswordUsuario->Text = gcnew String(usuario->getPassword().c_str());

                // Seleccionar tipo de usuario
                String^ tipoStr = gcnew String(usuario->getTipoString().c_str());
                for (int i = 0; i < cmbTipoUsuario->Items->Count; i++)
                {
                    if (cmbTipoUsuario->Items[i]->ToString() == tipoStr)
                    {
                        cmbTipoUsuario->SelectedIndex = i;
                        break;
                    }
                }

                chkActivoUsuario->Checked = usuario->isActivo();
                MostrarFormularioUsuario(false);
            }
        }

        System::Void MainForm::btnEliminarUsuario_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dgvUsuarios->SelectedRows->Count == 0)
            {
                MessageBox::Show(L"Seleccione un usuario para eliminar", L"Aviso",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }

            int idEliminar = Convert::ToInt32(dgvUsuarios->SelectedRows[0]->Cells[0]->Value);

            // No permitir eliminar el usuario actual
            if (idEliminar == usuarioActual->getId())
            {
                MessageBox::Show(L"No puede eliminar su propio usuario", L"Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (MessageBox::Show(L"¿Está seguro de eliminar este usuario?", L"Confirmar",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                Controllers::UsuarioController controller;
                if (controller.eliminarUsuario(idEliminar))
                {
                    MessageBox::Show(L"Usuario eliminado correctamente", L"Éxito",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                    CargarUsuarios();
                }
                else
                {
                    MessageBox::Show(L"Error al eliminar el usuario", L"Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        System::Void MainForm::btnGuardarUsuario_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Validar campos
            if (String::IsNullOrWhiteSpace(txtNombreUsuario->Text) ||
                String::IsNullOrWhiteSpace(txtUsernameUsuario->Text) ||
                String::IsNullOrWhiteSpace(txtPasswordUsuario->Text) ||
                cmbTipoUsuario->SelectedIndex < 0)
            {
                MessageBox::Show(L"Por favor complete todos los campos", L"Validación",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            std::string nombre = msclr::interop::marshal_as<std::string>(txtNombreUsuario->Text);
            std::string username = msclr::interop::marshal_as<std::string>(txtUsernameUsuario->Text);
            std::string password = msclr::interop::marshal_as<std::string>(txtPasswordUsuario->Text);

            // Determinar tipo de usuario
            Models::TipoUsuario tipo;
            String^ tipoSeleccionado = cmbTipoUsuario->SelectedItem->ToString();
            if (tipoSeleccionado == L"Dueño") tipo = Models::TipoUsuario::DUENO;
            else if (tipoSeleccionado == L"Administrador") tipo = Models::TipoUsuario::ADMINISTRADOR;
            else tipo = Models::TipoUsuario::CAJERO;

            Controllers::UsuarioController controller;

            if (modoNuevoUsuario)
            {
                // Verificar que el username no exista
                if (controller.existeUsername(username))
                {
                    MessageBox::Show(L"El nombre de usuario ya existe", L"Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                Models::Usuario nuevoUsuario(0, nombre, username, password, tipo, chkActivoUsuario->Checked);
                if (controller.crearUsuario(nuevoUsuario))
                {
                    MessageBox::Show(L"Usuario creado correctamente", L"Éxito",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                    OcultarFormularioUsuario();
                    CargarUsuarios();
                }
                else
                {
                    MessageBox::Show(L"Error al crear el usuario", L"Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
            else
            {
                Models::Usuario usuarioActualizado(usuarioEditandoId, nombre, username, password, tipo, chkActivoUsuario->Checked);
                if (controller.actualizarUsuario(usuarioActualizado))
                {
                    MessageBox::Show(L"Usuario actualizado correctamente", L"Éxito",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                    OcultarFormularioUsuario();
                    CargarUsuarios();
                }
                else
                {
                    MessageBox::Show(L"Error al actualizar el usuario", L"Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        System::Void MainForm::btnCancelarUsuario_Click(System::Object^ sender, System::EventArgs^ e)
        {
            OcultarFormularioUsuario();
        }

        void MainForm::MostrarFormularioUsuario(bool nuevo)
        {
            grpFormUsuario->Text = nuevo ? L"Nuevo Usuario" : L"Editar Usuario";
            grpFormUsuario->Visible = true;
        }

        void MainForm::OcultarFormularioUsuario()
        {
            grpFormUsuario->Visible = false;
            LimpiarFormularioUsuario();
        }

        void MainForm::LimpiarFormularioUsuario()
        {
            txtNombreUsuario->Text = "";
            txtUsernameUsuario->Text = "";
            txtPasswordUsuario->Text = "";
            cmbTipoUsuario->SelectedIndex = -1;
            chkActivoUsuario->Checked = true;
            usuarioEditandoId = 0;
        }

        // ===== VENTA DE BOLETOS =====

        void MainForm::CargarVentasRecientes()
        {
            dgvVentasRecientes->Rows->Clear();
            dgvVentasRecientes->Columns->Clear();

            dgvVentasRecientes->Columns->Add(L"Id", L"ID");
            dgvVentasRecientes->Columns->Add(L"Tipo", L"Tipo Boleto");
            dgvVentasRecientes->Columns->Add(L"Cantidad", L"Cantidad");
            dgvVentasRecientes->Columns->Add(L"Precio", L"Precio Unitario");
            dgvVentasRecientes->Columns->Add(L"Total", L"Total");
            dgvVentasRecientes->Columns->Add(L"Fecha", L"Fecha");

            Controllers::BoletoController controller;
            auto boletos = controller.listarBoletos();

            // Mostrar los últimos 50 boletos
            int count = 0;
            for (auto it = boletos.rbegin(); it != boletos.rend() && count < 50; ++it, ++count)
            {
                int rowIndex = dgvVentasRecientes->Rows->Add();
                dgvVentasRecientes->Rows[rowIndex]->Cells[0]->Value = it->getId();
                dgvVentasRecientes->Rows[rowIndex]->Cells[1]->Value = gcnew String(it->getTipoString().c_str());
                dgvVentasRecientes->Rows[rowIndex]->Cells[2]->Value = it->getCantidad();
                dgvVentasRecientes->Rows[rowIndex]->Cells[3]->Value = String::Format(L"${0:F2}", it->getPrecio());
                dgvVentasRecientes->Rows[rowIndex]->Cells[4]->Value = String::Format(L"${0:F2}", it->getTotal());
                dgvVentasRecientes->Rows[rowIndex]->Cells[5]->Value = gcnew String(it->getFechaVenta().c_str());
            }
        }

        System::Void MainForm::cmbTipoBoleto_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            ActualizarTotalVenta();
        }

        System::Void MainForm::numCantidad_ValueChanged(System::Object^ sender, System::EventArgs^ e)
        {
            ActualizarTotalVenta();
        }

        void MainForm::ActualizarTotalVenta()
        {
            double precio = ObtenerPrecioSeleccionado();
            int cantidad = (int)numCantidad->Value;
            double total = precio * cantidad;

            lblPrecioUnitario->Text = String::Format(L"Precio Unitario: ${0:F2}", precio);
            lblTotalVenta->Text = String::Format(L"Total: ${0:F2}", total);
        }

        double MainForm::ObtenerPrecioSeleccionado()
        {
            if (cmbTipoBoleto->SelectedIndex < 0) return 0;

            Models::TipoBoleto tipo;
            switch (cmbTipoBoleto->SelectedIndex)
            {
            case 0: tipo = Models::TipoBoleto::ADULTO; break;
            case 1: tipo = Models::TipoBoleto::NINO; break;
            case 2: tipo = Models::TipoBoleto::ADULTO_MAYOR; break;
            case 3: tipo = Models::TipoBoleto::ESTUDIANTE; break;
            default: tipo = Models::TipoBoleto::ADULTO; break;
            }

            return Controllers::BoletoController::obtenerPrecioBoleto(tipo);
        }

        System::Void MainForm::btnVender_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (cmbTipoBoleto->SelectedIndex < 0)
            {
                MessageBox::Show(L"Seleccione un tipo de boleto", L"Validación",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }

            Models::TipoBoleto tipo;
            switch (cmbTipoBoleto->SelectedIndex)
            {
            case 0: tipo = Models::TipoBoleto::ADULTO; break;
            case 1: tipo = Models::TipoBoleto::NINO; break;
            case 2: tipo = Models::TipoBoleto::ADULTO_MAYOR; break;
            case 3: tipo = Models::TipoBoleto::ESTUDIANTE; break;
            default: tipo = Models::TipoBoleto::ADULTO; break;
            }

            int cantidad = (int)numCantidad->Value;
            double total = ObtenerPrecioSeleccionado() * cantidad;

            if (MessageBox::Show(String::Format(L"¿Confirma la venta de {0} boleto(s) por ${1:F2}?", cantidad, total),
                L"Confirmar Venta", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
            {
                Controllers::BoletoController controller;
                if (controller.venderBoleto(tipo, cantidad, usuarioActual->getId()))
                {
                    MessageBox::Show(L"Venta realizada exitosamente", L"Éxito",
                        MessageBoxButtons::OK, MessageBoxIcon::Information);
                    CargarVentasRecientes();
                    numCantidad->Value = 1;
                }
                else
                {
                    MessageBox::Show(L"Error al realizar la venta", L"Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }
        }

        // ===== REPORTES =====

        void MainForm::CargarReporteGeneral()
        {
            Controllers::BoletoController controller;
            Controllers::ReporteVentas reporte = controller.generarReporteGeneral();

            lblTotalVentasReporte->Text = String::Format(L"Total Ventas: ${0:F2}", reporte.totalVentas);
            lblTotalBoletosReporte->Text = String::Format(L"Total Boletos Vendidos: {0}", reporte.totalBoletos);
            lblBoletosAdulto->Text = String::Format(L"Boletos Adulto: {0}", reporte.boletosAdulto);
            lblBoletosNino->Text = String::Format(L"Boletos Niño: {0}", reporte.boletosNino);
            lblBoletosAdultoMayor->Text = String::Format(L"Boletos Adulto Mayor: {0}", reporte.boletosAdultoMayor);
            lblBoletosEstudiante->Text = String::Format(L"Boletos Estudiante: {0}", reporte.boletosEstudiante);
        }

        System::Void MainForm::btnActualizarReporte_Click(System::Object^ sender, System::EventArgs^ e)
        {
            CargarReporteGeneral();
            MessageBox::Show(L"Reporte actualizado", L"Información",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
        }

        System::Void MainForm::btnReporteDiario_Click(System::Object^ sender, System::EventArgs^ e)
        {
            DateTime fecha = dtpFechaReporte->Value;
            String^ fechaStr = fecha.ToString(L"yyyy-MM-dd");
            std::string fechaStd = msclr::interop::marshal_as<std::string>(fechaStr);

            Controllers::BoletoController controller;
            Controllers::ReporteVentas reporte = controller.generarReporteDiario(fechaStd);

            String^ mensaje = String::Format(
                L"Reporte del día: {0}\n\n" +
                L"Total Ventas: ${1:F2}\n" +
                L"Total Boletos: {2}\n\n" +
                L"Desglose:\n" +
                L"- Adulto: {3}\n" +
                L"- Niño: {4}\n" +
                L"- Adulto Mayor: {5}\n" +
                L"- Estudiante: {6}",
                fechaStr, reporte.totalVentas, reporte.totalBoletos,
                reporte.boletosAdulto, reporte.boletosNino,
                reporte.boletosAdultoMayor, reporte.boletosEstudiante);

            MessageBox::Show(mensaje, L"Reporte Diario", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }
}
