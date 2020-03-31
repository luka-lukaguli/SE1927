#include <iostream>
#include <string>
#include "20.03.2020.Array.h"

using namespace std;

void PrintArray(const Array& array)
{
	for (int i = 0; i < array._size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	/*
	int n = 10;
	int m = 35;

	int* addr = &n;

	*addr = 20;
	addr = &m;

	const int* constAddr = &n;
	*constAddr = 20;
	constAddr = &m;

	int* const addrConst  = &n;
	*addrConst = 20;
	addrConst = &m;

	const int* const constAddrConst = &n;
	*constAddrConst = 20;
	constAddrConst = &m;
	*/


	if (true)
	{
		Array numbers(5);

		for (int i = 0; i < numbers._size; i++)
		{
			//numbers._collection[i] = rand() % 100;
			numbers[i] = rand() % 100;
		}

		PrintArray(numbers);

		numbers.Reverse();

		PrintArray(numbers);

		numbers.Sort([](double arg1, double arg2) {return arg1 > arg2; });

		numbers.Foreach([](int ind, double num) {cout << ind + 1 << ") " << num << " "; });
		
		//Array numbersCopy(numbers); // გამოიძახება copy კონსტრუქტორი
		
		Array emptyArray(7); // default კონსტრუქტორი
		emptyArray = numbers; // მინიჭების ოპერატორი

		
	}

	return 0;
}
