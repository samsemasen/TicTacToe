#pragma once
#include "Board.h"

struct Move
{
	int row, col;
};


class MiniMax 
{
public:


	char player = 'X', opponent = 'O';

	//MiniMax(Board* board);
	MiniMax() = default;
	~MiniMax() = default;

	// A utility function to find Log n in base 2 
	int log2(int n);

	int minimax(Board* board, int depth, bool isMax);
	Move findBestMove(Board* board);

private:
	Board* board_;
};
