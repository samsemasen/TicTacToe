#include <iostream>
#include <stdlib.h>
#include "Game.h"
using namespace std;

Game::Game(Board* board) :
    board_(board) // Initializing member variable board_
{}


void Game::run() {

    cout << "TIC TAC TOE GAME -- PLAYER [X] , COMPUTER [O]\n\n\n ";

    board_->displayBoard();

    while (board_->isMovesLeft()) {

        if (turn == 'X')
            playerTurn();
        else
            computerTurn();

        board_->displayBoard();

        evaluatedValue = board_->evaluate();

        if (evaluatedValue == 10) {
            cout << "\nCongratulations!Player with 'X' has won the game";
            break;
        }
        else if (evaluatedValue == -10) {
            cout << "\nYou Lost! COMPUTER with 'O' has won the game";
            break;
        }

    }

    if (evaluatedValue == 0) {
        cout << "\nGAME DRAW!!!\n";
    }

    cout << "\nGAME OVER!!!\n";
}



/// <summary>
///  Taking input from user,
///  updating the board according to choice 
///  and reassigning the turn
/// </summary>
void Game::playerTurn() 
{
    cout << "\tPlayer [X]'s turn : ";
    cin >> choice;

    switch (choice) {
    case 1: row = 0; col = 0; break;
    case 2: row = 0; col = 1; break;
    case 3: row = 0; col = 2; break;
    case 4: row = 1; col = 0; break;
    case 5: row = 1; col = 1; break;
    case 6: row = 1; col = 2; break;
    case 7: row = 2; col = 0; break;
    case 8: row = 2; col = 1; break;
    case 9: row = 2; col = 2; break;
    default:
        cout << "Invalid Move";
    }

    bool updated = board_->updateBoard(row, col, turn);

    if (updated)
        turn = 'O';
    else
        turn = 'X';

}

/// <summary>
/// Finding best move using minimax algorithm, 
/// updating the board according to choice 
/// and reassigning the turn
/// </summary>
void Game::computerTurn()
{
    MiniMax minimax;
    Move bestMove = minimax.findBestMove(board_);

    bool updated = board_->updateBoard(bestMove.row, bestMove.col, turn);

    if (updated) {
        cout << "\tPlayer - 2 [O]'s turn : " << initialBoard[bestMove.row][bestMove.col] << "\n";
        turn = 'X';
    }   
    else
        turn = 'O';
       
}



