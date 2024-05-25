#include "GlobalData.h"

namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;
    //���̂Ƃ���͎g�p���Ă��Ȃ����A��������[�h���Ɏ��s����K�v������i�����ԍ��őI�ʂ����[�h�j
    /**/void GlobalData::LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex)
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
	//���O�C�����
	/*���O�C���̏ꏊ�ɏ����K�v������R�[�h
	 �R���X�g���N�^�̏�

	 LoadFile();
     Index = 0;
			
	�f�U�C�i�ϐ��̏�
	 int Index;
	
	�֐�
	
	void ReadDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% RoomIndex) {
		try {
			//StreamReader���g���ăt�@�C������ǂݍ���
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(Filename);
			String^ line;

			while ((line = sr->ReadLine()) != nullptr) {
				cli::array<String^>^ parts = line->Split(',');
				if (parts->Length == 5) {
					DataArray[RoomIndex, 0] = parts[1];
					DataArray[RoomIndex, 1] = parts[2];
					DataArray[RoomIndex, 2] = parts[3];
					DataArray[RoomIndex, 3] = parts[4];
					DataArray[RoomIndex, 4] = parts[5];
					RoomIndex++;
				}
				else {
					throw gcnew Exception("�f�[�^�z�񂪂����ς��ł�");
				}
			}
			sr->Close();
		}
		catch (Exception^ e) {
			throw gcnew Exception("�t�@�C���ǂݍ��݃G���[" + e->Message);
		}

	};
		  void LoadFile() {
		    //�t�@�C��1����f�[�^��ǂݍ���Ń��X�g�{�b�N�X2�ɕ\��
			ReadDataFromFile("room1data.txt", PublicData::Room1Array, PublicData::Room1Index);
			//PublicData::LoadDataToListBox(PublicData::Room1Array, Index, listBox1);

			// �t�@�C��2����f�[�^��ǂݍ���Ń��X�g�{�b�N�X2�ɕ\��
			ReadDataFromFile("room2data.txt", PublicData::Room1Array, PublicData::Room2Index);
			//PublicData::LoadDataToListBox(PublicData::Room2Array, Index, listBox1);

			// �t�@�C��3����f�[�^��ǂݍ���Ń��X�g�{�b�N�X3�ɕ\��
			ReadDataFromFile("room3data.txt", PublicData::Room1Array, PublicData::Room3Index);
			//PublicData::LoadDataToListBox(PublicData::Room3Array, Index, listBox1);

			// �t�@�C��4����f�[�^��ǂݍ���Ń��X�g�{�b�N�X4�ɕ\��
			ReadDataFromFile("room4data.txt", PublicData::Room1Array, PublicData::Room4Index);
			//PublicData::LoadDataToListBox(PublicData::Room4Array, Index, listBox1);

			// �t�@�C��5����f�[�^��ǂݍ���Ń��X�g�{�b�N�X5�ɕ\��
			ReadDataFromFile("room5data.txt", PublicData::Room1Array, PublicData::Room5Index);
			//PublicData::LoadDataToListBox(PublicData::Room5Array, Index, listBox1);

			// �t�@�C��6����f�[�^��ǂݍ���Ń��X�g�{�b�N�X6�ɕ\��
			ReadDataFromFile("room6data.txt", PublicData::Room1Array, PublicData::Room6Index);
			//PublicData::LoadDataToListBox(PublicData::Room6Array, Index, listBox1);
		}

	*/


	//�����ڍ׉�ʂɋL�q�������
	/*�R���X�g���N�^
	LoadData();

	�֐�
	void LoadDataToListBox(cli::array<String^, 2>^ dataArray, int currentIndex) {
			for (int i = 0; i < currentIndex; i++) {
				listBox1->Items->Add("�\��: " + dataArray[i, 1] + ", " + dataArray[i, 2] + ", " + dataArray[i, 3] +dataArray[i, 4] + ", " + dataArray[i, 5]);
			}
		}
	LoadData() {
	listBox1->Items->Clear();
			switch (RoomNumber)
			{
				case 1:
					LoadDataToListBox(PublicData::Room1Array, PublicData::Room1Index);
					break;
				case 2:
					LoadDataToListBox(PublicData::Room2rray, PublicData::Room2Index);
					break;
				case 3:
					LoadDataToListBox(PublicData::Room3Array, PublicData::Room3Index);
					break;
				case 4:
					LoadDataToListBox(PublicData::Room4Array, PublicData::Room4Index);
					break;
				case 5:
					LoadDataToListBox(PublicData::Room5Array, PublicData::Room5Index);
					break;
				case 6:
					LoadDataToListBox(PublicData::Room6Array, PublicData::Room6Index);
					break;
			default:
				listBox1->Items->Add("�Y���̕����̗\��͂���܂���");
				break;
			}
	}

	�������ω������Ƃ��̏����ƃ��[�U�[�l�[���̂�������炭
	
	�P�F�R���X�g���N�^�Ɋ֐��̎w��
	�Q�F�֐��̒�`
	�R�F

	�����̏���
	���������ʂ̉��L�̕������R�s�y���ăR�����g�̏��͂���Ȃ�
	//�K�v�ȏ����͂����ɏ�������ł�������
		PublicData::Date = Day;
		//StartHour = StartHour + StartMin;
		//EndHour = EndHour + EndMin;
		Num = Convert::ToInt32(NumData);
		StartHour = Startint;
		EndHour = Endint;
	�P�F�R���X�g���N�^�Ɋ֐��̎w��
	
	Result();
	2:�֐��̓��e
	Result()
	{
	for (int i = 1;i<7;i++) {
		 int res = PublicData::ResearchReserve(i, PublicData::Date,StartHour,EndHour,Num);
		 if(res){
			switch (i){
			case 1:
				this->button1->Viseble = true;
			break;
			case 2:
				this->button2->Viseble = true;
			break;
			case 3:
				this->button3->Viseble = true;
			break;
			case 4:
				this->button4->Viseble = true;
			break;
			case 5:
				this->button5->Viseble = true;
			break;
			case 6:
				this->button6->Viseble = true;
			break;
			}
		 }else if()
	}
	}

	*/
    //���X�g�{�b�N�X�ɒǉ����鏈��(�ǉ�����K�v����)�R�s�y����GlobalData��PublicData�ɕϊ�
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

