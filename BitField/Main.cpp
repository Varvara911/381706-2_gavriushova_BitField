
//#include "stdafx.h" 
#include "TBitField.h"
#include "TSet.h"
#include <iostream>
#include <tchar.h>
using namespace std;

typedef unsigned int TELEM;


int Menu()
{
	cout << " 1 - включить элемент \n 2 - удалить элемент \n 3 - проверить наличие элемента \n 4 - дополнение \n 5 - ввести второе множество \n 6 - выход из программы \nВаш выбор: ";
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
				  cout << "Введите элемент.";
				  cin >> b1;
				  T1 = T1 + b1;
				  cout << "/nРезультат: ";
				  cout << T1;
				  break;
		}
		case 2:
		{
				  cout << "Введите элемент. ";
				  cin >> b1;
				  T1 = T1 - b1;
				  cout << "/nРезультат: ";
				  cout << T1;
				  break;
		}
		case 3:
		{
				  cout << "Введите элемент. ";
				  cin >> b1;
				  if (T1.IsMember(b1))
					  cout << b1 << " /nпринадлежит множеству \n";
				  else
					  cout << b1 << " /nне принадлежит множеству \n";
				  break;
		}
		case 4:
		{
				  cout << "/nРезультат: ";
				  cout << ~T1;
				  break;
		}
		case 5:
		{
				  int b2;
				  cout << "/nВторое множество: " << "\n";
				  cout << "MaxPower= ";
				  cin >> b2;
				  TSet T2(b2);
				  cin >> T2;
				  cout << T1;
				  cout << T2;
				  cout << "Объединение множеств: " << endl;
				  cout << (T1 + T2);
				  cout << "Пересечение  множеств: " << endl;
				  cout << (T1 * T2);
				  if (T1 == T2)
					  cout << " Множества равны. " << endl;
				  else
					  cout << " Множества не равны. " << endl;
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
