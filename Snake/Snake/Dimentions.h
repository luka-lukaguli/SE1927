#pragma once

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
