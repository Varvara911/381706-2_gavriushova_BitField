#pragma once
#include"Stack.h"

template<class T>
class TQueue public TStack<T>
{
	protected:
		int s;
	public:
		TQueue(int n = 0);
		TQueue(TQueue<T> &A);
		void Put(T&A);
		T Get();

		bool IsFull();
		bool IsEmpty();
		~Queue();
};

template<class T>
TQueue::TQueue(int n = 0) :TStack(n)
{
	s = 0;
}

template<class T>
TQueue::TQueue(TQueue<T> &A)
{
	if (A.l>0)
	{
		m = new T[A.l];
		for (int i = 0; i < l; i++)
		{
			m[i] = A.m[i];
		}
	}
	else
	{
		l = 0;
		m = 0;
	}
	s = A.s;
	t = A.t;
	count = A.count;
}

template<class T>
void TQueue::Put(T&A)
{
	if (IsFull())
		throw 1;
	m[s] = A;
	count++;
	s = (s + 1) % l;
}

template<class T>
T TQueue::Get()
{
	if (IsEmpty())
	{
		T tmp = m[t];
		count--;
		t = (t + 1) % l;
		return tmp;
	}
	else
		throw 1;
}

bool IsFull();
bool IsEmpty();
~Queue();

