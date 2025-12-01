#include "LoginForm.h"
#include "MainForm.h"
#include <msclr/marshal_cppstd.h>

namespace ZooManagement {
    namespace Views {

        System::Void LoginForm::btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
        {
            LimpiarError();

            if (String::IsNullOrWhiteSpace(txtUsername->Text))
            {
                MostrarError("Por favor ingrese su usuario");
                txtUsername->Focus();
                return;
            }

            if (String::IsNullOrWhiteSpace(txtPassword->Text))
            {
                MostrarError("Por favor ingrese su contraseña");
                txtPassword->Focus();
                return;
            }

            // Convertir de System::String a std::string
            std::string username = msclr::interop::marshal_as<std::string>(txtUsername->Text);
            std::string password = msclr::interop::marshal_as<std::string>(txtPassword->Text);

            // Autenticar usuario
            Controllers::UsuarioController controller;
            Models::Usuario* usuario = controller.autenticar(username, password);

            if (usuario != nullptr)
            {
                // Login exitoso - abrir formulario principal
                this->Hide();
                MainForm^ mainForm = gcnew MainForm(usuario);
                mainForm->ShowDialog();
                this->Close();
            }
            else
            {
                MostrarError("Usuario o contraseña incorrectos");
                txtPassword->Text = "";
                txtPassword->Focus();
            }
        }

        System::Void LoginForm::btnCancelar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }

        void LoginForm::MostrarError(System::String^ mensaje)
        {
            lblError->Text = mensaje;
            lblError->Visible = true;
        }

        void LoginForm::LimpiarError()
        {
            lblError->Text = "";
            lblError->Visible = false;
        }
    }
}
