#pragma once
#include "Header.h"
#include "keeper.h"
#include "orchestra.h"
#include "SetColor.h"

inline orchestra::orchestra() {
	name[0] = '\0';
	cost[0] = '\0';
	num_of_orch[0] = '\0';
	owner[0] = '\0';
	SetColor(0, 1);
	cout << "Orchestra->";
	SetColor(14, 1);
}

inline orchestra::orchestra(char *_name, char *_cost, char *_num_of_orch, char *_owner) {
	strcpy_s(name, _name);
	strcpy_s(cost, _cost);
	strcpy_s(num_of_orch, _num_of_orch);
	strcpy_s(owner, _owner);
}

inline void orchestra::set() {
	setlocale(LC_ALL, "Russian");
	cout << " Введите название инструмента:\t";
	cin >> this->name;
	while (true)
	{
		try
		{
			cout << " Введите стоимость :\t";
			cin >> this->cost;
			for (int i = 0; i < strlen(this->cost); i++)
				if (!isdigit(this->cost[i]))
					throw 7641;
			break;
		}
		catch (const int &ex)
		{
			SetColor(12, 1);
			cout << "Ошибка при вводе данных!" << endl << "Код ошибки: #" << ex << endl << "Введите данные ещё раз:\t" << endl;
			SetColor(14, 1);
		}
	}
	while (true)
	{
		try
		{
			cout << " Введите количество инструментов в оркестре:\t";
			cin >> this->num_of_orch;
			for (int i = 0; i < strlen(this->num_of_orch); i++)
				if (!isdigit(this->num_of_orch[i]))
					throw 7641;
			break;
		}
		catch (const int &ex)
		{
			SetColor(12, 1);
			cout << "Ошибка при вводе данных!" << endl << "Код ошибки: #" << ex << endl << "Введите данные ещё раз:\t" << endl;
			SetColor(14, 1);
		}
	}
	cout << " Введите имя владельца:\t";
	cin >> this->owner;
}

inline void orchestra::put() {
	setlocale(LC_ALL, "Russian");
	cout << "\n Название инструмента:\t" << this->name;
	cout << "\n Стоимость:\t\t" << this->cost;
	cout << "\n Количество в оркестре:\t" << this->num_of_orch;
	cout << "\n Имя владельца:\t\t" << this->owner;
}

inline char* orchestra::ret_name() {
	return this->name;
}
inline char* orchestra::ret_owner() {
	return this->owner;
}
inline orchestra::~orchestra() { SetColor(0, 1); cout << "<-dstrctr_orchestra"; SetColor(14, 1); }
