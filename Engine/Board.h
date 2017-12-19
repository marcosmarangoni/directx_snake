#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
private:
	static int constexpr dimension = 20;
	static int constexpr width = 25;
	static int constexpr height = 25;
	static int constexpr cellMargin = 2;
	Graphics& gfx;
	int x, y;
public:
	Board(Graphics& _gfx, int _x, int _y);
	~Board();
	void DrawCell(const Location& loc, Color c);
	void DrawMapBorder(int thickness, Color c);
	static int GetGridWidth();
	static int GetGridHeight();
	bool IsInsideBoard(const Location& loc) const;
};

