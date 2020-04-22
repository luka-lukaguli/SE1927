#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

template <typename iter, typename  Action>
void For(iter begin, iter end, Action action)
{
	while (begin != end)
	{
		action(*begin);
		++begin;
	}
}

struct EvenNumbers
{
	int currentValue = 2;

	EvenNumbers(int value)
	{
		currentValue = value;
	}

	EvenNumbers& operator++()
	{
		currentValue += 2;
		return *this;
	}

	bool operator!=(const EvenNumbers& other) const
	{
		return currentValue != other.currentValue;
	}

	int operator*() const
	{
		return currentValue;
	}
};

template <typename T>
struct Vector
{
	T* collection;
	int size;

	Vector(initializer_list<T> list)
	{
		size = list.size();
		collection = new T[size];
		int i = 0;
		for (auto begin = list.begin(), end = list.end(); begin != end; ++begin)
		{
			collection[i++] = *begin;
		}
	}

	struct iterator
	{
	};

	struct const_iterator
	{
	};

	struct reverse_iterator
	{
	};

	struct reverse_const_iterator
	{
	};

	iterator begin();
};

struct Student
{
	string Id;
	string name;
	int score;
};

struct StudentIdComparer
{
	bool operator()(const Student& left, const  Student& right) const
	{
		return left.Id < right.Id;
	}
};

struct StudentScoreComparer
{
	bool operator()(const Student& left, const  Student& right) const
	{
		return left.score < right.score;
	}
};

int main()
{
	// http://www.cplusplus.com/reference/stl/

	double numbers[5]{ 10,20,30,40, 50 };
	int intNumbers[3]{ 1,2,3 };

	For(intNumbers + 0, intNumbers + 3, [](int n) {cout << n << " "; });

	cout << endl;

	For(numbers + 0, numbers + 5, [](double n) {cout << n * 10 << " "; });

	cout << endl;

	EvenNumbers begin(2);
	EvenNumbers end(20);

	For(begin, end, [](int n) {cout << n << " "; });

	vector<int> intVector{ 10,20,30,40,50 };

	auto beg = intVector.begin();

	auto en = intVector.end();

	cout << "\n--------- Vector ------------------------\n";

	For(beg, en, [](int& n) { n *= 10; });

	auto rbeg = intVector.rbegin();
	auto ren = intVector.rend();
	cout << "\n--------- Vector Reverse------------------------\n";

	For(rbeg, ren, [](int n) {cout << n << " "; });
	cout << endl;
	bool all = all_of(intVector.begin() + 1, intVector.begin() + 3, [](int n) {return n > 30; });
	all = all_of(numbers, numbers + 5, [](int n) {return n > 30; });

	generate(intVector.begin(), intVector.end(), rand);

	For(intVector.begin(), intVector.end(), [](int n) {cout << n << " "; });

	vector<int> foo(3, 100);   // three ints with a value of 100
	vector<int> bar(5, 200);   // five ints with a value of 200

	cout << "\nfoo.data() : " << foo.data() << endl;
	cout << "bar.data() : " << bar.data() << endl;

	foo.swap(bar);

	cout << "foo.data() : " << foo.data() << endl;
	cout << "bar.data() : " << bar.data() << endl;

	set<int> uniqueNumbers;
	uniqueNumbers.insert(10);
	uniqueNumbers.insert(20);
	uniqueNumbers.insert(30);
	uniqueNumbers.insert(10);

	cout << "\n--------- Unique Numbers Set------------------------\n";
	For(uniqueNumbers.begin(), uniqueNumbers.end(), [](int n) {cout << n << " "; });

	StudentIdComparer idComp;
	StudentScoreComparer scoreComp;

	vector<Student> it;
	vector<Student> programming;

	set<Student, StudentIdComparer> students(idComp);

	students.insert(Student
		{
		   "12345",
		   "Davit",
		   79
		});

	students.insert(Student
		{
		   "12345",
		   "Davit",
		   90
		});

	students.insert(Student
		{
		   "12345",
		   "Davit",
		   100
		});

	For(students.begin(), students.end(), [](Student s) {cout << s.name << endl; });

	return 0;
}