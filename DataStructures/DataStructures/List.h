#pragma once
#include <exception> // ჩავრთოთ გამონაკლისების ბიბლიოთეკა იმისთვის რომ გამონაკლისი ვისროლოთ

template <typename T>
class List
{
private:
	int _size = 0; //  მასივის მოცულობას აღნიშნავს
	T* _collection = nullptr;
	int _count = 0; // მასივში მიმდინარე ელემენტების რაოდენობას აღნიშნავს

public:
	// default კონსტრუქტორი
	List()
	{
	}

	// გადარვირთული კონსტრუქტორი
	List(int size)
	{
		if (size <= 0)
			throw std::exception("size must be more than zero");
		_size = size;
		_collection = new T[_size]; // დინამიური მასივი
	}

	// copy კონსტრუქტორი
	List(const List<T>& other) noexcept
	{
		_size = other._count;
		_count = other._count;
		_collection = new T[_size];

		for (int i = 0; i < _count; i++)
		{
			_collection[i] = other._collection[i];
		}
	}

	List(List<T>&& other) noexcept
	{
		_size = other._count;
		_count = other._count;
		_collection = other._collection;

		other._collection = nullptr;
	}

	// დესტრუქტორი
	~List()
	{
		// გამოყენებას რომ დავამთავრებ უეჭველი უნდა წავშალო თორემ memory leak იქნება
		delete[] _collection;
	}

	List<T>& operator=(const List<T>& other) noexcept
	{
		if (this == &other)
			return *this;

		delete[] _collection;

		_size = other._count;
		_count = other._count;

		if (other._collection == nullptr)
		{
			_collection = nullptr;
			return *this;
		}

		_collection = new T[_size];

		for (int i = 0; i < _count; i++)
		{
			_collection[i] = other._collection[i];
		}

		return *this;
	}

	List<T>& operator=(List<T>&& other) noexcept
	{
		delete[] _collection;

		_size = other._count;
		_count = other._count;
		_collection = other._collection;

		other._collection = nullptr;

		return *this;
	}

	T& operator[](int index) const
	{
		if (index < 0 || index >= _count)
			throw std::exception("index out of range");
		return _collection[index];
	}

	void Reverse()
	{
		for (int i = 0, j = _count - 1; i < _count / 2; i++, j--)
		{
			T temp = _collection[i];
			_collection[i] = _collection[j];
			_collection[j] = temp;
		}
	}

	void CopyFrom(const T* source, int size)
	{
		if (source == nullptr)
			throw std::exception("source is null pointer");

		if (size < 0)
			throw std::exception("size can not be negative");

		for (int i = 0; i < size; i++)
		{
			_collection[i] = source[i];
		}
	}

	void CopyFrom(const  T* source, int sourceIndex, int count)
	{
		for (int i = 0; i < count; i++)
		{
			_collection[i] = source[sourceIndex++];
		}
	}

	void CopyFrom(const  T* source, int sourceIndex, int destinationIndex, int count)
	{
		int size = sourceIndex + count;
		while (sourceIndex < size)
		{
			_collection[destinationIndex++] = source[sourceIndex++];
		}
	}

	void CopyFrom(const List<T>& source)
	{
		CopyFrom(source._collection, source._size);
	}

	void CopyFrom(const List<T>& source, int sourceIndex, int count)
	{
		CopyFrom(source._collection, sourceIndex, count);
	}

	void CopyFrom(const List<T>& source, int sourceIndex, int destinationIndex, int count)
	{
		CopyFrom(source._collection, sourceIndex, destinationIndex, count);
	}

	int IndexOf(T element)
	{
		for (int i = 0; i < _count; i++)
		{
			if (_collection[i] == element)
			{
				return i;
			}
		}
		return -1;
	}

	// მოძებნის ბოლო შემხვედრ element-ს მასივში. თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	int LastIndexOf(T element) const
	{
		for (int i = _size - 1; i >= 0; i--)
		{
			if (_collection[i] == element)
			{
				return i;
			}
		}
		return -1;
	}

	// მოძებნის პირველივე შემხვედრ ელემენტს რომელიც აკმაყოფილებს predicate პირობას.
	// თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	template <typename Predicate>
	int Find(Predicate predicate) const
	{
		for (int i = 0; i < _count; i++)
		{
			if (predicate(_collection[i]))
			{
				return i;
			}
		}
		return -1;
	}

	// მოძებნის ბოლო შემხვედრ ელემენტს რომელიც აკმაყოფილებს predicate პირობას.
	// თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	template <typename Predicate>
	int FindLast(Predicate predicate) const
	{
		for (int i = _size - 1; i >= 0; i--)
		{
			if (predicate(_collection[i]))
			{
				return i;
			}
		}
		return -1;
	}

