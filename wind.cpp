#pragma once
#include "Header.h"
#include "keeper.h"
#include "wind.h"
#include "orchestra.h"
#include "SetColor.h"

inline wind::wind() { defects[0] = '\0'; SetColor(0, 1); cout << "Wind#"; SetColor(14, 1); }

inline void wind::set() {
	orchestra::set();
	cout << " Дефекты:\t\t";
	cin >> this->defects;
	cout << " Краткое описание:\t";
	cin >> this->description;
}

inline void wind::put() {
	orchestra::put();
	cout << "\n Дефекты:\t\t" << defects;
	cout << "\n Краткое описание:\t" << description << endl;
}

inline wind::~wind() { SetColor(0, 1); cout << "#dstrctr_wind"; SetColor(14, 1); }
