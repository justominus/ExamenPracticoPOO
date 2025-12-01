#pragma once

#include "../controllers/UsuarioController.h"
#include "../controllers/BoletoController.h"
#include "../models/Usuario.h"

namespace ZooManagement {
    namespace Views {

        using namespace System;
        using namespace System::ComponentModel;
        using namespace System::Collections;
        using namespace System::Windows::Forms;
        using namespace System::Data;
        using namespace System::Drawing;

        /// <summary>
        /// Formulario Principal del Sistema de Gestión del Zoológico
        /// Contiene pestañas para los diferentes módulos según el perfil del usuario:
        /// - Gestión de Usuarios (Dueño, Administrador)
        /// - Venta de Boletos (Todos)
        /// - Reportes (Dueño, Administrador)
        /// </summary>
        public ref class MainForm : public System::Windows::Forms::Form
        {
        private:
            Models::Usuario* usuarioActual;

        public:
            MainForm(Models::Usuario* usuario)
            {
                usuarioActual = usuario;
                InitializeComponent();
                ConfigurarPermisos();
                CargarDatosIniciales();
            }

        protected:
            ~MainForm()
            {
                if (components)
                {
                    delete components;
                }
            }

        private:
            System::ComponentModel::Container ^components;
            
            // Menú y barra de estado
            System::Windows::Forms::MenuStrip^ menuPrincipal;
            System::Windows::Forms::ToolStripMenuItem^ menuArchivo;
            System::Windows::Forms::ToolStripMenuItem^ menuCerrarSesion;
            System::Windows::Forms::ToolStripMenuItem^ menuSalir;
            System::Windows::Forms::StatusStrip^ statusBar;
            System::Windows::Forms::ToolStripStatusLabel^ lblUsuarioActual;
            System::Windows::Forms::ToolStripStatusLabel^ lblPerfilActual;
            
            // TabControl principal
            System::Windows::Forms::TabControl^ tabControl;
            System::Windows::Forms::TabPage^ tabUsuarios;
            System::Windows::Forms::TabPage^ tabVentas;
            System::Windows::Forms::TabPage^ tabReportes;
            
            // Panel Usuarios
            System::Windows::Forms::DataGridView^ dgvUsuarios;
            System::Windows::Forms::Button^ btnNuevoUsuario;
            System::Windows::Forms::Button^ btnEditarUsuario;
            System::Windows::Forms::Button^ btnEliminarUsuario;
            System::Windows::Forms::GroupBox^ grpFormUsuario;
            System::Windows::Forms::TextBox^ txtNombreUsuario;
            System::Windows::Forms::TextBox^ txtUsernameUsuario;
            System::Windows::Forms::TextBox^ txtPasswordUsuario;
            System::Windows::Forms::ComboBox^ cmbTipoUsuario;
            System::Windows::Forms::CheckBox^ chkActivoUsuario;
            System::Windows::Forms::Button^ btnGuardarUsuario;
            System::Windows::Forms::Button^ btnCancelarUsuario;
            System::Windows::Forms::Label^ lblNombre;
            System::Windows::Forms::Label^ lblUsernameForm;
            System::Windows::Forms::Label^ lblPasswordForm;
            System::Windows::Forms::Label^ lblTipoUsuario;
            
            // Panel Ventas
            System::Windows::Forms::GroupBox^ grpVenta;
            System::Windows::Forms::ComboBox^ cmbTipoBoleto;
            System::Windows::Forms::NumericUpDown^ numCantidad;
            System::Windows::Forms::Label^ lblPrecioUnitario;
            System::Windows::Forms::Label^ lblTotalVenta;
            System::Windows::Forms::Button^ btnVender;
            System::Windows::Forms::DataGridView^ dgvVentasRecientes;
            System::Windows::Forms::Label^ lblTipoBoleto;
            System::Windows::Forms::Label^ lblCantidad;
            
            // Panel Reportes
            System::Windows::Forms::GroupBox^ grpReporteGeneral;
            System::Windows::Forms::Label^ lblTotalVentasReporte;
            System::Windows::Forms::Label^ lblTotalBoletosReporte;
            System::Windows::Forms::Label^ lblBoletosAdulto;
            System::Windows::Forms::Label^ lblBoletosNino;
            System::Windows::Forms::Label^ lblBoletosAdultoMayor;
            System::Windows::Forms::Label^ lblBoletosEstudiante;
            System::Windows::Forms::Button^ btnActualizarReporte;
            System::Windows::Forms::DateTimePicker^ dtpFechaReporte;
            System::Windows::Forms::Button^ btnReporteDiario;

#pragma region Windows Form Designer generated code
            void InitializeComponent(void)
            {
                this->components = gcnew System::ComponentModel::Container();
                
                // Inicializar controles
                this->menuPrincipal = gcnew System::Windows::Forms::MenuStrip();
                this->menuArchivo = gcnew System::Windows::Forms::ToolStripMenuItem();
                this->menuCerrarSesion = gcnew System::Windows::Forms::ToolStripMenuItem();
                this->menuSalir = gcnew System::Windows::Forms::ToolStripMenuItem();
                this->statusBar = gcnew System::Windows::Forms::StatusStrip();
                this->lblUsuarioActual = gcnew System::Windows::Forms::ToolStripStatusLabel();
                this->lblPerfilActual = gcnew System::Windows::Forms::ToolStripStatusLabel();
                
                this->tabControl = gcnew System::Windows::Forms::TabControl();
                this->tabUsuarios = gcnew System::Windows::Forms::TabPage();
                this->tabVentas = gcnew System::Windows::Forms::TabPage();
                this->tabReportes = gcnew System::Windows::Forms::TabPage();
                
                // Controles de Usuarios
                this->dgvUsuarios = gcnew System::Windows::Forms::DataGridView();
                this->btnNuevoUsuario = gcnew System::Windows::Forms::Button();
                this->btnEditarUsuario = gcnew System::Windows::Forms::Button();
                this->btnEliminarUsuario = gcnew System::Windows::Forms::Button();
                this->grpFormUsuario = gcnew System::Windows::Forms::GroupBox();
                this->txtNombreUsuario = gcnew System::Windows::Forms::TextBox();
                this->txtUsernameUsuario = gcnew System::Windows::Forms::TextBox();
                this->txtPasswordUsuario = gcnew System::Windows::Forms::TextBox();
                this->cmbTipoUsuario = gcnew System::Windows::Forms::ComboBox();
                this->chkActivoUsuario = gcnew System::Windows::Forms::CheckBox();
                this->btnGuardarUsuario = gcnew System::Windows::Forms::Button();
                this->btnCancelarUsuario = gcnew System::Windows::Forms::Button();
                this->lblNombre = gcnew System::Windows::Forms::Label();
                this->lblUsernameForm = gcnew System::Windows::Forms::Label();
                this->lblPasswordForm = gcnew System::Windows::Forms::Label();
                this->lblTipoUsuario = gcnew System::Windows::Forms::Label();
                
                // Controles de Ventas
                this->grpVenta = gcnew System::Windows::Forms::GroupBox();
                this->cmbTipoBoleto = gcnew System::Windows::Forms::ComboBox();
                this->numCantidad = gcnew System::Windows::Forms::NumericUpDown();
                this->lblPrecioUnitario = gcnew System::Windows::Forms::Label();
                this->lblTotalVenta = gcnew System::Windows::Forms::Label();
                this->btnVender = gcnew System::Windows::Forms::Button();
                this->dgvVentasRecientes = gcnew System::Windows::Forms::DataGridView();
                this->lblTipoBoleto = gcnew System::Windows::Forms::Label();
                this->lblCantidad = gcnew System::Windows::Forms::Label();
                
                // Controles de Reportes
                this->grpReporteGeneral = gcnew System::Windows::Forms::GroupBox();
                this->lblTotalVentasReporte = gcnew System::Windows::Forms::Label();
                this->lblTotalBoletosReporte = gcnew System::Windows::Forms::Label();
                this->lblBoletosAdulto = gcnew System::Windows::Forms::Label();
                this->lblBoletosNino = gcnew System::Windows::Forms::Label();
                this->lblBoletosAdultoMayor = gcnew System::Windows::Forms::Label();
                this->lblBoletosEstudiante = gcnew System::Windows::Forms::Label();
                this->btnActualizarReporte = gcnew System::Windows::Forms::Button();
                this->dtpFechaReporte = gcnew System::Windows::Forms::DateTimePicker();
                this->btnReporteDiario = gcnew System::Windows::Forms::Button();
                
                this->menuPrincipal->SuspendLayout();
                this->statusBar->SuspendLayout();
                this->tabControl->SuspendLayout();
                this->tabUsuarios->SuspendLayout();
                this->tabVentas->SuspendLayout();
                this->tabReportes->SuspendLayout();
                this->SuspendLayout();
                
                // 
                // menuPrincipal
                // 
                this->menuPrincipal->Items->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem^>(1) { this->menuArchivo });
                this->menuPrincipal->Location = System::Drawing::Point(0, 0);
                this->menuPrincipal->Name = L"menuPrincipal";
                this->menuPrincipal->Size = System::Drawing::Size(900, 24);
                this->menuPrincipal->TabIndex = 0;
                
                // 
                // menuArchivo
                // 
                this->menuArchivo->DropDownItems->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem^>(2) { this->menuCerrarSesion, this->menuSalir });
                this->menuArchivo->Name = L"menuArchivo";
                this->menuArchivo->Size = System::Drawing::Size(60, 20);
                this->menuArchivo->Text = L"Archivo";
                
