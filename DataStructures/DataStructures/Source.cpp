#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

template <typename TNode>
void PrintNode(TNode node)
{
	cout << "{ " << node->Key << " : " << node->Value << " }" << endl;
}

void Print(BinaryTree<int, int>::Node* node)
{
	cout << node->Key << " ";
}

int main()
{
	BinaryTree<int, int> numbers;

	numbers.Add(25, 0);
	numbers.Add(30, 0);
	numbers.Add(10, 0);
	numbers.Add(3, 0);
	numbers.Add(17, 0);

	numbers.Add(27, 0);
	numbers.Add(26, 0);
	numbers.Add(29, 0);

	numbers.Add(55, 0);
	numbers.Add(53, 0);
	numbers.Add(77, 0);
	numbers.Add(54, 0);
	numbers.Add(100, 0);
	numbers.Add(32, 0);

	numbers.TraverseInOrder(Print);
	cout << endl;
	numbers.Delete(30);
	numbers.Delete(25);
	numbers.TraverseInOrder(Print);

	return 0;
}