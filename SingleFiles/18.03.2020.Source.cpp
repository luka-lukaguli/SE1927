#include <iostream>
#include <string>
#include "18.03.2020.Array.h"

using namespace std;

struct Product
{
	string Name;
	double Price;
	int Quantity;

	// Overloaded Constructor
	Product(string name, double price, int quantity)
	{
		Name = name;
		Price = price;
		Quantity = quantity;
	}

	// Overloaded Constructor
	Product(string name, double price)
	{
		Name = name;
		Price = price;
		Quantity = 0;
	}

	// Overloaded Constructor
	Product(int quantity)
	{
		Quantity = quantity;
	}

	void Initialize(string name, double price, int quantity)
	{
		Name = name;
		Price = price;
		Quantity = quantity;
	}

	// Default Constructor
	Product()
	{
		Price = 0;
		Quantity = 0;
	}

	// Copy Constructor ეს არის ძალიან მნიშნველოვანი ტიპი თუმცა აქ არ გვჭირდება
	Product(const Product& other)
	{
		Name = other.Name;
		Price = other.Price;
		Quantity = other.Quantity;
	}

	void CopyFrom(const Product& other)
	{
		Name = other.Name;
		Price = other.Price;
		Quantity = other.Quantity;
	}

	// გადატვირთული მინიჭების ოპერატორი -- ესეც არის ძალიან მნიშნველოვანი ტიპი თუმცა 
	// აქ ესეც არ გვჭირდება
	void operator=(const Product& other)
	{
		Name = other.Name;
		Price = other.Price;
		Quantity = other.Quantity;
	}

	void operator=(int quantity)
	{

		Quantity = quantity;
	}
};

void PrintWithReference(Product& p)
{
	// რაღაცას აკეთებს
}

void Print(Product p)
{
	// რაღაცას აკეთებს
}





int main()
{
	Product prod;
	prod.Name = "Keyboard";
	prod.Price = 129.99;
	prod.Quantity = 20;

	Product otherProd("keyboard", 219.99, 20);


	if (true)
	{
		Array numbers(5);

		for (int i = 0; i < numbers._size; i++)
		{
			//numbers._collection[i] = rand() % 100;
			numbers[i] = rand() % 100;
		}


		for (int i = 0; i < numbers._size; i++)
		{
			cout << numbers._collection[i] << " ";
		}
		cout << endl;

		// აქ ვიყენებთ numbers მასივი

		// აქ კიდევ უფრო მაგრად ვიყენებთ numbers მასივი

		// გამოყენებას რომ დავამთავრებ უეჭველი უნდა წავშალო თორემ memory leak იქნება
		delete[] numbers._collection;
	}

#pragma region Product

	//
	//Product product1("Keyboard", 259.99, 10); // გამოიძახება გადატვირთული კონსტრუქტორი
	//product1.Initialize("Keyboard", 259.99, 10);
	//product1.Initialize("Keyboard", 259.99, 10);
	//product1.Initialize("Keyboard", 259.99, 10);

	//Print(product1); // გამოიძახება კოპი კონსტრუქტორი
	//PrintWithReference(product1); // **** არა არა და არ **** გამოიძახება კოპი კონსტრუქტორი

	//Product product_Quantity(7); // გამოიძახება გადატვირთული კონსტრუქტორი
	//Product productQuantity = 7; // გამოიძახება გადატვირთული კონსტრუქტორი

	//product_Quantity = 9; // გამოიძახება მინიჭების ოპერატორი რომელიც გადატვირთულია int-სთვის

	//Product product2(product1); // გამოიძახება კოპი კონსტრუქტორი
	//Product product4 = product1; // გამოიძახება კოპი კონსტრუქტორი

	//Product product3; // გამოიძახება default კონსტრუქტორი
	//product3 = product2; // გამოიძახება მინიჭების ოპერატორი

	//product2.CopyFrom(product1);
	//product2.CopyFrom(product1);
	//product2.CopyFrom(product1);

	//  
#pragma endregion



	return 0;
}
