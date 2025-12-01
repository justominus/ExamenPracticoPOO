#pragma once

#include "boleteria.h"
#include "UIStyles.h"

namespace proyectoZoo {

 using namespace System;
 using namespace System::ComponentModel;
 using namespace System::Collections;
 using namespace System::Windows::Forms;
 using namespace System::Data;
 using namespace System::Drawing;

 public ref class MenuCajero : public System::Windows::Forms::Form
 {
 public:
 MenuCajero(void)
 {
 InitializeComponent();
 this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
 // apply styles
 UIStyles::ApplyGlobalStyles(this);
 }

 protected:
 ~MenuCajero()
 {
 if (components) delete components;
 }

 private:
 System::Windows::Forms::MenuStrip^ menuStrip1;
 System::Windows::Forms::ToolStripMenuItem^ boleteriaToolStripMenuItem;
 System::Windows::Forms::Panel^ panelContent;
 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
 void InitializeComponent(void)
 {
 this->components = (gcnew System::ComponentModel::Container());
 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
 this->boleteriaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
 this->panelContent = (gcnew System::Windows::Forms::Panel());
 this->menuStrip1->SuspendLayout();
 this->SuspendLayout();
 // 
 // menuStrip1
 // 
 this->menuStrip1->ImageScalingSize = System::Drawing::Size(24,24);
 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(1) { this->boleteriaToolStripMenuItem });
 this->menuStrip1->Location = System::Drawing::Point(0,0);
 this->menuStrip1->Name = L"menuStrip1";
 this->menuStrip1->Size = System::Drawing::Size(800,33);
 this->menuStrip1->TabIndex =0;
 this->menuStrip1->Text = L"menuStrip1";
 // 
 // boleteriaToolStripMenuItem
 // 
 this->boleteriaToolStripMenuItem->Name = L"boleteriaToolStripMenuItem";
 this->boleteriaToolStripMenuItem->Size = System::Drawing::Size(96,29);
 this->boleteriaToolStripMenuItem->Text = L"Boleteria";
 this->boleteriaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MenuCajero::boleteriaToolStripMenuItem_Click);
 // 
 // panelContent
 // 
 this->panelContent->Dock = System::Windows::Forms::DockStyle::Fill;
 this->panelContent->Location = System::Drawing::Point(0,33);
 this->panelContent->Name = L"panelContent";
 this->panelContent->Size = System::Drawing::Size(800,417);
 this->panelContent->TabIndex =1;
 // 
 // MenuCajero
 // 
 this->AutoScaleDimensions = System::Drawing::SizeF(12,25);
 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
 this->ClientSize = System::Drawing::Size(800,450);
 this->Controls->Add(this->panelContent);
 this->Controls->Add(this->menuStrip1);
 this->MainMenuStrip = this->menuStrip1;
 this->Name = L"MenuCajero";
 this->Text = L"MenuCajero";
 this->menuStrip1->ResumeLayout(false);
 this->menuStrip1->PerformLayout();
 this->ResumeLayout(false);
 }
#pragma endregion

 private: System::Void boleteriaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
 this->panelContent->Controls->Clear();
 proyectoZoo::MyForm^ f = gcnew proyectoZoo::MyForm();
 f->TopLevel = false;
 f->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
 f->Dock = System::Windows::Forms::DockStyle::Fill;
 this->panelContent->Controls->Add(f);
 f->Show();
 }
 };
}
