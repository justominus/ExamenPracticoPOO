#pragma once

#include "VerEmpleado.h"
#include "boleteria.h"
#include "Usuarios.h"
#include "BalanceGeneral.h"
#include "Animales.h"
// forward declare Login
// #include "Login.h"

namespace proyectoZoo {

    ref class Login;

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuDueño
	/// </summary>
	public ref class MenuDueño : public System::Windows::Forms::Form
	{
	public:
		MenuDueño(void)
		{
			InitializeComponent();
			// keep default size from designer / Windows
			// TODO: agregar código de constructor aquí
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuDueño()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panelContent;

	private:


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	internal:
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ verEmpleadoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ verAnimalesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ balanceGeneralToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cerrarSesionToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuDueño::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuStrip3 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->verEmpleadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->verAnimalesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->balanceGeneralToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cerrarSesionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panelContent->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(291, 172);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(332, 126);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->panelContent->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panelContent->Controls->Add(this->pictureBox2);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 30);
			this->panelContent->Margin = System::Windows::Forms::Padding(2);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(887, 477);
			this->panelContent->TabIndex = 11;
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			this->contextMenuStrip2->ImageScalingSize = System::Drawing::Size(32, 32);
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(61, 4);
			this->contextMenuStrip3->ImageScalingSize = System::Drawing::Size(32, 32);
			this->contextMenuStrip3->Name = L"contextMenuStrip3";
			this->contextMenuStrip3->Size = System::Drawing::Size(61, 4);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->verEmpleadoToolStripMenuItem,
					this->verAnimalesToolStripMenuItem, this->balanceGeneralToolStripMenuItem, this->cerrarSesionToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(887, 30);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			this->verEmpleadoToolStripMenuItem->Name = L"verEmpleadoToolStripMenuItem";
			this->verEmpleadoToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->verEmpleadoToolStripMenuItem->Text = L"Ver Empleado";
			this->verEmpleadoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuDueño::verEmpleadoToolStripMenuItem_Click);
			this->verAnimalesToolStripMenuItem->Name = L"verAnimalesToolStripMenuItem";
			this->verAnimalesToolStripMenuItem->Size = System::Drawing::Size(109, 24);
			this->verAnimalesToolStripMenuItem->Text = L"Ver Animales";
			this->verAnimalesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuDueño::verAnimalesToolStripMenuItem_Click);
			this->balanceGeneralToolStripMenuItem->Name = L"balanceGeneralToolStripMenuItem";
			this->balanceGeneralToolStripMenuItem->Size = System::Drawing::Size(130, 24);
			this->balanceGeneralToolStripMenuItem->Text = L"Balance General";
			this->balanceGeneralToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuDueño::balanceGeneralToolStripMenuItem_Click);
			this->cerrarSesionToolStripMenuItem->Name = L"cerrarSesionToolStripMenuItem";
			this->cerrarSesionToolStripMenuItem->Size = System::Drawing::Size(106, 24);
			this->cerrarSesionToolStripMenuItem->Text = L"Cerrar sesión";
			this->cerrarSesionToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->cerrarSesionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuDueño::cerrarSesionToolStripMenuItem_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(887, 507);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MenuDueño";
			this->Text = L"MenuDueño";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panelContent->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Abrir formulario VerEmpleado como diálogo
	proyectoZoo::VerEmpleado^ ver = gcnew proyectoZoo::VerEmpleado();
	ver->ShowDialog();
}
private: System::Void verEmpleadoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Mostrar Usuarios embebido dentro del panelContent
	// Limpiar contenido previo
	this->panelContent->Controls->Clear();
	proyectoZoo::Usuarios^ ver = gcnew proyectoZoo::Usuarios();
	ver->TopLevel = false;
	ver->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	ver->Dock = System::Windows::Forms::DockStyle::Fill;
	this->panelContent->Controls->Add(ver);
	ver->Show();
}
private: System::Void verAnimalesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// abrir Animales embebido
	this->panelContent->Controls->Clear();
	proyectoZoo::Animales^ a = gcnew proyectoZoo::Animales();
	a->TopLevel = false;
	a->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	a->Dock = System::Windows::Forms::DockStyle::Fill;
	this->panelContent->Controls->Add(a);
	a->Show();
}
private: System::Void boleteriaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// abrir boleteria embebida
	this->panelContent->Controls->Clear();
	proyectoZoo::MyForm^ b = gcnew proyectoZoo::MyForm();
	b->TopLevel = false;
	b->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	b->Dock = System::Windows::Forms::DockStyle::Fill;
	this->panelContent->Controls->Add(b);
	b->Show();
}
private: System::Void balanceGeneralToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// abrir BalanceGeneral embebida
	this->panelContent->Controls->Clear();
	proyectoZoo::BalanceGeneral^ bg = gcnew proyectoZoo::BalanceGeneral();
	bg->TopLevel = false;
	bg->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
	bg->Dock = System::Windows::Forms::DockStyle::Fill;
	this->panelContent->Controls->Add(bg);
	bg->Show();
}

private: System::Void cerrarSesionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	System::Reflection::Assembly^ assemblyRef = System::Reflection::Assembly::GetExecutingAssembly();
	Object^ obj = assemblyRef->CreateInstance("proyectoZoo.Login");
	System::Windows::Forms::Form^ loginForm = dynamic_cast<System::Windows::Forms::Form^>(obj);
	if (loginForm != nullptr) {
		loginForm->ShowDialog();
	}
	this->Close();
}
};
}
