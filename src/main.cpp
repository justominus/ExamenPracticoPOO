// main.cpp - Punto de entrada del Sistema de Gestión del Zoológico
// Sistema desarrollado en C++ con Windows Forms
// Perfiles: Dueño (acceso completo), Administrador (gestión), Cajero (ventas)
// Módulos: Login, CRUD usuarios, venta boletos, reportes

#include "views/LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    
    // Crear directorio de datos si no existe
    System::IO::Directory::CreateDirectory("data");
    
    // Iniciar con el formulario de login
    ZooManagement::Views::LoginForm^ loginForm = gcnew ZooManagement::Views::LoginForm();
    Application::Run(loginForm);
    
    return 0;
}
