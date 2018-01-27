#ifndef BOARD_H
#define BOARD_H
#define ROW(INDEX) ((int)INDEX/8)
#define COL(INDEX) ((int)INDEX%8)
#define IS_BLACK(X,Y)  ((bool)((X+Y)&1))
#define IS_WHITE(X,Y)  (!(IS_BLACK(X,Y)))
#define to64Square(R,C) (R*8+C)
#include "Square.h"
#include "Pieces.h"
#include "Moves.h"

class Board{
public:
    Square squares[NUMBER_OF_SQUARES];
    int score;
    bool blackCheck;
    bool blackMate;
    bool whiteCheck;
    bool whiteMate;
    bool stalMate;

    int fiftyMoveRule;
    int repeatedMove;

    bool blackCastled;
    bool whiteCastled;
    bool blackCanCastle;
    bool whiteCanCastle;

    bool endGamePhase;

    /** MoveContent file LastMove**/
//    PieceColor enPassantPosition;

//    int enPassantPosition;

    PieceColor whosMove;

    int moveCount;
    /**CONSTRUCTORS**/
    Board();


};
#endif // BOARD_H