                // 
                // menuCerrarSesion
                // 
                this->menuCerrarSesion->Name = L"menuCerrarSesion";
                this->menuCerrarSesion->Size = System::Drawing::Size(152, 22);
                this->menuCerrarSesion->Text = L"Cerrar Sesión";
                this->menuCerrarSesion->Click += gcnew System::EventHandler(this, &MainForm::menuCerrarSesion_Click);
                
                // 
                // menuSalir
                // 
                this->menuSalir->Name = L"menuSalir";
                this->menuSalir->Size = System::Drawing::Size(152, 22);
                this->menuSalir->Text = L"Salir";
                this->menuSalir->Click += gcnew System::EventHandler(this, &MainForm::menuSalir_Click);
                
                // 
                // statusBar
                // 
                this->statusBar->Items->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem^>(2) { this->lblUsuarioActual, this->lblPerfilActual });
                this->statusBar->Location = System::Drawing::Point(0, 528);
                this->statusBar->Name = L"statusBar";
                this->statusBar->Size = System::Drawing::Size(900, 22);
                this->statusBar->TabIndex = 1;
                
                // 
                // lblUsuarioActual
                // 
                this->lblUsuarioActual->Name = L"lblUsuarioActual";
                this->lblUsuarioActual->Size = System::Drawing::Size(50, 17);
                this->lblUsuarioActual->Text = L"Usuario:";
                
