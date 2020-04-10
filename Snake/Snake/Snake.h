#pragma once
#include "Dimentions.h"
#include "DoublyLinkedList.h"

enum Direction
{
	Left = 1,
	Up,
	Right,
	Down
};

struct Snake
{
private:
	Margin margin;

public:
	DoublyLinkedList<Point> body;
	int direction;

	const char shape = 'O';

	Snake(const Margin& margin)
	{
		this->margin = margin;

		body.AddLast(Point(10, 10));
		body.AddLast(Point(9, 10));
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

	void FollowHead()
	{
		body.ReverseFor([](auto& node)
			{
				if (node->_previous != nullptr)
					node->_value = node->_previous->_value;
			});
	}

	void Move()
	{
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

		FollowHead();
	}

	void Eat()
	{
		auto tail = body.Last();
		Move();
		body.AddLast(tail);
	}
};
