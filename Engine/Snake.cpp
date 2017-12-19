#include "Snake.h"
#include <assert.h>

void Snake::DetermineSpeed()
{
	if (snakeSpeedScaling < 5)
	{
		snakeSpeedScaling++;
		snakeSpeed = 20 - (snakeSpeedScaling * 2);
	}
}

Color Snake::DetermineBodyColor()
{
	bodyColorScaling++;
	if (bodyColorScaling > 5) bodyColorScaling = 0;
	Color _c = Color::Color(0, 255 - (bodyColorScaling * 25), 0);

	return _c;
}

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location loc(segments[0].GetLocation());
	loc.Add(delta_loc);
	return loc;
}

void Snake::Grow()
{
	DetermineSpeed();
	if (nSegments < nSegmentMax)
	{
		segments[nSegments].InitBody(DetermineBodyColor());
		nSegments++;
	}
}

void Snake::Draw(Board & board) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(board);
	}
}

bool Snake::IsInTileExceptEnd(const Location & loc) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].GetLocation() == loc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location & loc) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == loc)
		{
			return true;
		}
	}
	return false;
}

int Snake::GetSnakeSpeed() const
{
	return snakeSpeed;
}

void Snake::Segment::InitHead(const Location & _loc)
{
	loc = _loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color _c)
{
	c = _c;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & board) const
{
	board.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