                // 
                // lblPerfilActual
                // 
                this->lblPerfilActual->Name = L"lblPerfilActual";
                this->lblPerfilActual->Size = System::Drawing::Size(40, 17);
                this->lblPerfilActual->Text = L"Perfil:";
                
                // 
                // tabControl
                // 
                this->tabControl->Controls->Add(this->tabUsuarios);
                this->tabControl->Controls->Add(this->tabVentas);
                this->tabControl->Controls->Add(this->tabReportes);
                this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
                this->tabControl->Location = System::Drawing::Point(0, 24);
                this->tabControl->Name = L"tabControl";
                this->tabControl->SelectedIndex = 0;
                this->tabControl->Size = System::Drawing::Size(900, 504);
                this->tabControl->TabIndex = 2;
                
                // ===== TAB USUARIOS =====
                this->tabUsuarios->Text = L"Gestión de Usuarios";
                this->tabUsuarios->Padding = System::Windows::Forms::Padding(10);
                
                // DataGridView Usuarios
                this->dgvUsuarios->Location = System::Drawing::Point(10, 10);
                this->dgvUsuarios->Size = System::Drawing::Size(550, 200);
                this->dgvUsuarios->AllowUserToAddRows = false;
                this->dgvUsuarios->AllowUserToDeleteRows = false;
                this->dgvUsuarios->ReadOnly = true;
                this->dgvUsuarios->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
                this->dgvUsuarios->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
                
