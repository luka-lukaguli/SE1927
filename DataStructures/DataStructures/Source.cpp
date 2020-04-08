#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "SinglyLinkedList.h"

using namespace  std;

struct Point
{
	short x = 0;
	short y = 0;

	Point(short x, short y)
	{
		this->x = x;
		this->y = y;
	}

	Point() = default;
};

struct Margin
{
	short top = 0, bottom = 0, left = 0, right = 0;

	Margin() = default;

	Margin(short top, short bottom, short left, short right)
	{
		this->top = top;
		this->bottom = bottom;
		this->left = left;
		this->right = right;
	}
};

struct Snake
{
private:
	SinglyLinkedList<Point> body;
	Margin margin;

public:
	const char headShape = 'V';
	const char bodyShape = 'O';

	Snake(const Margin& margin)
	{
		this->margin = margin;

		body.AddLast(Point(10, 10));
	}

	void MoveLeft()
	{
		auto& head = body.First();
		if (head.x == margin.left)
			head.x = margin.right;

		head.x--;
	}

	void MoveRight()
	{
		auto& head = body.First();
		if (head.x == margin.right)
			head.x = margin.left;

		head.x++;
	}

	void MoveUp()
	{
		auto& head = body.First();
		if (head.y == margin.top)
			head.y = margin.bottom;

		head.y--;
	}

	void MoveDown()
	{
		auto& head = body.First();
		if (head.y == margin.bottom)
			head.y = margin.top;

		head.y++;
	}

	Point Head()
	{
		return body.First();
	}
};

struct Environment
{
	const char border = '#';

	Margin margin;

	Environment(short left, short top, short right, short bottom)
	{
		margin.left = left;
		margin.top = top;
		margin.right = right;
		margin.bottom = bottom;
	}

	static void SetCursor(const Point& point)
	{
		COORD p = { point.x, point.y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	}

	static void SetCursor(short x, short y)
	{
		COORD p = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	}

	static void Clear()
	{
		system("cls");
	}

	void DrawBorder()
	{
		DrawTopBorder();
		DrawLeftBorder();
		DrawBottomBorder();
		DrawRightBorder();
	}

private:
	void DrawTopBorder()
	{
		for (short x = margin.left; x < margin.right; x++)
		{
			SetCursor(x, margin.top);
			cout << border;
		}
	}

	void DrawLeftBorder()
	{
		for (short y = margin.top; y < margin.bottom; y++)
		{
			SetCursor(margin.left, y);
			cout << border << "\n";
		}
	}

	void DrawBottomBorder()
	{
		for (short x = margin.left; x < margin.right; x++)
		{
			SetCursor(x, margin.bottom);
			cout << border;
		}
	}

	void DrawRightBorder()
	{
		for (short y = margin.top; y < margin.bottom; y++)
		{
			SetCursor(margin.right, y);
			cout << border << "\n";
		}
	}
};

int main()
{
	char controller;

	Environment environment(5, 5, 45, 25);
	Snake snake(environment.margin);

	while (true)
	{
		environment.Clear();
		environment.DrawBorder();
		environment.SetCursor(snake.Head());
		cout << snake.headShape;
		controller = _getch();

		switch (controller)
		{
		case 'w':
			snake.MoveUp();
			break;

		case 's':
			snake.MoveDown();
			break;

		case 'd':
			snake.MoveRight();
			break;

		case 'a':
			snake.MoveLeft();
			break;
		}
	}

	return 0;
}