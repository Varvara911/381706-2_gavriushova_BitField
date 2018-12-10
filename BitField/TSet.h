#pragma once
#include "TBitField.h"
#include <iostream>
using namespace std;
class TSet
{
private:
	int MaxPower;       // ������������ �������� ���������
	TBitField BitField; // ������� ���� ��� �������� ���-�� �������
public:
	TSet(int mp);
	TSet(const TSet &s);
	TSet(const TBitField &x);
	TSet(const TSet &s, const TBitField &x);
	~TSet();
	operator TBitField();      // �������������� ���� � �������� ����
	void InsElem(const int n);       // �������� ������� � ���������
	void DelElem(const int n);       // ������� ������� �� ���������
	int IsMember(const int n) const; // ��������� ������� �������� � ���������
	int operator== (const TSet &s); // ���������
	TSet& operator=(const TSet &s); // ������������
	TSet operator+ (const int n);   // ��������� �������� � ���������
	TSet operator-(const int n);   // �������� �������� �� ���������
	TSet operator+ (const TSet &s); // �����������
	TSet operator* (const TSet &s); // �����������
	TSet operator~ (void);          // ����������
	friend istream &operator >> (istream &in, TSet &x);
	friend ostream &operator<<(ostream &out, const TSet &x);
};
