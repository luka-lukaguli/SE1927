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

// პარამეტრად მივიღოთ იმ მასივის მისამართი რომლის ოპტიმიზაციაც გვინდა ანუ პოინტერის პოინტერი
void Optimize(char* * charArrayPtr)
{
	char* charArray = *charArrayPtr; // მასივის მისამართიდან ამოვიღეთ მასივი და შევინახეთ ცვლადში
	int length = StringLength(charArray); // გავიგეთ მასივისი სიგრძე
	int capacity = length + 1; // გავიგეთ მასივის მოცულობა
	char* temp = new char[capacity];  // შევქმენით ამ მოცულობის დროებითი მასივი

	for (int i = 0; i < capacity; i++)
	{
		// იმ მასიდან რომლის ოპტიმიზაციასაც ვცდილობთ გადმოგვაქვს თითოეული ელემენტი 
		// დროებით მასივში
		temp[i] = charArray[i];
	}

	// ვშლით ძველ მასივს
	delete[] charArray;
	*charArrayPtr = temp; // მასივის მისამართიდან გადავედით ამ მასივზე და მასში შევინახეთ ახალი მასივი.
}


char* OptimizeBadVersion(char* charArray)
{
	int length = StringLength(charArray);
	int capacity = length + 1; // გავიგეთ მასივის მოცულობა
	char* temp = new char[capacity];  // შევქმენით ამ მოცულობის დროებითი მასივი

	for (int i = 0; i < capacity; i++)
	{
		// იმ მასიდან რომლის ოპტიმიზაციასაც ვცდილობთ გადმოგვაქვს თითოეული ელემენტი 
		// დროებით მასივში
		temp[i] = charArray[i];
	}

	// ვშლით ძველ მასივს
	delete[] charArray;

	return temp;
}


int main()
{
	char* charArray = new char[100000000];
	cout << "enter text: ";
	cin >> charArray;
	cout << "charArray before : " << charArray << endl;

	Optimize(&charArray);

	cout << "charArray after: " << charArray << endl;

	int a = 10;
	int b = 20;



	return 0;
}