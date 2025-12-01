#pragma once

#include "Usuarios.h"
#include "boleteria.h"

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
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
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

	private: System::Windows::Forms::Panel^ panelContent;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->verEmpleadoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelContent = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->verEmpleadoToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(955, 40);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// verEmpleadoToolStripMenuItem
			// 
			this->verEmpleadoToolStripMenuItem->Name = L"verEmpleadoToolStripMenuItem";
			this->verEmpleadoToolStripMenuItem->Size = System::Drawing::Size(181, 36);
			this->verEmpleadoToolStripMenuItem->Text = L"Ver Empleado";
			this->verEmpleadoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuAdmin::verEmpleadoToolStripMenuItem_Click);
			// 
			// panelContent
			// 
			this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContent->Location = System::Drawing::Point(0, 40);
			this->panelContent->Name = L"panelContent";
			this->panelContent->Size = System::Drawing::Size(955, 653);
			this->panelContent->TabIndex = 1;
			// 
			// MenuAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 693);
			this->Controls->Add(this->panelContent);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MenuAdmin";
			this->Text = L"MenuAdmin";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
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
