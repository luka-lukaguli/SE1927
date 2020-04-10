#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "SinglyLinkedList.h"

using namespace  std;

short Random(short min, short max)
{
	return rand() % (max - min) + min;
}

enum Direction
{
	Left = 1,
	Up,
	Right,
	Down
};

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

	bool operator==(const Point& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator==(Point&& other)
	{
		return x == other.x && y == other.y;
	}
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
	Margin margin;

public:
	SinglyLinkedList<Point> body;
	int direction;

	const char shape = 'O';

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

	void Follow(const Point& point)
	{
	}

	void Move()
	{
		auto headPosition = body.First();
		switch (direction)
		{
		case Left:
			MoveLeft();
			break;
		case Up:
			MoveUp();
			break;
		case Right:
			MoveRight();
			break;
		case Down:
			MoveDown();
			break;
		}

		Follow(headPosition);
	}

	void Eat()
	{
		auto tail = body.Last();
		Move();
		body.AddLast(tail);
	}
};

struct Food
{
	Point position;
	Margin margin;

	const char shape = '@';

	Food(const Margin& margin)
	{
		this->margin = margin;
		SetNewPosition();
	}

	void SetNewPosition()
	{
		position.x = Random(margin.left + 1, margin.right - 1);
		position.y = Random(margin.top + 1, margin.bottom - 1);
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

	void Clear()
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

	void Draw(Snake& snake)
	{
		snake.body.Foreach([&snake](const Point& bodyPart)
			{
				SetCursor(bodyPart);
				cout << snake.shape;
			});
	}

	void Draw(Food& food)
	{
		SetCursor(food.position);
		cout << food.shape;
	}

	void GetControl(char& control)
	{
		while (_kbhit())
			control = _getch();
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
	int gameSpeed = 100;
	Environment environment(5, 5, 45, 25);

	Snake snake(environment.margin);
	Food food(environment.margin);

	char controller = 'p';
	while (true)
	{
		environment.Clear();
		environment.DrawBorder();
		environment.Draw(snake);
		environment.Draw(food);
		environment.GetControl(controller);

		if (food.position == snake.Head())
		{
			snake.Eat();
			food.SetNewPosition();
		}

		switch (controller)
		{
		case 'w':
			snake.direction = Up;
			break;

		case 's':
			snake.direction = Down;
			break;

		case 'd':
			snake.direction = Right;
			break;

		case 'a':
			snake.direction = Left;
			break;
		}

		snake.Move();

		Sleep(gameSpeed);
	}

	return 0;
}