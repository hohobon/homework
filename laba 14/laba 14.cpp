#include <iostream>
#include <string>
#include <ctime>
using namespace std;



struct Data
{
	string fio;
	string city17;
	string ulitsa;
	int home;
	int passport = 0;
};

void RANDOM(Data* arr)
{
	string DIO[] = { "Юдина Василиса Дмитриевна" ,"Климов Иван Даниилович" ,"Жмышенко Михаил Петрович" ,"Пупкин Владислав Альюертович" ,"Диего Сергеевич Брандо" ,"Афанасьева Ольга Тихоновна" ,"Николаева Вера Егоровна" ,"Баранов Степан Михайлович" ,"Логинов Максим Антонович" ,"Логинов Максим Антонович" ,"Волков Савва Захарович" ,"Платонова Антонина Кирилловна" ,"Павлов Владислав Ярославович" ,"Власов Платон Григорьевич" ,"Голубев Роберт Богданович" ,"Соколова Елизавета Никитична" ,"Никитина Полина Святославовна" ,"Моисеева Мария Дмитриевна" ,"Тимофеева Виктория Фёдоровна" ,"Тимофеева Виктория Фёдоровна" ,"Пономарева Элина Юрьевна" ,"Морозов Макар Давидович" ,"Ефимов Юрий Платонович" };
	string ulits[] = { "Ленина","Мира","Дедюкина","Стаханова","Сталина","Красной Армии","Сапожника","Акихабара","Собянина","Кривичей","Зифиркина","Набережная","Комсомольский проспект","Коровкина","Полосухина","Перекатная","Чукотская","Кисельная","Карпинского","Спартаковская","Уездный проспект","Ульяновская","Караиельная","Сахаоная","Озерная","Боброва","Каменная","Пирогова", };
	string LEGOCITY[] = { "LEGOCITY","Москва","Калыма","Рязань","Казань","Серов","Югорск","Нижняя Тура","Верхняя Тура","Нижний Тагил","Суздаль","Коноха","Сити17","Готем","Метрополис","Зверополис","Токио","Осака","Киото","Екатеринбург","Горнозаводск","Краснотуринск","Берлин","Владивосток","Чебаркуль","Златоуст","Уфа","Новосибирск", };
	for (int i = 0; i < 100; i++)
	{
		int H = (sizeof(DIO) / sizeof(DIO[0]));
		int R = rand() % H;
		arr[i].fio = DIO[R];
		arr[i].city17 = LEGOCITY[R];
		arr[i].ulitsa = ulits[R];
		arr[i].passport = 100000 + rand() % 99999;
		arr[i].home = (rand() % 250);
	}
}

void print(Data* arr, int i, int size)
{
	for (i; i < size; i++)
	{
		cout << endl;
		cout << "ФИО:" << arr[i].fio << endl;
		cout << "Паспорт:" << arr[i].passport << endl;
		cout << "Город:" << arr[i].city17 << endl;
		cout << "Улица:" << arr[i].ulitsa << endl;
		cout << "Дом:" << arr[i].home << endl;

	}
}

