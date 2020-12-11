// zadacha so strokoi
#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(NULL, "RU");
	string stroka;
	cin >> stroka;

	string storage = ""; // хранилище открывающих скобок 
	string opens = "[{("; // открывающие скобки
	string closes = "]})";
	int counter1 = 0; // счетчики скобок 
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	int counter5 = 0;
	int counter6 = 0;
	bool match = true; // сбалансированная ли строка
	for (int i = 0; i < stroka.length(); i++) { // цикл по всем элементам в строке
		switch (stroka[i]) { // счетчики
		case '{': {
			counter1++;
			break;
		}
		case '[': {
			counter2++;
			break;
		}
		case '(': {
			counter3++;
			break;
		}
		case '}': {
			counter4++;
			break;
		}
		case ']': {
			counter5++;
			break;
		}
		case ')': {
			counter6++;
			break;
		}
				cout << opens.find(stroka[i]) << endl;
				if (opens.find(stroka[i]) != closes.find(stroka[i])) { // проверка открывающая скобка или нет 
					storage += stroka[i]; // если открывающая то обавляем ее в хранилище
				}
				else {
					if (storage.length() == 0 || storage[storage.length() - 1] != stroka[i]) {
						match = false; // {()}
					}
					if (storage.length() > 0)
						storage = storage.substr(0, storage.length() - 1);
				}
		}
		cout << "кол-во открывающих фигурных" << min(counter1, counter4) << endl;

		if (match == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}
}






			