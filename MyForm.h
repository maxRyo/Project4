#pragma once
#include "GlobalData.h"
#include "Form4.h"

namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
         
            InitializeComponent();
            //ファイルの読み込み操作
            LoadFile();
            Index = 0;
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::ListBox^ listBox1;
    private: System::Windows::Forms::ListBox^ listBox2;
    private: System::Windows::Forms::ListBox^ listBox3;
    private: System::Windows::Forms::ListBox^ listBox4;
    private: System::Windows::Forms::ListBox^ listBox5;
    private: System::Windows::Forms::ListBox^ listBox6;
    private: System::Windows::Forms::Button^ button2;

    private:
        //デザイナ変数
        System::ComponentModel::Container^ components;
        int Index;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->listBox1 = (gcnew System::Windows::Forms::ListBox());
            this->listBox2 = (gcnew System::Windows::Forms::ListBox());
            this->listBox3 = (gcnew System::Windows::Forms::ListBox());
            this->listBox4 = (gcnew System::Windows::Forms::ListBox());
            this->listBox5 = (gcnew System::Windows::Forms::ListBox());
            this->listBox6 = (gcnew System::Windows::Forms::ListBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(155, 270);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Load Data";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // listBox1
            // 
            this->listBox1->FormattingEnabled = true;
            this->listBox1->ItemHeight = 18;
            this->listBox1->Location = System::Drawing::Point(10, 10);
            this->listBox1->Name = L"listBox1";
            this->listBox1->Size = System::Drawing::Size(150, 184);
            this->listBox1->TabIndex = 1;
            // 
            // listBox2
            // 
            this->listBox2->FormattingEnabled = true;
            this->listBox2->ItemHeight = 18;
            this->listBox2->Location = System::Drawing::Point(170, 10);
            this->listBox2->Name = L"listBox2";
            this->listBox2->Size = System::Drawing::Size(150, 184);
            this->listBox2->TabIndex = 2;
            // 
            // listBox3
            // 
            this->listBox3->FormattingEnabled = true;
            this->listBox3->ItemHeight = 18;
            this->listBox3->Location = System::Drawing::Point(330, 10);
            this->listBox3->Name = L"listBox3";
            this->listBox3->Size = System::Drawing::Size(150, 184);
            this->listBox3->TabIndex = 3;
            // 
            // listBox4
            // 
            this->listBox4->FormattingEnabled = true;
            this->listBox4->ItemHeight = 18;
            this->listBox4->Location = System::Drawing::Point(490, 10);
            this->listBox4->Name = L"listBox4";
            this->listBox4->Size = System::Drawing::Size(150, 184);
            this->listBox4->TabIndex = 4;
            // 
            // listBox5
            // 
            this->listBox5->FormattingEnabled = true;
            this->listBox5->ItemHeight = 18;
            this->listBox5->Location = System::Drawing::Point(650, 10);
            this->listBox5->Name = L"listBox5";
            this->listBox5->Size = System::Drawing::Size(150, 184);
            this->listBox5->TabIndex = 5;
            // 
            // listBox6
            // 
            this->listBox6->FormattingEnabled = true;
            this->listBox6->ItemHeight = 18;
            this->listBox6->Location = System::Drawing::Point(810, 10);
            this->listBox6->Name = L"listBox6";
            this->listBox6->Size = System::Drawing::Size(150, 184);
            this->listBox6->TabIndex = 6;
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(490, 235);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 23);
            this->button2->TabIndex = 7;
            this->button2->Text = L"button2";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1000, 300);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->listBox1);
            this->Controls->Add(this->listBox2);
            this->Controls->Add(this->listBox3);
            this->Controls->Add(this->listBox4);
            this->Controls->Add(this->listBox5);
            this->Controls->Add(this->listBox6);
            this->Name = L"MyForm";
            this->Text = L"Form2";
            this->ResumeLayout(false);
        }
