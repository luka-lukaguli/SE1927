#include <iostream>
#include <exception> // ჩავრთოთ გამონაკლისების ბიბლიოთეკა იმისთვის რომ გამონაკლისი ვისროლოთ
#include <fstream>
#include "List.h"
#include "Array.h"
#include "String.h"

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

//struct Product
//{
//public:
//	string name;
//	string description;
//
//private:
//	double _price;
//	double _discount;
//	int _quantity;
//
//public:
//
//	Product(double _price)
//	{
//		_price = _price;
//	}
//
//	// Getter
//	double GetPrice() const { return _price; }
//
//	// Getter
//	double GetDiscount() const { return _discount; }
//
//	// Getter
//	int GetQuantity() const { return _quantity; }
//
//	// Getter
//	double GetDiscountedPrice() const { return _price - _price * _discount; }
//
//	// Setter
//	void SetPrice(double price)
//	{
//		if (price >= 0)
//			_price = price;
//	}
//
//	// Setter
//	void SetDiscount(double discount)
//	{
//		if (discount >= 0 && discount < 1)
//			_discount = discount;
//	}
//
//	// Setter
//	void SetQuantity(int quantity)
//	{
//		if (quantity >= 0)
//			_quantity = quantity;
//	}
//};
//
//void PrintProduct(const Product& prod)
//{
//	cout << "Price          : " << prod.GetPrice() << endl;
//	cout << "Discount       : " << prod.GetDiscount() << endl;
//	cout << "Quantity       : " << prod.GetQuantity() << endl;
//	cout << "DiscountedPrice: " << prod.GetDiscountedPrice() << endl;
//}

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

int main()
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

	return 0;
}