#pragma once

#include "../controllers/UsuarioController.h"
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
        /// Formulario de Login para el Sistema de Gestión del Zoológico
        /// Permite autenticar usuarios con diferentes perfiles:
        /// - Dueño: Acceso completo
        /// - Administrador: Gestión de usuarios y reportes
        /// - Cajero: Venta de boletos
        /// </summary>
        public ref class LoginForm : public System::Windows::Forms::Form
        {
        public:
            LoginForm(void)
            {
                InitializeComponent();
            }

        protected:
            ~LoginForm()
            {
                if (components)
                {
                    delete components;
                }
            }

        private:
            System::ComponentModel::Container ^components;
            System::Windows::Forms::TextBox^ txtUsername;
            System::Windows::Forms::TextBox^ txtPassword;
            System::Windows::Forms::Button^ btnLogin;
            System::Windows::Forms::Button^ btnCancelar;
            System::Windows::Forms::Label^ lblUsername;
            System::Windows::Forms::Label^ lblPassword;
            System::Windows::Forms::Label^ lblTitulo;
            System::Windows::Forms::PictureBox^ picLogo;
            System::Windows::Forms::Panel^ panelLogin;
            System::Windows::Forms::Label^ lblError;

#pragma region Windows Form Designer generated code
            void InitializeComponent(void)
            {
                this->txtUsername = (gcnew System::Windows::Forms::TextBox());
                this->txtPassword = (gcnew System::Windows::Forms::TextBox());
                this->btnLogin = (gcnew System::Windows::Forms::Button());
                this->btnCancelar = (gcnew System::Windows::Forms::Button());
                this->lblUsername = (gcnew System::Windows::Forms::Label());
                this->lblPassword = (gcnew System::Windows::Forms::Label());
                this->lblTitulo = (gcnew System::Windows::Forms::Label());
                this->panelLogin = (gcnew System::Windows::Forms::Panel());
                this->lblError = (gcnew System::Windows::Forms::Label());
                this->panelLogin->SuspendLayout();
                this->SuspendLayout();
                // 
                // lblTitulo
                // 
                this->lblTitulo->AutoSize = true;
                this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
                this->lblTitulo->ForeColor = System::Drawing::Color::ForestGreen;
                this->lblTitulo->Location = System::Drawing::Point(80, 20);
                this->lblTitulo->Name = L"lblTitulo";
                this->lblTitulo->Size = System::Drawing::Size(240, 32);
                this->lblTitulo->TabIndex = 0;
                this->lblTitulo->Text = L"Sistema Zoo Manager";
                // 
                // lblUsername
                // 
                this->lblUsername->AutoSize = true;
                this->lblUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
                this->lblUsername->Location = System::Drawing::Point(30, 80);
                this->lblUsername->Name = L"lblUsername";
                this->lblUsername->Size = System::Drawing::Size(56, 19);
                this->lblUsername->TabIndex = 1;
                this->lblUsername->Text = L"Usuario:";
                // 
                // txtUsername
                // 
                this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
                this->txtUsername->Location = System::Drawing::Point(30, 105);
                this->txtUsername->Name = L"txtUsername";
                this->txtUsername->Size = System::Drawing::Size(340, 25);
                this->txtUsername->TabIndex = 2;
                // 
                // lblPassword
                // 
                this->lblPassword->AutoSize = true;
                this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
                this->lblPassword->Location = System::Drawing::Point(30, 145);
                this->lblPassword->Name = L"lblPassword";
                this->lblPassword->Size = System::Drawing::Size(78, 19);
                this->lblPassword->TabIndex = 3;
                this->lblPassword->Text = L"Contraseña:";
                // 
                // txtPassword
                // 
                this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
                this->txtPassword->Location = System::Drawing::Point(30, 170);
                this->txtPassword->Name = L"txtPassword";
                this->txtPassword->PasswordChar = '*';
                this->txtPassword->Size = System::Drawing::Size(340, 25);
                this->txtPassword->TabIndex = 4;
                // 
                // lblError
                // 
                this->lblError->AutoSize = true;
                this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
                this->lblError->ForeColor = System::Drawing::Color::Red;
                this->lblError->Location = System::Drawing::Point(30, 205);
                this->lblError->Name = L"lblError";
                this->lblError->Size = System::Drawing::Size(0, 15);
                this->lblError->TabIndex = 5;
                this->lblError->Visible = false;
                // 
                // btnLogin
                // 
                this->btnLogin->BackColor = System::Drawing::Color::ForestGreen;
                this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
                this->btnLogin->ForeColor = System::Drawing::Color::White;
                this->btnLogin->Location = System::Drawing::Point(30, 230);
                this->btnLogin->Name = L"btnLogin";
                this->btnLogin->Size = System::Drawing::Size(160, 40);
                this->btnLogin->TabIndex = 6;
                this->btnLogin->Text = L"Iniciar Sesión";
                this->btnLogin->UseVisualStyleBackColor = false;
                this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
                // 
                // btnCancelar
                // 
                this->btnCancelar->BackColor = System::Drawing::Color::Gray;
                this->btnCancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
                this->btnCancelar->ForeColor = System::Drawing::Color::White;
                this->btnCancelar->Location = System::Drawing::Point(210, 230);
                this->btnCancelar->Name = L"btnCancelar";
                this->btnCancelar->Size = System::Drawing::Size(160, 40);
                this->btnCancelar->TabIndex = 7;
                this->btnCancelar->Text = L"Cancelar";
                this->btnCancelar->UseVisualStyleBackColor = false;
                this->btnCancelar->Click += gcnew System::EventHandler(this, &LoginForm::btnCancelar_Click);
                // 
                // panelLogin
                // 
                this->panelLogin->BackColor = System::Drawing::Color::White;
                this->panelLogin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
                this->panelLogin->Controls->Add(this->lblTitulo);
                this->panelLogin->Controls->Add(this->lblUsername);
                this->panelLogin->Controls->Add(this->txtUsername);
                this->panelLogin->Controls->Add(this->lblPassword);
                this->panelLogin->Controls->Add(this->txtPassword);
                this->panelLogin->Controls->Add(this->lblError);
                this->panelLogin->Controls->Add(this->btnLogin);
                this->panelLogin->Controls->Add(this->btnCancelar);
                this->panelLogin->Location = System::Drawing::Point(50, 30);
                this->panelLogin->Name = L"panelLogin";
                this->panelLogin->Size = System::Drawing::Size(400, 300);
                this->panelLogin->TabIndex = 0;
                // 
                // LoginForm
                // 
                this->AcceptButton = this->btnLogin;
                this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
                this->BackColor = System::Drawing::Color::FromArgb(240, 240, 240);
                this->ClientSize = System::Drawing::Size(500, 360);
                this->Controls->Add(this->panelLogin);
                this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
                this->MaximizeBox = false;
                this->MinimizeBox = false;
                this->Name = L"LoginForm";
                this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
                this->Text = L"Zoo Manager - Iniciar Sesión";
                this->panelLogin->ResumeLayout(false);
                this->panelLogin->PerformLayout();
                this->ResumeLayout(false);
            }
#pragma endregion

        private:
            System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e);
            System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e);
            void MostrarError(System::String^ mensaje);
            void LimpiarError();
        };
    }
}
