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
	int Count()
	{
		return _count;
	}

	SinglyLinkedList() = default;

	SinglyLinkedList(const SinglyLinkedList& other)
	{
		*this = other;
	}

	// ეს არის Move კონსტრუქტორი რომელიც rvalues-გადმოცემის დროს გამოიძახება
	// იქიდან გამომდინარე რომ rvalues დროის ძალიან მცირე პერიოდში ცოცხლობს და მაშინვე კვდება
	// კარგი იქნება თუ მოვპარავთ რესურს რომელიც შექმნა რომ ეს რესურსი ტყუილად არ გაიფლანგოს

	SinglyLinkedList(SinglyLinkedList&& other)
	{
		// დაწერეთ მოპარვის ლოგიკა და იგივე გააკეთეთ მინიჭების ოპერატორისთვის
	}

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
		Node* iterator = _head;

		while (iterator != nullptr)
		{
			action(iterator->_value);
			iterator = iterator->_next;
		}
	}

	bool RemoveFirst()
	{
		if (_head == nullptr)
			return false;

		if (_head == _tail)
		{
			_tail = nullptr;
		}

		Node* newHead = _head->_next;
		delete[] _head;
		_head = newHead;

		_count--;
		return true;
	}

	void Clear()
	{
		while (RemoveFirst());
	}

#pragma region Operators

	void operator=(const SinglyLinkedList& other)
	{
		Clear();

		Node* begin = other._head;

		while (begin != nullptr)
		{
			AddLast(begin->_value);
			begin = begin->_next;
		}
	}

	void operator=(SinglyLinkedList&& other)
	{
		// დასამთავრებელია
	}
	// 0. გადააკეთეთ Template-ად, რომ ნებისმიერი ტიპების შენახვა შევძლოთ, ეხლა მარტო double-ზე მუშაობს
	// 1. დაამატეთ ბოლოდან წაშლის ლოგიკა
	// 2. დაამატეთ ფუნქცია რომელიც ერთი ლისტ გარდაქმნის მეორე ლისტად და დააბრუნებს ახალს გარდაქმნილ ლისტს
	// 3. დაწერეთ იმ პირველივე ნოუდის პოვნის ფუნქცია რომელიც აკმატოფილებს გადაცემულ კრიტერიუმს
	// 4. დაწერეთ იმ ბოლო ნოუდის პოვნის ფუნქცია რომელიც აკმატოფილებს გადაცემულ კრიტერიუმს
	// 5. დაწერეთ ფუქნცია რომელიც ყველა ისეთ ელემენტს დაბრუნებს რომლებიც აკმაყოფილებენ გადაცემულ კრიტერიუმს

#pragma endregion

	~SinglyLinkedList()
	{
		Clear();
	}
};
