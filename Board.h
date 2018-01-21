#ifndef BOARD_H
#define BOARD_H
#define ROW(INDEX) ((int)INDEX/8)
#define COL(INDEX) ((int)INDEX%8)
#include "Square.h"
#include "Pieces.h"

class Board{
public:
    Square squares[64];
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
//    PieceColor enPassantColor;

    int enPassantPosition;

    PieceColor whosMove;

    int moveCount;
    /**CONSTRUCTORS**/
    Board();







};
#endif // BOARD_H
