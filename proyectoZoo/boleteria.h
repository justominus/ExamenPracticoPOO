#pragma once

// Removed UIStyles integration to use Windows Forms defaults

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Resumen de MyForm (Boleteria)
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// use designer defaults
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numNino))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numAdulto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTercera))->BeginInit();
			this->SuspendLayout();
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->labelTitle->ForeColor = System::Drawing::Color::Black;
			this->labelTitle->Location = System::Drawing::Point(24, 20);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(121, 31);
			this->labelTitle->TabIndex = 15;
			this->labelTitle->Text = L"Boletería";
			// 
			// labelNombre
			// 
			this->labelNombre->AutoSize = true;
			this->labelNombre->ForeColor = System::Drawing::Color::Black;
			this->labelNombre->Location = System::Drawing::Point(20, 81);
			this->labelNombre->Name = L"labelNombre";
			this->labelNombre->Size = System::Drawing::Size(59, 16);
			this->labelNombre->TabIndex = 7;
			this->labelNombre->Text = L"Nombre:";
			// 
			// labelCedula
			// 
			this->labelCedula->AutoSize = true;
			this->labelCedula->ForeColor = System::Drawing::Color::Black;
			this->labelCedula->Location = System::Drawing::Point(20, 117);
			this->labelCedula->Name = L"labelCedula";
			this->labelCedula->Size = System::Drawing::Size(53, 16);
			this->labelCedula->TabIndex = 5;
			this->labelCedula->Text = L"Cédula:";
			// 
			// labelCorreo
			// 
			this->labelCorreo->AutoSize = true;
			this->labelCorreo->ForeColor = System::Drawing::Color::Black;
			this->labelCorreo->Location = System::Drawing::Point(20, 153);
			this->labelCorreo->Name = L"labelCorreo";
			this->labelCorreo->Size = System::Drawing::Size(51, 16);
			this->labelCorreo->TabIndex = 3;
			this->labelCorreo->Text = L"Correo:";
			// 
			// labelDireccion
			// 
			this->labelDireccion->AutoSize = true;
			this->labelDireccion->ForeColor = System::Drawing::Color::Black;
			this->labelDireccion->Location = System::Drawing::Point(20, 189);
			this->labelDireccion->Name = L"labelDireccion";
			this->labelDireccion->Size = System::Drawing::Size(67, 16);
			this->labelDireccion->TabIndex = 1;
			this->labelDireccion->Text = L"Dirección:";
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(100, 77);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(220, 22);
			this->txtNombre->TabIndex = 6;
			// 
			// txtCedula
			// 
			this->txtCedula->Location = System::Drawing::Point(100, 113);
			this->txtCedula->Name = L"txtCedula";
			this->txtCedula->Size = System::Drawing::Size(220, 22);
			this->txtCedula->TabIndex = 4;
			// 
			// txtCorreo
			// 
			this->txtCorreo->Location = System::Drawing::Point(100, 149);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(220, 22);
			this->txtCorreo->TabIndex = 2;
			// 
			// txtDireccion
			// 
			this->txtDireccion->Location = System::Drawing::Point(100, 185);
			this->txtDireccion->Name = L"txtDireccion";
			this->txtDireccion->Size = System::Drawing::Size(220, 22);
			this->txtDireccion->TabIndex = 0;
			// 
			// labelNiño
			// 
			this->labelNiño->AutoSize = true;
			this->labelNiño->ForeColor = System::Drawing::Color::Black;
			this->labelNiño->Location = System::Drawing::Point(463, 77);
			this->labelNiño->Name = L"labelNiño";
			this->labelNiño->Size = System::Drawing::Size(38, 16);
			this->labelNiño->TabIndex = 13;
			this->labelNiño->Text = L"Niño:";
			// 
			// labelAdulto
			// 
			this->labelAdulto->AutoSize = true;
			this->labelAdulto->ForeColor = System::Drawing::Color::Black;
			this->labelAdulto->Location = System::Drawing::Point(463, 115);
			this->labelAdulto->Name = L"labelAdulto";
			this->labelAdulto->Size = System::Drawing::Size(48, 16);
			this->labelAdulto->TabIndex = 11;
			this->labelAdulto->Text = L"Adulto:";
			// 
			// labelTercera
			// 
			this->labelTercera->AutoSize = true;
			this->labelTercera->ForeColor = System::Drawing::Color::Black;
			this->labelTercera->Location = System::Drawing::Point(433, 154);
			this->labelTercera->Name = L"labelTercera";
			this->labelTercera->Size = System::Drawing::Size(94, 16);
			this->labelTercera->TabIndex = 9;
			this->labelTercera->Text = L"Tercera Edad:";
			// 
			// numNino
			// 
			this->numNino->Location = System::Drawing::Point(539, 73);
			this->numNino->Name = L"numNino";
			this->numNino->Size = System::Drawing::Size(80, 22);
			this->numNino->TabIndex = 12;
			// 
			// numAdulto
			// 
			this->numAdulto->Location = System::Drawing::Point(539, 111);
			this->numAdulto->Name = L"numAdulto";
			this->numAdulto->Size = System::Drawing::Size(80, 22);
			this->numAdulto->TabIndex = 10;
			// 
			// numTercera
			// 
			this->numTercera->Location = System::Drawing::Point(539, 150);
			this->numTercera->Name = L"numTercera";
			this->numTercera->Size = System::Drawing::Size(80, 22);
			this->numTercera->TabIndex = 8;
			// 
			// buttonIngresar
			// 
			this->buttonIngresar->BackColor = System::Drawing::Color::DarkCyan;
			this->buttonIngresar->ForeColor = System::Drawing::Color::Black;
			this->buttonIngresar->Location = System::Drawing::Point(293, 267);
			this->buttonIngresar->Name = L"buttonIngresar";
			this->buttonIngresar->Size = System::Drawing::Size(160, 40);
			this->buttonIngresar->TabIndex = 0;
			this->buttonIngresar->Text = L"Ingresar";
			this->buttonIngresar->UseVisualStyleBackColor = false;
			this->buttonIngresar->Click += gcnew System::EventHandler(this, &MyForm::buttonIngresar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(971, 540);
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
			this->Controls->Add(this->labelTitle);
			this->ForeColor = System::Drawing::Color::Bisque;
			this->Name = L"MyForm";
			this->Text = L"Boleteria";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
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

			// reset field colors
			this->txtNombre->ForeColor = System::Drawing::Color::Black;
			this->txtCedula->ForeColor = System::Drawing::Color::Black;

			// validate nombre: no digits allowed
			if (nombre->Length == 0 || Regex::IsMatch(nombre, "\\d")) {
				this->txtNombre->ForeColor = System::Drawing::Color::Red;
				MessageBox::Show("caracteres invalidos", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// validate cedula: exactly 10 digits
			if (!Regex::IsMatch(cedula, "^[0-9]{10}$")) {
				this->txtCedula->ForeColor = System::Drawing::Color::Red;
				MessageBox::Show("Se deben Igresar 10 digitos", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
