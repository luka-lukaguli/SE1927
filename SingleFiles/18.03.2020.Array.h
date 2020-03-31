#pragma once

struct Array
{
	int _size = 0;
	double* _collection = nullptr;
	
	Array() 
	{
	}
	
	Array(int size)
	{
		_size = size;
		_collection = new double[_size]; // დინამიური მასივი
	}
	
	double& operator[](int index)
	{
		return _collection[index];
	}

	void Reverse()
	{
		//მასივში შეაბრუნებს ელემენტებს თანმიმდევრობას
	}
	
	void CopyFrom(double* source, int size)
	{
		// შეავსებს ჩვენს მასივის პარამეტრად გადმოცემული კოლექციიდან
	}

	void CopyFrom(double* source, int sourceIndex , int count)
	{
		// შეავსებს ჩვენს მასივის პარამეტრად გადმოცემული კოლექციიდან
	}

	void CopyFrom(double* source, int sourceIndex, int destinationIndex , int count)
	{
		// შეავსებს ჩვენს მასივის პარამეტრად გადმოცემული კოლექციიდან
	}

	int IndexOf(double element)
	{
		// მოძებნის პირველივე შემხვედრ element-ს მასივში. თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	}

	int LastIndexOf(double element)
	{
		// მოძებნის ბოლო შემხვედრ element-ს მასივში. თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	}

	template <typename Predicate>
	int Find(Predicate predicate)
	{
		// მოძებნის პირველივე შემხვედრ ელემენტს რომელიც აკმაყოფილებს predicate
		// პირობას. თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	}

	template <typename Predicate>
	int FindLast(Predicate predicate)
	{
		// მოძებნის ბოლო შემხვედრ ელემენტს რომელიც აკმაყოფილებს predicate
		// პირობას. თუ იპოვა დააბრუნებს მის ინდექსს თუ ვერა დააბრუნებს -1-ს;
	}

	template <typename Comparer>
	void Sort(Comparer comparer)
	{
		// მასივში ელემენტებს დაალაგებს. ელემეტები უნდა შეადაროთ comparer-ით
	}

};
