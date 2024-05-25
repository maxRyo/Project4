#pragma once
#include "GlobalData.h"

namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form5 : public System::Windows::Forms::Form
    {
    public:
        Form5(void)
        {
            InitializeComponent();
            LoadData();
        }

    protected:
        ~Form5()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::ListBox^ listBox1;
    private: System::Windows::Forms::ComboBox^ comboBox1;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            // 
            // listBox1
            // 
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 18;
            this->listBox1->Location = System::Drawing::Point(100, 100);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(200, 184);
            this->listBox1->TabIndex = 0;
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
                L"File1", L"File2", L"File3", L"File4", L"File5",
                    L"File6"
            });
            this->comboBox1->Location = System::Drawing::Point(100, 30);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 26);
            this->comboBox1->TabIndex = 1;
            this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form5::comboBox1_SelectedIndexChanged);
            // 
            // Form5
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(400, 400);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->listBox1);
            this->Name = L"Form5";
            this->Text = L"Form5";
            this->Load += gcnew System::EventHandler(this, &Form5::Form5_Load);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

        String^ selectedFile = this->comboBox1->Text;
        listBox1->Items->Clear();

        if (selectedFile == "File1") {
            LoadDataToListBox(GlobalData::formData1Array, GlobalData::formData1Index);
        }
        else if (selectedFile == "File2") {
            LoadDataToListBox(GlobalData::formData2Array, GlobalData::formData2Index);
        }
        else if (selectedFile == "File3") {
            LoadDataToListBox(GlobalData::formData3Array, GlobalData::formData3Index);
        }
        else if (selectedFile == "File4") {
            LoadDataToListBox(GlobalData::formData4Array, GlobalData::formData4Index);
        }
        else if (selectedFile == "File5") {
            LoadDataToListBox(GlobalData::formData5Array, GlobalData::formData5Index);
        }
        else if (selectedFile == "File6") {
            LoadDataToListBox(GlobalData::formData6Array, GlobalData::formData6Index);
        }
    }

    private:
        void LoadData() {
            //‚±‚Ì‰º‚Ì
            
            String^ selectedFile = GlobalData::name;
            listBox1->Items->Clear();

            if (selectedFile == "File1") {
                LoadDataToListBox(GlobalData::formData1Array, GlobalData::formData1Index);
            }
            else if (selectedFile == "File2") {
                LoadDataToListBox(GlobalData::formData2Array, GlobalData::formData2Index);
            }
            else if (selectedFile == "File3") {
                LoadDataToListBox(GlobalData::formData3Array, GlobalData::formData3Index);
            }
            else if (selectedFile == "File4") {
                LoadDataToListBox(GlobalData::formData4Array, GlobalData::formData4Index);
            }
            else if (selectedFile == "File5") {
                LoadDataToListBox(GlobalData::formData5Array, GlobalData::formData5Index);
            }
            else if (selectedFile == "File6") {
                LoadDataToListBox(GlobalData::formData6Array, GlobalData::formData6Index);
            }
        }

        void LoadDataToListBox(array<String^, 2>^ dataArray, int currentIndex) {
            for (int i = 0; i < currentIndex; i++) {
                listBox1->Items->Add("—\–ñ: " + dataArray[i, 0] + ", " + dataArray[i, 1] + ", " + dataArray[i, 2]);
            }
        }
    private: System::Void Form5_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadData();
    }
};
}
