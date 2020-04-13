#pragma once

#include <iostream>

template <typename TKey, typename TValue>
class BinaryTree
{
public:
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

private:
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

	template <typename Action>
	void TraverseInOrder(Action action)
	{
		TraverseInOrder(root, action);
	}

	template <typename Action>
	void TraversePreOrder(Action action)
	{
		TraversePreOrder(root, action);
	}

	template <typename Act>
	void TraversePostOrder(Act action)
	{
		TraversePostOrder(root, action);
	}

	template <typename Action>
	void TraversePostOrder(Node* theRoot, Action action)
	{
		if (theRoot == nullptr)
			return;
		TraverseInOrder(theRoot->Left, action);
		TraverseInOrder(theRoot->Right, action);
		action(theRoot);
	}

	template <typename Action>
	void TraversePreOrder(Node* theRoot, Action action)
	{
		if (theRoot == nullptr)
			return;
		action(theRoot);
		TraverseInOrder(theRoot->Left, action);
		TraverseInOrder(theRoot->Right, action);
	}

	template <typename Action>
	void TraverseInOrder(Node* theRoot, Action a)
	{
		if (theRoot == nullptr)
			return;
		TraverseInOrder(theRoot->Left, a);
		a(theRoot);
		TraverseInOrder(theRoot->Right, a);
	}
};
