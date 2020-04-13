#pragma once

template <typename TKey, typename TValue>
class BinaryTree
{
	struct Node
	{
		TKey Key;
		TValue Value;
		Node* Left = nullptr;
		Node* Right = nullptr;

		Node(TKey key, TValue value)
		{
			Key = key;
			Value = value;
		}
	};

	Node* root = nullptr;
	int count = 0;

public:

	bool Add(TKey key, TValue value)
	{
		if (root == nullptr)
		{
			root = new Node(key, value);
			count++;
			return true;
		}

		auto current = root;
		auto parent = current;

		bool isLeftNode = false;
		while (current != nullptr)
		{
			parent = current;
			if (key < current->Key)
			{
				current = current->Left;
				isLeftNode = true;
			}
			else if (key > current->Key)
			{
				current = current->Right;
				isLeftNode = false;
			}
			else
				return false;
		}

		if (isLeftNode)
			parent->Left = new Node(key, value);
		else
			parent->Right = new Node(key, value);

		count++;
		return true;
	}
};
