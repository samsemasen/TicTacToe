#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

constexpr int SIZE = 3;

class Board
{

public:


	char board[3][3];

	Board(); 
	virtual ~Board() = default;

	void displayBoard();
	bool updateBoard(int row, int column, char value);
	int evaluate();
	bool isMovesLeft();
	bool isCellEmpty(int row, int column);
	bool gameover();

private:
	/*char board_[SIZE][SIZE];*/

};