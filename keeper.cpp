#pragma once
#include "Header.h"
#include "Keeper.h"
#include "SetColor.h"

/// ЗАПИСЬ В ФАЙЛ
template<typename T>
inline void operator <<(const string file, T buf) {
	ofstream f;
	try
	{
		f.open(file, ios::binary | ios::app);
		if (!f.is_open()) {
			throw 505;
		}
		int swtch1;
		while (true)
		{
			buf.set();
			f.write(reinterpret_cast<char*>(&buf), sizeof(T));
			cout << "Ввести ещё один инструмент? \n1 -> ДА\n2 -> НЕТ " << endl;
			cin >> swtch1;
			if (swtch1 != 1)
				break;
		}
		f.close();
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}
}

/// ЧТЕНИЕ ИЗ ФАЙЛА
template<typename T>
inline void operator >>(const string file, T buf) {
	ifstream in;
	try
	{
		in.open(file, ios::binary | ios::in);
		if (!in.is_open()) {
			throw 505;
		}
		while (in.read(reinterpret_cast<char*>(&buf), sizeof(T)))
			buf.put();
		in.close();
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}
}

/// УДАЛЕНИЕ ЭЛЕМЕНТА
template<typename T>
inline void operator <<=(const string file, T buf) {
	ofstream f;			///открытие файла для записи
	ifstream in;		///открытие файла для чтения
	int swtch1;
	T* temp;
	char name[20];
	char FIO[30];
	bool FLAG = false;

	try
	{
		in.open(file, ios::binary | ios::in);
		if (!in.is_open()) {
			throw 505;
		}
		swtch1 = 0;
		while (in.read(reinterpret_cast<char*>(&buf), sizeof(T)))
			swtch1++;

		in.clear();
		in.seekg(0);

		temp = new T[swtch1];
		swtch1 = 0;
		while (in.read(reinterpret_cast<char*>(&buf), sizeof(T))) {
			temp[swtch1] = buf; //заполнение массива
			temp[swtch1].put();
			swtch1++;
		}
		in.close();
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}

	cout << "Введите название инструмента -> ";
	cin >> name;
	cout << "Введите имя владельца -> ";
	cin >> FIO;

	try
	{
		f.open(file, ios::binary | ios::out);
		if (!f.is_open())
		{
			throw 505;
		}
		for (int i = 0; i < swtch1; i++)
		{
			if (strcmp(temp[i].ret_name(), name) == 0 && strcmp(temp[i].ret_owner(), FIO) == 0)
			{
				FLAG = true;
			}
			else
			{
				f.write(reinterpret_cast<char*>(&temp[i]), sizeof(T));
				temp[i].put();
			}
		}
		if (FLAG)
		{
			SetColor(10, 1);
			cout << "Данные об инструменте удалены! =D" << endl;
			FLAG = false;
			SetColor(14, 1);
		}
		else
		{
			SetColor(12, 1);
			cout << "По данному запросу результатов не найдено... :(" << endl;
			SetColor(14, 1);
		}
		delete[] temp;
		f.close();
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}
}
/// РЕДАКТИРОВАНИЕ БАЗЫ
template<typename T>
inline void operator >>=(const string file, T buf) {
	ofstream f;			///открытие файла для записи
	ifstream in;		///открытие файла для чтения
	int swtch1;
	T* temp;
	char name[20];
	char FIO[30];
	bool FLAG = false;

	try
	{
		in.open(file, ios::binary | ios::out);
		if (!in.is_open())
		{
			throw 505;
		}
		swtch1 = 0;
		while (in.read(reinterpret_cast<char*>(&buf), sizeof(T)))
			swtch1++;

		in.clear();
		in.seekg(0);

		temp = new T[swtch1];
		swtch1 = 0;
		while (in.read(reinterpret_cast<char*>(&buf), sizeof(T))) {
			temp[swtch1] = buf;
			temp[swtch1].put();
			swtch1++;
		}
		in.close();
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}

	cout << "Данные о каком инструменте вы хотели бы изменить?" << endl;
	cout << "Введите название инструмента -> ";
	cin >> name;
	cout << "Введите имя владельца -> ";
	cin >> FIO;

	try
	{
		f.open(file, ios::binary | ios::out);
		if (!f.is_open())
		{
			throw 505;
		}
		for (int i = 0; i < swtch1; i++)
		{
			if (strcmp(temp[i].ret_name(), name) == 0 && strcmp(temp[i].ret_owner(), FIO) == 0)
			{
				cout << "Введите новые данные об инстрменте: " << endl;
				temp[i].set();
				f.write(reinterpret_cast<char*>(&temp[i]), sizeof(T));
				FLAG = true;
			}
			else
			{
				f.write(reinterpret_cast<char*>(&temp[i]), sizeof(T));
			}
		}
		if (FLAG)
		{
			SetColor(10, 1);
			cout << "Редактирование прошло успешно! :)" << endl;
			FLAG = false;
			SetColor(14, 1);
		}
		else
		{
			SetColor(12, 1);
			cout << "Некорректно введены данные... 0_o" << endl;
			SetColor(14, 1);
		}
		delete[] temp;
		f.close();

	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}
}
