#pragma once

#include "Ingresos.h"
#include "Egresos.h"

namespace proyectoZoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de BalanceGeneral
	/// </summary>
	public ref class BalanceGeneral : public System::Windows::Forms::Form
	{
	public:
		BalanceGeneral(void)
		{
			InitializeComponent();
			// Load sample ingresos and egresos and populate grid
			List<Ingreso^>^ ingresosList = Ingresos::GetAll();
			List<Egreso^>^ egresosList = Egresos::GetAll();

			double saldo = 0.0;

			// ingresos
			for each (Ingreso^ ig in ingresosList)
			{
				int row = this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[row]->Cells[0]->Value = ig->Description;
				this->dataGridView1->Rows[row]->Cells[1]->Value = ig->Value.ToString();
				this->dataGridView1->Rows[row]->Cells[2]->Value = "";
				saldo += ig->Value;
				this->dataGridView1->Rows[row]->Cells[3]->Value = saldo.ToString();
			}

			//egresos
			for each (Egreso^ eg in egresosList)
			{
				int row = this->dataGridView1->Rows->Add();
				this->dataGridView1->Rows[row]->Cells[0]->Value = eg->Description;
				this->dataGridView1->Rows[row]->Cells[1]->Value = "";
				this->dataGridView1->Rows[row]->Cells[2]->Value = eg->Value.ToString();
				saldo -= eg->Value;
				this->dataGridView1->Rows[row]->Cells[3]->Value = saldo.ToString();
			}

			// Add total row
			int totalRow = this->dataGridView1->Rows->Add();
			this->dataGridView1->Rows[totalRow]->Cells[0]->Value = "Total";
			this->dataGridView1->Rows[totalRow]->Cells[1]->Value = "";
			this->dataGridView1->Rows[totalRow]->Cells[2]->Value = "";
			this->dataGridView1->Rows[totalRow]->Cells[3]->Value = saldo.ToString();
			// color total
			if (saldo >= 0) this->dataGridView1->Rows[totalRow]->Cells[3]->Style->ForeColor = Color::Green;
			else this->dataGridView1->Rows[totalRow]->Cells[3]->Style->ForeColor = Color::Red;

			// Ensure the grid shows all rows without vertical scrollbar
			this->dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
			int totalRows = this->dataGridView1->Rows->Count;
			int rowHeight = this->dataGridView1->RowTemplate->Height;
			int headerHeight = this->dataGridView1->ColumnHeadersHeight;
			// set height to fit rows plus header, add small padding
			this->dataGridView1->Height = headerHeight + totalRows * rowHeight + 10;
			// disable vertical scrollbar
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~BalanceGeneral()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ descripcion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ingresos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ egresos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ saldo;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BalanceGeneral::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->descripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ingresos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->egresos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->saldo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(287, 11);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(247, 81);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->descripcion,
					this->ingresos, this->egresos, this->saldo
			});
			this->dataGridView1->Location = System::Drawing::Point(76, 158);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(596, 150);
			this->dataGridView1->TabIndex = 4;
			// 
			// descripcion
			// 
			this->descripcion->HeaderText = L"Descripción";
			this->descripcion->MinimumWidth = 6;
			this->descripcion->Name = L"descripcion";
			this->descripcion->Width = 125;
			// 
			// ingresos
			// 
			this->ingresos->HeaderText = L"Ingresos";
			this->ingresos->MinimumWidth = 6;
			this->ingresos->Name = L"ingresos";
			this->ingresos->Width = 125;
			// 
			// egresos
			// 
			this->egresos->HeaderText = L"Egresos";
			this->egresos->MinimumWidth = 6;
			this->egresos->Name = L"egresos";
			this->egresos->Width = 125;
			// 
			// saldo
			// 
			this->saldo->HeaderText = L"Saldo";
			this->saldo->MinimumWidth = 6;
			this->saldo->Name = L"saldo";
			this->saldo->Width = 125;
			// 
			// BalanceGeneral
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(810, 419);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"BalanceGeneral";
			this->Text = L"BalanceGeneral";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
