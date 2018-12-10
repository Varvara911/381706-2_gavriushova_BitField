//#include "stdafx.h"
#include <stdio.h>
#include "TSet.h"
#include "TBitField.h"
#include <iostream>
using namespace std;



TSet::TSet(int tmp) : BitField(tmp)
{
	MaxPower = tmp;
}


TSet::TSet(const TSet &s, const TBitField &x) : BitField(x)
{
	MaxPower = s.MaxPower;

}

TSet::TSet(const TSet &s) :BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

void TSet::InsElem(const int n)
{
	BitField.SetBit(n);
}

void TSet::DelElem(const int n)
{
	BitField.ClrBit(n);
}

int TSet::IsMember(const int n) const
{

	if (BitField.GetBit(n) == 0)
		return 0;
	else
		return 1;

}

int TSet::operator== (const TSet &s)
{
	if (MaxPower != s.MaxPower)
		return 0;
	if (BitField == s.BitField)
		return 1;
	else return 0;
}



TSet& TSet::operator=(const TSet &s)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

TSet TSet::operator+ (const int n)
{
	if (IsMember(n) == 1)
	{
		return *this;
	}
	else
	{
		BitField.SetBit(n);
		return *this;
	}
}

TSet TSet::operator-(const int n)
{
	if (IsMember(n) == 0)
	{
		return *this;
	}
	else
	{
		BitField.ClrBit(n);
		return *this;
	}
}

TSet TSet::operator+ (const TSet &s)
{
	int len = MaxPower;
	if (s.MaxPower>MaxPower)
		len = s.MaxPower;
	TSet tmp(len);
	for (int i = 0; i<s.MaxPower; i++)
	{
		if (s.IsMember(i))
			tmp.InsElem(i);
	}
	for (int i = 0; i<MaxPower; i++)
	{
		if (IsMember(i))
		{
			if (tmp.IsMember(i) == 0)
				tmp.InsElem(i);
		}
	}


	return tmp;
}

TSet TSet::operator* (const TSet &s)
{
	TSet tmp(BitField & s.BitField);
	return tmp;
}

TSet TSet::operator~ (void)
{
	TSet res(*this);
	res.BitField = ~res.BitField;
	return res;
}

istream &operator >> (istream &in, TSet &x)
{
	int n = 0;
	cout << "Введите элементы множества " << "\n";
	while (n >= 0)
	{
		in >> n;
		if (n >= 0)
			x = x + n;
	}
	return in;
}

ostream &operator<<(ostream &out, const TSet &x)
{
	cout << "Множество: ";
	for (int i = 0; i < x.MaxPower; i++)
	{
		if (x.BitField.GetBit(i))
			out << i << " ";
	}
	cout << "Битовое поле: ";
	out << x.BitField;
	cout << "\n";
	return out;
}



TSet::~TSet()
{
}
