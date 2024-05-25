#pragma once

namespace Project4 {
    using namespace System;

    public ref class GlobalData {
        static property GlobalData^ Instance {
            GlobalData^ get() {
                if (instance == nullptr) {
                    instance = gcnew GlobalData();
                }
                return instance;
            }
        }

    private:
        static GlobalData^ instance = nullptr;
    public:
        //�����ԍ�
        static String^ name;
        
        static array<String^, 2>^ formData1Array = gcnew array<String^, 2>(100, 3);
        static array<String^, 2>^ formData2Array = gcnew array<String^, 2>(100, 3);
        static array<String^, 2>^ formData3Array = gcnew array<String^, 2>(100, 3);
        static array<String^, 2>^ formData4Array = gcnew array<String^, 2>(100, 3);
        static array<String^, 2>^ formData5Array = gcnew array<String^, 2>(100, 3);
        static array<String^, 2>^ formData6Array = gcnew array<String^, 2>(100, 3);
        static String^ filename;
        static int formData1Index = 0;
        static int formData2Index = 0;
        static int formData3Index = 0;
        static int formData4Index = 0;
        static int formData5Index = 0;
        static int formData6Index = 0;

        // �t�@�C������f�[�^��ǂݍ��ފ֐�
        void LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex);

        // �z������X�g�{�b�N�X�ɕ\������֐�
        static void LoadDataToListBox(array<String^, 2>^ dataArray, int currentIndex, System::Windows::Forms::ListBox^ listBox);

        // �t�@�C���Ƀf�[�^���������ފ֐��i���������K�v�Ȃ��j
        static void SaveDataToFile(String^ fileName, String^ room, String^ data, String^ mokuteki);
    };
}
