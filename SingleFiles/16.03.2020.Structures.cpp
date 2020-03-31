#include <iostream>
#include <string>
#include <math.h>
#include "Algorithms.h"

using namespace std;

struct Product
{
	// სახელი
	string Name;
	// აღწერა
	string Description;
	// ფასი
	double Price;
	// ფასდაკლების კოეფიციენტი
	double Discount;
	// რაოდენობა
	double Quantity;

	Product()
	{
		Price = 0;
		Discount = 0;
		Quantity = 0;
	}

	Product(string name, string description, double price, double discount, int quantity)
	{
		Name = name;
		Description = description;
		Price = price;
		Discount = discount;
		Quantity = quantity;
	}


	void Initialize(string name, string description, double price, double discount, int quantity)
	{
		Name = name;
		Description = description;
		Price = price;
		Discount = discount;
		Quantity = quantity;
	}


	bool Equal(Product& other)
	{
		return Price == other.Price;
	}

	// ასეთი სახის ფუნქციას ეძახიან "მეთოდს"
	bool IsMoreThan(Product& other)
	{
		return Price > other.Price;
	}

	// ასეთი სახის ფუნქციას ეძახიან "მეთოდს"
	bool IsLessThan(Product& other)
	{
		return Price < other.Price;
	}

	bool operator>(const Product& other)
	{
		return Price > other.Price;
	}

	bool operator<(const Product& other)
	{
		return Price < other.Price;
	}

	bool operator>=(const Product& other)
	{
		return Price >= other.Price;
	}

	bool operator<=(const Product& other)
	{
		return Price <= other.Price;
	}

	bool operator==(const Product& other)
	{
		return Price == other.Price;
	}

	bool operator!=(const Product& other)
	{
		return Price != other.Price;
	}

};

struct Point
{
	double X;
	double Y;

	Point(double x, double y)
	{
		X = x;
		Y = y;
	}

	Point()
	{
		X = 0;
		Y = 0;
	}

	bool operator==(const Point& other)
	{
		return X == other.X && Y == other.Y;
	}


	/*bool operator!=(const  Point& other)
	{
		return !(*this == other);
	}*/

	double Distance() const
	{
		return sqrt(X * X + Y * Y);
	}

	bool operator>(const Point& other)
	{
		return Distance() > other.Distance();
	}

	bool operator<(const Point& other)
	{
		return Distance() < other.Distance();
	}

	bool operator<=(const Point& other)
	{
		return Distance() <= other.Distance();
	}

	bool operator>=(const Point& other)
	{
		return Distance() >= other.Distance();
	}

	double Distance(const Point& other) const
	{
		double x2 = (other.X - X) * (other.X - X);
		double y2 = (other.Y - Y) * (other.Y - Y);
		return sqrt(x2 + y2);
	}

	Point operator+ (const Point& other) const
	{
		return Point(X + other.X, Y + other.Y);
	}

	Point operator- (const Point& other) const
	{
		return Point(X - other.X, Y - other.Y);
	}

	Point operator* (int number) const
	{
		return Point(X * number, Y * number);
	}
};

void PrintArray(int* collection, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << collection[i] << " " ;
	}
	cout << endl;
}

void PrintArray(int* begin, int* end)
{
	while (begin != end)
	{
		cout << *begin << " ";

		begin++;
	}
	cout << endl;
}

int StringLength(const char* charArray)
{
	int length = 0;
	while (charArray[length] != '\0')
	{
		length++;
	}
	return length;
}


void Optimize(char* & charArray)
{
	int size = StringLength(charArray) + 1;
	char* temp = new char[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = charArray[i];
	}
	delete[] charArray;
	charArray = temp;
}

template<typename Predicate>
int ArrayCopy(double* source, double* destination, int size, Predicate predicate)
{
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (predicate(source[i]))
		{
			destination[j] = source[i];
			j++;
		}
	}
	return j;
}

struct Array
{
	double* collection;
	int size;
};

template<typename Predicate>
void ArrayCopy(Array& source, Array& destination, Predicate predicate)
{
	int j = 0;
	for (int i = 0; i < source.size; i++)
	{
		if (predicate(source.collection[i]))
		{
			destination.collection[j] = source.collection[i];
			j++;
		}
	}
	destination.size = j;

}


void ArrayPrint(Array& array)
{
	for (int i = 0; i < array.size; i++)
	{
		cout << array.collection[i] << " ";
	}
	cout << endl;
}


int main()
{


	//Product products[5]
	//{
	//	Product("Iphone X",	"Iphone X. Has 128 GB internal memory and 8 Gb RAM",
	//	3499.99, 0.05, 20),

	//	Product("Iphone XI", "Iphone X. Has 128 GB internal memory and 8 Gb RAM",
	//	4999.99, 0.00, 7),

	//	Product("Galaxy Note 10", "The most powerful smartphone",
	//	199.99, 0.00, 20),

	//	Product("Logitec Keyboard", "Logitec mechanical keyboard SM764G",
	//	199.99, 0.00, 0),

	//	Product("Logitec Mouse", "Gaming mouse with 8 buttons",
	//	129.98, 0.15, 100),
	//};




	///*int index = -1;
	//for (int i = 0; i < 5; i++)
	//{
	//	if (products[i].Name == searchName)
	//	{
	//		index = i;
	//		break;
	//	}
	//}*/

	//string searchName;
	//cout << "Enter Name: ";
	//getline(cin, searchName);

	//int ind = FindIndex(products, 5, [searchName](Product product) {return product.Name == searchName; /* Closure */ });


	const int length = 5;
	int numbers[length]{ 1,2,3,4,5 };

	
	/*int size = 1000;
	char* text = new char[size];

	cin >> text ;

	Optimize(text);*/

	PrintArray(numbers, length);
	PrintArray(numbers + 0, numbers + 5);
	PrintArray(numbers + 1, numbers + 5);
	PrintArray(numbers + 1, numbers + 4);

	Array doubleNumbers;
	doubleNumbers.size = 10;
	doubleNumbers.collection = new double[10]{ -1, -5, 17, 20, -7, 8,10 ,20, 9, 10};

	Array positiveNumber;
	positiveNumber.collection = new double[10];

	ArrayCopy(doubleNumbers, positiveNumber, [](double n) {return n > 0; });
	ArrayPrint(positiveNumber);

	delete[] doubleNumbers.collection;
	delete[] positiveNumber.collection;


	return 0;
}