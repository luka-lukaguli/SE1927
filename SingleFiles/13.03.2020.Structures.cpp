#include <iostream>
#include <string>

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

	// default constructor - ქვია ისეთ კონსტრუქტორს რომელსაც არ აქვს პარამეტრები
	Product()
	{
		Price = 0;
		Discount = 0;
		Quantity = 0;
	}

	// ასეთი სახის ფუნქციას ქვია "კონსტრუქტორი"
	// კონსტრუქტორს არ აქვს დასაბრუნებელი ტიპი და ყოველთვის სტრუქტურის სახელი ჰქვია
	// კონსტრუქტორი ქმნის სტრუქტურის ობიექტს.
	Product(string name, string description, double price, double discount, int quantity)
	{
		Name = name;
		Description = description;
		Price = price;
		Discount = discount;
		Quantity = quantity;
	}

	// ასეთი სახის ფუნქციას ეძახიან "მეთოდს"
	void Initialize(string name, string description, double price, double discount, int quantity)
	{
		Name = name;
		Description = description;
		Price = price;
		Discount = discount;
		Quantity = quantity;
	}

	// ასეთი სახის ფუნქციას ეძახიან "მეთოდს"
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


	// გადატვირთეთ შემდეგი ოპერატორები:
	// 1. > , < , >= , <= , == , != 
	// 2. + , - , +=, -=

	// ასეთი სახის ფუნქციას ეძახიან "ოპერატორს"
	// ოპერატორს სახელის დარქმევის წესია "operator" + "სიმბოლო"
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

	Product operator+=(const Product& other)
	{
		Price += other.Price;
		// this სტრუქტურის შიგნით ინახავას იმ ობიექტის მისამართს რომლიდანაც გამოიძახეს ფუნქცია
		return *this;
	}



	Product operator-=(const Product& other)
	{
		Price -= other.Price;
		return *this;
	}

	Product operator+(const Product& other)
	{
		Product result;
		result.Price = Price + other.Price;
		return result;
	}

	Product operator-(const Product& other)
	{
		Product result;
		result.Price = Price - other.Price;
		return result;
	}
};


bool Equals(Product prod1, Product prod2)
{
	return prod1.Price == prod2.Price;
}

struct Point
{
	double X;
	double Y;

	Point(double x, double y)
	{
		X = x;
		Y = y;
	}

	Point() {
		X = 0;
		Y = 0;
	}
};

int main()
{
	int number;
	number = 10;

	int otherNumber = 20;


	Product prod1("Iphone X", "The best Iphone X", 3299.99, 0.05, 20);
	//prod1.Initialize("Iphone X", "The best Iphone X", 3299.99, 0.05, 20);

	Product prod2;
	prod2.Initialize("Galaxy Note 10", "The most powerfull smartphone", 3599.99, 0.01, 10);
	prod1.Initialize("Iphone XI", "New Version of Iphone", 7799.99, 0.00, 20);


	// Product prod3 = prod1.operator+=(prod2);
	Product prod3 = prod1 += prod2;

	prod2 += prod3;


	if (prod1.Equal(prod2))
	{
		cout << prod1.Name << " costs same as " << prod2.Name;
	}

	if (prod1 > prod2)
	{
		cout << prod1.Name << " is more expensive than " << prod2.Name;
	}

	if (prod1.IsMoreThan(prod2))
	{
		cout << prod1.Name << " is more expensive than " << prod2.Name;
	}

	if (prod1.IsLessThan(prod2))
	{
		cout << prod1.Name << " is cheaper than " << prod2.Name;
	}


	/*

		********************დავალება********************

		გააკეთეთ წერტილის სტრუქტურა რომელიც აღწერს ორგანზომილებიან წერტილს რომელსაც აქვს
		შემდეგი ველები:

		o  X - x კოორდინატი
		o  Y - y კოორდინატი

		განსაზღვრეთ მიმატების ოპერატორი
		განსაზღვრეთ გამოკლების ოპერატორი
		განსაზღვრეთ გამრავლების ოპერატორი
		განსაზღვრეთ გაყოფის ოპერატორი

		განსაზღვრეთ ტოლობის (==) ოპერატორი
		განსაზღვრეთ არუდრის (!=) ოპერატორი
		განსაზღვრეთ მეტობის ოპერატორი
		განსაზღვრეთ ნაკლებობის ოპერატორი
		განსაზღვრეთ მეტობა-ტოლობის ოპერატორი
		განსაზღვრეთ ნაკლებობა-ტოლობის ოპერატორი

	*/
	
	Point a(10, 20);
	
	Point b(15, 17);

	
		
	return 0;
}