                // Botones CRUD Usuarios
                this->btnNuevoUsuario->Text = L"Nuevo";
                this->btnNuevoUsuario->Location = System::Drawing::Point(580, 10);
                this->btnNuevoUsuario->Size = System::Drawing::Size(100, 30);
                this->btnNuevoUsuario->Click += gcnew System::EventHandler(this, &MainForm::btnNuevoUsuario_Click);
                
                this->btnEditarUsuario->Text = L"Editar";
                this->btnEditarUsuario->Location = System::Drawing::Point(580, 50);
                this->btnEditarUsuario->Size = System::Drawing::Size(100, 30);
                this->btnEditarUsuario->Click += gcnew System::EventHandler(this, &MainForm::btnEditarUsuario_Click);
                
                this->btnEliminarUsuario->Text = L"Eliminar";
                this->btnEliminarUsuario->Location = System::Drawing::Point(580, 90);
                this->btnEliminarUsuario->Size = System::Drawing::Size(100, 30);
                this->btnEliminarUsuario->Click += gcnew System::EventHandler(this, &MainForm::btnEliminarUsuario_Click);
                
                // Grupo Formulario Usuario
                this->grpFormUsuario->Text = L"Datos del Usuario";
                this->grpFormUsuario->Location = System::Drawing::Point(10, 220);
                this->grpFormUsuario->Size = System::Drawing::Size(550, 200);
                this->grpFormUsuario->Visible = false;
                
                this->lblNombre->Text = L"Nombre:";
                this->lblNombre->Location = System::Drawing::Point(20, 30);
                this->lblNombre->AutoSize = true;
                
                this->txtNombreUsuario->Location = System::Drawing::Point(100, 28);
                this->txtNombreUsuario->Size = System::Drawing::Size(200, 23);
                
                this->lblUsernameForm->Text = L"Usuario:";
                this->lblUsernameForm->Location = System::Drawing::Point(20, 60);
                this->lblUsernameForm->AutoSize = true;
                
                this->txtUsernameUsuario->Location = System::Drawing::Point(100, 58);
                this->txtUsernameUsuario->Size = System::Drawing::Size(200, 23);
                
                this->lblPasswordForm->Text = L"Contraseña:";
                this->lblPasswordForm->Location = System::Drawing::Point(20, 90);
                this->lblPasswordForm->AutoSize = true;
                
                this->txtPasswordUsuario->Location = System::Drawing::Point(100, 88);
                this->txtPasswordUsuario->Size = System::Drawing::Size(200, 23);
                
                this->lblTipoUsuario->Text = L"Tipo:";
                this->lblTipoUsuario->Location = System::Drawing::Point(320, 30);
                this->lblTipoUsuario->AutoSize = true;
                
                this->cmbTipoUsuario->Location = System::Drawing::Point(380, 28);
                this->cmbTipoUsuario->Size = System::Drawing::Size(150, 23);
                this->cmbTipoUsuario->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
                this->cmbTipoUsuario->Items->AddRange(gcnew cli::array<Object^>(3) { L"Dueño", L"Administrador", L"Cajero" });
                
                this->chkActivoUsuario->Text = L"Usuario Activo";
                this->chkActivoUsuario->Location = System::Drawing::Point(380, 58);
                this->chkActivoUsuario->Checked = true;
                
