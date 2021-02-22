#include <iostream>
#include <stdlib.h>
#include "MiniMax.h"
#include "Game.h"

using namespace std;

int main()
{
//    // The number of elements in scores must be 
//// a power of 2. 
//    int scores[] = { 3, 5, 2, 9, 12, 5, 23, 23 };
//    int n = sizeof(scores) / sizeof(scores[0]);
//
//    MiniMax miniMax;
//    int h = miniMax.log2(n);
//    int res = miniMax.miniMax(0, 0, true, scores, h);
//
//    cout << "The optimal value is : " << res << endl;
//    return 0;



    
    Board* newBoard = new Board;
    Game game(newBoard);
    game.run();

}