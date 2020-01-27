#include <iostream>

using namespace std;

int main()
{
	int staticArray[5];  // გამოყოფს 20 (4 * 5) ბაიტს და პირველი უჯრის მისამართს შეინახავს მასივის სახელში

	int* dynamicArray = new int[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "staticArray + " << i << " = " << staticArray + i << endl;
	}


	// int* dynamicArray = (int*)malloc(sizeof(int) * 5); // malloc ფუნქცია ოპერატიულ მეხსიერებაში გამოყოფს იმდენ ბაიტს
	// რამდენსაც ეტყვით და გიბრუნებთ პირველი უჯრის მისამართს რომელიც გადამყავს int-ის მისამართი

	dynamicArray[0] = 10;
	dynamicArray[2] = 20;

	delete[]  dynamicArray;

	int first;
	int second;
	int third;

	int* arr;

	for (int i = 0; i < 5; i++)
	{
		arr = new int[10000000];
		delete[]arr;
	}






	return 0;
}