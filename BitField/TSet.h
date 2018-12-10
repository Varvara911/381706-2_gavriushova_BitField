#pragma once
#include "TBitField.h"
#include <iostream>
using namespace std;
class TSet
{
private:
	int MaxPower;       // максимальная мощность множества
	TBitField BitField; // битовое поле для хранения хар-го вектора
public:
	TSet(int mp);
	TSet(const TSet &s);
	TSet(const TBitField &x);
	TSet(const TSet &s, const TBitField &x);
	~TSet();
	operator TBitField();      // преобразование типа к битовому полю
	void InsElem(const int n);       // включить элемент в множество
	void DelElem(const int n);       // удалить элемент из множества
	int IsMember(const int n) const; // проверить наличие элемента в множестве
	int operator== (const TSet &s); // сравнение
	TSet& operator=(const TSet &s); // присваивание
	TSet operator+ (const int n);   // включение элемента в множество
	TSet operator-(const int n);   // удаление элемента из множества
	TSet operator+ (const TSet &s); // объединение
	TSet operator* (const TSet &s); // пересечение
	TSet operator~ (void);          // дополнение
	friend istream &operator >> (istream &in, TSet &x);
	friend ostream &operator<<(ostream &out, const TSet &x);
};
