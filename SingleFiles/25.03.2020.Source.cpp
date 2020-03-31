#include <iostream>
#include <string>
#include <exception> // ჩავრთოთ გამონაკლისების ბიბლიოთეკა იმისთვის რომ გამონაკლისი ვისროლოთ
#include "25.03.2020.List.h"
#include "25.03.2020.Array.h"

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



struct Product
{
public:
	string name;
	string description;

private:
	double _price;
	double _discount;
	int _quantity;

public:

	Product(double _price)
	{
		_price = _price;
	}

	// Getter
	double GetPrice() const { return _price; }

	// Getter
	double GetDiscount() const { return _discount; }

	// Getter
	int GetQuantity() const { return _quantity; }

	// Getter
	double GetDiscountedPrice() const { return _price - _price * _discount; }

	// Setter
	void SetPrice(double price)
	{
		if (price >= 0)
			_price = price;
	}

	// Setter
	void SetDiscount(double discount)
	{
		if (discount >= 0 && discount < 1)
			_discount = discount;
	}

	// Setter
	void SetQuantity(int quantity)
	{
		if (quantity >= 0)
			_quantity = quantity;
	}
};

void PrintProduct(const Product& prod)
{
	cout << "Price          : " << prod.GetPrice() << endl;
	cout << "Discount       : " << prod.GetDiscount() << endl;
	cout << "Quantity       : " << prod.GetQuantity() << endl;
	cout << "DiscountedPrice: " << prod.GetDiscountedPrice() << endl;
}

int main()
{
	// 1. Template-ად გადააკეთეთ მასი ჩვენი დაწერილი მასივი
	// 2. დაიწყეთ სტრინგის მონაცემთა სტრუქტურის წერა. მაგალითისთვის როგორი უნდა იყოს არიღეთ ჩვენი დაწერილი List
	//  სტრინგი უფრო მარტივია რადგან ის არ არის Template, ის არის char-ების მასივი ანუ T* ის მაგივრად აქვს char*;
	
	
	Product prod(1000);
	prod.name = "IPhone";
	prod.description = "The most expensive smartphone";

	prod.SetPrice(4599.99);
	prod.SetDiscount(0.10);
	prod.SetQuantity(20);

	PrintProduct(prod);

	prod.SetPrice(5599.99);
	prod.SetDiscount(0.2);
	prod.SetQuantity(-20);

	PrintProduct(prod);

	List<Product> products;
	products.Add(prod);

	for (int i = 0; i < products.Count(); i++)
	{
		PrintProduct(products[i]);
	}

	if (true)
	{
		List<double> numbers(5);

		for (int i = 0; i < numbers.Size(); i++)
		{
			numbers.Add(rand() % 100);
		}

		try
		{
			cout << numbers[-5] << endl;
		}
		catch (const exception & ex)
		{
			cout << ex.what() << endl;
		}

		//numbers.ReallocateInternal();
		//
		//numbers._collection = nullptr;
		//numbers._size += 20;
		//numbers._count = 77;

		numbers.Insert(3, 11111);

		PrintArray(numbers);

		PrintArray(numbers);

		cout << "numbers._count : " << numbers.Count() << endl;
		cout << "numbers._size : " << numbers.Size() << endl;

		numbers.Reverse();

		PrintArray(numbers);



	}

	return 0;
}
