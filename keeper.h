#pragma once

class keeper
{
public:
	/// ЗАПИСЬ В ФАЙЛ
	template<typename T>
	friend void operator <<(const string file, T buf);

	/// ЧТЕНИЕ ИЗ ФАЙЛА
	template<typename T>
	friend void operator >>(const string file, T buf);

	/// УДАЛЕНИЕ ЭЛЕМЕНТА
	template<typename T>
	friend void operator <<=(const string file, T buf);

	/// РЕДАКТИРОВАНИЕ БАЗЫ
	template<typename T>
	friend void operator >>=(const string file, T buf);
};
