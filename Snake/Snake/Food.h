#pragma once
#include <cstdlib>

#include "Dimentions.h"

short Random(short min, short max)
{
	return rand() % (max - min) + min;
}

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
