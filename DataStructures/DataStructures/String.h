#pragma once
#include <exception>
#include <iostream>

class String
{
private:
	int _capacity = 0; //  მასივის მოცულობას აღნიშნავს
	char* _text = nullptr;
	int _length = 0; // მასივში მიმდინარე ელემენტების რაოდენობას აღნიშნავს

public:
	String()
	{
	};

	String(const String& other)
	{
		InitializeInternal(other._length, other._length + 1);

		for (int i = 0; i < _capacity; i++)
		{
			_text[i] = other._text[i];
		}
	}

	String(const char* text)
	{
		_length = StringLength(text);
		_capacity = _length + 1;

		_text = new char[_capacity];

		for (int i = 0; i < _capacity; i++)
		{
			_text[i] = text[i];
		}
	}

	String(int length, int capacity)
	{
		InitializeInternal(length, capacity);
	}

	const String& operator=(const char* text)
	{
		if (text == nullptr)
			throw std::exception("text can not be nullptr");

		int length = StringLength(text);
		InitializeInternal(length, length + 1);

		for (int i = 0; i < _capacity; i++)
		{
			_text[i] = text[i];
		}
		return *this;
	}

	const String& operator=(const String& other)
	{
		if (other._text == nullptr)
		{
			delete[] _text;
			_capacity = 0;
			_length = 0;
			_text = nullptr;
			return *this;
		}

		InitializeInternal(other._length, other._length + 1);

		for (int i = 0; i < _capacity; i++)
		{
			_text[i] = other._text[i];
		}
		return *this;
	}

	char& operator[](int index) const
	{
		if (index < 0 || index >= _length)
			throw std::exception("index is out of range");
		return _text[index];
	}

	int StringLength(const char* text) const
	{
		int length = 0;
		while (text[length] != '\0')
		{
			length++;
		}
		return length;
	}

	// ეძებს მითითებულ სიმბოლოს ტექტსში.
	// startIndex: საიდან დაიწყოს ძებნა.
	// ignoreCase: მიაქციოს თუ არა ყურადღება რეგისტრს. თუ არის true არ ყურადღებას არ აქცევს.
	// თუ ვერ იპოვბა აბრუნებს -1-ს
	int IndexOf(char symbol, int startIndex = 0, bool ignoreCase = false)
	{
		// შევამოწმით ინდექსი საზღვრებს ხომ არ გაცდა
		if (startIndex < 0 || startIndex >= _length)
			throw std::exception("startIndex is out of range");

		for (int i = startIndex; i < _length; i++)
		{
			char first = ignoreCase ? ToLower(_text[i]) : _text[i];
			char second = ignoreCase ? ToLower(symbol) : symbol;
			if (first == second)
				return i;
		}
		return -1;
	}

	// ტექსტიდან იღებს ქვეტექსტს მითითებული ინედქსიდან მითითებული რაოდენობით
	String Substring(int index, int count)
	{
		if (index < 0 || index >= _length)
			throw std::exception("startIndex is out of range");

		if (count < 0 || index + count > _length)
			throw std::exception("count is out of range");

		String substring(count, count + 1);
		int end = index + count;
		for (int i = index, j = 0; i < end; i++, j++)
		{
			substring._text[j] = _text[i];
		}
		substring._text[count] = '\0';
		return substring;
	}

	// ტექსტიდან იღებს ქვეტექსტს მითითებული ინედქსიდან
	String Substring(int index)
	{
		if (index < 0 || index >= _length)
			throw std::exception("startIndex is out of range");

		return Substring(index, _length - index);
	}

	// symbol გადაყავს დიდ ასოში
	char ToUpper(char symbol)
	{
		return  symbol >= 'a' && symbol <= 'z' ? symbol - ('a' - 'A') : symbol;
	}

	// აბრუნებს ახალ ტექსტს რომელიც არის დიდ ასოებში გადაყვანილი
	String ToUpper()
	{
		String newString(_length, _length + 1);

		for (int i = 0; i < newString._capacity; i++)
		{
			newString._text[i] = ToUpper(_text[i]);
		}

		return newString;
	}

	// symbol გადაყავს პატარა ასოში
	char ToLower(char symbol)
	{
		return  symbol >= 'A' && symbol <= 'Z' ? symbol + ('a' - 'A') : symbol;
	}

	// აბრუნებს ახალ ტექსტს რომელიც არის პატარა ასოებში გადაყვანილი
	String ToLower()
	{
		String newString(_length, _length + 1);

		for (int i = 0; i < newString._capacity; i++)
		{
			newString._text[i] = ToLower(_text[i]);
		}

		return newString;
	}

	// ერთ ტექსტს შეადარებს მეორეს.
	// აბრუნებს -1-ს თუ პირველი ნაკლებია მეორეზე, 0-ს თუ ტოლი და 1-ს თუ მეტია
	int Compare(const String other) // TODO: დაამატეთ რეგისტრის დაიგნორების ფუნქციონალი
	{
		int count = _length <= other._length ? _length : other._length;
		for (int i = 0; i < count; i++)
		{
			if (_text[i] < other._text[i]) return -1;
			if (_text[i] > other._text[i]) return 1;
		}

		if (_length < other._length) return -1;
		if (_length > other._length) return 1;

		return 0;
	}

	// TODO: 6. ფუნქცია რომელიც ერთ ტექსტში იპოვის მეორეს

	// TODO: 7. ფუნქცია რომელიც დახლეჩს ტექტს მითითებული სიმბოლოს მიხედვით და დაგვიბრუნებს ტექსტების ლისტს

	friend std::ostream& operator<< (std::ostream& os, String& str);
	friend String operator+(const String& other, const char* text);
	friend String operator+(const String& other, String& str);

	~String()
	{
		// გამოყენებას რომ დავამთავრებ უეჭველი უნდა წავშალო თორემ memory leak იქნება
		delete[] _text;
	}

private:
	void InitializeInternal(int length, int capacity)
	{
		delete[] _text;
		_capacity = capacity;
		_length = length;
		_text = new char[_capacity];
	}
};

std::istream& operator>>(std::istream& is, String& str)
{
	char* buffer = new char[1000000];
	is >> buffer;
	str = buffer;
	delete[] buffer;
	return is;
}

std::ostream& operator<<(std::ostream& os, String& str)
{
	os << str._text;
	return  os;
}

void GetLine(std::istream& is, String& str, int bufferSize = 1000000)
{
	char* buffer = new char[bufferSize];
	is.getline(buffer, bufferSize);
	str = buffer;
	delete[] buffer;
}

String operator+(const String& first, String& second)
{
	int newLength = first._length + second._length;
	int newCapacity = newLength + 1;

	String newString;
	newString._length = newLength;
	newString._capacity = newCapacity;
	newString._text = new char[newCapacity];
	char* newText = newString._text;

	for (int i = 0; i < first._length; i++)
	{
		newText[i] = first._text[i];
	}
	for (int i = first._length, j = 0; i < newCapacity; i++, j++)
	{
		newText[i] = second._text[j];
	}

	return newString;
}

String operator+(const String& first, const char* other)
{
	int newLength = first._length + first.StringLength(other);
	int newCapacity = newLength + 1;

	String newString;
	newString._length = newLength;
	newString._capacity = newCapacity;
	newString._text = new char[newCapacity];
	char* newText = newString._text;

	for (int i = 0; i < first._length; i++)
	{
		newText[i] = first._text[i];
	}
	for (int i = first._length, j = 0; i < newCapacity; i++, j++)
	{
		newText[i] = other[j];
	}

	return newString;
}