#pragma once

#include "MenuDueño.h"
#include "MenuAdmin.h"
#include "MenuCajero.h"
#include "Usuario.h"

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			// Inicializar lista de usuarios semilla
			proyectoZoo::Usuario::GetAllUsers();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	internal: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelError;

	private: System::Windows::Forms::TextBox^ textUsuario;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;

	internal:
	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textUsuario = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->labelError = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(29, 161);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 54);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(388, 29);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(247, 81);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->label1->Location = System::Drawing::Point(25, 47);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 24);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Usuario";
			this->label1->Click += gcnew System::EventHandler(this, &Login::label1_Click);
			// 
			// textUsuario
			// 
			this->textUsuario->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textUsuario->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textUsuario->Location = System::Drawing::Point(29, 47);
			this->textUsuario->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textUsuario->Name = L"textUsuario";
			this->textUsuario->Size = System::Drawing::Size(185, 30);
			this->textUsuario->TabIndex = 5;
			this->textUsuario->Text = L"Usuario";
			this->textUsuario->TextChanged += gcnew System::EventHandler(this, &Login::textUsuario_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox1->Location = System::Drawing::Point(29, 94);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(185, 30);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"*******";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-3, -1);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(350, 422);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->labelError);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->textUsuario);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(381, 138);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(254, 253);
			this->panel1->TabIndex = 8;
			// 
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->ForeColor = System::Drawing::Color::Red;
			this->labelError->Location = System::Drawing::Point(29, 136);
			this->labelError->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(0, 16);
			this->labelError->TabIndex = 9;
			this->labelError->Visible = false;
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(683, 416);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->textUsuario->Text->Trim();
		String^ password = this->textBox1->Text->Trim();

		// Use Usuario::ValidateCredentials to centralize validation
		Usuario^ found = Usuario::ValidateCredentials(username, password);

		if (found == nullptr) {
			this->labelError->Text = L"Credenciales incorrectas.";
			this->labelError->Visible = true;
			return;
		}

		// Credenciales correctas
		this->labelError->Visible = false;
		this->Hide();
		if (found->Cargo == L"Administrador") {
			proyectoZoo::MenuAdmin^ menu = gcnew proyectoZoo::MenuAdmin();
			menu->ShowDialog();
		} else if (found->Cargo == L"Cajero" || found->Cargo == L"Boletero") {
			proyectoZoo::MenuCajero^ menu = gcnew proyectoZoo::MenuCajero();
			MessageBox::Show(L"Ingreso exitoso.", L"Bienvenido", MessageBoxButtons::OK, MessageBoxIcon::Information);
			menu->ShowDialog();
		} else {
			proyectoZoo::MenuDueño^ menu = gcnew proyectoZoo::MenuDueño();
			menu->ShowDialog();
		}
		this->Close();
	}
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textUsuario_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
