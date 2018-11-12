#include "Header.h"
#include "keeper.h"
#include "orchestra.h"
#include "percussion.h"
#include "stringed.h"
#include "wind.h"
#include "SetColor.h"

#include "keeper.cpp"
#include "orchestra.cpp"
#include "percussion.cpp"
#include "stringed.cpp"
#include "wind.cpp"

int main()
{
	setlocale(LC_ALL, "Rus");

	/////////////////////////
	/*ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ*/
	/////////////////////////

	ofstream f;			///открытие файла для записи
	ifstream in;		///открытие файла для чтения

	percussion per_buf;
	stringed stringed_buf;
	wind wind_buf;

	string file;

	int swtch1 = 1;

	while (swtch1 != 0) {
		cout << endl << endl << "Выберите действие:" << endl <<
			"|1| <-> Вывести все данные оркестра на экран" << endl <<
			"|2| <-> Просмотр и редактирование данных инструментов конкретного типа" << endl <<
			"|0| <-> Выход" << endl;
		cin >> swtch1;
		switch (swtch1)
		{
		case 1: /*Вывести все данные оркестра на экран*/
			cout << "Данные каких инструментов вывести на экран?" << endl <<
				"|1| <-> Духовые инструменты" << endl <<
				"|2| <-> Струнные инструменты" << endl <<
				"|3| <-> Ударные инструменты" << endl <<
				"|4| <-> Вывести всю базу данных на экран" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1:
				SetColor(15, 1);
				cout << endl << "\tWind instruments:" << endl;
				file = "wind.dat";
				file >> wind_buf;
				break;
			case 2:
				SetColor(15, 1);
				cout << endl << endl << "\tStringed instruments:" << endl;
				file = "stringed.dat";
				file >> stringed_buf;
				break;
			case 3:
				SetColor(15, 1);
				cout << endl << endl << "\tPercussion instruments:" << endl;
				file = "percussion.dat";
				file >> per_buf;
				break;
			case 4:
				SetColor(15, 1);
				cout << endl << "\tWind instruments:" << endl;
				file = "wind.dat";
				file >> wind_buf;
				SetColor(15, 1);
				cout << endl << endl << "\tStringed instruments:" << endl;
				file = "stringed.dat";
				file >> stringed_buf;
				SetColor(15, 1);
				cout << endl << endl << "\tPercussion instruments:" << endl;
				file = "percussion.dat";
				file >> per_buf;
				SetColor(14, 1);
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "Выберите тип инструментов:" << endl <<
				"|1| <-> Духовые инструменты" << endl <<
				"|2| <-> Струнные инструменты" << endl <<
				"|3| <-> Ударные инструменты" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1: /*Духовые*/
				file = "wind.dat";
				cout << "Выберите действие:" << endl <<
					"|1| <-> Вывод на экран" << endl <<
					"|2| <-> Добавление нового инструмента в базу" << endl <<
					"|3| <-> Удаление инструмента из базы" << endl <<
					"|4| <-> Редактирование базы" << endl;
				cin >> swtch1;
				switch (swtch1)
				{
				case 1: /*Вывод на экран*/
					file >> wind_buf;
					break;
				case 2: /*Добавление в базу*/
					file << wind_buf;//добавление
					file >> wind_buf;//вывод на экран
					system("wind.dat");
					break;
				case 3: /*Удаление из базы по названию инстр и ФИО владельца*/
					file <<= wind_buf;
					break;
				case 4: /*Редактирование базы*/
					file >>= wind_buf;
					break;
				default:
					break;
				}
				break;
			case 2: /*Струнные*/
				file = "stringed.dat";
				cout << "Выберите действие:" << endl <<
					"|1| <-> Вывод на экран" << endl <<
					"|2| <-> Добавление нового инструмента в базу" << endl <<
					"|3| <-> Удаление инструмента из базы" << endl <<
					"|4| <-> Редактирование базы" << endl;
				cin >> swtch1;
				switch (swtch1)
				{
				case 1: /*Вывод на экран*/
					file >> stringed_buf;
					break;
				case 2: /*Добавление в базу*/
					file << stringed_buf;//добавление
					file >> stringed_buf;//вывод на экран
					system("stringed.dat");
					break;
				case 3: /*Удаление из базы по названию инстр и ФИО владельца*/
					file <<= stringed_buf;
					break;
				case 4: /*Редактирование базы*/
					file >>= stringed_buf;
					break;
				default:
					break;
				}
				break;
			case 3: /*Ударные*/
				file = "percussion.dat";
				cout << "Выберите действие:" << endl <<
					"|1| <-> Вывод на экран" << endl <<
					"|2| <-> Добавление нового инструмента в базу" << endl <<
					"|3| <-> Удаление инструмента из базы" << endl <<
					"|4| <-> Редактирование базы" << endl;
				cin >> swtch1;
				switch (swtch1)
				{
				case 1: /*Вывод на экран*/
					file >> per_buf;
					break;
				case 2: /*Добавление в базу*/
					file << per_buf;
					file >> per_buf;
					system("percussion.dat");
					break;
				case 3: /*Удаление из базы по названию инстр и ФИО владельца*/
					file <<= per_buf;
					break;
				case 4: /*Редактирование базы*/
					file >>= per_buf;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		case 0:
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
