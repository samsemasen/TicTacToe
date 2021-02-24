#pragma once

#include <iostream>
#include <stdlib.h>
using namespace std;

constexpr int SIZE = 3;
const char initialBoard[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

class Board
{
public:
	char board[3][3];

	Board(); 
	~Board() = default;
	void displayBoard();
	bool updateBoard(int row, int column, char value);
	int evaluate();
	bool isMovesLeft();
	bool isCellEmpty(int row, int column);

private:
	/*char board[SIZE][SIZE];*/

};