#pragma once

class Rectangle
{
public:
	int left = 0;
	int right = 0;
	int top = 0;
	int bottom = 0;

	Rectangle();
	~Rectangle();

	bool CompletelyOutside(const Rectangle& other) const;
	bool Inside(const Rectangle& other) const;
	void ClipTo(const Rectangle& other);
	void Translate(int posX, int posY);

	int Width() const { return right - left; }
	int Height() const { return bottom - top; }
};

