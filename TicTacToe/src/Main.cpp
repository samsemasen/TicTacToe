#include <iostream>
#include <stdlib.h>
#include "Game.h"


int main()
{
    Board* newBoard = new Board;
    Game game(newBoard);

    game.run();

    delete newBoard; // freeing space 
    return 0;
}