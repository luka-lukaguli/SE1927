#include <iostream>
using namespace std;


void Swap(int* firstAddress, int* secondAddress)
{
	int temp = *firstAddress;
	*firstAddress = *secondAddress;
	*secondAddress = temp;
}

int main()
{

	//// 3. გააკეთეთ ცვლადი, ამ ცვლადის პოინტერი და ამ პოინტერის პოინტერი.
	////    პოინტერის პოინტერის გამოყენებით შეცვალეთ ამ ცვლადის მნიშვნელობა.
	//int a = 10;

	//int* ptr = &a;  // შევქმენით პოინტერი და შევინახეთ first ცვლადის მისამართი
	//int** ptr_ptr = &ptr; //  შევქმენით პოინტერის პოინტერი და ptr პოინტერის მისამართი

	//int b = 20;
	//ptr = &b;  // პოინტერში რომელშიც ინახებოდა first ცვლადის მისამართი შევინახეთ
	//// second ცვლადის მისამართი

	//cout << "before: first = " << a << endl;   // 10
	//cout << "before: second = " << b << endl; // 20

	//**ptr_ptr = 300;  // გადავედი ptr-ზე და გადავედი second-ზე და ჩავწერე 300

	//cout << "after: first = " << a << endl;  // 10  
	//cout << "after: second = " << b << endl; // 300

	// ----------------------------------------------------------- //

	int a = 10;
	int b = 20;

	cout << "before: a = " << a << endl;
	cout << "before: b = " << b << endl;

	Swap(&a, &b);

	cout << "after: a = " << a << endl;
	cout << "after: b = " << b << endl;

	int first = a;
	int second = b;

	int temp = first;
	first = second;
	second = temp;

	int num = 1111839567;



	char* address = (char*)&num;
	cout << *(address + 3) ;
	cout << *(address + 2) ;
	cout << *(address + 1) ;
	cout << *(address + 0) << endl;



	return 0;
}