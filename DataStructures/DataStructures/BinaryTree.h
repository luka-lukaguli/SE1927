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

	int Count() { return count; }

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

	Node* BinarySearch(TKey key)
	{
		return BinarySearch(key, root);
	}

	// ReSharper disable once CppNotAllPathsReturnValue
	Node* BinarySearch(TKey key, Node* current, Node*& parent)
	{
		if (current == nullptr)
			return nullptr;

		if (key == current->Key)
			return current;

		parent = current;
		if (key < current->Key)
			return BinarySearch(key, current->Left, parent);

		if (key > current->Key)
			return BinarySearch(key, current->Right, parent);
	}

	bool IsLeaf(Node* node)
	{
		return node->Right == nullptr && node->Left == nullptr;
	}

	bool IsSingleParent(Node* node)
	{
		return !IsDoubleParent(node) && !IsLeaf(node);
	}

	bool IsDoubleParent(Node* node)
	{
		return node->Right != nullptr && node->Left != nullptr;
	}

	void Delete(TKey key)
	{
		auto parent = root;
		auto nodeTodelete = BinarySearch(key, root, parent);

		DeleteNode(nodeTodelete, parent);
	}

	void DeleteNode(Node* nodeToDelete, Node* parentNode)
	{
		if (nodeToDelete == nullptr)
			return;

		if (IsLeaf(nodeToDelete))
			DeleteLeaf(nodeToDelete, parentNode);
		else if (IsSingleParent(nodeToDelete))
			DeleteSingleParent(nodeToDelete, parentNode);
		else if (IsDoubleParent(nodeToDelete))
			DeleteDoubleParent(nodeToDelete, parentNode);
		count--;
	}

	void DeleteLeaf(Node* nodeToDelete, Node* parentNode)
	{
		if (root == nodeToDelete)
			root = nullptr;
		else if (parentNode->Left == nodeToDelete)
			parentNode->Left = nullptr;
		else
			parentNode->Right = nullptr;

		delete nodeToDelete;
	}

	void DeleteSingleParent(Node* nodeToDelete, Node* parentNode)
	{
		auto childNode = nodeToDelete->Left != nullptr ? nodeToDelete->Left : nodeToDelete->Right;

		if (nodeToDelete == root)
		{
			root = childNode;
			delete nodeToDelete;
			return;
		}

		if (parentNode->Left == nodeToDelete)
			parentNode->Left = childNode;
		else
			parentNode->Right = childNode;

		delete nodeToDelete;
	}

	void DeleteDoubleParent(Node* nodeToDelete, Node* parentNode)
	{
		auto substituteParent = nodeToDelete->Right;
		auto substitute = Min(nodeToDelete->Right, substituteParent);
		if (substitute != substituteParent)
			substituteParent->Left = substitute->Right;

		substitute->Left = nodeToDelete->Left;
		substitute->Right = nodeToDelete->Right;

		if (nodeToDelete == root)
		{
			root = substitute;
		}
		else
		{
			if (parentNode->Left == nodeToDelete)
				parentNode->Left = substitute;
			else
				parentNode->Right = substitute;
		}
		delete nodeToDelete;
	}

	Node* Min(Node* current, Node*& parent)
	{
		if (current->Left == nullptr)
			return current;
		parent = current;
		return Min(current->Left, parent);
	}

	Node* Max(Node* current, Node*& parent)
	{
		if (current->Right == nullptr)
			return current;
		parent = current;
		return Max(current->Right, parent);
	}
};
