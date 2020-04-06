#pragma once

template <class T>
struct Node
{
	T _value;
	Node<T>* _next = nullptr;

	Node(T value)
	{
		_value = value;
	}
};

template <class T>
class SinglyLinkedList
{
private:
	Node<T>* _head = nullptr;
	Node<T>* _tail = nullptr;
	int _count = 0;

public:
	int Count()
	{
		return _count;
	}

	SinglyLinkedList() = default;

	SinglyLinkedList(const SinglyLinkedList<T>& other)
	{
		*this = other;
	}

	// ეს არის Move კონსტრუქტორი რომელიც rvalues-გადმოცემის დროს გამოიძახება
	// იქიდან გამომდინარე რომ rvalues დროის ძალიან მცირე პერიოდში ცოცხლობს და მაშინვე კვდება
	// კარგი იქნება თუ მოვპარავთ რესურს რომელიც შექმნა რომ ეს რესურსი ტყუილად არ გაიფლანგოს

	SinglyLinkedList(SinglyLinkedList<T>&& other) noexcept
	{
		_head = other._head;
		_tail = other._tail;
		_count = other._count;

		other._head = nullptr;
		other._tail = nullptr;
	}

	void AddLast(T item)
	{
		auto newNode = new Node<T>(item);

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

	void AddFirst(T item)
	{
		auto newNode = new Node<T>(item);

		if (_head == nullptr && _tail == nullptr)
		{
			_tail = newNode;
		}
		else
		{
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
		}

		auto  newHead = _head->_next;
		delete[] _head;
		_head = newHead;

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
		}

		auto  newtail = _head;
		while (newtail->_next != _tail)
		{
			newtail = newtail->_next;
		}

		delete[] _tail;
		_tail = newtail;
		_tail->_next = nullptr;
		_count--;

		return true;
	}

	void Clear()
	{
		while (RemoveFirst());
	}

#pragma region Operators

	SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& other) noexcept
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

	SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&& other) noexcept
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

	// 2. დაამატეთ ფუნქცია რომელიც ერთი ლისტ გარდაქმნის მეორე ლისტად და დააბრუნებს ახალს გარდაქმნილ ლისტს
	// 3. დაწერეთ იმ პირველივე ნოუდის პოვნის ფუნქცია რომელიც აკმაყოფილებს გადაცემულ კრიტერიუმს
	// 4. დაწერეთ იმ ბოლო ნოუდის პოვნის ფუნქცია რომელიც აკმატოფილებს გადაცემულ კრიტერიუმს
	// 5. დაწერეთ ფუქნცია რომელიც ყველა ისეთ ელემენტს დაბრუნებს რომლებიც აკმაყოფილებენ გადაცემულ კრიტერიუმს

#pragma endregion

	~SinglyLinkedList()
	{
		Clear();
	}
};
