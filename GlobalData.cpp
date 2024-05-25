#include "GlobalData.h"

namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;
    //今のところは使用していないが、これをロード時に実行する必要がある（部屋番号で選別しロード）
    void GlobalData::LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex)
    {
        int Index = 0; // インデックス(ファイルの読み込み)をリセット

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
                    System::Diagnostics::Debug::WriteLine("Reading line: " + line);
                    dataArray[Index, 0] = parts[0]->Trim();
                    dataArray[Index, 1] = parts[1]->Trim();
                    dataArray[Index, 2] = parts[2]->Trim();
                    currentIndex++;
                    Index++;
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

    //リストボックスに追加する処理、
    void GlobalData::LoadDataToListBox(array<String^, 2>^ dataArray, int currentIndex, System::Windows::Forms::ListBox^ listBox)
    {
        listBox->Items->Clear();
        for (int i = 0; i < currentIndex; i++) {
            if (dataArray[i, 0] == nullptr || dataArray[i, 1] == nullptr || dataArray[i, 2] == nullptr) {
                System::Diagnostics::Debug::WriteLine("Null value in dataArray at index: " + i);
            }
            else {
                listBox->Items->Add("予約: " + dataArray[i, 0] + ", " + dataArray[i, 1] + ", " + dataArray[i, 2]);
            }
        }
    }

    void GlobalData::SaveDataToFile(String^ fileName, String^ room, String^ data, String^ mokuteki)
    {
        try
        {
            // ファイルを開く
            System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileName, true);

            // データをファイルに書き込む
            sw->WriteLine("予約: " + room + "," + data + "," + mokuteki);

            // ファイルを閉じる
            sw->Close();

            // 保存完了のメッセージを表示
            MessageBox::Show("データがファイルに保存されました。", "情報", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ e)
        {
            // エラーメッセージを表示
            MessageBox::Show("ファイルに書き込む際にエラーが発生しました: " + e->Message, "エラー", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}
