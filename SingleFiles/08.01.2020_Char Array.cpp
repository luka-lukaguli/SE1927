#include <iostream>

using namespace std;


// 1. დაწერეთ ფუნქცია რომელიც იპოვის სტრინგის სიგრძე
int StringLength(char charArray[])
{
	int length = 0;
	while (charArray[length] != '\0')
	{
		length++;
	}
	return length;
}

//             ***  საახალწლო დავალება ***
// 1. დაწერეთ ფუნქცია რომელიც ერთ სტრინგს დააკოპირებს მეორეში
void StringCopy(char source[], char destination[])
{
	// პირველი ვარიანტი
	int i = -1;
	do
	{
		i++;
		destination[i] = source[i];
	} while (source[i] != '\0');

	// მეორე ვარიანტი
	/*int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = source[i];*/
}

// 2. დაწერეთ ფუნქცია რომელიც დაითვლის რამდენჯერ მეორდება გადაცემული
//    სიმბოლო სტრინგში
int CountSymbol(char charArray[], char symbol)
{
	int count = 0;
	for (int i = 0; charArray[i] != '\0'; i++)
	{
		if (charArray[i] == symbol)
		{
			count++;
		}
	}
	return count;
}

// 3. დაწერეთ ფუნქცია რომელიც გადაცემულ სტრინგში გადაცემულ სიმბოლოს შეცვლის
//    მეორე გადაცემული სიმბოლოთი
//    მაგ: Lenovo გადავცემ o-ს და გადავცემ i-ს შედეგი უნდა იყოს Lenivi
void ReplaceSymbol(char charArray[], char oldChar, char newChar)
{
	for (int i = 0; charArray[i] != '\0'; i++)
	{
		if (charArray[i] == oldChar)
		{
			charArray[i] = newChar;
		}
	}
}

// 4. დაწერეთ ფუნქცია რომელიც გვეტყვის(დააბრუნებს) არის თუ არა გადაცემული სიმბოლო
//    დიდი ასო
bool IsUpper(char symbol)
{
	return symbol >= 'A' && symbol <= 'Z';
}

bool IsLower(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}

// 5. დაწერეთ ფუნქცია რომელიც გვეტყვის ტექსტის ყველა სიმბოლო არის თუ არა დიდი ასო
bool IsUpper(char charArray[])
{
	for (int i = 0; charArray[i] != '\0'; i++)
	{
		if (!IsUpper(charArray[i]))
		{
			return false;
		}
	}
	return true;
}

// 6. დაწერეთ ფუნქცია რომელიც ერთ ცალ გადაცემულ სიმბოლოს გადაიყვანს პატარა
//    ასოში და დააბრუნებს
char ToLower(char letter)
{
	if (IsUpper(letter))
	{
		return letter + ('a' - 'A');
	}
	return letter;
}

char ToUpper(char letter)
{
	if (IsLower(letter))
	{
		return letter - ('a' - 'A');
	}
	return letter;
}

// 7. დაწერეთ ფუნქცია რომელიც სტრინგში პატარა ასოებს გადაიყვანს დიდ ასოებში
void ToUpper(char charArray[])
{
	for (int i = 0; charArray[i] != '\0'; i++)
	{
		charArray[i] = ToUpper(charArray[i]);
	}
}

// 8. დაწერეთ ფუნქცია რომელიც სტრინგში დიდ ასოებს გადაიყვანს პატარა ასოებში
void ToLower(char charArray[])
{
	for (int i = 0; charArray[i] != '\0'; i++)
	{
		charArray[i] = ToLower(charArray[i]);
	}
}
int main()
{
	const int size = 20;
	char text[size] = "Hello World!";

	cout << text << endl;

	char textCopy[size];
	StringCopy(text, textCopy);

	cout << "text : " << text << endl;
	cout << "text Copy: " << textCopy << endl;

	int count = CountSymbol(text, 'l');

	ReplaceSymbol(text, 'l', 'L');
	cout << "text : " << text << endl;

	IsUpper(text);

	cout << ToLower('H');
	cout << ToLower('i');
	cout << ToLower('!');

	cout << endl;

	cout << ToUpper('H');
	cout << ToUpper('i');
	cout << ToUpper('!');
	
	cout << endl;

	ToUpper(text);
	cout << text << endl;

	ToLower(text);
	cout << text << endl;


	return 0;
}