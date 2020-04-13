#include <iostream>
#include "BinaryTree.h"

using namespace std;

void Function(int number)
{
	if (number == 0)
		return;
	Function(number - 1);
	cout << "Inside Function " << number << endl;
}

int Factorial(int number)
{
	if (number == 0)
		return 1;
	return number * Factorial(number - 1);
}

int Sum(int number)
{
	if (number == 0)
		return 0;
	return number + Sum(number - 1);
}
typedef BinaryTree<int, double>::Node* node;

void Print(node n)
{
	cout << n->Key << " ";
}

int main()
{
	BinaryTree<int, double> numbers;

	numbers.Add(25, 0);
	numbers.Add(10, 0);
	numbers.Add(30, 0);
	numbers.Add(3, 0);

	numbers.TraverseInOrder([](node n) {cout << n->Key << " "; });
	cout << "\n------------------------\n";
	numbers.TraversePreOrder([](node n) {cout << n->Key << " "; });
	cout << "\n------------------------\n";

	numbers.TraversePostOrder([](node n) {cout << n->Key << " "; });

	return 0;
}