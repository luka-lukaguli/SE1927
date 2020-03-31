#include <iostream>
#include <string>
#include "23.03.2020.List.h"

using namespace std;

void PrintArray(const List& array)
{
	for (int i = 0; i < array.Count(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	
	if (true)
	{
		List numbers(5);

		for (int i = 0; i < 5; i++)
		{
			numbers.Add(rand() % 100);
		}
		
		//numbers.ReallocateInternal();
		//
		//numbers._collection = nullptr;
		//numbers._size += 20;
		//numbers._count = 77;

		numbers.Insert(3, 11111);
		
		PrintArray(numbers);

		PrintArray(numbers);

		cout << "numbers._count : "<< numbers.Count() << endl;
		cout << "numbers._size : " << numbers.Size() << endl;

		numbers.Reverse();

		PrintArray(numbers);

		
		
	}

	return 0;
}
