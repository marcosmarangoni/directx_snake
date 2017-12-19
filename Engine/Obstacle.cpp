#include "Obstacle.h"



Obstacle::Obstacle(std::mt19937& _rng, Snake& _snake, Board& _board)
	:
	rng(_rng),
	snake(_snake),
	board(_board)
{
}


Obstacle::~Obstacle()
{
}

void Obstacle::CreateObstacle()
{
	if (nObstacles >= maxNumObstacles) return;
	nObstacles++;
	std::uniform_int_distribution<int> xDist(0, Board::GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, Board::GetGridHeight() - 1);

	bool colliding = true;
	Location _loc;

	while (colliding)
	{
		_loc = { xDist(rng),yDist(rng) };
		colliding = IsInObstacle(_loc) | snake.IsInTile(_loc);
	}

	obstacles[nObstacles - 1].InitObstacle(_loc, obstacleColor);
}

bool Obstacle::IsInObstacle(const Location & _loc) const
{
	for (int i = 0; i < nObstacles; i++)
	{
		if (obstacles[i].IsColliding(_loc))
		{
			return true;
		}
	}
	return false;
}

void Obstacle::Draw(Board & board) const
{
	for (int i = 0; i < nObstacles; i++)
	{
		obstacles[i].Draw(board);
	}
}

void Obstacle::ObstacleTile::InitObstacle(Location _loc, Color _c)
{
	loc = _loc;
	c = _c;
}

bool Obstacle::ObstacleTile::IsColliding(const Location & _loc) const
{
	return loc == _loc;
}

void Obstacle::ObstacleTile::Draw(Board & board) const
{
	board.DrawCell(loc, c);
}
