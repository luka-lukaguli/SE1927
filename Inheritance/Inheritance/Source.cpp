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
	int _age = 0;

public:
	int _weight;

	int GetAge()
	{
		return _age;
	}

	virtual void SetAge(int age)
	{
		if (age >= 0 && age <= 20)
		{
			_age = age;
		}
	}

	// წმინდა ვირტუალური ფუნქცია --- იგივე აბსტრაქტული ფუნქცია
	virtual void MakeVoice() = 0;

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

// კითხვა: არის Cat (კატა) კლასი Animal (ცხოველი) ???
// პასუხი: კი
// თუ ამ კითხვაზე პასუხი არის "კი", მაშინ შეგვიძლია გამოვიყენოთ მემკვიდრეობა
//
// მემკვიდრეობა -- "არის" მიმართება
class Cat : public Animal  // Cat არის Animal --- ':' -ეს სიმბოლო ამ შემთხვევაში ნიშნავს სიტყვარ 'არის'
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

	void MakeVoice()
	{
		Mew();
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

	void MakeVoice()
	{
		Bark();
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

//    მემკვიდრე (შვილი - child) : მშობელი (parent)
//    წარმოებული (derived) : საბაზისო(base)
class Mouse : public Animal
{
public:

	void SetAge(int age)
	{
		if (age >= 0 && age <= 3)
		{
			_age = age;
		}
	}

	void MakeVoice()
	{
		cout << "wrip... wrip..." << endl;
	}
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

vector<string> Split(const string& line, const string& separator = " ");

class Logger
{
public:
	virtual void Log(const char* text) = 0;
};

void ConsoleLog(const char* text)
{
	cout << text;
}

class ConsoleLogger : public  Logger
{
public:
	void Log(const char* text)
	{
		cout << text;
	}
};

class FileLogger : public Logger
{
private:
	ofstream fout;

public:

	FileLogger(const char* filename)
	{
		fout.open(filename);
	}

	void Log(const char* text)
	{
		fout << text;
	}

	~FileLogger()
	{
		fout.close();
	}
};

class Worker
{
public:
	void Work(Logger& logger)
	{
		// working...
		logger.Log("Work started\n");
		// working...
		logger.Log("Working\n");

		// working...
		logger.Log("Work finished\n");
	}
};

class Programmer
{
public:
	virtual void WriteCode() = 0;
};

class CSharpProgrammer : public Programmer
{
public:
	virtual void WriteCode()
	{
		cout << "C# code" << endl;
	}
};

class CppProgrammer : public Programmer
{
public:
	virtual void WriteCode()
	{
		cout << "C++ code" << endl;
	}
};

class Employee :public CSharpProgrammer, public CppProgrammer
{
public:
};

int main()
{
	Employee* programmer = new Employee();
	//programmer->WriteCode(); // Diamond Problem

	Animal* animal = new Dog(10, 25);

	cout << "animal age: " << animal->GetAge() << endl;

	cout << "1 year later" << endl;

	animal->SetAge(11);
	cout << "animal age: " << animal->GetAge() << endl;

	animal->MakeVoice();

	Mouse* mouse = new Mouse();
	mouse->SetAge(5);
	cout << "mouse age: " << mouse->GetAge() << endl;

	animal = mouse;

	animal->MakeVoice();

	animal->SetAge(5);
	cout << "animal age: " << animal->GetAge() << endl;

	Worker worker;

	FileLogger file_logger("27.08.2020.txt");
	ConsoleLogger console_logger;

	//worker.Work(file_logger);
	worker.Work(file_logger);
	worker.Work(console_logger);

	return 0;
}

vector<string> Split(const string& line, const string& separator)
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