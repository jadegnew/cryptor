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
	cout << "���� �������" << endl;
	cout << "1. ����������� �����������" << endl;
	cout << "2. ������������ �����������" << endl;
	cout << "������� �������: ";
	cin.clear();
	cin >> step;
	system("cls");
	if (step == 1) {
		cout << "1. ������ � �������" << endl;
		cout << "2. ����������� �� �����" << endl;
		cout << "������� �������: ";
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
		cout << "1. ����������� �� �����" << endl;
		dec();
	}
	else {
		cout << "�������. ������� ����������� ��������" << endl;
		cout << "������ ����-��� ������, ��� ����������� �� ����" << endl;
		_getch();
		cin.clear();
		cin.ignore();
		main_menu();
	}
}
void enc() {
	system("cls");
	if (f) {
		cout << "������ �����: " << endl;
		cin.ignore();
		getline(cin, oStr);
		srand(static_cast<unsigned int>(time(0)));
		RESIZE();
		VERENC();
		cout << "������������ �����: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << enc_msg[i];
		}
		cout << "\n����: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << key[i];
		}
		cout << "\n\n��� ��������, �������� ����-��� ������" << endl;
		_getch();
		system("cls");
		save();
	}
	else {
		string name;
		cout << "������ ������ ���� �� ����� ������ �� ���� �����: " << endl;
		cin >> name;
		system("cls");
		file(name);
		RESIZE();
		VERENC();
		cout << "������������ �����: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << enc_msg[i];
		}
		cout << "\n����: " << endl;
		for (int i = 0; i < oStr.length(); i++)
		{
			cout << key[i];
		}
		cout << "\n\n��� ��������, �������� ����-��� ������" << endl;
		_getch();
		system("cls");
		save();
		main_menu();
	}
}
void dec() {
	system("cls");
	string name;
	cout << "������ ������ ���� �� ����� ������ �� ���� �����: " << endl;
	cin >> name;
	system("cls");
	file(name);
	enc_msg.resize(oStr.length());
	for (int i = 0; i < oStr.length(); i++)
	{
		enc_msg[i] = oStr[i];
	}
	cout << "������ ������ ���� �� ����� ����� �� ���� �����: " << endl;
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
	cout << "������������ �����: " << endl;
	for (int i = 0; i < oStr.length(); i++)
	{
		cout << enc_msg[i];
	}
	cout << "\n����: " << endl;
	for (int i = 0; i < oStr.length(); i++)
	{
		cout << key[i];
	}
	cout << "\n������������� �����: " << endl;
	for (int i = 0; i < oStr.length(); i++)
	{
		cout << denc_msg[i];
	}
	cout << "\n\n��� ��������, �������� ����-��� ������" << endl;
	_getch();
	system("cls");
	save();
	main_menu();
}
void save() {
	string name;
	if (f2) {
		cout << "������ ������ ���� �� ����� ������ �� ���� �����: " << endl;
		SAVE(enc_msg);
		cout << "������ ������ ���� �� ����� ����� �� ���� �����: " << endl;
		SAVE(key);
	}
	else {
		cout << "������ ���� ���������� ����� ����������� �� ���� �����: " << endl;
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
		cout << "�������. ���� �� ����." << endl;
		cout << "������ ����-��� ������, ��� ����������� �� ����." << endl;
		_getch();
		main_menu();
	}
	file.close();
}