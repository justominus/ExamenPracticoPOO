#pragma once

#include "Usuario.h"

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de Usuarios
	/// </summary>
	public ref class Usuarios : public System::Windows::Forms::Form
	{
	public:
		Usuarios(void)
		{
			InitializeComponent();
			userList = gcnew List<Usuario^>();
			editingIndex = -1;
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Usuarios()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;

	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCedula;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCorreo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEdad;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colUsuario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colClave;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCargo;
	private: System::Windows::Forms::NotifyIcon^ notifyIcon1;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	// Datos en memoria
	private: List<Usuario^>^ userList;
	private: int editingIndex;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Usuarios::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCedula = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCorreo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEdad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colUsuario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colClave = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCargo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->textBox1->Location = System::Drawing::Point(54, 142);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(401, 34);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Usuario";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Usuarios::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox2->Location = System::Drawing::Point(54, 193);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(401, 34);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"Clave";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox3->Location = System::Drawing::Point(54, 246);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(401, 34);
			this->textBox3->TabIndex = 4;
			this->textBox3->Text = L"Edad";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox4->Location = System::Drawing::Point(497, 142);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(433, 34);
			this->textBox4->TabIndex = 5;
			this->textBox4->Text = L"Nombres";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Control;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox5->Location = System::Drawing::Point(497, 193);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(433, 34);
			this->textBox5->TabIndex = 6;
			this->textBox5->Text = L"Cedula";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Control;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox6->Location = System::Drawing::Point(497, 246);
			this->textBox6->Margin = System::Windows::Forms::Padding(2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(433, 34);
			this->textBox6->TabIndex = 7;
			this->textBox6->Text = L"Correo";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::Control;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(54, 295);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(401, 37);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->Text = L"Cargo";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkCyan;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(497, 290);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(431, 42);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Usuarios::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->colNombre,
					this->colCedula, this->colCorreo, this->colEdad, this->colUsuario, this->colClave, this->colCargo
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(28, 381);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 60;
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowTemplate->Height = 20;
			this->dataGridView1->Size = System::Drawing::Size(800, 134);
			this->dataGridView1->TabIndex = 12;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Usuarios::dataGridView1_CellContentClick);
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->MinimumWidth = 10;
			this->colNombre->Name = L"colNombre";
			// 
			// colCedula
			// 
			this->colCedula->HeaderText = L"Cedula";
			this->colCedula->MinimumWidth = 10;
			this->colCedula->Name = L"colCedula";
			// 
			// colCorreo
			// 
			this->colCorreo->HeaderText = L"Correo";
			this->colCorreo->MinimumWidth = 10;
			this->colCorreo->Name = L"colCorreo";
			// 
			// colEdad
			// 
			this->colEdad->HeaderText = L"Edad";
			this->colEdad->MinimumWidth = 10;
			this->colEdad->Name = L"colEdad";
			// 
			// colUsuario
			// 
			this->colUsuario->HeaderText = L"Usuario";
			this->colUsuario->MinimumWidth = 10;
			this->colUsuario->Name = L"colUsuario";
			// 
			// colClave
			// 
			this->colClave->HeaderText = L"Clave";
			this->colClave->MinimumWidth = 10;
			this->colClave->Name = L"colClave";
			// 
			// colCargo
			// 
			this->colCargo->HeaderText = L"Cargo";
			this->colCargo->MinimumWidth = 10;
			this->colCargo->Name = L"colCargo";
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(54, 31);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(260, 81);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// Usuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1283, 627);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Usuarios";
			this->Text = L"Usuarios";
			this->Load += gcnew System::EventHandler(this, &Usuarios::Usuarios_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Agregar o actualizar usuario
		String^ nombre = this->textBox4->Text;
		String^ cedula = this->textBox5->Text;
		String^ correo = this->textBox6->Text;
		String^ edad = this->textBox3->Text;
		String^ usuario = this->textBox1->Text;
		String^ clave = this->textBox2->Text;
		String^ cargo = this->comboBox1->Text;

		// Validaciones
		// Nombre: no vacío, solo letras y espacios
		if (String::IsNullOrWhiteSpace(nombre)) {
			MessageBox::Show("El nombre no puede estar vacío", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		for (int i = 0; i < nombre->Length; i++) {
			wchar_t ch = nombre[i];
			if (!System::Char::IsLetter(ch) && ch != ' ') {
				MessageBox::Show("El nombre solo debe contener letras y espacios", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		// Cédula: exactamente 10 dígitos
		if (String::IsNullOrEmpty(cedula) || cedula->Length != 10) {
			MessageBox::Show("La cédula debe contener exactamente 10 dígitos", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		for (int i = 0; i < cedula->Length; i++) {
			if (!System::Char::IsDigit(cedula[i])) {
				MessageBox::Show("La cédula solo debe contener números", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}

		if (editingIndex == -1) {
			Usuario^ u = gcnew Usuario(nombre, cedula, correo, edad, usuario, clave, cargo);
			userList->Add(u);
		} else {
			// actualizar
			Usuario^ u = userList[editingIndex];
			u->Nombre = nombre;
			u->Cedula = cedula;
			u->Correo = correo;
			u->Edad = edad;
			u->UsuarioName = usuario;
			u->Clave = clave;
			u->Cargo = cargo;
			editingIndex = -1;
			this->button2->Text = L"Agregar";
		}
		RefreshGrid();
		// limpiar campos
		this->textBox1->Text = L"Usuario";
		this->textBox2->Text = L"Clave";
		this->textBox3->Text = L"Edad";
		this->textBox4->Text = L"Nombres";
		this->textBox5->Text = L"Cedula";
		this->textBox6->Text = L"Correo";
		this->comboBox1->Text = L"Cargo";
	}
private: System::Void Usuarios_Load(System::Object^ sender, System::EventArgs^ e) {
		// agregar columnas de botones (Editar, Eliminar)
		DataGridViewButtonColumn^ btnEdit = gcnew DataGridViewButtonColumn();
		btnEdit->Name = L"Editar";
		btnEdit->HeaderText = L"Editar";
		btnEdit->Text = L"Editar";
		btnEdit->UseColumnTextForButtonValue = true;
		this->dataGridView1->Columns->Add(btnEdit);

		DataGridViewButtonColumn^ btnDelete = gcnew DataGridViewButtonColumn();
		btnDelete->Name = L"Eliminar";
		btnDelete->HeaderText = L"Eliminar";
		btnDelete->Text = L"Eliminar";
		btnDelete->UseColumnTextForButtonValue = true;
		this->dataGridView1->Columns->Add(btnDelete);

		// datos quemados de ejemplo
		userList->Add(gcnew Usuario(L"Alex Dubert", L"1234567890", L"alex@example.com", L"23", L"alex", L"1234", L"Administrador"));
		userList->Add(gcnew Usuario(L"Maria Lopez", L"8765432109", L"maria@example.com", L"28", L"marial", L"abcd", L"Dueño"));
		userList->Add(gcnew Usuario(L"Carlos Ruiz", L"1122334455", L"carlos@example.com", L"45", L"carlosr", L"pass", L"Dueño"));

		RefreshGrid();
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		try {
			if (e->RowIndex <0 || e->ColumnIndex <0) return;
			// verificar que existan las columnas antes de usarlas
			if (!this->dataGridView1->Columns->Contains(L"Editar") || !this->dataGridView1->Columns->Contains(L"Eliminar")) return;
			int editCol = this->dataGridView1->Columns[L"Editar"]->Index;
			int delCol = this->dataGridView1->Columns[L"Eliminar"]->Index;
			if (e->ColumnIndex == delCol) {
				// eliminar usuario
				if (e->RowIndex >=0 && e->RowIndex < userList->Count) {
					// Confirmación antes de eliminar
					System::Windows::Forms::DialogResult res = MessageBox::Show(
						L"¿Está seguro que desea eliminar este usuario?",
						L"Confirmar eliminación",
						MessageBoxButtons::YesNo,
						MessageBoxIcon::Warning);
					if (res == System::Windows::Forms::DialogResult::Yes) {
						userList->RemoveAt(e->RowIndex);
						RefreshGrid();
					}
				}
			} else if (e->ColumnIndex == editCol) {
				// editar: cargar datos en el formulario
				if (e->RowIndex >=0 && e->RowIndex < userList->Count) {
					Usuario^ u = userList[e->RowIndex];
					this->textBox4->Text = u->Nombre;
					this->textBox5->Text = u->Cedula;
					this->textBox6->Text = u->Correo;
					this->textBox3->Text = u->Edad;
					this->textBox1->Text = u->UsuarioName;
					this->textBox2->Text = u->Clave;
					this->comboBox1->Text = u->Cargo;
					editingIndex = e->RowIndex;
					this->button2->Text = L"Actualizar";
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
}

	private: void RefreshGrid() {
		try {
			this->dataGridView1->Rows->Clear();
			for (int i =0; i < userList->Count; i++) {
				Usuario^ u = userList[i];
				int idx = this->dataGridView1->Rows->Add();
				DataGridViewRow^ row = this->dataGridView1->Rows[idx];
				// Ensure we have enough cells
				if (row->Cells->Count >=7) {
					row->Cells[0]->Value = u->Nombre;
					row->Cells[1]->Value = u->Cedula;
					row->Cells[2]->Value = u->Correo;
			 	row->Cells[3]->Value = u->Edad;
			 	row->Cells[4]->Value = u->UsuarioName;
			 	row->Cells[5]->Value = u->Clave;
			 	row->Cells[6]->Value = u->Cargo;
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, L"RefreshGrid Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
