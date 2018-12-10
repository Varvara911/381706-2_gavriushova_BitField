
//#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TBitField.h"
#include <iostream>
using namespace std;
typedef unsigned int TELEM;

TBitField::TBitField(int len)
{
	if (len>0)
	{
		BitLen = len;
		MemLen = (len + 31) >> 5;
		pMEM = new TELEM[MemLen];
		if (pMEM != NULL)
		{
			for (int i = 0; i < MemLen; i++)
			{
				pMEM[i] = 0;
			}
		}
	}
}

TBitField::TBitField(const TBitField& x)
{
	BitLen = x.BitLen;
	MemLen = (BitLen + 31) >> 5;

	pMEM = new TELEM[MemLen];
	if (pMEM != NULL)
	{
		for (int i = 0; i < MemLen; i++)
		{
			pMEM[i] = x.pMEM[i];
		}
	}
	if (pMEM == NULL)
	{
		cout << "Завершение работы. ";
		return;
	}
}

TBitField::~TBitField(void)
{
	delete[]pMEM;
	pMEM = NULL;
}


int TBitField::GetMemIndex(const int n) const
{
	return(n >> 5);
}

TELEM TBitField::GetMemMask(const int n) const
{
	return(1 << (n & 31));
}

int TBitField::GetLength(void) const
{
	return BitLen;
}

int TBitField::GetBit(const int n) const
{
	if ((n >= 0)&(n<BitLen))
		return pMEM[GetMemIndex(n)] & GetMemMask(n);
	else
		return 0;
}

void TBitField::SetBit(const int n)
{
	if ((n >= 0)&(n<BitLen))
		pMEM[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) const
{
	if ((n >= 0)&(n<BitLen))
		pMEM[GetMemIndex(n)] &= ~GetMemMask(n);
}


TBitField& TBitField::operator=(const TBitField &x)
{
	if (&x != this)
	{
		BitLen = x.BitLen;
		if (MemLen != x.MemLen)
		{
			delete[]pMEM;
			MemLen = x.MemLen;
			pMEM = new TELEM[MemLen];
		}
		for (int i = 0; i < MemLen; i++)
			pMEM[i] = x.pMEM[i];
	}
	return *this;
}

int TBitField::operator==(const TBitField &x)
{
	if (MemLen == x.MemLen)
	{
		for (int i = 0; i < MemLen; i++)
		{
			for (int j = 0; j < x.MemLen; j++)
			{
				if (pMEM[i] != x.pMEM[j])
				{
					return 0;
				}
			}
		}
		return 1;
	}
	else
		return 0;
}

TBitField TBitField::operator|(const TBitField &x)
{
	int len = BitLen;
	if (x.BitLen <= len)
		len = x.BitLen;
	TBitField temp(len);
	for (int i = 0; i < MemLen; i++)
		temp.pMEM[i] = pMEM[i];
	for (int i = 0; i < x.MemLen; i++)
		temp.pMEM[i] |= x.pMEM[i];
	return temp;
}
TBitField TBitField::operator&(const TBitField &x)
{
	int len = BitLen;
	if (x.BitLen <= len)
		len = x.BitLen;
	TBitField temp(len);
	for (int i = 0; i < MemLen; i++)
		temp.pMEM[i] = pMEM[i];
	for (int i = 0; i < x.MemLen; i++)
		temp.pMEM[i] &= x.pMEM[i];
	return temp;
}

TBitField TBitField::operator~(void)
{
	int len = BitLen;
	TBitField temp(len);
	temp = *this;
	for (int i = 0; i<MemLen; i++)
		temp.pMEM[i] = ~temp.pMEM[i];
	return temp;
}

istream &operator>>(istream &in, TBitField &x)
{
	cout << "Enter max size of bit field  " << endl;
	in >> x.BitLen;
	x.MemLen = (x.BitLen + 31) >> 5;
	x.pMEM = new TELEM[x.MemLen];

	int i = 0;
	char c;
	cout << "Enter bit field  " << endl;
	if (x.pMEM != NULL)
	{
		for (int j = 0; j < x.MemLen; j++)
		{
			x.pMEM[j] = 0;
		}

		do
		{
			in >> c;
			if (c == '1')
				x.SetBit(i);

			i++;
		} while (((c == '1') || (c == '0')) && (i<x.BitLen));

	}
	return in;
}

ostream &operator<<(ostream &out, const TBitField &x)
{
	for (int i = 0; i < x.BitLen; i++)
	if (x.GetBit(i))//1
		out << '1';
	else
		out << '0';
	return out;
}