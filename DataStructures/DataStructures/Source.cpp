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

	// "firstName,lastName,phoneNumber"
	static Student Parse(const String& line)
	{
		List<String> data = line.Split(',');
		Student student;
		student.firstName = data[0];
		student.lastName = data[1];
		student.phoneNumber = data[2];
		return student;
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
		students.Add(Student::Parse(line));
	}
	fin.close();

	students.Sort([](Student s1, Student s2) {return s1.firstName.Compare(s2.firstName) == -1; });
	students.Foreach([](int i, const Student& s) {PrintStudent(s); });
}

int main()
{
	// ProcessStudents();

	SinglyLinkedList<int> numbers;

	//const int count = 1000;
	const int count = 7;

	for (int i = 0; i < count; i++)
	{
		numbers.AddLast(i * 15);
	}

	numbers.Foreach([](int n) {cout << n << " "; });

	auto node = numbers.FindLast([](int n) {return n > 45; });
	if (node != nullptr)
	{
		cout << endl << node->_value;
	}

	auto odds = numbers.FindAll([](int n) {return n % 2 == 1; });
	cout << endl;
	odds.Foreach([](int n) {cout << n << " "; });

	cout << "\n------------------------------\n";
	auto bigNumbers = numbers.Transform<int>([](int n) {return n * 100; });

	bigNumbers.Foreach([](int n) {cout << n << " "; });

	String line;

	SinglyLinkedList<Student> students;

	//ifstream fin("data.csv");
	//while (!fin.eof())
	//{
	//	GetLine(fin, line, 200);
	//	students.AddLast(Student::Parse(line));
	//}
	//fin.close();

	//students.Foreach([](const Student& s) {PrintStudent(s); });
	cout << "\n------------------------------\n";
	/*auto phoneNumbers = students.Transform<String>([](const Student& s) {return s.phoneNumber; });*/

	return 0;
}