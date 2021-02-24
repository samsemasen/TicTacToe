#include <iostream>
#include "MiniMax.h" 

/// <summary>
/// Finds the best possible move for the COMPUTER[O]
/// </summary>
/// <param name="board"></param>
Move MiniMax::findBestMove(Board* board)
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
            bool isEmpty = board->isCellEmpty(i, j);
            if (isEmpty)
            {
                // Make the move
                board->board[i][j] = opponent; 

                // compute evaluation function for this move.             
                // ismax = true because computer makes its turn and we are checking after that 
                int moveVal = minimax(board, 0, true, MIN, MAX);            
                
                // Undo the move
                board->board[i][j] = initialBoard[i][j];

                // If the value of the current move is
                // less than the best value, then update
                // best // COMPUTER[O] --> Minimizer
                if (moveVal < bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    //cout << "\n The value of the best Move is :" << bestVal << " \n";

    return bestMove;
}



/// <summary>
//  This function considers all the possible ways the game can go 
/// </summary>
/// <param name="board"></param>
/// <param name="depth">-->depth of the board</param>
/// <param name="isMax">-->Player[X] is Maximizer, Computer[O] is Minimizer</param>
/// <param name="alpha">-->the best value that the maximizer currently can guarantee at that level or above.</param>
/// <param name="beta">--> the best value that the minimizer currently can guarantee at that level or above</param>
/// <returns>the value of the board</returns>
int MiniMax::minimax(Board* board, int depth, bool isMax, int alpha, int beta)
{
    int score = board->evaluate();

    // If Maximizer has won the game return his/her evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then it is a tie
    if (!board->isMovesLeft())
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
                if (board->isCellEmpty(i, j))
                {
                    // Make the move
                    board->board[i][j] = player;

                    // Call minimax recursively and choose the maximum value
                    best = max(best, minimax(board, depth + 1, !isMax, alpha, beta));

                    // Undo the move
                    board->board[i][j] = initialBoard[i][j];

                    alpha = max(alpha, best);
                    // Alpha Beta Pruning 
                    if (beta <= alpha)
                        return best;
                    
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
                if (board->isCellEmpty(i, j))
                {
                    // Make the move
                    board->board[i][j] = opponent;

                    // Call minimax recursively and choose the minimum value
                    best = min(best, minimax(board, depth + 1, !isMax, alpha, beta));

                    // Undo the move
                    board->board[i][j] = initialBoard[i][j];
                
                    beta = min(beta, best);
                    // Alpha Beta Pruning 
                    if (beta <= alpha)
                        return best;
                }
            }
        }
        return best;
    }
}



