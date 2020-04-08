#include <iostream>
#include <exception> // ჩავრთოთ გამონაკლისების ბიბლიოთეკა იმისთვის რომ გამონაკლისი ვისროლოთ
#include <fstream>
#include "List.h"
#include "Array.h"
#include "Queue.h"
#include "String.h"
#include "SinglyLinkedList.h"
#include "Stack.h"

using namespace std;

template <typename T>
void PrintArray(const List<T>& array)
{
	for (int i = 0; i < array.Count(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

struct Customer
{
	String firstName;
	String lastName;
	String phoneNumber;

	Customer() = default;

	Customer(const String& line)
	{
		List<String> data = line.Split(',');
		firstName = data[0];
		lastName = data[1];
		phoneNumber = data[2];
	}
};

void PrintCustomer(const Customer& student)
{
	cout << student.firstName << " ";
	cout << student.lastName << " ";
	cout << student.phoneNumber;
	cout << "\n------------------------------\n";
}

char ReadKey(const char* message = "")
{
	cout << message;
	char key;
	cin >> key;
	return key;
}

int main()
{
	unsigned short lastNumber = 1;

	Queue<unsigned short> customers;

	while (true)
	{
		auto choice = ReadKey(" Click [E] wait operator\n Click [D] call customer\n --> ");

		switch (choice)
		{
		case 'e':
		case 'E':
			customers.Enqueue(lastNumber++);
			break;

		case 'd':
		case 'D':
			cout << "Number : " << customers.Dequeue() << endl;
			break;

		default:
			cout << "Invalid input " << endl;
			break;
		}
	}

	return 0;
}