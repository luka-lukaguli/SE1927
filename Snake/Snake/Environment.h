#pragma once
#include <Windows.h>
#include <conio.h>

#include "Dimentions.h"
#include "Food.h"
#include "Snake.h"

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
		snake.body.Foreach([&snake](Point& bodyPart)
			{
				SetCursor(bodyPart);
				std::cout << snake.shape;
			});
	}

	void Draw(Food& food)
	{
		SetCursor(food.position);
		std::cout << food.shape;
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
			std::cout << border;
		}
	}

	void DrawLeftBorder()
	{
		for (short y = margin.top; y < margin.bottom; y++)
		{
			SetCursor(margin.left, y);
			std::cout << border << "\n";
		}
	}

	void DrawBottomBorder()
	{
		for (short x = margin.left; x < margin.right; x++)
		{
			SetCursor(x, margin.bottom);
			std::cout << border;
		}
	}

	void DrawRightBorder()
	{
		for (short y = margin.top; y < margin.bottom; y++)
		{
			SetCursor(margin.right, y);
			std::cout << border << "\n";
		}
	}
};
