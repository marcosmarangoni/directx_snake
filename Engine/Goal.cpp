#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Board & board, const Snake & snake, const Obstacle& obstacle)
{
	Respawn(rng, board, snake, obstacle);
}

void Goal::Respawn(std::mt19937 & rng, const Board & board, const Snake & snake, const Obstacle& obstacle)
{
	std::uniform_int_distribution<int> xDist(0, Board::GetGridWidth()-1);
	std::uniform_int_distribution<int> yDist(0, Board::GetGridHeight() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc) || obstacle.IsInObstacle(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board & board) const
{
	board.DrawCell(loc, c);
}

const Location & Goal::GetLocation() const
{
	return loc;
}
