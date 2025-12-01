#include "main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    proyectoZoo::main^ form = gcnew proyectoZoo::main();
    Application::Run(form);
    return 0;
}

