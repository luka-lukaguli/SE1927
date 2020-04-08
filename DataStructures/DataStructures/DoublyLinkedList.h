#pragma once

template <class T>
class DoublyLinkedList
{
public:
	struct Node
	{
		T _value;
		Node* _next = nullptr;
		Node* _previous = nullptr;

		Node(T value)
		{
			_value = value;
		}
	};

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;
	int _count = 0;

public:
	int Count()
	{
		return _count;
	}

	DoublyLinkedList() = default;

	DoublyLinkedList(const DoublyLinkedList<T>& other)
	{
		*this = other;
	}

	// ეს არის Move კონსტრუქტორი რომელიც rvalues-გადმოცემის დროს გამოიძახება
	// იქიდან გამომდინარე რომ rvalues დროის ძალიან მცირე პერიოდში ცოცხლობს და მაშინვე კვდება
	// კარგი იქნება თუ მოვპარავთ რესურს რომელიც შექმნა რომ ეს რესურსი ტყუილად არ გაიფლანგოს

	DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept
	{
		_head = other._head;
		_tail = other._tail;
		_count = other._count;

		other._head = nullptr;
		other._tail = nullptr;
	}

	void AddLast(T item)
	{
		auto newNode = new Node(item);

		if (_head == nullptr && _tail == nullptr)
		{
			_head = newNode;
		}
		else
		{
			_tail->_next = newNode;
			newNode->_previous = _tail;
		}
		_tail = newNode;
		_count++;
	}

	void AddFirst(T item)
	{
		auto newNode = new Node(item);

		if (_head == nullptr && _tail == nullptr)
		{
			_tail = newNode;
		}
		else
		{
			_head->_previous = newNode;
			newNode->_next = _head;
		}
		_head = newNode;
		_count++;
	}

	template <typename Action>
	void Foreach(Action action)
	{
		auto iterator = _head;

		while (iterator != nullptr)
		{
			action(iterator->_value);
			iterator = iterator->_next;
		}
	}

	bool RemoveFirst() noexcept
	{
		if (_head == nullptr)
			return false;

		if (_head == _tail)
		{
			_tail = nullptr;
			delete _head;
			_head = nullptr;
		}
		else
		{
			_head = _head->_next;
			delete _head->_previous;
			_head->_previous = nullptr;
		}

		_count--;
		return true;
	}

	bool RemoveLast() noexcept
	{
		if (_head == nullptr)
			return false;

		if (_head == _tail)
		{
			_tail = nullptr;
			delete _head;
			_head = nullptr;
		}
		else
		{
			_tail = _tail->_previous;
			delete _tail->_next;
			_tail->_next = nullptr;
		}

		_count--;
		return true;
	}

	void Clear()
	{
		while (RemoveFirst());
	}

	// ერთი ლისტ გარდაქმნის მეორე ლისტად და აბრუნებს ახალს გარდაქმნილ ლისტს
	// transformFunction: ფუნქცია რომელიც ერთ ობიექტს გადაიყვანს მეორე იმავე ან სხვა ტიპის ობიექტში
	template<class TResult, class TransformFunction>
	DoublyLinkedList<TResult> Transform(TransformFunction transformFunction)
	{
		DoublyLinkedList<TResult> resultList;

		for (auto iterator = _head; iterator != nullptr; iterator = iterator->_next)
		{
			auto result = transformFunction(iterator->_value);
			resultList.AddLast(result);
		}
		return resultList;
	}

	// პოულობს პირველივე ნოუდს რომელიც აკმაყოფილებს გადაცემულ კრიტერიუმს
	template <typename Predicate>
	Node* FindFirst(Predicate predicate)
	{
		for (auto iterator = _head; iterator != nullptr; iterator = iterator->_next)
		{
			if (predicate(iterator->_value))
			{
				return iterator;
			}
		}
		return nullptr;
	}

	// პოულობს ბოლო ნოუდს რომელიც აკმაყოფილებს გადაცემულ კრიტერიუმს
	template <typename Predicate>
	Node* FindLast(Predicate predicate)
	{
		Node* result = nullptr;
		for (auto iterator = _head; iterator != nullptr; iterator = iterator->_next)
		{
			if (predicate(iterator->_value))
			{
				result = iterator;
			}
		}
		return result;
	}

	// პოულობს ყველა ნოუდს რომელიც აკმაყოფილებს გადაცემულ კრიტერიუმს
	template <typename Predicate>
	DoublyLinkedList<T> FindAll(Predicate predicate)
	{
		DoublyLinkedList<T> result;
		for (auto iterator = _head; iterator != nullptr; iterator = iterator->_next)
		{
			if (predicate(iterator->_value))
			{
				result.AddLast(iterator->_value);
			}
		}
		return result;
	}

#pragma region Operators

	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other) noexcept
	{
		if (this == &other)
			return *this;

		Clear();

		auto begin = other._head;

		while (begin != nullptr)
		{
			AddLast(begin->_value);
			begin = begin->_next;
		}
		return *this;
	}

	DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& other) noexcept
	{
		if (this == &other)
			return *this;

		Clear();

		_head = other._head;
		_tail = other._tail;
		_count = other._count;

		other._head = nullptr;
		other._tail = nullptr;

		return *this;
	}

#pragma endregion

	~DoublyLinkedList()
	{
		Clear();
	}
};