                this->btnGuardarUsuario->Text = L"Guardar";
                this->btnGuardarUsuario->Location = System::Drawing::Point(100, 140);
                this->btnGuardarUsuario->Size = System::Drawing::Size(100, 30);
                this->btnGuardarUsuario->Click += gcnew System::EventHandler(this, &MainForm::btnGuardarUsuario_Click);
                
                this->btnCancelarUsuario->Text = L"Cancelar";
                this->btnCancelarUsuario->Location = System::Drawing::Point(210, 140);
                this->btnCancelarUsuario->Size = System::Drawing::Size(100, 30);
                this->btnCancelarUsuario->Click += gcnew System::EventHandler(this, &MainForm::btnCancelarUsuario_Click);
                
                // Agregar controles al grupo
                this->grpFormUsuario->Controls->Add(this->lblNombre);
                this->grpFormUsuario->Controls->Add(this->txtNombreUsuario);
                this->grpFormUsuario->Controls->Add(this->lblUsernameForm);
                this->grpFormUsuario->Controls->Add(this->txtUsernameUsuario);
                this->grpFormUsuario->Controls->Add(this->lblPasswordForm);
                this->grpFormUsuario->Controls->Add(this->txtPasswordUsuario);
                this->grpFormUsuario->Controls->Add(this->lblTipoUsuario);
                this->grpFormUsuario->Controls->Add(this->cmbTipoUsuario);
                this->grpFormUsuario->Controls->Add(this->chkActivoUsuario);
                this->grpFormUsuario->Controls->Add(this->btnGuardarUsuario);
                this->grpFormUsuario->Controls->Add(this->btnCancelarUsuario);
                
                // Agregar controles al tab Usuarios
                this->tabUsuarios->Controls->Add(this->dgvUsuarios);
                this->tabUsuarios->Controls->Add(this->btnNuevoUsuario);
                this->tabUsuarios->Controls->Add(this->btnEditarUsuario);
                this->tabUsuarios->Controls->Add(this->btnEliminarUsuario);
                this->tabUsuarios->Controls->Add(this->grpFormUsuario);
                
                // ===== TAB VENTAS =====
                this->tabVentas->Text = L"Venta de Boletos";
                this->tabVentas->Padding = System::Windows::Forms::Padding(10);
                
                // Grupo Venta
                this->grpVenta->Text = L"Nueva Venta";
                this->grpVenta->Location = System::Drawing::Point(10, 10);
                this->grpVenta->Size = System::Drawing::Size(400, 180);
                
                this->lblTipoBoleto->Text = L"Tipo de Boleto:";
                this->lblTipoBoleto->Location = System::Drawing::Point(20, 30);
                this->lblTipoBoleto->AutoSize = true;
                
