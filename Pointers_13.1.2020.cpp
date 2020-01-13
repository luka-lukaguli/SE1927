#include <iostream>

using namespace std;


int main()
{
	int number = 20;

	cout << "number value: " << number << endl;

	cout << "&number: " << &number << endl;

	int* numberAddress = &number;

	cout << "numberAddress: " << numberAddress << endl;
	cout << "*numberAddress: " << *numberAddress << endl; // გადამისამართება. ვეუბნებით რომ
	// გახსნას იმ უჯრაზე რომლის მისამართსაც ინახავს. ანუ უნდა გადახტეს იმ უჯრაზე;
	
	*numberAddress = 30;
	cout << "*numberAddress: " << *numberAddress << endl; // გადამისამართება. ვეუბნებით რომ
	cout << "number value: " << number << endl;

	/*
		დავალება: ითამაშეთ პოინტერებით :)
	
	*/


	return 0;
}

