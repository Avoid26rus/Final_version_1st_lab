#pragma once
#include "orchestra.h"

class wind : public orchestra
{
private:
	char defects[20]; //дефект
	char description[1000]; ///краткое описание
public:
	friend keeper;
	wind();
	void set();
	void put();
	~wind();
};
