#pragma once

#include "Animal.h"

namespace proyectoZoo {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    /// <summary>
    /// Resumen de Animales
    /// </summary>
    public ref class Animales : public System::Windows::Forms::Form
    {
    public:
        Animales(void)
        {
            InitializeComponent();
            // load animals and initialize
            this->animalsList = AnimalsData::GetAll();
            this->editingRow = -1;
            SetupGridButtons();
            PopulateGrid();
        }

    protected:
        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~Animales()
        {
            if (components)
            {
                delete components;
            }
        }
    private:
        List<Animal^>^ animalsList;
        int editingRow;

    private: System::Windows::Forms::TextBox^ textBox1;
    protected:
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::TextBox^ textBox5;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ nombre;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ identificacion;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ especie;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ sexo;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ edad;
    private: System::Windows::Forms::DataGridViewButtonColumn^ colEditar;
    private: System::Windows::Forms::DataGridViewButtonColumn^ colEliminar;

    private:
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        System::ComponentModel::Container ^components;

        void SetupGridButtons()
        {
            // Add Edit and Delete button columns if not added yet
            bool hasEdit = false, hasDel = false;
            for each (DataGridViewColumn^ c in this->dataGridView1->Columns)
            {
                if (c->Name == "colEditar") hasEdit = true;
                if (c->Name == "colEliminar") hasDel = true;
            }
            if (!hasEdit)
            {
                this->colEditar = gcnew DataGridViewButtonColumn();
                this->colEditar->Name = "colEditar";
                this->colEditar->HeaderText = "Editar";
                this->colEditar->Text = "Editar";
                this->colEditar->UseColumnTextForButtonValue = true;
                this->dataGridView1->Columns->Add(this->colEditar);
            }
            if (!hasDel)
            {
                this->colEliminar = gcnew DataGridViewButtonColumn();
                this->colEliminar->Name = "colEliminar";
                this->colEliminar->HeaderText = "Eliminar";
                this->colEliminar->Text = "Eliminar";
                this->colEliminar->UseColumnTextForButtonValue = true;
                this->dataGridView1->Columns->Add(this->colEliminar);
            }
            this->dataGridView1->CellContentClick += gcnew DataGridViewCellEventHandler(this, &Animales::dataGridView1_CellContentClick);
        }

        void PopulateGrid()
        {
            this->dataGridView1->Rows->Clear();
            for each (Animal^ a in this->animalsList)
            {
                int r = this->dataGridView1->Rows->Add();
                this->dataGridView1->Rows[r]->Cells[0]->Value = a->Nombre;
                this->dataGridView1->Rows[r]->Cells[1]->Value = a->Identificacion;
                this->dataGridView1->Rows[r]->Cells[2]->Value = a->Especie;
                this->dataGridView1->Rows[r]->Cells[3]->Value = a->Sexo;
                this->dataGridView1->Rows[r]->Cells[4]->Value = a->Edad;
            }
            this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            int rows = this->dataGridView1->Rows->Count;
            int rowH = this->dataGridView1->RowTemplate->Height;
            int headerH = this->dataGridView1->ColumnHeadersHeight;
            this->dataGridView1->Height = headerH + rows * rowH + 10;
        }

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Animales::typeid));
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->nombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->identificacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->especie = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->sexo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->edad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::SystemColors::Control;
            this->textBox1->Location = System::Drawing::Point(99, 109);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(221, 22);
            this->textBox1->TabIndex = 0;
            this->textBox1->Text = L"Nombre";
            // 
            // textBox2
            // 
            this->textBox2->BackColor = System::Drawing::SystemColors::Control;
            this->textBox2->Location = System::Drawing::Point(99, 147);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(221, 22);
            this->textBox2->TabIndex = 1;
            this->textBox2->Text = L"Numero de identificación";
            // 
            // textBox3
            // 
            this->textBox3->BackColor = System::Drawing::SystemColors::Control;
            this->textBox3->Location = System::Drawing::Point(101, 188);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(221, 22);
            this->textBox3->TabIndex = 2;
            this->textBox3->Text = L"Especie";
            // 
            // textBox4
            // 
            this->textBox4->BackColor = System::Drawing::SystemColors::Control;
            this->textBox4->Location = System::Drawing::Point(385, 109);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(215, 22);
            this->textBox4->TabIndex = 3;
            this->textBox4->Text = L"Sexo";
            // 
            // textBox5
            // 
            this->textBox5->BackColor = System::Drawing::SystemColors::Control;
            this->textBox5->Location = System::Drawing::Point(385, 147);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(215, 22);
            this->textBox5->TabIndex = 4;
            this->textBox5->Text = L"Edad";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::DarkCyan;
            this->button1->Location = System::Drawing::Point(385, 189);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(216, 27);
            this->button1->TabIndex = 5;
            this->button1->Text = L"Agregar";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Animales::button1_Click);
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(247, 21);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(249, 71);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox2->TabIndex = 14;
            this->pictureBox2->TabStop = false;
            // 
            // dataGridView1
            // 
            this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->nombre,
                    this->identificacion, this->especie, this->sexo, this->edad
            });
            this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
            this->dataGridView1->Location = System::Drawing::Point(45, 247);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(701, 97);
            this->dataGridView1->TabIndex = 15;
            // 
            // nombre
            // 
            this->nombre->HeaderText = L"Nombre";
            this->nombre->MinimumWidth = 6;
            this->nombre->Name = L"nombre";
            this->nombre->Width = 125;
            // 
            // identificacion
            // 
            this->identificacion->HeaderText = L"Identificación";
            this->identificacion->MinimumWidth = 6;
            this->identificacion->Name = L"identificacion";
            this->identificacion->Width = 125;
            // 
            // especie
            // 
            this->especie->HeaderText = L"Especie";
            this->especie->MinimumWidth = 6;
            this->especie->Name = L"especie";
            this->especie->Width = 125;
            // 
            // sexo
            // 
            this->sexo->HeaderText = L"Sexo";
            this->sexo->MinimumWidth = 6;
            this->sexo->Name = L"sexo";
            this->sexo->Width = 125;
            // 
            // edad
            // 
            this->edad->HeaderText = L"Edad";
            this->edad->MinimumWidth = 6;
            this->edad->Name = L"edad";
            this->edad->Width = 125;
            // 
            // Animales
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
            this->ClientSize = System::Drawing::Size(817, 375);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->pictureBox2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox5);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Name = L"Animales";
            this->Text = L"Animales";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ nombre = this->textBox1->Text->Trim();
        String^ id = this->textBox2->Text->Trim();
        String^ especie = this->textBox3->Text->Trim();
        String^ sexo = this->textBox4->Text->Trim();
        String^ edad = this->textBox5->Text->Trim();

        if (nombre->Length == 0 || id->Length == 0) {
            MessageBox::Show("Nombre e Identificación son obligatorios", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (this->editingRow == -1) {
            Animal^ a = gcnew Animal(nombre, id, especie, sexo, edad);
            this->animalsList->Add(a);
            PopulateGrid();
            this->textBox1->Text = "";
            this->textBox2->Text = "";
            this->textBox3->Text = "";
            this->textBox4->Text = "";
            this->textBox5->Text = "";
        }
        else {
            Animal^ a = this->animalsList[this->editingRow];
            a->Nombre = nombre;
            a->Identificacion = id;
            a->Especie = especie;
            a->Sexo = sexo;
            a->Edad = edad;
            this->editingRow = -1;
            this->button1->Text = L"Agregar";
            PopulateGrid();
            this->textBox1->Text = "";
            this->textBox2->Text = "";
            this->textBox3->Text = "";
            this->textBox4->Text = "";
            this->textBox5->Text = "";
        }
    }

    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex < 0) return;
        if (this->dataGridView1->Columns[e->ColumnIndex] == this->colEditar) {
            this->editingRow = e->RowIndex;
            this->textBox1->Text = (String^)this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value;
            this->textBox2->Text = (String^)this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
            this->textBox3->Text = (String^)this->dataGridView1->Rows[e->RowIndex]->Cells[2]->Value;
            this->textBox4->Text = (String^)this->dataGridView1->Rows[e->RowIndex]->Cells[3]->Value;
            this->textBox5->Text = (String^)this->dataGridView1->Rows[e->RowIndex]->Cells[4]->Value;
            this->button1->Text = L"Guardar";
        }
        else if (this->dataGridView1->Columns[e->ColumnIndex] == this->colEliminar) {
            auto dr = MessageBox::Show("¿Eliminar este animal?", "Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (dr == System::Windows::Forms::DialogResult::Yes) {
                 this->animalsList->RemoveAt(e->RowIndex);
                 PopulateGrid();
             }
         }
    }
};
}