void obraz(int *& p, string key)
{
	int j = 0, i = 1;
	p[0] = 0;
	while (i < key.length())
	{
		if (key[i] == key[j])
		{
			p[i] = j + 1;
			j++;
		}
		else if (j == 0)
		{
			p[i] = 0;
			
		}
		else
		{
			j = p[j - 1];
		}
		i++;
	}
	cout << endl;
	for (int i = 0; i < key.size(); i++)
	{
		cout << key[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < key.size(); i++)
	{
		cout << p[i] << "\t";
	}
	cout << endl;
}

void kmp(Data * arr)
{
	cout << "Введите ключ :";
	string key;
	cin.ignore();
	getline(cin, key);
	cout << endl;
	int* p = new int[key.length()];
	obraz(p, key);
	int l = 0, k = 0,n = key.length();
	bool found = false;
	for (int i = 0; i < 100; i++)
	{
		bool f = 0;
		string str = arr[i].city17 + " " + arr[i].ulitsa + " " + to_string(arr[i].home);
		while (k < str.length() && f != 1)
		{
			if (str[k] == key[l]) 
			{
				k++; l++;
				if (l == n)
				{
					print(arr, i, i + 1);
					found = 1;
					f = 1;
				}
			}
			else if (l == 0)
			{
				k++;
			}
			else
			{
				l = p[l - 1];
			}
		}
		k = 0; l = 0;
		
	}
	if (found == 0) cout << "не найдено" << endl;
}

int SearchInTable(char sy, string str, int* indexes)
{
	for (int i = 1; i < str.length(); i++)
	{
		if (sy == str[i])
		{
			return indexes[i];
		}
	}
	return indexes[str.length()-1];
}

void boyer_moor(Data* arr, string strC, int* indexes, string key)
{
	bool Found = false;
	string str = "";
	for (int t = 0; t < 100; t++)
	{
		string str = arr[t].city17 + " " + arr[t].ulitsa + " " + to_string(arr[t].home);
		int k = key.length()-1;
		char sy;
		int shift = k;
		bool f3 = false;
		while (k < str.length() && f3 == false)
		{
			int i = k;// указатель индекса искомой строки
			sy = str[k];
			int j = key.length()-1;
			while (key[j] == str[i] && j > 0)
			{
				i--;
				j--;
				if (key[0] == str[i])
				{
					f3 = true;
				}
			}
			shift = SearchInTable(sy, strC, indexes); // сдвиг указателя искомой строки
			k = k + shift;
			if (f3 == true)
			{
				print(arr, t, t + 1);
				Found = true;
			}
		}
	}
	if (Found != 1)
	{
		cout << endl << endl << "Элементы не найдены!" << endl << endl;
	}
	delete[] indexes;
}

void InitTable(Data* arr)
{
	string key; // ключ поиска
	cout << "Введите строку по которой будет выполняться поиск: \t";
	cin.ignore();
	getline(cin, key);
	string strC = key + "*"; // строка таблицы

	int* indexes = new int[strC.length()]; // Массив индексов
	indexes[strC.length() - 1] = strC.length() - 1;
	int extraI = 1;
	bool last_found = 0;
	for (int i = strC.length() - 3; i >= 0; i--)
	{
		indexes[i] = extraI;
		extraI++;
	}
	for (int i = strC.length() - 3; i >= 0; i--)
	{
		char tmp = strC[i]; // переменная, хранящая символ в цикле
		for (int j = i - 1; j >= 0; j--)
		{
			if (tmp == strC[j])
			{
				indexes[j] = indexes[i];
			}

		}
	}
	for (int i = strC.length() - 3; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{

			if (strC[strC.length() - 2] == strC[j])

			{
				indexes[strC.length() - 2] = strC[j];
				last_found = 1;
			}
		}
	}
	if (last_found != 1) indexes[strC.length() - 2] = strC.length() - 1;
		
	cout << endl;
	for (int i = 0; i < strC.size(); i++)
	{
		cout << strC[i] << "\t";
	}
	cout << endl << endl;
	for (int i = 0; i < strC.size(); i++)
	{
		cout << indexes[i] << "\t";
	}
	cout << endl;

	int size_new = strC.length();

	
	for (int i = strC.length() - 2; i >= 0; i--)
	{
		char tmp = strC[i]; // переменная, хранящая символ в цикле
		for (int j = i - 1; j >= 0; j--)
		{
			if (tmp == strC[j])
			{
				indexes[j] = -1;
				size_new--;
			}

		}
	}
	extraI = 0;
	int* STRc = new int[size_new];
	int size = strC.length();
	for (int i = 0;i < size; i++)
	{
		if (indexes[i] != -1)
		{
			STRc[extraI] = indexes[i];
			extraI++;
		}
		else
		{
			strC.erase(i, i);
		}
	}
	delete[] indexes;
	indexes = STRc;
	cout << endl;
	for (int i = 0; i < strC.size(); i++)
	{
		cout << strC[i] << "\t";
	}
	cout << endl << endl;
	for (int i = 0; i < strC.size(); i++)
	{
		cout << indexes[i] << "\t";
	}
	cout << endl;

	boyer_moor(arr, strC, indexes, key);
	cout << endl;
}


int main()
{
	system("chcp 1251>nul");
	Data* arr = new Data[100];
	RANDOM(arr);
	print(arr,0,100);
	bool f = 1;
	int menu;
	while (f != 0)
	{
		cout << "Метод Кнута Морриса Прата 1" << endl << "Метод Бойера мура 2" << endl << "выход press any key" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:kmp(arr); break;
		case 2:InitTable(arr); break;
		default: f = 0; break;
		}	
	}
	return 0;
}

