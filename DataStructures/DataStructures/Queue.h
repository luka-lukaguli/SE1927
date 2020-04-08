#pragma once
#include "SinglyLinkedList.h"

template <typename T>
class Queue
{
private:
	SinglyLinkedList<T> _collection;

public:
	void Enqueue(T item)
	{
		_collection.AddLast(item);
	}

	T Dequeue()
	{
		auto item = _collection.First();
		_collection.RemoveFirst();
		return item;
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
