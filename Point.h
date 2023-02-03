#pragma once
struct Point
{
	int x, y;
	Point():x(-1), y(-1) {}
	Point(int a, int b) : x(a), y(b) {}
	bool operator==(const Point& other) { return x == other.x && y == other.y; }
};

kekfafs