                this->cmbTipoBoleto->Location = System::Drawing::Point(120, 28);
                this->cmbTipoBoleto->Size = System::Drawing::Size(150, 23);
                this->cmbTipoBoleto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
                this->cmbTipoBoleto->Items->AddRange(gcnew cli::array<Object^>(4) { L"Adulto", L"Niño", L"Adulto Mayor", L"Estudiante" });
                this->cmbTipoBoleto->SelectedIndex = 0;
                this->cmbTipoBoleto->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cmbTipoBoleto_SelectedIndexChanged);
                
                this->lblCantidad->Text = L"Cantidad:";
                this->lblCantidad->Location = System::Drawing::Point(20, 60);
                this->lblCantidad->AutoSize = true;
                
                this->numCantidad->Location = System::Drawing::Point(120, 58);
                this->numCantidad->Size = System::Drawing::Size(80, 23);
                this->numCantidad->Minimum = 1;
                this->numCantidad->Maximum = 100;
                this->numCantidad->Value = 1;
                this->numCantidad->ValueChanged += gcnew System::EventHandler(this, &MainForm::numCantidad_ValueChanged);
                
                this->lblPrecioUnitario->Text = L"Precio Unitario: $150.00";
                this->lblPrecioUnitario->Location = System::Drawing::Point(20, 95);
                this->lblPrecioUnitario->AutoSize = true;
                this->lblPrecioUnitario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
                
                this->lblTotalVenta->Text = L"Total: $150.00";
                this->lblTotalVenta->Location = System::Drawing::Point(20, 120);
                this->lblTotalVenta->AutoSize = true;
                this->lblTotalVenta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
                this->lblTotalVenta->ForeColor = System::Drawing::Color::ForestGreen;
                
                this->btnVender->Text = L"Realizar Venta";
                this->btnVender->Location = System::Drawing::Point(120, 145);
                this->btnVender->Size = System::Drawing::Size(150, 30);
                this->btnVender->BackColor = System::Drawing::Color::ForestGreen;
                this->btnVender->ForeColor = System::Drawing::Color::White;
                this->btnVender->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                this->btnVender->Click += gcnew System::EventHandler(this, &MainForm::btnVender_Click);
                
                this->grpVenta->Controls->Add(this->lblTipoBoleto);
                this->grpVenta->Controls->Add(this->cmbTipoBoleto);
                this->grpVenta->Controls->Add(this->lblCantidad);
                this->grpVenta->Controls->Add(this->numCantidad);
                this->grpVenta->Controls->Add(this->lblPrecioUnitario);
                this->grpVenta->Controls->Add(this->lblTotalVenta);
                this->grpVenta->Controls->Add(this->btnVender);
                
                // DataGridView Ventas Recientes
                this->dgvVentasRecientes->Location = System::Drawing::Point(10, 200);
                this->dgvVentasRecientes->Size = System::Drawing::Size(860, 250);
                this->dgvVentasRecientes->AllowUserToAddRows = false;
                this->dgvVentasRecientes->AllowUserToDeleteRows = false;
                this->dgvVentasRecientes->ReadOnly = true;
                this->dgvVentasRecientes->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
                
                this->tabVentas->Controls->Add(this->grpVenta);
                this->tabVentas->Controls->Add(this->dgvVentasRecientes);
                
                // ===== TAB REPORTES =====
                this->tabReportes->Text = L"Reportes";
                this->tabReportes->Padding = System::Windows::Forms::Padding(10);
                
                // Grupo Reporte General
                this->grpReporteGeneral->Text = L"Reporte de Ventas";
                this->grpReporteGeneral->Location = System::Drawing::Point(10, 10);
                this->grpReporteGeneral->Size = System::Drawing::Size(400, 250);
                
                this->lblTotalVentasReporte->Text = L"Total Ventas: $0.00";
                this->lblTotalVentasReporte->Location = System::Drawing::Point(20, 40);
                this->lblTotalVentasReporte->AutoSize = true;
                this->lblTotalVentasReporte->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
                this->lblTotalVentasReporte->ForeColor = System::Drawing::Color::ForestGreen;
                
                this->lblTotalBoletosReporte->Text = L"Total Boletos Vendidos: 0";
                this->lblTotalBoletosReporte->Location = System::Drawing::Point(20, 80);
                this->lblTotalBoletosReporte->AutoSize = true;
                this->lblTotalBoletosReporte->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
                
                this->lblBoletosAdulto->Text = L"Boletos Adulto: 0";
                this->lblBoletosAdulto->Location = System::Drawing::Point(40, 115);
                this->lblBoletosAdulto->AutoSize = true;
                
                this->lblBoletosNino->Text = L"Boletos Niño: 0";
                this->lblBoletosNino->Location = System::Drawing::Point(40, 140);
                this->lblBoletosNino->AutoSize = true;
                
                this->lblBoletosAdultoMayor->Text = L"Boletos Adulto Mayor: 0";
                this->lblBoletosAdultoMayor->Location = System::Drawing::Point(40, 165);
                this->lblBoletosAdultoMayor->AutoSize = true;
                
                this->lblBoletosEstudiante->Text = L"Boletos Estudiante: 0";
                this->lblBoletosEstudiante->Location = System::Drawing::Point(40, 190);
                this->lblBoletosEstudiante->AutoSize = true;
                
                this->btnActualizarReporte->Text = L"Actualizar Reporte";
                this->btnActualizarReporte->Location = System::Drawing::Point(20, 220);
                this->btnActualizarReporte->Size = System::Drawing::Size(150, 25);
                this->btnActualizarReporte->Click += gcnew System::EventHandler(this, &MainForm::btnActualizarReporte_Click);
                
                this->grpReporteGeneral->Controls->Add(this->lblTotalVentasReporte);
                this->grpReporteGeneral->Controls->Add(this->lblTotalBoletosReporte);
                this->grpReporteGeneral->Controls->Add(this->lblBoletosAdulto);
                this->grpReporteGeneral->Controls->Add(this->lblBoletosNino);
                this->grpReporteGeneral->Controls->Add(this->lblBoletosAdultoMayor);
                this->grpReporteGeneral->Controls->Add(this->lblBoletosEstudiante);
                this->grpReporteGeneral->Controls->Add(this->btnActualizarReporte);
                
                // Controles de Reporte Diario
                this->dtpFechaReporte->Location = System::Drawing::Point(430, 30);
                this->dtpFechaReporte->Size = System::Drawing::Size(200, 23);
                
                this->btnReporteDiario->Text = L"Ver Reporte del Día";
                this->btnReporteDiario->Location = System::Drawing::Point(430, 60);
                this->btnReporteDiario->Size = System::Drawing::Size(150, 25);
                this->btnReporteDiario->Click += gcnew System::EventHandler(this, &MainForm::btnReporteDiario_Click);
                
                this->tabReportes->Controls->Add(this->grpReporteGeneral);
                this->tabReportes->Controls->Add(this->dtpFechaReporte);
                this->tabReportes->Controls->Add(this->btnReporteDiario);
                
                // 
                // MainForm
                // 
                this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
                this->ClientSize = System::Drawing::Size(900, 550);
                this->Controls->Add(this->tabControl);
                this->Controls->Add(this->statusBar);
                this->Controls->Add(this->menuPrincipal);
                this->MainMenuStrip = this->menuPrincipal;
                this->Name = L"MainForm";
                this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
                this->Text = L"Zoo Manager - Sistema de Gestión";
                this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
                
                this->menuPrincipal->ResumeLayout(false);
                this->menuPrincipal->PerformLayout();
                this->statusBar->ResumeLayout(false);
                this->statusBar->PerformLayout();
                this->tabControl->ResumeLayout(false);
                this->tabUsuarios->ResumeLayout(false);
                this->tabVentas->ResumeLayout(false);
                this->tabReportes->ResumeLayout(false);
                this->ResumeLayout(false);
                this->PerformLayout();
            }
