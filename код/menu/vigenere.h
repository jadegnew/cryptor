#pragma once
#define RES_VIG(){\
				tlenth = ostr.length();\
				opentxt.resize(ostr.length());\
				encr_vig.resize(ostr.length());\
				key_vig.resize(ostr.length());\
}
#define DEC_RES_VIG(){\
				tlenth = ostr.length();\
				encr_vig.resize(ostr.length());\
				key_vig.resize(ostr.length());\
				decr_vig.resize(ostr.length());\
}
#define SET_KEY_VIG() {\
					cout << "Введіть ключ: " << endl;\
					getline(cin, ostr);\
					klenth = ostr.length();\
					for (int i = 0; i < tlenth;)\
					{\
						for (int j = 0; j < klenth; j++) {\
							if (i < tlenth) {\
								if (ostr[j] != '\0') {\
									key_vig[i] = ostr[j] - 143;\
									i++;\
								}\
							}\
						}\
					}\
}

#define SAVE_VIG(j){\
						cin >> s1; \
						ofstream file;\
						file.open(s1);\
						if (file.is_open()) {\
							for (int i = 0; i < tlenth; i++)\
							{\
								file << j[i];\
							}\
						}\
						file.close();\
}

#include "Header.h"
using namespace std;

string ostr;
int tlenth;
int klenth;
vector <char> opentxt;
vector <char> encr_vig;
vector <char> key_vig;
vector <char> decr_vig;
bool fl_enc_vig = false;
bool fl_dec_vig = false;
bool save_vig = false;


void encr_vigenere();
void from_f(string s1);
void decr_vigenere();
void save_vigenere();

void vigenere_main() {
	int step = 0;
	cout << "Шифр Віженера" << endl;
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
			fl_enc_vig = true;
			encr_vigenere();
			main_menu();
			break;
		case 2:
			fl_enc_vig = false;
			encr_vigenere();
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
			fl_dec_vig = true;
			decr_vigenere();
			main_menu();
			break;
		case 2:
			fl_dec_vig = false;
			decr_vigenere();
			main_menu();
			break;
		}
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

void encr_vigenere() {
	save_vig = true;
	if (fl_enc_vig) {
		cout << "Введіть текст для шифрування: " << endl;
		cin.ignore();
		getline(cin, ostr);
		RES_VIG();
		for (int i = 0; i < ostr.length(); i++)
		{
			opentxt[i] = ostr[i];
		}
		SET_KEY_VIG();
	}
	else {
		string s1;
		cout << "Введіть повний шлях до файлу тексту та його назви: " << endl;
		cin >> s1;
		system("cls");
		from_f(s1);
		RES_VIG();
		for (int i = 0; i < ostr.length(); i++)
		{
			opentxt[i] = ostr[i];
		}
		cin.ignore();
		SET_KEY_VIG();
	}
	for (int i = 0; i < tlenth; i++) {
		int tmp = ((opentxt[i] + (key_vig[i] - 48)));
		if (tmp > 255) {
			tmp -= 224;
		}
		encr_vig[i] = (char)tmp;
	}
	cout << "Зашифроване повідомлення: " << endl;
	for (int i = 0; i < tlenth; i++) {
		cout << encr_vig[i];
	}
	cout << endl;
	save_vigenere();
}

void decr_vigenere() {
	save_vig = false;
	if (fl_dec_vig) {
		cout << "Введіть текст для дешифрування: " << endl;
		cin.ignore();
		getline(cin, ostr);
		DEC_RES_VIG();
		for (int i = 0; i < ostr.length(); i++)
		{
			encr_vig[i] = ostr[i];
		}
		SET_KEY_VIG();
		for (int i = 0; i < tlenth; i++) {
			if (encr_vig[i] > 32) {
				key_vig[i] = key_vig[i] + 224;
			}
			decr_vig[i] = ((encr_vig[i] - (key_vig[i] - 48)));
		}

	}
	else {
		string s1;
		cout << "Введіть повний шлях до файлу тексту та його назву: " << endl;
		cin >> s1;
		system("cls");
		from_f(s1);
		DEC_RES_VIG();
		for (int i = 0; i < ostr.length(); i++)
		{
			encr_vig[i] = ostr[i];
		}
		cin.ignore();
		SET_KEY_VIG();
		for (int i = 0; i < tlenth; i++) {
			if (encr_vig[i] > 32) {
				key[i] = key[i] + 224;
			}
			decr_vig[i] = ((encr_vig[i] - (key_vig[i] - 48)));
		}
	}
	cout << "Розшифроване повідомлення: " << endl;
	for (int i = 0; i < tlenth; i++) {
		cout << decr_vig[i];
	}
	cout << endl;
	save_vigenere();
}
void from_f(string s1) {
	ifstream file;
	file.open(s1);
	if (file.is_open()) {
		while (!file.eof()) {
			getline(file, ostr, '\0');
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

void save_vigenere() {
	string s1;
	if (save_vig) {
		cout << "Введіть назву файлу для збереження шифру" << endl;
		SAVE_VIG(encr_vig);
	}
	else {
		cout << "Введіть назву файлу для збереження розшифровки" << endl;
		SAVE_VIG(decr_vig);
	}

}