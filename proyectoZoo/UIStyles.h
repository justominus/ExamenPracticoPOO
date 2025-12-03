#pragma once

namespace proyectoZoo {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class UIStyles
    {
    public:
        // Colors matching MenuDueño theme
        static initonly Color WindowBack = SystemColors::ActiveCaptionText; // dark background for forms
        static initonly Color FormTextColor = SystemColors::ButtonHighlight; // light text on dark form
        static initonly Color PanelBack = SystemColors::ButtonHighlight; // white content area
        static initonly Color PanelTextColor = Color::Black; // dark text on white panels
        static initonly Color TextBoxBorder = Color::FromArgb(200, 200, 200); // subtle border
        static initonly Color ButtonColor = Color::DarkCyan; // buttons similar to existing ones
        static initonly Color ButtonTextColor = Color::White;
        static initonly Color MenuActive = Color::FromArgb(180, 210, 245); // light blue for active menu

        // Apply styles to form and all nested children
        static void ApplyGlobalStyles(Form^ form)
        {
            if (form == nullptr) return;

            // ensure form is not maximized
            try {
                form->WindowState = System::Windows::Forms::FormWindowState::Normal;
            }
            catch (...) {}

            form->BackColor = WindowBack;
            form->ForeColor = FormTextColor;

            ApplyToControlsRecursive(form, form->Controls);

            // If form has a MainMenuStrip, ensure its items are styled
            if (form->MainMenuStrip != nullptr)
            {
                StyleMenuStrip(form->MainMenuStrip);
            }
        }

    private:
        static void ApplyToControlsRecursive(Control^ containerForm, System::Collections::IEnumerator^ dummy) {}

        static void ApplyToControlsRecursive(Control^ parent, System::Collections::IEnumerable^ controls)
        {
            for each (Control^ c in controls)
            {
                // Panels: content area should be white (PanelBack)
                if (dynamic_cast<Panel^>(c) != nullptr)
                {
                    c->BackColor = PanelBack;
                    c->ForeColor = PanelTextColor;
                    // recurse into panel children
                    ApplyToControlsRecursive(c, c->Controls);
                    continue;
                }

                // MenuStrip
                if (dynamic_cast<MenuStrip^>(c) != nullptr)
                {
                    MenuStrip^ ms = (MenuStrip^)c;
                    ms->BackColor = WindowBack;
                    ms->ForeColor = FormTextColor;
                    StyleMenuStrip(ms);
                    // also style items
                    for each (ToolStripItem^ item in ms->Items)
                    {
                        item->ForeColor = FormTextColor;
                    }
                    continue;
                }

                // Labels directly on form: use form text color
                if (dynamic_cast<Label^>(c) != nullptr)
                {
                    c->ForeColor = (c->Parent == parent && dynamic_cast<Panel^>(c->Parent) == nullptr) ? FormTextColor : PanelTextColor;
                    continue;
                }

                // TextBox: if inside panel use Panel style, else use form style
                if (dynamic_cast<TextBox^>(c) != nullptr)
                {
                    TextBox^ tb = (TextBox^)c;
                    if (dynamic_cast<Panel^>(tb->Parent) != nullptr)
                    {
                        tb->BackColor = PanelBack;
                        tb->ForeColor = PanelTextColor;
                    }
                    else
                    {
                        tb->BackColor = WindowBack;
                        tb->ForeColor = FormTextColor;
                    }
                    tb->BorderStyle = BorderStyle::FixedSingle;
                    tb->Paint += gcnew PaintEventHandler(&UIStyles::TextBox_Paint);
                    continue;
                }

                // NumericUpDown: style similar to TextBox
                if (dynamic_cast<NumericUpDown^>(c) != nullptr)
                {
                    NumericUpDown^ nu = (NumericUpDown^)c;
                    if (dynamic_cast<Panel^>(nu->Parent) != nullptr)
                    {
                        nu->BackColor = PanelBack;
                        nu->ForeColor = PanelTextColor;
                    }
                    else
                    {
                        nu->BackColor = WindowBack;
                        nu->ForeColor = FormTextColor;
                    }
                    continue;
                }

                // Buttons: use ButtonColor
                if (dynamic_cast<Button^>(c) != nullptr)
                {
                    Button^ b = (Button^)c;
                    b->BackColor = ButtonColor;
                    b->FlatStyle = FlatStyle::Flat;
                    b->FlatAppearance->BorderSize = 0;
                    b->ForeColor = ButtonTextColor;
                    continue;
                }

                // DataGridView: style for panel background if inside panel
                if (dynamic_cast<DataGridView^>(c) != nullptr)
                {
                    DataGridView^ dg = (DataGridView^)c;
                    dg->EnableHeadersVisualStyles = false;
                    dg->BackgroundColor = (dynamic_cast<Panel^>(dg->Parent) != nullptr) ? PanelBack : WindowBack;
                    dg->DefaultCellStyle->BackColor = (dynamic_cast<Panel^>(dg->Parent) != nullptr) ? PanelBack : WindowBack;
                    dg->DefaultCellStyle->ForeColor = PanelTextColor;
                    dg->ColumnHeadersDefaultCellStyle->BackColor = PanelBack;
                    dg->ColumnHeadersDefaultCellStyle->ForeColor = PanelTextColor;
                    continue;
                }

                // PictureBox: set to panel background if inside panel
                if (dynamic_cast<PictureBox^>(c) != nullptr)
                {
                    c->BackColor = (dynamic_cast<Panel^>(c->Parent) != nullptr) ? PanelBack : WindowBack;
                    continue;
                }

                // For other controls, set foreground according to parent
                if (c->Parent != nullptr && dynamic_cast<Panel^>(c->Parent) != nullptr)
                {
                    c->ForeColor = PanelTextColor;
                }
                else
                {
                    c->ForeColor = FormTextColor;
                }

                // Recurse into child controls
                if (c->HasChildren)
                {
                    ApplyToControlsRecursive(parent, c->Controls);
                }
            }
        }

