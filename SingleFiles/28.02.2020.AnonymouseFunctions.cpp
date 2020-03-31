#include <iostream>

using namespace std;


template <typename T>
void PrintCollection(T collection, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << collection[i] << " ";
	}
	cout << endl;
}



template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Reallocate(T*& collection, int newSize)
{
	T* temp = new T[newSize];
	for (int i = 0; i < newSize; i++)
	{
		temp[i] = collection[i];
	}
	delete[] collection;
	collection = temp;
}

template <typename T>
T Min(T* collection, int length)
{
	T minValue = collection[0];
	for (int i = 1; i < length; i++)
	{
		if (collection[i] < minValue)
		{
			minValue = collection[i];
		}
	}
	return minValue;
}

template <typename T>
int MinIndex(T* collection, int length)
{
	int minIndex = 0;
	for (int i = 1; i < length; i++)
	{
		if (collection[i] < collection[minIndex])
		{
			minIndex = i;
		}
	}
	return minIndex;
}

bool Ascending(int arg1, int arg2)
{
	return arg1 < arg2;
}

bool Descending(double arg1, double arg2)
{
	return arg1 > arg2;
}

bool OddsFirst(int arg1, int arg2)
{
	return arg1 % 2 != 0 && arg2 % 2 == 0;
}

char ToLower(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
		return symbol + ('a' - 'A');
	return symbol;
}

bool AscendingIgnoreCase(char arg1, char arg2)
{
	return ToLower(arg1) < ToLower(arg2);
}

template <typename T, typename TFunc>
void Sort(T* collection, int length, TFunc fuction)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (fuction(collection[j], collection[i]))
			{
				T temp = collection[i];
				collection[i] = collection[j];
				collection[j] = temp;
			}
		}
	}
}


template <typename T, typename TFunc>
int FindIndex(T* collection, int size, TFunc VigacFunqcia)
{
	for (int i = 0; i < size; i++)
	{
		if (VigacFunqcia(collection[i]))
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	const int size = 7;
	int numbers[]{ 10, 20, 25, 27, 28, 30, 1000 };

	int index = FindIndex(numbers, size, [](int number)	{return number == 20;});
	index = FindIndex(numbers, size, [](int number) {return number > 100; });
	index = FindIndex(numbers, size, [](int number)	{return number % 2 == 1;});
	index = FindIndex(numbers, size, [](int number) {return number % 2 == 0; });
	index = FindIndex(numbers, size, [](int number)	{return number > 100 && number <= 1000;});

	// Sort-სთვის დაწერილი ფუნქციები გადააკეთეთ ანონიმურ ფუნქციებად.


	return 0;
}