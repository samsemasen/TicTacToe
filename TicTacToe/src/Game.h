#pragma once
#include "Board.h"
#include "MiniMax.h"

class Game {
public:
	int choice;
	int row, column;
	char turn = 'X';
	bool draw = false;
	int evaluatedValue;

	Game(Board* board);
	~Game() = default;
	void run();
	void playerTurn();
	void computerTurn();

private:
	Board* board_;

};