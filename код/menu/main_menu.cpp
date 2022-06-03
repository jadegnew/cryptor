#include "Header.h"
#include "vername.h"
#include "vigenere.h"
#include "grosnf.h"
bool flag_0 = false;
bool flag_1 = false;
bool flag_2 = false;
bool flag_3 = false;
bool info = false;
bool exit_ = false;

void help();

void main_menu() {
	system("cls");

	int key = 0;
	int step = 0;

	cout << "���� ������� <-" << endl;
	cout << "���� ³������" << endl;
	cout << "���� �����������" << endl;
	cout << "����������" << endl;
	cout << "�����" << endl;

	do {
		key = _getch();
		if (key == KEY_DOWN) {
			if (step < 4 )step++;
			else if (step >= 4)step = 0;
			
		}
		else if (key == KEY_UP) {
			if (step > 0) step--;
			else if (step <= 0) step = 4;
		}
		switch (step) {
		case 0:
			system("cls");
			flag_0 = true;
			flag_1 = false;
			flag_2 = false;
			info = false;
			exit_ = false;
			cout << "���� ������� <-" << endl;
			cout << "���� ³������" << endl;
			cout << "���� �����������" << endl;
			cout << "����������" << endl;
			cout << "�����" << endl;
			break;
		case 1:
			system("cls");
			flag_0 = false;
			flag_1 = true;
			flag_2 = false;
			info = false;
			exit_ = false;
			cout << "���� ������� " << endl;
			cout << "���� ³������ <-" << endl;
			cout << "���� �����������" << endl;
			cout << "����������" << endl;
			cout << "�����" << endl;
			break;
		case 2:
			system("cls");
			flag_0 = false;
			flag_1 = false;
			flag_2= true;
			exit_ = false;
			info = false;
			cout << "���� �������" << endl;
			cout << "���� ³������" << endl;
			cout << "���� ����������� <-" << endl;
			cout << "����������" << endl;
			cout << "�����" << endl;
			break;
		case 3:
			system("cls");
			flag_0 = false;
			flag_1 = false;
			flag_2 = false;
			exit_ = false;
			info = true;
			cout << "���� �������" << endl;
			cout << "���� ³������ " << endl;
			cout << "���� �����������" << endl;
			cout << "���������� <-" << endl;
			cout << "�����" << endl;
			break;
		case 4:
			system("cls");
			flag_0 = false;
			flag_1 = false;
			flag_2 = false;
			info = false;
			exit_ = true;
			cout << "���� �������" << endl;
			cout << "���� ³������ " << endl;
			cout << "���� �����������" << endl;
			cout << "����������" << endl;
			cout << "����� <-" << endl;
			break;
		}
	} while (key != 13);

	if (exit_) {
		exit(0);
	}
	if (info) {
		help();
	}
	if (flag_0) {
		system("cls");
		ver_main();
	}
	if (flag_1) {
		system("cls");
		vigenere_main();
	}
	if (flag_2) {
		system("cls");
		gros_main();
	}
}


void help() {
	int key = 0;
	system("cls");
	cout << "���������� ���������� �� ������������ ������." << endl;
	cout << endl;
	cout << endl;
	cout << "���� �������: " << endl;
	cout << "��� ���������� ������� ������� ������ ����� ��� ����� ����� � ������� �� �������� ENTER. ��� ���������� ������������" << endl;
	cout << "�������� ���������� �� ����. ��� ������������ ������ ����� ����� � �������, � ���� ����� ����� � ������." << endl;
	cout << endl;
	cout << endl;
	cout << "���� ³������:" << endl;
	cout << "��� ���������� ������� ³������ ������ ����� Ҳ���� �������� ������� ��� ���������� ����," << endl;
	cout << "���� ������ ���� : ����� �������� �������." << endl;
	cout << "��� ������������ ������� ³������ ������ ���������� Ҳ���� �������� �������, ���� ������ ���� ������ ����." << endl;
	cout << endl;
	cout << endl;
	cout << "���� �����������:" << endl;
	cout << "��� ���������� ������� ����������� ������ ����� Ҳ���� �������� ������� �� ���������� ����, ���� ������ ���� � ����." << endl;
	cout << "��� ������������ ������� ����������� ������ ���������� Ҳ���� ��̲����� �������, ���� ������ ��������� ����." << endl;
	cout << endl;
	cout << endl;
	cout << "�������������� ������ ��� �������� �� ���������. ��� ����������� �� ����, �������� ������ ESC." << endl;
	cout << endl;
	cout << endl;
	cout << "����: 1" << endl;
	while (key != 27) {
		key = _getch();
		switch (key) {
		case KEY_RIGHT:
			system("cls");
			cout << "���������� ���������� �� ������������ ������." << endl;
			cout << endl;
			cout << endl;
			cout << "���� �������: " << endl;
			cout << "��� ���������� ������� ������� ������ ����� ��� ����� ����� � ������� �� �������� ENTER. ��� ���������� ������������" << endl;
			cout << "�������� ���������� �� ����. ��� ������������ ������ ����� ����� � �������, � ���� ����� ����� � ������." << endl;
			cout << endl;
			cout << endl;
			cout << "���� ³������:" << endl;
			cout << "��� ���������� ������� ³������ ������ ����� Ҳ���� �������� ������� ��� ���������� ����," << endl;
			cout << "���� ������ ���� : ����� �������� �������." << endl;
			cout << "��� ������������ ������� ³������ ������ ���������� Ҳ���� �������� �������, ���� ������ ���� ������ ����." << endl;
			cout << endl;
			cout << endl;
			cout << "���� �����������:" << endl;
			cout << "��� ���������� ������� ����������� ������ ����� Ҳ���� �������� ������� �� ���������� ����, ���� ������ ���� � ����." << endl;
			cout << "��� ������������ ������� ����������� ������ ���������� Ҳ���� ��̲����� �������, ���� ������ ��������� ����." << endl;
			cout << endl;
			cout << endl;
			cout << "�������������� ������ ��� �������� �� ���������. ��� ����������� �� ����, �������� ������ ESC." << endl;
			cout << endl;
			cout << endl;
			cout << "����: 1" << endl;
			break;
		case KEY_LEFT:
			system("cls");
			cout << "���������� � �������� ��� ���������� �����." << endl;
			cout << endl;
			cout << endl;
			cout << "��� �������� ��� ������� ���� �� �������/������, ������ ���� � ����� � ������:" << endl;
			cout << "D:\\\\�����\\\\��'�_�����.txt - � ��� ������������ ����� � ����-��� �������� �� �������." << endl;
			cout << "��'�_�����.txt - � ��� ������������ ����� � ��������, � ��� ���������� ����������� ���� ��������." << endl;
			cout << "�������: ����� � �������/������ ����'������ ������ ���� �������� � �������� ANSI." << endl;
			cout << endl;
			cout << endl;
			cout << "������������� �� ��������� ����������� ����� �������� ������ �� 1 ������," << endl;
			cout << "��� �������� �������� ��������������." << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "�������������� ������ ��� �������� �� ���������. ��� ����������� �� ����, �������� ������ ESC." << endl;
			cout << endl;
			cout << endl;
			cout << "����: 2" << endl;
			break;
		}
	}
	main_menu();
}