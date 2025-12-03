#pragma once

#include "Usuarios.h"
#include "boleteria.h"

// forward declare Login to avoid circular include
namespace proyectoZoo { ref class Login; }

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuAdmin
	/// </summary>
	public ref class MenuAdmin : public System::Windows::Forms::Form
	{
	public:
		MenuAdmin(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuAdmin()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ verEmpleadoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cerrarSesionToolStripMenuItem;

	private: System::Windows::Forms::Panel^ panelContent;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuAdmin::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->verEmpleadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cerrarSesionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			this->panelContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->verEmpleadoToolStripMenuItem,
					this->cerrarSesionToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(637, 26);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->verEmpleadoToolStripMenuItem->Name = L"verEmpleadoToolStripMenuItem";
			this->verEmpleadoToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->verEmpleadoToolStripMenuItem->Text = L"Ver Empleado";
			this->verEmpleadoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuAdmin::verEmpleadoToolStripMenuItem_Click);
			this->cerrarSesionToolStripMenuItem->Name = L"cerrarSesionToolStripMenuItem";
			this->cerrarSesionToolStripMenuItem->Size = System::Drawing::Size(106, 24);
			this->cerrarSesionToolStripMenuItem->Text = L"Cerrar sesión";
			this->cerrarSesionToolStripMenuItem->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->cerrarSesionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuAdmin::cerrarSesionToolStripMenuItem_Click);
			this->panelContent->Controls->Add(this->pictureBox2);
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 26);
			this->panelContent->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(637, 418);
			this->panelContent->TabIndex = 1;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(195, 144);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(247, 81);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(637, 444);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MenuAdmin";
			this->Text = L"MenuAdmin";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panelContent->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void verEmpleadoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panelContent->Controls->Clear();
		proyectoZoo::Usuarios^ u = gcnew proyectoZoo::Usuarios();
		u->TopLevel = false;
		u->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		u->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panelContent->Controls->Add(u);
		u->Show();
	}

	private: System::Void cerrarSesionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		// create login form instance via reflection to avoid include circularity
		System::Reflection::Assembly^ assemblyRef = System::Reflection::Assembly::GetExecutingAssembly();
		Object^ obj = assemblyRef->CreateInstance("proyectoZoo.Login");
		System::Windows::Forms::Form^ loginForm = dynamic_cast<System::Windows::Forms::Form^>(obj);
		if (loginForm != nullptr) {
			loginForm->ShowDialog();
		}
		this->Close();
	}

	private: System::Void boleteriaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->panelContent->Controls->Clear();
		proyectoZoo::MyForm^ b = gcnew proyectoZoo::MyForm();
		b->TopLevel = false;
		b->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		b->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panelContent->Controls->Add(b);
		b->Show();
	}
	};
}
