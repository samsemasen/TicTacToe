#pragma once
#include "Board.h"

struct Move
{
	int row, col;
};


class MiniMax 
{
public:

	const int MAX = 1000;
	const int MIN = -1000;

	char player = 'X', opponent = 'O';

	MiniMax() = default;
	~MiniMax() = default;

	int minimax(Board* board, int depth, bool isMax , int alpha , int beta);
	Move findBestMove(Board* board);

private:

};