	// მასივში ელემენტებს დაალაგებს. ელემეტები უნდა შეადაროთ comparer-ით
	template <typename Comparer>
	void Sort(Comparer comparer)
	{
		for (int i = 0; i < _count - 1; i++)
		{
			for (int j = i + 1; j < _count; j++)
			{
				if (comparer(_collection[j], _collection[i]))
				{
					T temp = _collection[i];
					_collection[i] = _collection[j];
					_collection[j] = temp;
				}
			}
		}
	}

	// დაწერეთ ფუნქცია სახელად Foreach რომელიც პარამეტრად გადაცემულ ფუნქციას შესრულებს თითოეული
	// ელემენტისთვის
	template < typename Action>
	void For(Action executeAction)
	{
		for (int i = 0; i < _count; i++)
		{
			executeAction(i, _collection[i]);
		}
	}

	template <typename Action>
	void Foreach(Action executeAction)
	{
		for (int i = 0; i < _count; i++)
		{
			executeAction(_collection[i]);
		}
	}

	// ფუნქცია მასივში  ამატებს ელემენტს. თუ არ ყოფნის არსებული კოლექცია ქმნის ახალს
	void Add(T element)
	{
		if (_collection == nullptr)
		{
			_size = 4;
			_collection = new T[_size];
		}
		else if (_count == _size)
		{
			_size *= 2;

			ReallocateInternal();
		}

		_collection[_count] = element;

		_count++;
	}

	// ფუნქცია მასივში ამატებს ელემენტს მითითებულ ინდექსზე.
	// თუ არ ყოფნის არსებული კოლექცია ქმნის ახალს
	void Insert(int index, T element)
	{
		if (index < 0 || index > _count)
			return; // უნდა ვიყვიროთ რომ არ შეიძლება index-საზღვრებს გაცდა

		if (index == _count)
		{
			Add(element);
			return;
		}

		if (_count == _size)
		{
			_size *= 2;
			T* newCollection = new T[_size];

			// გადმოვიტანოთ პირველი ნაწილი ახალ კოლექციაში
			for (int i = 0; i < index; i++)
			{
				newCollection[i] = _collection[i];
			}

			// index-ზე დავსვათ ახალი ელემენტი
			newCollection[index] = element;

			// გადმოვიტანოთ მეორე ნაწილი ახალ კოლექციაში
			for (int i = index; i < _count; i++)
			{
				newCollection[i + 1] = _collection[i];
			}

			delete[] _collection;
			_collection = newCollection;
		}
		else
		{
			for (int i = _count; i > index; i--)
			{
				_collection[i] = _collection[i - 1];
			}
			_collection[index] = element;
		}

		_count++;
	}

	// მოცულოვა დაყავს რაოდენობაზე
	void SrinkToFit()
	{
		if (_size > _count)
		{
			_size = _count;

			ReallocateInternal();
		}
	}

	// ცვლის მასივის მოცულობას.
	// მოცულობას ხდის size-ის ტოლს იმ შემთხვევაში თუ არსებული მოცულობა size-ზე ნაკლებია.
	// სხვა შემთხვევაში არაფერი არ ხდება.
	// მაგ.: თუ იყო 50 და size = 100 გახდება 100; თუ იყო 100 და size = 50 ყველაფერი იგივე დარჩება
	void Expand(int size)
	{
		if (_size < size)
		{
			_size = size;

			ReallocateInternal();
		}
	}

	// ცვლის მასივის მოცულობას. მოცულობას გახდის size-ის ტოლს თუ არსებული მოცულობა size-ზე ნაკლებია.
	// თუ არსებული მოცულობა size-ზე მეტია შეამცირებს size-მდე და დატოვებს მხოლოდ 0-დან size-მდე ელემეტებს
	// მაგ.: თუ იყო 50 და size = 100 უნდა გახდეს 100; თუ იყო 100 და size = 50 უნდე გახდეს 50
	void Reallocate(int size)
	{
		if (_size == size)
			return;

		if (_size < size)
			Expand(size);

		if (_size > size)
		{
			_size = size;

			if (_count > size)
				_count = size;

			ReallocateInternal();
		}
	}

	// Getter - ეძახიან ისეთ მეთოდებს რომლებიც ცვლადის მნიშვნელობას გიბრუნებენ
	// აბრუნებს ელემენტების რაოდენობას
	int Count() const
	{
		return _count;
	}

	// Getter - ეძახიან ისეთ მეთოდებს რომლებიც ცვლადის მნიშვნელობას გიბრუნებენ
	// აბრუნებს მოცულობას
	int Size() const
	{
		return _size;
	}

private:
	void ReallocateInternal()
	{
		T* newCollection = new T[_size];
		for (int i = 0; i < _count; i++)
		{
			newCollection[i] = _collection[i];
		}
		delete[] _collection;
		_collection = newCollection;
	}
};
