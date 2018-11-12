#pragma once

class orchestra
{
private:
	char name[20]; //название инстр
	char cost[20]; //стоимость инстр
	char num_of_orch[20]; //кол-во в оркестре
	char owner[30]; //ФИО владельца
public:
	friend keeper;
	template<typename T>
	friend void operator <<(const string, T);
	template<typename T>
	friend void operator >>(const string, T);
	template<typename T>
	friend void operator <<=(const string, T);
	template<typename T>
	friend void operator >>=(const string, T);

	orchestra();
	orchestra(char *_name, char *_cost, char *_num_of_orch, char *_owner);
	void set();
	void put();
	char* ret_name();
	char* ret_owner();
	~orchestra();
};
