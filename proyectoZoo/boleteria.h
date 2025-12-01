#pragma once

#include "UIStyles.h"

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm (Boleteria)
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// apply global styles
			UIStyles::ApplyGlobalStyles(this);
			// override for this form: white background and black text
			this->BackColor = System::Drawing::Color::White;
			this->ForeColor = System::Drawing::Color::Black;
			// adjust top-level controls to match
			for each (Control^ c in this->Controls) {
				if (dynamic_cast<Label^>(c) != nullptr) {
					c->ForeColor = System::Drawing::Color::Black;
				}
				else if (dynamic_cast<TextBox^>(c) != nullptr) {
					c->BackColor = System::Drawing::Color::White;
					c->ForeColor = System::Drawing::Color::Black;
				}
				else if (dynamic_cast<NumericUpDown^>(c) != nullptr) {
					c->BackColor = System::Drawing::Color::White;
					c->ForeColor = System::Drawing::Color::Black;
				}
				else if (dynamic_cast<Panel^>(c) != nullptr) {
					c->BackColor = System::Drawing::Color::White;
					c->ForeColor = System::Drawing::Color::Black;
					// also adjust children inside panel
					for each (Control^ pc in c->Controls) {
						if (dynamic_cast<Label^>(pc) != nullptr || dynamic_cast<TextBox^>(pc) != nullptr || dynamic_cast<NumericUpDown^>(pc) != nullptr)
						{
							pc->ForeColor = System::Drawing::Color::Black;
							if (dynamic_cast<TextBox^>(pc) != nullptr) pc->BackColor = System::Drawing::Color::White;
						}
					}
				}
				else if (dynamic_cast<PictureBox^>(c) != nullptr) {
					c->BackColor = System::Drawing::Color::White;
				}
				else if (dynamic_cast<Button^>(c) != nullptr) {
					c->ForeColor = System::Drawing::Color::Black;
				}
			}
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ labelNombre;
	private: System::Windows::Forms::Label^ labelCedula;
	private: System::Windows::Forms::Label^ labelCorreo;
	private: System::Windows::Forms::Label^ labelDireccion;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtCedula;
	private: System::Windows::Forms::TextBox^ txtCorreo;
	private: System::Windows::Forms::TextBox^ txtDireccion;
	private: System::Windows::Forms::Label^ labelNiño;
	private: System::Windows::Forms::Label^ labelAdulto;
	private: System::Windows::Forms::Label^ labelTercera;
	private: System::Windows::Forms::NumericUpDown^ numNino;
	private: System::Windows::Forms::NumericUpDown^ numAdulto;
	private: System::Windows::Forms::NumericUpDown^ numTercera;
	private: System::Windows::Forms::Button^ buttonIngresar;
	private: System::ComponentModel::IContainer^ components;

	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->labelNombre = (gcnew System::Windows::Forms::Label());
			this->labelCedula = (gcnew System::Windows::Forms::Label());
			this->labelCorreo = (gcnew System::Windows::Forms::Label());
			this->labelDireccion = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtCedula = (gcnew System::Windows::Forms::TextBox());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->txtDireccion = (gcnew System::Windows::Forms::TextBox());
			this->labelNiño = (gcnew System::Windows::Forms::Label());
			this->labelAdulto = (gcnew System::Windows::Forms::Label());
			this->labelTercera = (gcnew System::Windows::Forms::Label());
			this->numNino = (gcnew System::Windows::Forms::NumericUpDown());
			this->numAdulto = (gcnew System::Windows::Forms::NumericUpDown());
			this->numTercera = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonIngresar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numNino))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAdulto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTercera))->BeginInit();
			this->SuspendLayout();
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelTitle->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelTitle->Location = System::Drawing::Point(24, 20);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(121, 31);
			this->labelTitle->TabIndex = 15;
			this->labelTitle->Text = L"Boletería";
			this->pictureBox2->Location = System::Drawing::Point(24, 60);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(400, 120);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			this->labelNombre->AutoSize = true;
			this->labelNombre->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelNombre->Location = System::Drawing::Point(460, 60);
			this->labelNombre->Name = L"labelNombre";
			this->labelNombre->Size = System::Drawing::Size(59, 16);
			this->labelNombre->TabIndex = 7;
			this->labelNombre->Text = L"Nombre:";
			this->labelCedula->AutoSize = true;
			this->labelCedula->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelCedula->Location = System::Drawing::Point(460, 96);
			this->labelCedula->Name = L"labelCedula";
			this->labelCedula->Size = System::Drawing::Size(53, 16);
			this->labelCedula->TabIndex = 5;
			this->labelCedula->Text = L"Cédula:";
			this->labelCorreo->AutoSize = true;
			this->labelCorreo->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelCorreo->Location = System::Drawing::Point(460, 132);
			this->labelCorreo->Name = L"labelCorreo";
			this->labelCorreo->Size = System::Drawing::Size(51, 16);
			this->labelCorreo->TabIndex = 3;
			this->labelCorreo->Text = L"Correo:";
			this->labelDireccion->AutoSize = true;
			this->labelDireccion->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelDireccion->Location = System::Drawing::Point(460, 168);
			this->labelDireccion->Name = L"labelDireccion";
			this->labelDireccion->Size = System::Drawing::Size(67, 16);
			this->labelDireccion->TabIndex = 1;
			this->labelDireccion->Text = L"Dirección:";
			this->txtNombre->Location = System::Drawing::Point(540, 56);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(220, 22);
			this->txtNombre->TabIndex = 6;
			this->txtCedula->Location = System::Drawing::Point(540, 92);
			this->txtCedula->Name = L"txtCedula";
			this->txtCedula->Size = System::Drawing::Size(220, 22);
			this->txtCedula->TabIndex = 4;
			this->txtCorreo->Location = System::Drawing::Point(540, 128);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(220, 22);
			this->txtCorreo->TabIndex = 2;
			this->txtDireccion->Location = System::Drawing::Point(540, 164);
			this->txtDireccion->Name = L"txtDireccion";
			this->txtDireccion->Size = System::Drawing::Size(220, 22);
			this->txtDireccion->TabIndex = 0;
			this->labelNiño->AutoSize = true;
			this->labelNiño->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelNiño->Location = System::Drawing::Point(24, 200);
			this->labelNiño->Name = L"labelNiño";
			this->labelNiño->Size = System::Drawing::Size(38, 16);
			this->labelNiño->TabIndex = 13;
			this->labelNiño->Text = L"Niño:";
			this->labelAdulto->AutoSize = true;
			this->labelAdulto->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelAdulto->Location = System::Drawing::Point(24, 240);
			this->labelAdulto->Name = L"labelAdulto";
			this->labelAdulto->Size = System::Drawing::Size(48, 16);
			this->labelAdulto->TabIndex = 11;
			this->labelAdulto->Text = L"Adulto:";
			this->labelTercera->AutoSize = true;
			this->labelTercera->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->labelTercera->Location = System::Drawing::Point(24, 280);
			this->labelTercera->Name = L"labelTercera";
			this->labelTercera->Size = System::Drawing::Size(94, 16);
			this->labelTercera->TabIndex = 9;
			this->labelTercera->Text = L"Tercera Edad:";
			this->numNino->Location = System::Drawing::Point(100, 196);
			this->numNino->Name = L"numNino";
			this->numNino->Size = System::Drawing::Size(80, 22);
			this->numNino->TabIndex = 12;
			this->numAdulto->Location = System::Drawing::Point(100, 236);
			this->numAdulto->Name = L"numAdulto";
			this->numAdulto->Size = System::Drawing::Size(80, 22);
			this->numAdulto->TabIndex = 10;
			this->numTercera->Location = System::Drawing::Point(130, 276);
			this->numTercera->Name = L"numTercera";
			this->numTercera->Size = System::Drawing::Size(80, 22);
			this->numTercera->TabIndex = 8;
			this->buttonIngresar->Location = System::Drawing::Point(24, 320);
			this->buttonIngresar->Name = L"buttonIngresar";
			this->buttonIngresar->Size = System::Drawing::Size(160, 40);
			this->buttonIngresar->TabIndex = 0;
			this->buttonIngresar->Text = L"Ingresar";
			this->buttonIngresar->UseVisualStyleBackColor = true;
			this->buttonIngresar->Click += gcnew System::EventHandler(this, &MyForm::buttonIngresar_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->ClientSize = System::Drawing::Size(800, 450);
			this->Controls->Add(this->txtDireccion);
			this->Controls->Add(this->labelDireccion);
			this->Controls->Add(this->txtCorreo);
			this->Controls->Add(this->labelCorreo);
			this->Controls->Add(this->txtCedula);
			this->Controls->Add(this->labelCedula);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->labelNombre);
			this->Controls->Add(this->buttonIngresar);
			this->Controls->Add(this->numTercera);
			this->Controls->Add(this->labelTercera);
			this->Controls->Add(this->numAdulto);
			this->Controls->Add(this->labelAdulto);
			this->Controls->Add(this->numNino);
			this->Controls->Add(this->labelNiño);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->labelTitle);
			this->ForeColor = System::Drawing::Color::Bisque;
			this->Name = L"MyForm";
			this->Text = L"Boleteria";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numNino))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAdulto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTercera))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

	private: System::Void buttonIngresar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// read guest info
			String^ nombre = this->txtNombre->Text->Trim();
			String^ cedula = this->txtCedula->Text->Trim();
			String^ correo = this->txtCorreo->Text->Trim();
			String^ direccion = this->txtDireccion->Text->Trim();
			// read quantities
			int nNino = (int)this->numNino->Value;
			int nAdulto = (int)this->numAdulto->Value;
			int nTercera = (int)this->numTercera->Value;
			// precios (ejemplo)
			int pNino =5;
			int pAdulto =10;
			int pTercera =7;
			int total = nNino * pNino + nAdulto * pAdulto + nTercera * pTercera;
			String^ msg = String::Format("Total a cobrar: {0}\nNombre: {1}\nCédula: {2}\nCorreo: {3}\nDirección: {4}\nDetalle (Niños: {5}, Adultos: {6},3ra edad: {7})",
				total, nombre, cedula, correo, direccion, nNino, nAdulto, nTercera);
			MessageBox::Show(msg, L"Venta realizada", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
