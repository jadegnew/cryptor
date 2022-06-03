#pragma once
#include "Header.h"
#define RESIZE(){\
				    opentext.resize(oStr.length());\
				    enc_msg.resize(oStr.length()); \
				    key.resize(oStr.length()); \
}

#define VERENC(){\
					for (int i = 0; i < oStr.length(); i++)\
					{\
						opentext[i] = oStr[i];\
						key[i] = (char)rand() % (255 - 174) + 174;\
						\
						enc_msg[i] = opentext[i] ^ key[i];\
						enc_msg[i] << 10; \
					}\
}

#define SAVE(j){\
					cin >> name;\
					ofstream file;\
					file.open(name);\
					if (file.is_open()) {\
						for (int i = 0; i < oStr.length(); i++)\
						{\
							file << j[i];\
						}\
					}\
					file.close();\
}

using namespace std;
bool f = false;
bool f2 = false;
string oStr;
vector <char> opentext;
vector <char> enc_msg;
vector <char> denc_msg;
vector <char> key;

void dec();
void enc();
void file(string name);
void save();
void ver_main() {
	int step = 0;
	cout << "Шифр Вернама" << endl;
	cout << "1. Зашифрувати повідомлення" << endl;
	cout << "2. Розшифрувати повідомлення" << endl;
	cout << "Виберіть функцію: ";
	cin.clear();
	cin >> step;
	system("cls");
	if (step == 1) {
		cout << "1. Ввести в консоль" << endl;
		cout << "2. Завантажити із файлу" << endl;
		cout << "Виберіть функцію: ";
		cin >> step;
		system("cls");
		switch (step) {
		case 1:
			f = true;
			f2 = true;
			enc();
			main_menu();
			break;
		case 2:
			f = false;
			f2 = true;
			enc();
			main_menu();
			break;
		}
	}
	else if (step == 2) {
		f2 = false;
		cout << "1. Завантажити із файлу" << endl;
		dec();
	}
	else {
		cout << "Помилка. Введено неправильне значення" << endl;
		cout << "Введіть будь-яку клавішу, щоб повернутися до меню" << endl;
		_getch();
		cin.clear();
		cin.ignore();
		main_menu();
	}
}
void enc() {
	system("cls");
	if (f) {
		cout << "Введіть текст: " << endl;
		cin.ignore();
		getline(cin, oStr);
		srand(static_cast<unsigned int>(time(0)));
		RESIZE();
		VERENC();
		cout << "Зашифрований текст: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << enc_msg[i];
		}
		cout << "\nКлюч: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << key[i];
		}
		cout << "\n\nЩоб зберегти, натисніть будь-яку клавішу" << endl;
		_getch();
		system("cls");
		save();
	}
	else {
		string name;
		cout << "Введіть повний шлях до файлу тексту та його назву: " << endl;
		cin >> name;
		system("cls");
		file(name);
		RESIZE();
		VERENC();
		cout << "Зашифрований текст: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << enc_msg[i];
		}
		cout << "\nКлюч: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << key[i];
		}
		cout << "\n\nЩоб зберегти, натисніть будь-яку клавішу" << endl;
		_getch();
		system("cls");
		save();
		main_menu();
	}
}
void dec() {
	system("cls");
	string name;
	cout << "Введіть повний шлях до файлу тексту та його назву: " << endl;
	cin >> name;
	system("cls");
	file(name);
	enc_msg.resize(oStr.length());
	for (int i = 0; i < oStr.length(); i++)
	{
		enc_msg[i] = oStr[i];
	}
	cout << "Введіть повний шлях до файлу ключа та його назву: " << endl;
	cin >> name;
	system("cls");
	file(name);
	key.resize(oStr.length());
	for (int i = 0; i < oStr.length(); i++)
	{
		key[i] = oStr[i];
	}
	
	denc_msg.resize(oStr.length());
	for (int i = 0; i < oStr.length(); i++)
	{
		denc_msg[i] = enc_msg[i] ^ key[i];
	}
	cout << "Зашифрований текст: " << endl;
	for (int i = 0; i < oStr.length(); i++)
	{
		cout << enc_msg[i];
	}
	cout << "\nКлюч: " << endl;
	for (int i = 0; i < oStr.length(); i++)
	{
		cout << key[i];
	}
	cout << "\nРозшифрований текст: " << endl;
	for (int i = 0; i < oStr.length(); i++)
	{
		cout << denc_msg[i];
	}
	cout << "\n\nЩоб зберегти, натисніть будь-яку клавішу" << endl;
	_getch();
	system("cls");
	save();
	main_menu();
}
void save() {
	string name;
	if (f2) {
		cout << "Введіть повний шлях до файлу тексту та його назву: " << endl;
		SAVE(enc_msg);
		cout << "Введіть повний шлях до файлу ключа та його назву: " << endl;
		SAVE(key);
	}
	else {
		cout << "Введіть шлях збереження файлу розшифровки та його назву: " << endl;
		SAVE(denc_msg);
	}
}
void file(string name) {
	ifstream file;
	file.open(name);
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, oStr);
		}
	}
	else {
		cout << "Помилка. Файл не існує." << endl;
		cout << "Введіть будь-яку клавішу, щоб повернутися до меню." << endl;
		_getch();
		main_menu();
	}
	file.close();
}