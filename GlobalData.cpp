#include "GlobalData.h"

namespace Project4 {
    using namespace System;
    using namespace System::Windows::Forms;
    //今のところは使用していないが、これをロード時に実行する必要がある（部屋番号で選別しロード）
    /**/void GlobalData::LoadDataFromFile(String^ fileName, array<String^, 2>^ dataArray, int% currentIndex)
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
	//ログイン画面
	/*ログインの場所に書く必要があるコード
	 コンストラクタの所

	 LoadFile();
     Index = 0;
			
	デザイナ変数の所
	 int Index;
	
	関数
	
	void ReadDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% RoomIndex) {
		try {
			//StreamReaderを使ってファイルから読み込む
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
					throw gcnew Exception("データ配列がいっぱいです");
				}
			}
			sr->Close();
		}
		catch (Exception^ e) {
			throw gcnew Exception("ファイル読み込みエラー" + e->Message);
		}

	};
		  void LoadFile() {
		    //ファイル1からデータを読み込んでリストボックス2に表示
			ReadDataFromFile("room1data.txt", PublicData::Room1Array, PublicData::Room1Index);
			//PublicData::LoadDataToListBox(PublicData::Room1Array, Index, listBox1);

			// ファイル2からデータを読み込んでリストボックス2に表示
			ReadDataFromFile("room2data.txt", PublicData::Room1Array, PublicData::Room2Index);
			//PublicData::LoadDataToListBox(PublicData::Room2Array, Index, listBox1);

			// ファイル3からデータを読み込んでリストボックス3に表示
			ReadDataFromFile("room3data.txt", PublicData::Room1Array, PublicData::Room3Index);
			//PublicData::LoadDataToListBox(PublicData::Room3Array, Index, listBox1);

			// ファイル4からデータを読み込んでリストボックス4に表示
			ReadDataFromFile("room4data.txt", PublicData::Room1Array, PublicData::Room4Index);
			//PublicData::LoadDataToListBox(PublicData::Room4Array, Index, listBox1);

			// ファイル5からデータを読み込んでリストボックス5に表示
			ReadDataFromFile("room5data.txt", PublicData::Room1Array, PublicData::Room5Index);
			//PublicData::LoadDataToListBox(PublicData::Room5Array, Index, listBox1);

			// ファイル6からデータを読み込んでリストボックス6に表示
			ReadDataFromFile("room6data.txt", PublicData::Room1Array, PublicData::Room6Index);
			//PublicData::LoadDataToListBox(PublicData::Room6Array, Index, listBox1);
		}

	*/


	//部屋詳細画面に記述するもの
	/*コンストラクタ
	LoadData();

	関数
	void LoadDataToListBox(cli::array<String^, 2>^ dataArray, int currentIndex) {
			for (int i = 0; i < currentIndex; i++) {
				listBox1->Items->Add("予約: " + dataArray[i, 1] + ", " + dataArray[i, 2] + ", " + dataArray[i, 3] +dataArray[i, 4] + ", " + dataArray[i, 5]);
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
				listBox1->Items->Add("該当の部屋の予約はありません");
				break;
			}
	}

	日時が変化したときの処理とユーザーネームのやつもおそらく
	
	１：コンストラクタに関数の指定
	２：関数の定義
	３：

	検索の処理
	検索する画面の下記の部分をコピペしてコメントの所はいらない
	//必要な処理はここに書き込んでください
		PublicData::Date = Day;
		//StartHour = StartHour + StartMin;
		//EndHour = EndHour + EndMin;
		Num = Convert::ToInt32(NumData);
		StartHour = Startint;
		EndHour = Endint;
	１：コンストラクタに関数の指定
	
	Result();
	2:関数の内容
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
    //リストボックスに追加する処理(追加する必要あり)コピペしてGlobalDataをPublicDataに変換
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

//改良中
//#include "PublicData.h"
namespace Project3 {
	void PublicData::ReadDataFromFile(String^ Filename, cli::array<String^, 2>^ DataArray, int% RoomIndex) {
		try {
			//StreamReaderを使ってファイルから読み込む
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
					throw gcnew Exception("データ配列がいっぱいです");
				}
			}
			sr->Close();
		}
		catch (Exception^ e) {
			throw gcnew Exception("ファイル読み込みエラー" + e->Message);
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