#pragma endregion

        private:
            // Configuración de permisos según perfil
            void ConfigurarPermisos();
            void CargarDatosIniciales();
            
            // Eventos de menú
            System::Void menuCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void menuSalir_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
            
            // Eventos de gestión de usuarios
            void CargarUsuarios();
            System::Void btnNuevoUsuario_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void btnEditarUsuario_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void btnEliminarUsuario_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void btnGuardarUsuario_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void btnCancelarUsuario_Click(System::Object^ sender, System::EventArgs^ e);
            void MostrarFormularioUsuario(bool nuevo);
            void OcultarFormularioUsuario();
            void LimpiarFormularioUsuario();
            
            // Eventos de venta de boletos
            void CargarVentasRecientes();
            System::Void cmbTipoBoleto_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
            System::Void numCantidad_ValueChanged(System::Object^ sender, System::EventArgs^ e);
            System::Void btnVender_Click(System::Object^ sender, System::EventArgs^ e);
            void ActualizarTotalVenta();
            double ObtenerPrecioSeleccionado();
            
            // Eventos de reportes
            void CargarReporteGeneral();
            System::Void btnActualizarReporte_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void btnReporteDiario_Click(System::Object^ sender, System::EventArgs^ e);
            
            // Variables de estado
            int usuarioEditandoId;
            bool modoNuevoUsuario;
        };
    }
}
