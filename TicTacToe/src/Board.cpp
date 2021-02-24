#include "Board.h"

Board::Board()
{
    int value = 1;
	//initialize the board
	for ( int i = 0; i < SIZE; i++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			//board[i][y] = '.';
			board[i][y] = '0' + value++;
		}
	}
}

void Board::displayBoard() 
{

    cout << "PLAYER - 1 [X] \t PLAYER - 2 [O]\n";

    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t     |     |     \n";
}

bool Board::updateBoard(int row , int column , char value) 
{
    if (isCellEmpty(row,column)) 
    {
        board[row][column] = value;
        return true;
    }
    else 
    {
        cout << "this spot is already filled , please choose another spot \n";
        return false;
    }
        
}


int Board::evaluate()
{
    // Checking for Rows for X or O victory. 
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && 
            board[row][1] == board[row][2])
        {
            if (board[row][0] == 'X')
                return +10;
            else if (board[row][0] == 'O')
                return -10;
        }
    }

    // Checking for Columns for X or O victory. 
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && 
            board[1][col] == board[2][col])
        {
            if (board[0][col] == 'X')
                return +10;
            else if (board[0][col] == 'O')
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory. 
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 'X')
            return +10;
        else if (board[0][0] == 'O')
            return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == 'X')
            return +10;
        else if (board[0][2] == 'O')
            return -10;
    }

    // Else if none of them have won then return 0 
    return 0;
}
//board
//evoluation func


bool Board::isMovesLeft()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
    return false;
}

bool Board::isCellEmpty(int row , int column)
{
    if (board[row][column] != 'X' && board[row][column] != 'O')
        return true;
    else
        return false;
}
