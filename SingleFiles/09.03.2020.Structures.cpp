#include <iostream>
#include <string>


using namespace std;

/*
	სახელი
	გვარი
	ასაკი
	ქულა
*/

struct Course
{
	string Name;
	int length;
	int credit;
	string lecturer;
};

struct Student
{
	Course major;
	Course minor;

	string FirstName;
	string LastName;
	int	Age;
	double Score;
	bool IsMarried;
};

void PrintStudent(string firstName, string lastName, int age, double score)
{
	cout << firstName << " " 
		<< lastName << " " 
		<< age << " " 
		<< score << endl;
}

void PrintStudent(Student stud)
{
	cout << stud.FirstName << " "
		<< stud.LastName << " "
		<<stud.Age << " "
		<< stud.Score << endl;
}

Student CreateStudent()
{
	Student newStudent;
	cout << "Enter first name: ";
	cin >> newStudent.FirstName;
	
	cout << "Enter last name: ";
	cin >> newStudent.LastName;

	cout << "Enter age: ";
	cin >> newStudent.Age;

	cout << "Enter score: ";
	cin >> newStudent.Score;

	return newStudent;
}

int main()
{
	/*Student student = CreateStudent();
	PrintStudent(student);*/

	// Daviti
	int age = 25;
	double score = 55.7;
	string firstName = "Davit";
	string lastName = "Margvelashvili";

	int age2 = 25;
	double score2 = 55.7;
	string firstName2 = "Davit";
	string lastName2 = "Margvelashvili";

	Course programming;
	programming.credit = 5;
	programming.Name = "Programming Basics";
	programming.length = 6;
	programming.lecturer = "Davit Margvelashvili";

	Course it;
	it.credit = 10;
	it.Name = "IT Essentials";
	it.length = 12;
	it.lecturer = "Zura Dzuliashvili";


	Student giorgi;
	giorgi.FirstName = "Giorgi";
	giorgi.LastName = "Giorgadze";
	giorgi.Age = 25;
	giorgi.Score = 55.7;
	giorgi.major = programming;
	giorgi.minor = it;

	cout << giorgi.major.lecturer << endl;

	PrintStudent("Davit", "Margvelashvili", 25, 55.7);
	PrintStudent(giorgi);

	/*
		1) შექმენით პროდუქტის სტრუქტურა რომელსაც ექნება შემდეგი მახასიათბლები:

		o. დასახელება;
		o. აღწერა;
		o. ფასი;
		o. ფასდაკლება;
		o. რაოდენობა;
		

		2) შექმენით კლიენტის სტრუქტურა რომელსაც ექნება შემდეგი მახასიათბლები:

		o. სახელი
		o. გვარი
		o. ელ-ფოსტა
		o. მისმართი
		o. თანხა (ბალანსი)
	
	*/

	return 0;
}