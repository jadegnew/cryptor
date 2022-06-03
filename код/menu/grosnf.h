#pragma once
#define RES(){\
				textlenth = str.length();\
				text.resize(str.length());\
				encr.resize(str.length());\
				key_gronsf.resize(str.length());\
}
#define DEC_RES(){\
				textlenth = str.length();\
				encr.resize(str.length());\
				key_gronsf.resize(str.length());\
				decr.resize(str.length());\
}
#define SET_KEY() {\
					cout << "Введіть ключ: " << endl;\
					getline(cin, str);\
					keylenth = str.length();\
					for (int i = 0; i < textlenth;)\
					{\
						for (int j = 0; j < keylenth; j++) {\
							if (i < textlenth) {\
								if (str[j] != '\0') {\
									key_gronsf[i] = str[j];\
									i++;\
								}\
							}\
						}\
					}\
}

#define SAVE_GRONSF(j){\
						cin >> s1; \
						ofstream file;\
						file.open(s1);\
						if (file.is_open()) {\
							for (int i = 0; i < textlenth; i++)\
							{\
								file << j[i];\
							}\
						}\
						file.close();\
}

#include "Header.h"
using namespace std;

string str;
int textlenth;
int keylenth;
vector <char> text;
vector <char> encr;
vector <char> key_gronsf;
vector <char> decr;
bool fl_enc = false;
bool fl_dec = false;
bool save_grons = false;


void encr_gronsf();
void from_file(string s1);
void decr_gronsf();
void save_gronsf();

void gros_main() {
	int step = 0;
	cout << "Шифр Гронсфельда" << endl;
	cout << "1. Зашифрувати повідомлення" << endl;
	cout << "2. Розшифрувати повідомлення" << endl;
	cout << "Виберіть функцію: ";
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
			fl_enc = true;
			encr_gronsf();
			main_menu();
			break;
		case 2:
			fl_enc = false;
			encr_gronsf();
			main_menu();
			break;
		}

	}
	else if (step == 2) {
		cout << "1. Ввести в консоль" << endl;
		cout << "2. Завантажити із файлу" << endl;
		cout << "Виберіть функцію: ";
		cin >> step;
		system("cls");
		switch (step) {
		case 1:
			fl_dec = true;
			decr_gronsf();
			main_menu();
			break;
		case 2:
			fl_dec = false;
			decr_gronsf();
			main_menu();
			break;
		}
	}
	else {
		cout << "Помилка. Введено неправильне значення" << endl;
		cout << "Введіть будь-яку клавішу, щоб повернутися до меню" << endl;
		_getch();
		cin.clear();
		/*cin.ignore();
		cin.ignore();*/
		cin.ignore();
		main_menu();
	}
}

void encr_gronsf() {
	save_grons = true;
	if (fl_enc) {
		cout << "Введіть текст для шифрування: " << endl;
		cin.ignore();
		getline(cin, str);
		RES();
		for (int i = 0; i < str.length(); i++)
		{
			text[i] = str[i];
		}
		SET_KEY();
	}
	else {
		string s1;
		cout << "Введіть повний шлях до файлу тексту та його назву: " << endl;
		cin >> s1;
		system("cls");
		from_file(s1);
		RES();
		for (int i = 0; i < str.length(); i++)
		{
			text[i] = str[i];
		}
		cin.ignore();
		SET_KEY();
	}
	for (int i = 0; i < textlenth; i++) {
		int tmp = ((text[i] + (key_gronsf[i] - 48)));
		if (tmp > 255) {
			tmp -= 224;
		}
		encr[i] = (char)tmp;
	}
	cout << "Зашифроване повідомлення: " << endl;
	for (int i = 0; i < textlenth; i++) {
		cout << encr[i];
	}
	cout << endl;
	save_gronsf();
}

void decr_gronsf() {
	save_grons = false;
	if (fl_dec) {
		cout << "Введіть текст для дешифрування: " << endl;
		cin.ignore();
		getline(cin, str);
		DEC_RES();
		for (int i = 0; i < str.length(); i++)
		{
			encr[i] = str[i];
		}
		SET_KEY();
		for (int i = 0; i < textlenth; i++) {
			if (encr[i] > 32) {
				key_gronsf[i] = key_gronsf[i] + 224;
			}
			decr[i] = ((encr[i] - (key_gronsf[i] - 48)));
		}
		
	}
	else {
		string s1;
		cout << "Введіть повний шлях до файлу тексту та його назву: " << endl;
		cin >> s1;
		system("cls");
		from_file(s1);
		DEC_RES();
		for (int i = 0; i < str.length(); i++)
		{
			encr[i] = str[i];
		}
		cin.ignore();
		SET_KEY();
		for (int i = 0; i < textlenth; i++) {
			if (encr[i] > 32) {
				key_gronsf[i] = key_gronsf[i] + 224;
			}
			decr[i] = ((encr[i] - (key_gronsf[i] - 48)));
		}
	}
	cout << "Розшифроване повідомлення: " << endl;
	for (int i = 0; i < textlenth; i++) {
		cout << decr[i];
	}
	cout << endl;
	save_gronsf();
}
void from_file(string s1){
	ifstream file;
	file.open(s1);
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, str, '\0');
		}
	}
	else {
		cout << "Ошибка. Файл не существует." << endl;
		cout << "Введіть будь-яку клавішу, щоб повернутися до меню." << endl;
		_getch();
		main_menu();
	}
	file.close();
}

void save_gronsf() {
	string s1;
	if (save_grons) {
		cout << "Введіть назву файлу для збереження шифру" << endl;
		SAVE_GRONSF(encr);
	}
	else {
		cout << "Введіть назву файлу для збереження розшифровки" << endl;
		SAVE_GRONSF(decr);
	}
	
}