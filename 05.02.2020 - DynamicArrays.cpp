#include <iostream>

using namespace std;

int StringLength(char* charArray)
{
	int length = 0;
	while (charArray[length] != '\0')
	{
		length++;
	}
	return length;
}

int main()
{
	char* firstName = new char[50];

	cout << "Enter name: ";
	cin >> firstName;

	char* lastName = new char[50];
	cout << "Enter last name: ";
	cin >> lastName;

	int firstLength = StringLength(firstName);
	int lastLength = StringLength(lastName);
	
	int fullLength = firstLength + lastLength + 2;
	
	char* fullName = new char[fullLength];
	

	for (int i = 0; i < firstLength; i++)
	{
		fullName[i] = firstName[i];
	}

	fullName[firstLength] = ' ';

	for (int i = 0, j = firstLength + 1; j < fullLength; i++, j++)
	{
		fullName[j] = lastName[i];
	}


	cout << "Fullname: " << fullName << endl;


	char* charArray = new char[100];


	// გაიტანეთ ფუნქციაში
	// ოპტიმიზაცია
	int length = StringLength(charArray);
	int capacity = length + 1; // გავიგეთ მასივის მოცულობა
	char* temp = new char[capacity];  // შევქმენით ამ მოცულობის დროებითი მასივი
	for (int i = 0; i < capacity; i++) 
	{
		// იმ მასიდან რომლის ოპტიმიზაციასაც ვცდილობთ გადმოგვაქვს თითოეული ელემენტი 
		// დროებით მასივშ
		temp[i] = charArray[i];
	}
	// ვშლით ძველ მასივს
	delete[] charArray;
	charArray = temp; // პოინტერში რომელშიც ძველი მასივის მისამართს ვინახავდით შევინახოთ
	// ახალი მასივის მისამართი




	

	//// fistname 
	//// lastname
	//// fullname = firstname + lastname

	//// მაგ.: fistname = Bruce\0
	////		 lastname = Lee\0
	////		 fullName = Bruce Lee\0






	return 0;
}