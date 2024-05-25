#pragma once

namespace Project4 {
    using namespace System;

    //�C���X�^���X���ɕK�v�ȗv�f�����K�v����
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


#pragma once
#include<fstream>
static int RoomNumber;
static int StartHour;
static int StartMin;
static int EndHour;
static int EndMin;
static int Num;
static int Id;
static int flag;
namespace Project3 {
	using namespace System;
	ref class PublicData
	{
		static property PublicData^ Instance {
			PublicData^ get() {
				if (instance == nullptr) {
					instance = gcnew PublicData();
				}
				return instance;
			}
		}
	private:
		static PublicData^ instance = nullptr;
	public:
		//���O�C���Ŏg�p����ϐ�
		static String^ Id = "";
		static String^ PassWord;
		static int Flag = 1;

		//�V�K�o�^�Ŏg�p����ϐ�
		static String^ NewId = "";
		static String^ NewPassword = "";

		//�I�𕔉��ԍ���ۊǂ���ϐ�
		static int RoomNumber = 0;

		//�\��Ŏg�p����ϐ�
		static String^ Date = "";
		static String^ StartHour = "";
		static String^ StartMin = "";
		static String^ EndHour = "";
		static String^ EndMin = "";
		static int Num = 0;

		//�F�؏���ۊǂ���z��
		static cli::array<String^, 1>^ UserArray = gcnew cli::array<String^, 1>(100);

		//�F�؏��z��̍Ō�̗v�f���w���v�f�ԍ�
		static int UserInfoIndex = 0;

		//�������ꂼ��̃e�L�X�g�f�[�^��ۊǂ���z��
		static cli::array<String^, 2>^ Room1Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room2Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room3Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room4Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room5Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room6Array = gcnew cli::array<String^, 2>(100, 5);

		//�����z��̍Ō�̗v�f���w���v�f�ԍ�
		static int Room1Index = 0;
		static int Room2Index = 0;
		static int Room3Index = 0;
		static int Room4Index = 0;
		static int Room5Index = 0;
		static int Room6Index = 0;


		//�����̃t�@�C������f�[�^��ǂݍ��ފ֐�
		static void ReadDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% RoomIndex);

		//�F�؏��t�@�C������f�[�^��ǂݍ��ފ֐�
		static void UserDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% UserIndex);

		//�f�[�^���d�����Ă��Ȃ����̊֐�
		static int ResearchReserve(int RoomNumber, String^ Date, int Start, int End, int people);

	};
}
