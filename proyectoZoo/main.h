#pragma once

#include "Login.h"

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de main
	/// </summary>
	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();
			// Ocultar el formulario principal y mostrar el Login como diálogo de prueba
			this->Hide();
			proyectoZoo::Login^ login = gcnew proyectoZoo::Login();
			login->ShowDialog();
			// El Login se encargará de abrir MenuDueño; mantenemos main oculto como formulario contenedor.
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~main()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

		// Controles añadidos
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ zooToolStripMenuItem;
		System::Windows::Forms::Button^ buttonInicio;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->zooToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonInicio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24,24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(1) {
				this->zooToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0,0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(842,33);
			this->menuStrip1->TabIndex =0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// zooToolStripMenuItem
			// 
			this->zooToolStripMenuItem->Name = L"zooToolStripMenuItem";
			this->zooToolStripMenuItem->Size = System::Drawing::Size(50,29);
			this->zooToolStripMenuItem->Text = L"zoo";
			// 
			// buttonInicio
			// 
			this->buttonInicio->Location = System::Drawing::Point(346,250);
			this->buttonInicio->Name = L"buttonInicio";
			this->buttonInicio->Size = System::Drawing::Size(150,50);
			this->buttonInicio->TabIndex =1;
			this->buttonInicio->Text = L"inicio";
			this->buttonInicio->UseVisualStyleBackColor = true;
			this->buttonInicio->Click += gcnew System::EventHandler(this, &main::buttonInicio_Click);
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12,25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842,903);
			this->Controls->Add(this->buttonInicio);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"main";
			this->Text = L"zoo";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Manejador del botón inicio
	private:
		void buttonInicio_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MessageBox::Show(L"Botón \"inicio\" pulsado", L"Inicio", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}
