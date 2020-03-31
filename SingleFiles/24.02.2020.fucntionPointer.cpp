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
int FindIndex(T* collection, T element, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (collection[i] == element)
		{
			return i;
		}
	}
	return -1;
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



int main()
{
	const int length = 9;
	int intNumbers[]{ 1, 4, 3,2, 7, 8, 9, 10, 11};
	double doubleNumbers[length]{ 1.1,4.4 ,3.3, 2.2 };
	char text[6] = "Davit";

	PrintCollection(intNumbers, length);
	PrintCollection(doubleNumbers, length);
	PrintCollection(text, 5);

	Sort(doubleNumbers, length, Ascending);
	Sort(intNumbers, length, Ascending);
	Sort(text, 5, Ascending);
	PrintCollection(text, 5);
	Sort(text, 5, AscendingIgnoreCase);
	PrintCollection(text, 5);


	PrintCollection(intNumbers, length);
	PrintCollection(doubleNumbers, length);

	int index = FindIndex<int>(intNumbers, 2, length);
	index = FindIndex<double>(doubleNumbers, 3.3, length);

	int minInt = Min(intNumbers, length);
	double minDouble = Min(doubleNumbers, length);

	char minChar = Min(text, 5);
	int minCharIndex = MinIndex(text, 5);

	cout << intNumbers << endl;
	cout << Ascending << endl;

	Sort(intNumbers, length, OddsFirst);
	PrintCollection(intNumbers, length);


	return 0;
}