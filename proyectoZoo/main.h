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
			// TODO: agregar código de constructor aquí
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


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
		   System::Windows::Forms::Button^ buttonInicio;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->buttonInicio = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 1, 0, 1);
			this->menuStrip1->Size = System::Drawing::Size(1044, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// buttonInicio
			// 
			this->buttonInicio->BackColor = System::Drawing::Color::DarkCyan;
			this->buttonInicio->Location = System::Drawing::Point(839, 449);
			this->buttonInicio->Margin = System::Windows::Forms::Padding(2);
			this->buttonInicio->Name = L"buttonInicio";
			this->buttonInicio->Size = System::Drawing::Size(148, 61);
			this->buttonInicio->TabIndex = 1;
			this->buttonInicio->Text = L"Empezar";
			this->buttonInicio->UseVisualStyleBackColor = false;
			this->buttonInicio->Click += gcnew System::EventHandler(this, &main::buttonInicio_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(50, 438);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(547, 91);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Proyecto ZOO";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(70, 544);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(312, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Desarrollado por Alexander Dubert";
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1044, 578);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonInicio);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"main";
			this->Text = L"ProyectoZOO";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Manejador del botón inicio
	private:
		void buttonInicio_Click(System::Object^ sender, System::EventArgs^ e)
		{
			MessageBox::Show(L"Bienvenido al Zoo Aquarium de Valencia", L"Inicio", MessageBoxButtons::OK, MessageBoxIcon::Information);
			// Abrir Login como diálogo. Ocultar main mientras se muestra.
			this->Hide();
			proyectoZoo::Login^ login = gcnew proyectoZoo::Login();
			login->ShowDialog();
			// Después del login cerramos main para que la app continúe con el menú abierto por Login
			this->Close();
		}
	};
}