        // draw a subtle border for TextBox
        static void TextBox_Paint(Object^ sender, PaintEventArgs^ e)
        {
            TextBox^ tb = dynamic_cast<TextBox^>(sender);
            if (tb == nullptr) return;
            Rectangle r = tb->ClientRectangle;
            r.Width -= 1; r.Height -= 1;
            Pen^ p = gcnew Pen(TextBoxBorder, 1);
            e->Graphics->DrawRectangle(p, r);
        }

        static void StyleMenuStrip(MenuStrip^ ms)
        {
            if (ms == nullptr) return;
            ms->Renderer = gcnew ToolStripProfessionalRenderer(gcnew System::Windows::Forms::ProfessionalColorTable());
            for each (ToolStripItem^ item in ms->Items)
            {
                item->MouseEnter -= gcnew EventHandler(&UIStyles::MenuItem_MouseEnter);
                item->MouseLeave -= gcnew EventHandler(&UIStyles::MenuItem_MouseLeave);
                item->Click -= gcnew EventHandler(&UIStyles::MenuItem_Click);
                item->MouseEnter += gcnew EventHandler(&UIStyles::MenuItem_MouseEnter);
                item->MouseLeave += gcnew EventHandler(&UIStyles::MenuItem_MouseLeave);
                item->Click += gcnew EventHandler(&UIStyles::MenuItem_Click);
            }
        }

        // Menu item hover/leave handlers
        static void MenuItem_MouseEnter(Object^ sender, EventArgs^ e)
        {
            ToolStripItem^ item = dynamic_cast<ToolStripItem^>(sender);
            if (item == nullptr) return;
            item->BackColor = MenuActive;
        }
        static void MenuItem_MouseLeave(Object^ sender, EventArgs^ e)
        {
            ToolStripItem^ item = dynamic_cast<ToolStripItem^>(sender);
            if (item == nullptr) return;
            item->BackColor = Color::Transparent;
        }
        static void MenuItem_Click(Object^ sender, EventArgs^ e)
        {
            ToolStripItem^ clicked = dynamic_cast<ToolStripItem^>(sender);
            if (clicked == nullptr) return;

            // set all siblings to default and clicked to active
            if (clicked->GetCurrentParent() != nullptr)
            {
                for each (ToolStripItem^ it in clicked->GetCurrentParent()->Items)
                {
                    it->BackColor = Color::Transparent;
                }
                clicked->BackColor = MenuActive;
            }
        }
    };

}
