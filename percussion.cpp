#pragma once
#include "Header.h"
#include "keeper.h"
#include "percussion.h"
#include "orchestra.h"
#include "SetColor.h"

inline percussion::percussion() { type[0] = '\0'; SetColor(0, 1); cout << "Percussion#"; SetColor(14, 1); }
inline percussion::percussion(char *_name, char *_cost, char *_num_of_orch, char *_owner, char *_type) {
	orchestra::orchestra(_name, _cost, _num_of_orch, _owner);
	strcpy_s(type, _type);
}

inline void percussion::set() {
	orchestra::set();
	cout << " Тип инструмента:\t";
	cin >> this->type;
}

inline void percussion::put() {
	orchestra::put();
	cout << "\n Тип инструмента:\t" << type << endl;
}
inline percussion::~percussion() { SetColor(0, 1); cout << "#dstrctr_percussion"; SetColor(14, 1); }
