#include "Board.h"
#include <assert.h>



Board::Board(Graphics& _gfx, int _x, int _y)
	:
	gfx(_gfx),
	x(_x),
	y(_y)
{
}


Board::~Board()
{
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	int __x, __y;
	__x = loc.x * dimension;
	__y = loc.y * dimension;
	if (cellMargin > 0)
	{
		__x = (loc.x * dimension) + cellMargin / 2;
		__y = (loc.y * dimension) + cellMargin / 2;
	}
	//gfx.DrawRectDim(__x, __y, dimension - cellMargin, dimension - cellMargin, c);
	gfx.DrawCircle(__x, __y, (dimension)/2 - cellMargin, c);
}

void Board::DrawMapBorder(int thickness, Color c)
{
	gfx.DrawRectBorder(x, y, width*dimension, height*dimension, thickness, c);
}

int Board::GetGridWidth()
{
	return width;
}

int Board::GetGridHeight()
{
	return height;
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return
		loc.x >= 0 &&
		loc.x < width &&
		loc.y >= 0 &&
		loc.y < height;
}
