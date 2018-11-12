#pragma once
#include "orchestra.h"

class percussion : public orchestra //ударные
{
private:
	char type[20];
public:
	friend keeper;
	percussion();
	percussion(char *_name, char *_cost, char *_num_of_orch, char *_owner, char *_type);
	void set();
	void put();
	~percussion();
};
