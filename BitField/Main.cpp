
//#include "stdafx.h" 
#include "TBitField.h"
#include "TSet.h"
#include <iostream>
#include <tchar.h>
using namespace std;

typedef unsigned int TELEM;


int Menu()
{
	cout << " 1 - �������� ������� \n 2 - ������� ������� \n 3 - ��������� ������� �������� \n 4 - ���������� \n 5 - ������ ������ ��������� \n 6 - ����� �� ��������� \n��� �����: ";
	int k;
	cin >> k;
	cout << endl;
	return k;
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "");
	int b1;
	cout << "MaxPower= ";
	cin >> b1;


	TSet T1(b1);

	cin >> T1;
	cout << T1;

	while (1)
	{
      	switch (Menu())
		{
		case 1:
		{
				  cout << "������� �������.";
				  cin >> b1;
				  T1 = T1 + b1;
				  cout << "/n���������: ";
				  cout << T1;
				  break;
		}
		case 2:
		{
				  cout << "������� �������. ";
				  cin >> b1;
				  T1 = T1 - b1;
				  cout << "/n���������: ";
				  cout << T1;
				  break;
		}
		case 3:
		{
				  cout << "������� �������. ";
				  cin >> b1;
				  if (T1.IsMember(b1))
					  cout << b1 << " /n����������� ��������� \n";
				  else
					  cout << b1 << " /n�� ����������� ��������� \n";
				  break;
		}
		case 4:
		{
				  cout << "/n���������: ";
				  cout << ~T1;
				  break;
		}
		case 5:
		{
				  int b2;
				  cout << "/n������ ���������: " << "\n";
				  cout << "MaxPower= ";
				  cin >> b2;
				  TSet T2(b2);
				  cin >> T2;
				  cout << T1;
				  cout << T2;
				  cout << "����������� ��������: " << endl;
				  cout << (T1 + T2);
				  cout << "�����������  ��������: " << endl;
				  cout << (T1 * T2);
				  if (T1 == T2)
					  cout << " ��������� �����. " << endl;
				  else
					  cout << " ��������� �� �����. " << endl;
				  system("pause");
				  return 0;
		}
		default:
		{
				   return 0;
		}
		}
	}

	system("pause");

	return 0;
}
