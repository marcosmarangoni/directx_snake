#pragma once

#include "Board.h"
#include "Snake.h"
#include "Obstacle.h"
#include <random>
class Goal
{
public:
	Goal(std::mt19937& rng, const Board& board, const Snake& snake, const Obstacle& obstacle);
	void Respawn(std::mt19937& rng, const Board& board, const Snake& snake, const Obstacle& obstacle);
	void Draw(Board& board) const;
	const Location& GetLocation() const;
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};

