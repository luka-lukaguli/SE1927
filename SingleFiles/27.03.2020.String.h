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
		_capacity = other._capacity;
		_length = other._length;
		_text = new char[_capacity];

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

	const String& operator=(const char* text)
	{
		if (text == nullptr)
			throw std::exception("text can not be nullptr");

		delete[] _text;

		_length = StringLength(text);
		_capacity = _length + 1;

		_text = new char[_capacity];

		for (int i = 0; i < _capacity; i++)
		{
			_text[i] = text[i];
		}
		return *this;
	}

	
	

	const String& operator=(const String& other)
	{
		delete[] _text;
		_capacity = other._capacity;
		_length = other._length;

		if (other._text == nullptr)
		{
			_text = nullptr;
			return *this;
		}

		_text = new char[_capacity];

		for (int i = 0; i < _capacity; i++)
		{
			_text[i] = other._text[i];
		}
		return *this;
	}

	char& operator[](int index) const
	{
		if (index < 0 || index >= _length)
			throw std::exception("index out of range");
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


	friend std::ostream& operator<< (std::ostream& os, String& str);
	friend String operator+(const String& other, const char* text);
	friend String operator+(const String& other, String& str);


	~String()
	{
		// გამოყენებას რომ დავამთავრებ უეჭველი უნდა წავშალო თორემ memory leak იქნება
		delete[] _text;
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

	for (int i = 0; i <first. _length; i++)
	{
		newText[i] = first._text[i];
	}
	for (int i = first._length, j = 0; i < newCapacity; i++, j++)
	{
		newText[i] = other[j];
	}
	
	return newString;
}