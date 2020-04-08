#pragma once
#include "SinglyLinkedList.h"

template <typename T>
class Stack
{
private:
	SinglyLinkedList<T> _collection;

public:

	void Push(T item)
	{
		_collection.AddFirst(item);
	}

	T Pop()
	{
		auto item = _collection.First();
		_collection.RemoveFirst();
		return item;
	}

	T Peek()
	{
		return _collection.First();
	}

	void Clear()
	{
		_collection.Clear();
	}

	int Count()
	{
		return _collection.Count();
	}
};