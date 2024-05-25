#include "GlobalData.h"

namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;
    //���̂Ƃ���͎g�p���Ă��Ȃ����A��������[�h���Ɏ��s����K�v������i�����ԍ��őI�ʂ����[�h�j
    void GlobalData::LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex)
    {
        int Index = 0; // �C���f�b�N�X(�t�@�C���̓ǂݍ���)�����Z�b�g

        try
        {
            // �t�@�C�����J��
            System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(fileName);

            String^ line;
            // �t�@�C������1�s���ǂݍ��݁A�z��Ɋi�[����
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

            // �t�@�C�������
            sr->Close();
        }
        catch (Exception^ e)
        {
            // �G���[���b�Z�[�W��\��
            MessageBox::Show("�t�@�C����ǂݍ��ލۂɃG���[���������܂���: " + e->Message, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    //���X�g�{�b�N�X�ɒǉ����鏈���A
    void GlobalData::LoadDataToListBox(array<String^, 2>^ dataArray, int currentIndex, System::Windows::Forms::ListBox^ listBox)
    {
        listBox->Items->Clear();
        for (int i = 0; i < currentIndex; i++) {
            if (dataArray[i, 0] == nullptr || dataArray[i, 1] == nullptr || dataArray[i, 2] == nullptr) {
                System::Diagnostics::Debug::WriteLine("Null value in dataArray at index: " + i);
            }
            else {
                listBox->Items->Add("�\��: " + dataArray[i, 0] + ", " + dataArray[i, 1] + ", " + dataArray[i, 2]);
            }
        }
    }

    void GlobalData::SaveDataToFile(String^ fileName, String^ room, String^ data, String^ mokuteki)
    {
        try
        {
            // �t�@�C�����J��
            System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fileName, true);

            // �f�[�^���t�@�C���ɏ�������
            sw->WriteLine("�\��: " + room + "," + data + "," + mokuteki);

            // �t�@�C�������
            sw->Close();

            // �ۑ������̃��b�Z�[�W��\��
            MessageBox::Show("�f�[�^���t�@�C���ɕۑ�����܂����B", "���", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ e)
        {
            // �G���[���b�Z�[�W��\��
            MessageBox::Show("�t�@�C���ɏ������ލۂɃG���[���������܂���: " + e->Message, "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}
