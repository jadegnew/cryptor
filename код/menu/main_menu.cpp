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

	cout << "Шифр Вернама <-" << endl;
	cout << "Шифр Віженера" << endl;
	cout << "Шифр Гронсфельда" << endl;
	cout << "Інформація" << endl;
	cout << "Вихід" << endl;

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
			cout << "Шифр Вернама <-" << endl;
			cout << "Шифр Віженера" << endl;
			cout << "Шифр Гронсфельда" << endl;
			cout << "Інформація" << endl;
			cout << "Вихід" << endl;
			break;
		case 1:
			system("cls");
			flag_0 = false;
			flag_1 = true;
			flag_2 = false;
			info = false;
			exit_ = false;
			cout << "Шифр Вернама " << endl;
			cout << "Шифр Віженера <-" << endl;
			cout << "Шифр Гронсфельда" << endl;
			cout << "Інформація" << endl;
			cout << "Вихід" << endl;
			break;
		case 2:
			system("cls");
			flag_0 = false;
			flag_1 = false;
			flag_2= true;
			exit_ = false;
			info = false;
			cout << "Шифр Вернама" << endl;
			cout << "Шифр Віженера" << endl;
			cout << "Шифр Гронсфельда <-" << endl;
			cout << "Інформація" << endl;
			cout << "Вихід" << endl;
			break;
		case 3:
			system("cls");
			flag_0 = false;
			flag_1 = false;
			flag_2 = false;
			exit_ = false;
			info = true;
			cout << "Шифр Вернама" << endl;
			cout << "Шифр Віженера " << endl;
			cout << "Шифр Гронсфельда" << endl;
			cout << "Інформація <-" << endl;
			cout << "Вихід" << endl;
			break;
		case 4:
			system("cls");
			flag_0 = false;
			flag_1 = false;
			flag_2 = false;
			info = false;
			exit_ = true;
			cout << "Шифр Вернама" << endl;
			cout << "Шифр Віженера " << endl;
			cout << "Шифр Гронсфельда" << endl;
			cout << "Інформація" << endl;
			cout << "Вихід <-" << endl;
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
	cout << "Інструкція шифрування та дешифрування тексту." << endl;
	cout << endl;
	cout << endl;
	cout << "Шифр Вернама: " << endl;
	cout << "Для шифрування методом Вернама введіть текст або назву файлу з текстом та натисніть ENTER. Для подальшого використання" << endl;
	cout << "Збережіть шифротекст та ключ. Для дешифрування введіть назву файлу з текстом, а потім назву файла з ключем." << endl;
	cout << endl;
	cout << endl;
	cout << "Шифр Віженера:" << endl;
	cout << "Для шифрування методом Віженера введіть текст ТІЛЬКИ ВЕЛИКИМИ літерами або завантажте його," << endl;
	cout << "потім введіть ключ : слово ВЕЛИКИМИ літерами." << endl;
	cout << "Для дешифрування методом Віженера введіть шифротекст ТІЛЬКИ ВЕЛИКИМИ літерами, потім введіть потім введіть ключ." << endl;
	cout << endl;
	cout << endl;
	cout << "Шифр Гронсфельда:" << endl;
	cout << "Для шифрування методом Гронсфельда введіть текст ТІЛЬКИ ВЕЛИКИМИ літерами чи завантажте його, потім введіть ключ з цифр." << endl;
	cout << "Для дешифрування методом Гронсфельда введіть шифротекст ТІЛЬКИ ВИМІСНИМИ літерами, потім введіть чисельний ключ." << endl;
	cout << endl;
	cout << endl;
	cout << "Використовуйте стрілки для переходу між сторінками. Щоб повернутися до меню, натисніть клавішу ESC." << endl;
	cout << endl;
	cout << endl;
	cout << "Стор: 1" << endl;
	while (key != 27) {
		key = _getch();
		switch (key) {
		case KEY_RIGHT:
			system("cls");
			cout << "Інструкція шифрування та дешифрування тексту." << endl;
			cout << endl;
			cout << endl;
			cout << "Шифр Вернама: " << endl;
			cout << "Для шифрування методом Вернама введіть текст або назву файлу з текстом та натисніть ENTER. Для подальшого використання" << endl;
			cout << "Збережіть шифротекст та ключ. Для дешифрування введіть назву файлу з текстом, а потім назву файла з ключем." << endl;
			cout << endl;
			cout << endl;
			cout << "Шифр Віженера:" << endl;
			cout << "Для шифрування методом Віженера введіть текст ТІЛЬКИ ВЕЛИКИМИ літерами або завантажте його," << endl;
			cout << "потім введіть ключ : слово ВЕЛИКИМИ літерами." << endl;
			cout << "Для дешифрування методом Віженера введіть шифротекст ТІЛЬКИ ВЕЛИКИМИ літерами, потім введіть потім введіть ключ." << endl;
			cout << endl;
			cout << endl;
			cout << "Шифр Гронсфельда:" << endl;
			cout << "Для шифрування методом Гронсфельда введіть текст ТІЛЬКИ ВЕЛИКИМИ літерами чи завантажте його, потім введіть ключ з цифр." << endl;
			cout << "Для дешифрування методом Гронсфельда введіть шифротекст ТІЛЬКИ ВИМІСНИМИ літерами, потім введіть чисельний ключ." << endl;
			cout << endl;
			cout << endl;
			cout << "Використовуйте стрілки для переходу між сторінками. Щоб повернутися до меню, натисніть клавішу ESC." << endl;
			cout << endl;
			cout << endl;
			cout << "Стор: 1" << endl;
			break;
		case KEY_LEFT:
			system("cls");
			cout << "Інструкція з відкриття або збереження файлів." << endl;
			cout << endl;
			cout << endl;
			cout << "Щоб зберегти або відкрити файл із текстом/ключом, введіть шлях і назву у форматі:" << endl;
			cout << "D:\\\\папка\\\\ім'я_файлу.txt - у разі розташування файлу в будь-якій директорії на пристрої." << endl;
			cout << "ім'я_файлу.txt - у разі розташування файлу в директорії, у якій зберігається виконуваний файл програми." << endl;
			cout << "ВАЖЛИВО: файли з текстом/ключом ОБОВ'ЯЗКОВО повинні бути збережені в кодуванні ANSI." << endl;
			cout << endl;
			cout << endl;
			cout << "Рекомендується не шифрувати повідомлення надто великого обсягу за 1 прохід," << endl;
			cout << "щоб уникнути можливих некоректностей." << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Використовуйте стрілки для переходу між сторінками. Щоб повернутися до меню, натисніть клавішу ESC." << endl;
			cout << endl;
			cout << endl;
			cout << "Стор: 2" << endl;
			break;
		}
	}
	main_menu();
}