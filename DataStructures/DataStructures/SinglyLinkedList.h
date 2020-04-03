#pragma once

struct Node
{
	double _value;
	Node* _next = nullptr;

	Node(double value)
	{
		_value = value;
	}
};

class SinglyLinkedList
{
private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
	int _count = 0;

public:
	void AddLast(double item)
	{
		Node* newNode = new Node(item);

		if (_head == nullptr && _tail == nullptr)
		{
			_head = newNode;
		}
		else
		{
			_tail->_next = newNode;
		}
		_tail = newNode;
		_count++;
	}

	void AddFirst(double item)
	{
		Node* newNode = new Node(item);

		// დაასრულეთ თავში დამატება
	}
};
