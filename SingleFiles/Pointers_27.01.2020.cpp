#include <iostream>
#include "Pointers_17.01.2020.h"
#include <chrono>
using namespace std;
using namespace chrono;

void Swap(int* firstAddress, int* secondAddress)
{
	int temp = *firstAddress;
	*firstAddress = *secondAddress;
	*secondAddress = temp;
}

void PrintArray_(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void SwapArray(int** first, int** second)
{
	int* temp = *first;
	*first = *second;
	*second = temp;
}

template <typename T, int N>
int Size(T(&a)[N])
{
	return N;
}

void FillArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 100;
	}
}

int main()
{
	//// 3. გააკეთეთ ცვლადი, ამ ცვლადის პოინტერი და ამ პოინტერის პოინტერი.
	////    პოინტერის პოინტერის გამოყენებით შეცვალეთ ამ ცვლადის მნიშვნელობა.
	//int a = 10;

	//int* ptr = &a;  // შევქმენით პოინტერი და შევინახეთ first ცვლადის მისამართი
	//int** ptr_ptr = &ptr; //  შევქმენით პოინტერის პოინტერი და ptr პოინტერის მისამართი

	//int b = 20;
	//ptr = &b;  // პოინტერში რომელშიც ინახებოდა first ცვლადის მისამართი შევინახეთ
	//// second ცვლადის მისამართი

	//cout << "before: first = " << a << endl;   // 10
	//cout << "before: second = " << b << endl; // 20

	//**ptr_ptr = 300;  // გადავედი ptr-ზე და გადავედი second-ზე და ჩავწერე 300

	//cout << "after: first = " << a << endl;  // 10  
	//cout << "after: second = " << b << endl; // 300

	// ----------------------------------------------------------- //

	/*int a = 10;
	int b = 20;

	cout << "before: a = " << a << endl;
	cout << "before: b = " << b << endl;

	Swap(&a, &b);

	cout << "after: a = " << a << endl;
	cout << "after: b = " << b << endl;

	int first = a;
	int second = b;

	int temp = first;
	first = second;
	second = temp;

	int num = 1330857282;

	char* address = (char*)&num;

	cout << *(address + 0);
	cout << *(address + 1);
	cout << *(address + 2);
	cout << *(address + 3) << endl;

	cout << address[0];
	cout << address[1];
	cout << address[2];
	cout << address[3] << endl;*/

	// const int length = 5;
	// 
	// int numbers[length];
	// 
	// 
	// *(numbers + 0) = 10;
	// *(numbers + 1) = 20;
	// *(numbers + 2) = 30;
	// *(numbers + 3) = 40;
	// 
	// *(numbers + 4) = 50;
	// 
	// numbers[0] = 10;
	// numbers[1] = 20;
	// numbers[2] = 30;
	// numbers[3] = 40;
	// numbers[4] = 50;
	// 
	// int a = 10;
	// int* adress = &a + 20;


	/*
	int first[5]{ 1,2,3,4,5 };
	int second[5]{ 5,4,3,2,1 };

	auto start = high_resolution_clock::now();

	for (int i = 0; i < 10000000; i++)
	{
		int e = i;
	}

	auto finish = high_resolution_clock::now();

	auto result = start.time_since_epoch() - finish.time_since_epoch();

	cout << result.count() << endl;

	// result 0.027488 Seconds */

	srand(time(NULL));








	cin.get();
	cin.get();
	return 0;
}