#pragma endregion
        //読み込み処理の関数
        void LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex)
        {
            Index = 0; // インデックスをリセット

            try
            {
                // ファイルを開く
                System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fileName);

                String^ line;
                // ファイルから1行ずつ読み込み、配列に格納する
                while ((line = sr->ReadLine()) != nullptr)
                {
                    array<String^>^ parts = line->Split(',');
                    if (parts->Length == 3)
                    {
                        dataArray[Index, 0] = parts[0]->Trim()->Substring(4);
                        dataArray[Index, 1] = parts[1]->Trim();
                        dataArray[Index, 2] = parts[2]->Trim();
                        currentIndex++;
                        Index++;
                        System::Diagnostics::Debug::WriteLine("配列の内容" + Index);
                    }
                }

                // ファイルを閉じる
                sr->Close();
            }
            catch (Exception^ e)
            {
                // エラーメッセージを表示
                MessageBox::Show("ファイルを読み込む際にエラーが発生しました: " + e->Message, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        //ファイルの読み込み操作の内容
        void LoadFile() {
            LoadDataFromFile("file1.txt", GlobalData::formData1Array, GlobalData::formData1Index);
            System::Diagnostics::Debug::WriteLine("初期化の確認要素番号：" + GlobalData::formData1Index);
            //GlobalData::LoadDataToListBox(GlobalData::formData1Array, Index, listBox1);

            // ファイル2からデータを読み込んでリストボックス2に表示
            LoadDataFromFile("file2.txt", GlobalData::formData2Array, GlobalData::formData2Index);
            //GlobalData::LoadDataToListBox(GlobalData::formData2Array, Index, listBox2);

            // ファイル3からデータを読み込んでリストボックス3に表示
            LoadDataFromFile("file3.txt", GlobalData::formData3Array, GlobalData::formData3Index);
           // GlobalData::LoadDataToListBox(GlobalData::formData3Array, Index, listBox3);

            // ファイル4からデータを読み込んでリストボックス4に表示
            LoadDataFromFile("file4.txt", GlobalData::formData4Array, GlobalData::formData4Index);
            //GlobalData::LoadDataToListBox(GlobalData::formData4Array, Index, listBox4);

            // ファイル5からデータを読み込んでリストボックス5に表示
            LoadDataFromFile("file5.txt", GlobalData::formData5Array, GlobalData::formData5Index);
            //GlobalData::LoadDataToListBox(GlobalData::formData5Array, Index, listBox5);

            // ファイル6からデータを読み込んでリストボックス6に表示
            LoadDataFromFile("file6.txt", GlobalData::formData6Array, GlobalData::formData6Index);
            //GlobalData::LoadDataToListBox(GlobalData::formData6Array, Index, listBox6);
        }
//更新の操作
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    // ファイル1からデータを読み込んでリストボックス1に表示
    GlobalData::LoadDataToListBox(GlobalData::formData1Array, GlobalData::formData1Index, listBox1);

    // ファイル2からデータを読み込んでリストボックス2に表示
    GlobalData::LoadDataToListBox(GlobalData::formData2Array, GlobalData::formData2Index, listBox2);

    // ファイル3からデータを読み込んでリストボックス3に表示
    GlobalData::LoadDataToListBox(GlobalData::formData3Array, GlobalData::formData3Index, listBox3);

    // ファイル4からデータを読み込んでリストボックス4に表示
    GlobalData::LoadDataToListBox(GlobalData::formData4Array, GlobalData::formData4Index, listBox4);

    // ファイル5からデータを読み込んでリストボックス5に表示
    GlobalData::LoadDataToListBox(GlobalData::formData5Array, GlobalData::formData5Index, listBox5);

    // ファイル6からデータを読み込んでリストボックス6に表示
    GlobalData::LoadDataToListBox(GlobalData::formData6Array, GlobalData::formData6Index, listBox6);
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    Form4^ form4 = gcnew Form4();
    form4->ShowDialog();
}
};
}

