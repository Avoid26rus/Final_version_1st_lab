#pragma once
#include "Header.h"
#include "keeper.h"
#include "stringed.h"
#include "orchestra.h"
#include "SetColor.h"

inline stringed::stringed() { manufact[0] = '\0'; description[0] = '\0'; SetColor(0, 1); cout << "Stringed#"; SetColor(0, 1); }

inline void stringed::set() {
	orchestra::set();
	cout << " Производитель:\t\t";
	cin >> this->manufact;
	cout << " Краткое описание:\t";
	cin >> this->description;
}

inline void stringed::put() {
	orchestra::put();
	cout << "\n Производитель:\t\t" << manufact;
	cout << "\n Краткое описание:\t" << description << endl;
}

inline stringed::~stringed() { SetColor(0, 1); cout << "#dstrctr_stringed"; SetColor(14, 1); }
