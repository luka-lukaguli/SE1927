#include <iostream>
#include <exception> // ჩავრთოთ გამონაკლისების ბიბლიოთეკა იმისთვის რომ გამონაკლისი ვისროლოთ
#include <fstream>
#include "List.h"
#include "Array.h"
#include "String.h"
#include "SinglyLinkedList.h"

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

struct Student
{
	String firstName;
	String lastName;
	String phoneNumber;

	Student() = default;

	Student(const String& line)
	{
		Parse(line);
	}

	// "firstName,lastName,phoneNumber"
	void Parse(const String& line)
	{
		List<String> data = line.Split(',');

		firstName = data[0];
		lastName = data[1];
		phoneNumber = data[2];
	}
};

void PrintStudent(const Student& student)
{
	cout << student.firstName << " ";
	cout << student.lastName << " ";
	cout << student.phoneNumber;
	cout << "\n------------------------------\n";
}

void ProcessStudents()
{
	String line;

	List<Student> students;

	ifstream fin("data.csv");
	while (!fin.eof())
	{
		GetLine(fin, line, 200);
		students.Add(Student(line));
	}
	fin.close();

	students.Sort([](Student s1, Student s2) {return s1.firstName.Compare(s2.firstName) == -1; });
	students.Foreach([](int i, const Student& s) {PrintStudent(s); });
}

int main()
{
	// ProcessStudents();

	SinglyLinkedList numbersCopy;
	if (true)
	{
		SinglyLinkedList numbers;

		const int count = 1000000;
		//const int count = 3;

		for (int i = 0; i < count; i++)
		{
			numbers.AddLast(i * 10);
		}

		cout << "Count: " << numbers.Count() << endl;;

		numbersCopy = numbers;
	}
	cout << numbersCopy.Count() << endl;
	numbersCopy.Foreach([](double n) {cout << n << " "; });

	return 0;
}