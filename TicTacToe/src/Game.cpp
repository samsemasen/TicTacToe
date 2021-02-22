
#include <iostream>
#include <stdlib.h>
#include "Game.h"
using namespace std;

Game::Game(Board* board) :
    board_(board) // Initializing member variable board_
{}


void Game::run() {

    cout << "\t\tT I C  T A C  T O E  G A M E \n";
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
            cout << "\nCongratulations!Player with 'O' has won the game";
            break;
        }

    }

    if (evaluatedValue == 0) {
        cout << "\nGAME DRAW!!!\n";
    }

    cout << "\nGAME OVER!!!\n";
}



void Game::playerTurn() {
    /*turn = 'X';*/
    cout << "\tPlayer - 1 [X] turn : ";

    /*Taking input from user
    updating the board according to choice and reassigning the turn Start*/

    cin >> choice;

    /*switch case to get which row and column will be update*/

    switch (choice) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "Invalid Move";
    }

    bool updated = board_->updateBoard(row, column, turn);

  /*  if (updated)
        computerTurn();
    else 
        playerTurn();*/

    if (updated)
        turn = 'O';
    else
        turn = 'X';

}

void Game::computerTurn()
{
    /*turn = 'O';*/
    cout << "\tPlayer - 2 [O] turn : ";

    MiniMax minimax;
    Move bestMove = minimax.findBestMove(*board_);

    bool updated = board_->updateBoard(bestMove.row, bestMove.col, turn);

    //if (updated)
    //    playerTurn();    
    //else
    //    computerTurn();

    if (updated)
        turn = 'X';
    else
        turn = 'O';
       
}