//���ǒ�
//#include "PublicData.h"
namespace Project3 {
	void PublicData::ReadDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% RoomIndex) {
		try {
			//StreamReader���g���ăt�@�C������ǂݍ���
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(Filename);
			String^ line;

			while ((line = sr->ReadLine()) != nullptr) {
				cli::array<String^>^ parts = line->Split(',');
				if (parts->Length == 5) {
					DataArray[RoomIndex, 0] = parts[1];
					DataArray[RoomIndex, 1] = parts[2];
					DataArray[RoomIndex, 2] = parts[3];
					DataArray[RoomIndex, 3] = parts[4];
					DataArray[RoomIndex, 4] = parts[5];
					RoomIndex++;
				}
				else {
					throw gcnew Exception("�f�[�^�z�񂪂����ς��ł�");
				}
			}
			sr->Close();
		}
		catch (Exception^ e) {
			throw gcnew Exception("�t�@�C���ǂݍ��݃G���[" + e->Message);
		}

	};
	void PublicData::UserDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% UserIndex) {
		ReadDataFromFile(Filename, DataArray, UserIndex);
	};
	int PublicData::ResearchReserve(int RoomNumber, String^ Date, int Start, int End, int people) {
		int Max;
		switch (RoomNumber) {
		case 1:

			Max = 6;
			for (int i = 0; i < Room1Index; i++) {
				if (people <= Max)
				{
					if (Room1Array[i, 1] == Date)
					{
						if ((Convert::ToInt32(Room1Array[i, 2]) <= End) && ((Convert::ToInt32(Room1Array[i, 3]) < Start)))
						{
							return 1;
						}
						else { return 0; }
					}
					else { return 0; }
				}
				else { return 0; }
			}
		case 2:
			Max = 10;
			for (int i = 0; i < Room1Index; i++) {
				if (people <= Max)
				{
					if (Room2Array[i, 1] == Date)
					{
						if ((Convert::ToInt32(Room2Array[i, 2]) <= End) && ((Convert::ToInt32(Room2Array[i, 3]) < Start)))
						{
							return 1;
						}
						else { return 0; }
					}
					else { return 0; }
				}
				else { return 0; }
			}
		case 3:
			Max = 15;
			for (int i = 0; i < Room3Index; i++) {
				if (people <= Max)
				{
					if (Room3Array[i, 1] == Date)
					{
						if ((Convert::ToInt32(Room3Array[i, 2]) <= End) && ((Convert::ToInt32(Room3Array[i, 3]) < Start)))
						{
							return 1;
						}
						else { return 0; }
					}
					else { return 0; }
				}
				else { return 0; }
			}
		case 4:
			Max = 50;
			for (int i = 0; i < Room4Index; i++) {
				if (people <= Max)
				{
					if (Room4Array[i, 1] == Date)
					{
						if ((Convert::ToInt32(Room4Array[i, 2]) <= End) && ((Convert::ToInt32(Room4Array[i, 3]) < Start)))
						{
							return 1;
						}
						else { return 0; }
					}
					else { return 0; }
				}
				else { return 0; }
			}
		case 5:
			Max = 4;
			for (int i = 0; i < Room5Index; i++) {
				if (people <= Max)
				{
					if (Room5Array[i, 1] == Date)
					{
						if ((Convert::ToInt32(Room5Array[i, 2]) <= End) && ((Convert::ToInt32(Room5Array[i, 3]) < Start)))
						{
							return 1;
						}
						else { return 0; }
					}
					else { return 0; }
				}
				else { return 0; }
			}
		case 6:
			Max = 1;
			for (int i = 0; i < Room6Index; i++) {
				if (people <= Max)
				{
					if (Room6Array[i, 1] == Date)
					{
						if ((Convert::ToInt32(Room6Array[i, 2]) <= End) && ((Convert::ToInt32(Room6Array[i, 3]) < Start)))
						{
							return 1;
						}
						else { return 0; }
					}
					else { return 0; }
				}
				else { return 0; }
			}
		}
	}
}


