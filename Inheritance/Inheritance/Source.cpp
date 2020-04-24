#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace  std;

// https://www.learncpp.com/cpp-tutorial/115-inheritance-and-access-specifiers/  --- private, protected, public

class Animal
{
protected:
	int _age;

public:
	int _weight;

	int GetAge()
	{
		return _age;
	}

	void SetAge(int age)
	{
		if (age >= 0 && age <= 20)
		{
			_age = age;
		}
	}

	void Walk()
	{
		cout << "Walking" << endl;
	}

	void Eat()
	{
		cout << "Eating" << endl;
	}

	void Sleep()
	{
		cout << "Sleeping" << endl;
	}
};

// მემკვიდრეობა -- "არის" მიმართება
class Cat : public Animal  // Cat არის Animal
{
public:
	void Mew()
	{
		cout << "Mew, Mew..." << endl;
	}

	Cat(int age, int weight)
	{
		SetAge(age);
		_weight = weight;
	}

	void Info()
	{
		cout << "Hello I am cat. My age is " << _age << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(int age, int weight)
	{
		SetAge(age);
		_weight = weight;
	}

	void Bark()
	{
		cout << "Wauf, Wauf!!!" << endl;
	}

	void Info()
	{
		cout << "Hello I am dog. My age is " << _age << endl;
	}
};

class Address
{
public:
	string country;
	string city;
	string postalCode;
	string street;
};

// კომპოზიცია -- "აქვს" მიმართება
class Customer
{
public:
	Address address; // Customer-ს აქვს Address
	string firstname;
	string lastname;
	string phoneNumber;
};

void AnimalActions(Animal* animal)
{
	if (animal == nullptr)
		return;

	cout << "Age: " << animal->GetAge() << endl;
	cout << "Weight: " << animal->_weight << endl;

	animal->Eat();
	animal->Sleep();
	animal->Walk();
}

vector<string> Split(const string& line, const string& separator = " ")
{
	vector<string> result;

	int start = 0;
	int end = 0;

	int length = line.length();
	while (end != length)
	{
		end = line.find(separator, start);

		if (end < 0)
			end = length;

		result.push_back(line.substr(start, end - start));
		start = end + 1;
	}

	return result;
}

int main()
{
	Split("Hello World! how are you?", " ");

	int n;

	ifstream fin("numbers.txt");

	ofstream fout("data.csv");

	string line;

	vector<Customer> customers;

	while (!fin.eof())
	{
		getline(fin, line);
		auto data = Split(line, ",");

		Customer customer;
		customer.firstname = data[0];
		customer.lastname = data[1];
		customer.phoneNumber = data[2];
		customer.address.country = data[3];
		customer.address.city = data[4];
		customer.address.street = data[5];

		customers.push_back(customer);
	}

	sort(customers.begin(), customers.end(),
		[](Customer& left, Customer& right) {return left.firstname > right.firstname; });

	fout << "street" << "," << "firstname" << "," << "lastname" << endl;
	for (auto& customer : customers)
	{
		fout << customer.address.street << "," << customer.firstname << "," << customer.lastname << endl;
	}

	//cout << "Hello World" << endl;

	fin.close();

	return 0;
}