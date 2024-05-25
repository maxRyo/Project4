#pragma once

namespace Project4 {
    using namespace System;

    //インスタンス化に必要な要素書く必要あり
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
        //部屋番号
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

        // ファイルからデータを読み込む関数
        void LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex);

        // 配列をリストボックスに表示する関数
        static void LoadDataToListBox(array<String^, 2>^ dataArray, int currentIndex, System::Windows::Forms::ListBox^ listBox);

        // ファイルにデータを書き込む関数（ワンちゃん必要ない）
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
		//ログインで使用する変数
		static String^ Id = "";
		static String^ PassWord;
		static int Flag = 1;

		//新規登録で使用する変数
		static String^ NewId = "";
		static String^ NewPassword = "";

		//選択部屋番号を保管する変数
		static int RoomNumber = 0;

		//予約で使用する変数
		static String^ Date = "";
		static String^ StartHour = "";
		static String^ StartMin = "";
		static String^ EndHour = "";
		static String^ EndMin = "";
		static int Num = 0;

		//認証情報を保管する配列
		static cli::array<String^, 1>^ UserArray = gcnew cli::array<String^, 1>(100);

		//認証情報配列の最後の要素を指す要素番号
		static int UserInfoIndex = 0;

		//部屋それぞれのテキストデータを保管する配列
		static cli::array<String^, 2>^ Room1Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room2Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room3Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room4Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room5Array = gcnew cli::array<String^, 2>(100, 5);
		static cli::array<String^, 2>^ Room6Array = gcnew cli::array<String^, 2>(100, 5);

		//部屋配列の最後の要素を指す要素番号
		static int Room1Index = 0;
		static int Room2Index = 0;
		static int Room3Index = 0;
		static int Room4Index = 0;
		static int Room5Index = 0;
		static int Room6Index = 0;


		//部屋のファイルからデータを読み込む関数
		static void ReadDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% RoomIndex);

		//認証情報ファイルからデータを読み込む関数
		static void UserDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% UserIndex);

		//データが重複していないかの関数
		static int ResearchReserve(int RoomNumber, String^ Date, int Start, int End, int people);

	};
}
