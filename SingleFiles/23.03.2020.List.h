#pragma once

struct List
{
private:
	int _size = 0; //  მასივის მოცულობას აღნიშნავს
	int _count = 0; // მასივში მიმდინარე ელემენტების რაოდენობას აღნიშნავს
	double* _collection = nullptr;

public:
	// default კონსტრუქტორი
	List()
	{
	}

	// გადარვირთული კონსტრუქტორი
	List(int size)
	{
		_size = size;
		_collection = new double[_size]; // დინამიური მასივი
	}

	// copy კონსტრუქტორი
	List(const List& other)
	{
		_size = other._size;
		_count = other._count;
		_collection = new double[_size];

		for (int i = 0; i < _size; i++)
		{
			_collection[i] = other._collection[i];
		}
	}

	// დესტრუქტორი
	~List()
	{
		// გამოყენებას რომ დავამთავრებ უეჭველი უნდა წავშალო თორემ memory leak იქნება
		delete[] _collection;
	}

	void operator=(const List& other)
	{
		delete[] _collection;

		_size = other._size;
		_count = other._count;
		_collection = new double[_size];

		for (int i = 0; i < _size; i++)
		{
			_collection[i] = other._collection[i];
		}
	}

	double& operator[](int index) const
	{
		return _collection[index];
	}

	void Reverse()
	{
		for (int i = 0, j = _size - 1; i < _size / 2; i++, j--)
		{
			double temp = _collection[i];
			_collection[i] = _collection[j];
			_collection[j] = temp;
		}
	}

	void CopyFrom(const double* source, int size)
	{
		for (int i = 0; i < size; i++)
		{
			_collection[i] = source[i];
		}
	}

	void CopyFrom(const  double* source, int sourceIndex, int count)
	{
		for (int i = 0; i < count; i++)
		{
			_collection[i] = source[sourceIndex++];
		}
	}

	void CopyFrom(const  double* source, int sourceIndex, int destinationIndex, int count)
	{
		int size = sourceIndex + count;
		while (sourceIndex < size)
		{
			_collection[destinationIndex++] = source[sourceIndex++];
		}
	}

	void CopyFrom(const List& source)
	{
		CopyFrom(source._collection, source._size);
	}

	void CopyFrom(const List& source, int sourceIndex, int count)
	{
		CopyFrom(source._collection, sourceIndex, count);
	}

	void CopyFrom(const List& source, int sourceIndex, int destinationIndex, int count)
	{
		CopyFrom(source._collection, sourceIndex, destinationIndex, count);
	}

	int IndexOf(double element)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_collection[i] == element)
			{
				return i;
			}
		}
		return -1;
	}

	// მოძებნის ბოლო შემხვედრ element-ს მასივში. თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	int LastIndexOf(double element) const
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
		for (int i = 0; i < _size; i++)
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
		for (int i = 0; i < _size - 1; i++)
		{
			for (int j = i + 1; j < _size; j++)
			{
				if (comparer(_collection[j], _collection[i]))
				{
					double temp = _collection[i];
					_collection[i] = _collection[j];
					_collection[j] = temp;
				}
			}
		}
	}

	// დაწერეთ ფუნქცია სახელად Foreach რომელიც პარამეტრად გადაცემულ ფუნქციას შესრულებს თითოეული
	// ელემენტისთვის
	template <typename Action>
	void Foreach(Action executeAction)
	{
		for (int i = 0; i < _size; i++)
		{
			executeAction(i, _collection[i]);
		}
	}

	// ფუნქცია მასივში  ამატებს ელემენტს. თუ არ ყოფნის არსებული კოლექცია ქმნის ახალს
	void Add(double element)
	{
		if (_collection == nullptr)
		{
			_size = 4;
			_collection = new double[_size];
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
	void Insert(int index, double element)
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
			double* newCollection = new double[_size];

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
		{
			_size = size;

			if (size < _count)
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
		double* newCollection = new double[_size];
		for (int i = 0; i < _count; i++)
		{
			newCollection[i] = _collection[i];
		}
		delete[] _collection;
		_collection = newCollection;
	}

};
