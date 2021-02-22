
#include <iostream>
#include "MiniMax.h" 
using namespace std;
//
//MiniMax::MiniMax(Board* board) : board_(board) {}


// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int MiniMax::minimax(Board board, int depth, bool isMax)
{
    int score = board.evaluate();

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (!board.isMovesLeft())
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board.isCellEmpty(i,j))
                {
                    // Make the move
                    board.board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max(best,
                        minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board.board[i][j] = '.';
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board.isCellEmpty(i, j))
                {
                    // Make the move
                    board.board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                        minimax(board, depth + 1, !isMax));

                    // Undo the move
                    board.board[i][j] = '.';
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the opponent
Move MiniMax::findBestMove(Board board)
{
    int bestVal = +1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.isCellEmpty(i,j))
            {
                // Make the move
                board.board[i][j] = opponent;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);//true??

                // Undo the move
                board.board[i][j] = '.';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal < bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move is : %d\n\n",
        bestVal);

    return bestMove;
}

