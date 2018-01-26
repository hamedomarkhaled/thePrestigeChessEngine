#include "Board.h"
#include "Pieces.h"
#include "iostream"

/** initial board() **/
Board::Board():
    score(0),
    blackCheck(0),
    blackMate(0),
    whiteCheck(0),
    whiteMate(0),
    stalMate(0),
    fiftyMoveRule(0),
    repeatedMove(0),
    blackCastled(0),
    blackCanCastle(0),
    whiteCanCastle(0),
    whiteCastled(0),
    endGamePhase(0),
    whosMove(COLOR_WHITE),
    moveCount(0){
        std::cout << "BOARD\n";
    }
