#pragma once
#include "GlobalData.h"
#include "Form5.h"
namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form4 : public System::Windows::Forms::Form
    {
    public:
        Form4(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form4()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::Button^ button2;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(155, 270);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Save Data";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form4::button1_Click);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(155, 90);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 25);
            this->textBox1->TabIndex = 1;
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(155, 152);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(100, 25);
            this->textBox2->TabIndex = 2;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(155, 217);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(100, 25);
            this->textBox3->TabIndex = 3;
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"File1", L"File2", L"File3", L"File4", L"File5",
                    L"File6"
            });
            this->comboBox1->Location = System::Drawing::Point(155, 30);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 26);
            this->comboBox1->TabIndex = 4;
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(392, 198);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 5;
            this->button2->Text = L"button2";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form4::button2_Click);
            // 
            // Form4
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(660, 626);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Name = L"Form4";
            this->Text = L"Form4";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ room = this->textBox1->Text;
        String^ data = this->textBox2->Text;
        String^ mokuteki = this->textBox3->Text;
        String^ selectedFile = this->comboBox1->SelectedItem->ToString();

        if (selectedFile == "File1") {
            GlobalData::SaveDataToFile("file1.txt", room, data, mokuteki);
            GlobalData::formData1Array[GlobalData::formData1Index, 0] = room;
            GlobalData::formData1Array[GlobalData::formData1Index, 1] = data;
            GlobalData::formData1Array[GlobalData::formData1Index, 2] = mokuteki;
            GlobalData::formData1Index++;
        }
        else if (selectedFile == "File2") {
            GlobalData::SaveDataToFile("file2.txt", room, data, mokuteki);
            GlobalData::formData2Array[GlobalData::formData2Index, 0] = room;
            GlobalData::formData2Array[GlobalData::formData2Index, 1] = data;
            GlobalData::formData2Array[GlobalData::formData2Index, 2] = mokuteki;
            GlobalData::formData2Index++;
        }
        else if (selectedFile == "File3") {
            GlobalData::SaveDataToFile("file3.txt", room, data, mokuteki);
            GlobalData::formData3Array[GlobalData::formData3Index, 0] = room;
            GlobalData::formData3Array[GlobalData::formData3Index, 1] = data;
            GlobalData::formData3Array[GlobalData::formData3Index, 2] = mokuteki;
            GlobalData::formData3Index++;
        }
        else if (selectedFile == "File4") {
            GlobalData::SaveDataToFile("file4.txt", room, data, mokuteki);
            GlobalData::formData4Array[GlobalData::formData4Index, 0] = room;
            GlobalData::formData4Array[GlobalData::formData4Index, 1] = data;
            GlobalData::formData4Array[GlobalData::formData4Index, 2] = mokuteki;
            GlobalData::formData4Index++;
        }
        else if (selectedFile == "File5") {
            GlobalData::SaveDataToFile("file5.txt", room, data, mokuteki);
            GlobalData::formData5Array[GlobalData::formData5Index, 0] = room;
            GlobalData::formData5Array[GlobalData::formData5Index, 1] = data;
            GlobalData::formData5Array[GlobalData::formData5Index, 2] = mokuteki;
            GlobalData::formData5Index++;
        }
        else if (selectedFile == "File6") {
            GlobalData::SaveDataToFile("file6.txt", room, data, mokuteki);
            GlobalData::formData6Array[GlobalData::formData6Index, 0] = room;
            GlobalData::formData6Array[GlobalData::formData6Index, 1] = data;
            GlobalData::formData6Array[GlobalData::formData6Index, 2] = mokuteki;
            GlobalData::formData6Index++;
        }
       
        Form5^ form5 = gcnew Form5();
        GlobalData::name = selectedFile;
        form5->Show();
        
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
       
    }
};
}
