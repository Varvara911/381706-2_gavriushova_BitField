#pragma once
#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned int TELEM;
class TBitField
{
private:
	int BitLen;   // размер битового поля
	int MemLen;
	TELEM *pMEM;
	int   GetMemIndex(const int n) const; // индекс в pМем для бита n
	TELEM GetMemMask(const int n) const; // битовая маска для бита n
public:
	TBitField();
	TBitField(int N);
	TBitField(const TBitField &x);
	~TBitField();
	int GetLength(void) const;
	void SetBit(const int n);
	void ClrBit(const int n) const;
	int GetBit(const int n) const;
	int operator==(const TBitField &x);
	TBitField& operator=(const TBitField &x);
	TBitField operator|(const TBitField &x);
	TBitField operator&(const TBitField &x);
	TBitField operator~(void);
	friend istream &operator>>(istream &istr, TBitField &x);
	friend ostream &operator<<(ostream &ostr, const TBitField &x);
};
