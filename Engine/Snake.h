#pragma once

#include "Board.h"
class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& _loc);
		void InitBody(Color _c);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& board) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;

	};

private:
	static constexpr Color headColor = Colors::Yellow;
	static int constexpr nSegmentMax = 100;

	void DetermineSpeed();
	int snakeSpeed = 20;
	int snakeSpeedScaling = 1;

	Color DetermineBodyColor();
	int bodyColorScaling = 0;

	Segment segments[nSegmentMax];
	int nSegments = 1;
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& board) const;
	bool IsInTileExceptEnd(const Location& loc) const;
	bool IsInTile(const Location& loc) const;
	int GetSnakeSpeed() const;
};

