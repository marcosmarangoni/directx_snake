#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Obstacle
{
private:
	class ObstacleTile {
	private:
		Location loc;
		Color c;
	public:
		void InitObstacle(Location _loc, Color _c);
		bool IsColliding(const Location& _loc) const;
		void Draw(Board& board) const;

	};
private:
	static int constexpr maxNumObstacles = 15;
	static Color constexpr obstacleColor = Colors::Gray;
	ObstacleTile obstacles[maxNumObstacles];
	int nObstacles = 0;

	std::mt19937& rng;
	Snake& snake;
	Board& board;
public:
	Obstacle(std::mt19937& _rng, Snake& _snake, Board& _board);
	~Obstacle();
	void CreateObstacle();
	bool IsInObstacle(const Location& _loc) const;
	void Draw(Board& board) const;
};

