#pragma once
#include "orchestra.h"

class stringed : public orchestra///краткое описание
{
private:
	char manufact[20]; //наименование производителя
	char description[1000]; ///краткое описание
public:
	friend keeper;
	stringed();
	void set();
	void put();
	~stringed();
};
