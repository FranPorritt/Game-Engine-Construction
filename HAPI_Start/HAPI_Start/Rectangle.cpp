#include "Rectangle.h"
#include <algorithm>

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

bool Rectangle::CompletelyOutside(const Rectangle& other) const
{
	if (other.right < left)
		return true;

	if (other.top > bottom)
		return true;

	if (other.left > right)
		return true;

	if (other.bottom < top)
		return true;

	return false;
}

bool Rectangle::Inside(const Rectangle& other) const
{
	if ((right < other.right) && (bottom < other.bottom) && (left > other.left) && (top > other.top))
		return true;

	return false;
}

void Rectangle::ClipTo(const Rectangle& other) 
{
	left = std::max(left, other.left);
	right = std::min(right, other.right);
	top = std::max(top, other.top);
	bottom = std::min(bottom, other.bottom); 
}

void Rectangle::Translate(int posX, int posY)
{
	left += posX;
	right += posX;
	top += posY;
	bottom += posY;
}
