#pragma once

struct Array
{
	int _size = 0;
	double* _collection = nullptr;

	// default კონსტრუქტორი
	Array()
	{
	}

	// გადარვირთული კონსტრუქტორი
	Array(int size)
	{
		_size = size;
		_collection = new double[_size]; // დინამიური მასივი
	}

	// copy კონსტრუქტორი
	Array(const Array& other)
	{
		_size = other._size;
		_collection = new double[_size];
		for (int i = 0; i < _size; i++)
		{
			_collection[i] = other._collection[i];
		}
	}

	// დესტრუქტორი
	~Array()
	{
		// გამოყენებას რომ დავამთავრებ უეჭველი უნდა წავშალო თორემ memory leak იქნება
		delete[] _collection;
	}

	void operator=(const Array& other)
	{
		delete[] _collection;
		_size = other._size;
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

	void CopyFrom(const Array& source)
	{
		CopyFrom(source._collection, source._size);
	}

	void CopyFrom(const Array& source, int sourceIndex, int count)
	{
		CopyFrom(source._collection, sourceIndex, count);
	}

	void CopyFrom(const Array& source, int sourceIndex, int destinationIndex, int count)
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

	// სტრუქტურა დაუმატეთ Count ცლადი რომელიც მასივში მიმდინარე ელემენტების 
	// რაოდენობას აღნიშნავს

	void Add(double element)
	{
		// ფუნქცია მასივში უნდა ამატებდეს ელემენტს. თუ არ ყოფნის არსებული კოლექცია უნდა შქმნას ახალი
	}

	void Insert(int index, double element)
	{
		// ფუნქცია მასივში უნდა ამატებდეს ელემენტს მითითებულ ინდექსზე. 
		// თუ არ ყოფნის არსებული კოლექცია უნდა შქმნას ახალი
	}

};
