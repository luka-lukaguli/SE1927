#include <iostream>

using namespace std;

template <typename T, typename TFunc>
int FindIndex(T* collection, int size, TFunc function)
{
	for (int i = 0; i < size; i++)
	{
		if (function(collection[i]))
		{
			return i;
		}
	}
	return -1;
}

template <typename T, typename UnaryPredicate>
int FindLastIndex(T* collection, int size, UnaryPredicate function)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (function(collection[i]))
		{
			return i;
		}
	}
	return -1;
}

template <typename T, typename TFunc>
void Sort(T* collection, int size, TFunc function)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (function(collection[j], collection[i]))
			{
				T temp = collection[i];
				collection[i] = collection[j];
				collection[j] = temp;
			}
		}
	}
}

template <typename T>
void Copy(T* source, T* destination, int size)
{
	for (int i = 0; i < size; i++)
	{
		destination[i] = source[i];
	}
}

template <typename TSource, typename TDestination, typename Transformer>
void Transform(TSource* source, TDestination* destination, int size, Transformer transform)
{
	for (int i = 0; i < size; i++)
	{
		destination[i] = transform(source[i]);
	}
}

template <typename T>
void Copy(T* source, T* destination, int count, int sourceIndex, int destinationIndex)
{
	int length = sourceIndex + count;
	for (int i = sourceIndex, j = destinationIndex; i < length; i++, j++)
	{
		destination[j] = source[i];
	}
}


int main()
{
	double doubleNumbers[5]{ 10, 20, 22.5, 17.5, 16.5 };

	Sort(doubleNumbers, 5, [](double arg1, double arg2)
		{
			return arg1 < arg2;
		});


	int intNumbers[5]{ 10, 11, 16, 17, 18 };
	int numbersCopy[5];

	Copy(intNumbers, numbersCopy, 5);

	Transform(intNumbers, doubleNumbers, 5, [](int number)
		{
			return number * 0.01;
		});

	char text[12] = "Hello World";
	char upperText[12];

	Transform(text, text, 12, [](char symbol)
		{
			return	symbol >= 'a' && symbol <= 'z'
				? symbol - ('a' - 'A')
				: symbol;
		});


	Sort(intNumbers, 5, [](int arg1, int arg2)
		{
			return arg1 % 2 == 1 && arg2 % 2 != 1;
		});

	// STL - Standard Template Library

	cout << "More than 20 is on index: " <<
		FindIndex(doubleNumbers, 5, [](double number)
			{
				return number >= 20;
			});





	// დავალება: 

	/*
		+1. დაწერეთ ფუნქცია რომელიც იპოვის ბოლო ელემენტს რომელიც აკმაყოფილებს
		მითითებულ პირობას

		+2. დაწერეთ ფუნქცია რომელიც მასივს დაალაგებს.

		3. დაწერეთ ფუნქცია რომელიც
		ერთი მასივის მასივის გადააკოპირებს მეორე მასივიში

		4. დაწერეთ ფუნქცია რომელიც ერთი მასივის ელემენტებს გადააკოპირებს
		სხვა ტიპის მასივში და პარამეტრად მიიღებს ფუნქციას რომელიც გარდაქმნის ამ
		მასივის ელემენტს მეორე მასივის ელემენტად.

		5. დაწერეთ ფუნქცია რომელიც ერთი მასივიდან მითითებული რაოდენობით
		აიღებს ელემენტებს მითითებული ინდექსიდან
		და ჩაწერს მეორე მასივში მითითებულ ინდექსზე


		-------------- საშინაო დავალება -------------------------------

		6. დაწერეთ ფუნქცია რომელიც გაიგებს მასივის **ყველა** ელემენტი აკმაყოფილებს თუ არა
		 მითითებულ პირობას

		7. დაწერეთ ფუნქცია რომელიც გაიგებს მასივის **რომელიმე** ელემენტი აკმაყოფილებს თუ არა
		 მითითებულ პირობას

		8. დაწერეთ ფუნქცია რომელიც გაიგებს ერთი მასივი უდრის თუ არა მეორე მასივს

		9. დაწერეთ ფუნქცია რომელიც გაიგებს ორი მასივი ერთნაირია თუ არა და შედარებისთვის გამოიყენებს
		გარედან გადაცემულ ფუნქციას

		10. დაწერეთ ფუნქცია რომელიც ერთი მასივიდან მეორეში მხოლოდ იმ ელემენტებს გადააკოპირებს
		რომლებიც პირობას აკმაყოფილებენ.

		11. დაწერეთ ფუნქცია რომელიც ერთი მასივიდან მეორეში მხოლოდ იმ ელემენტებს გადააკოპირებს
		რომლებიც პირობას აკმაყოფილებენ.

	*/



	return 0;
}