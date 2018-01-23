#ifndef VALIDMOVES_H
#define VALIDMOVES_H
#include "Moves.h"
#include "Board.h"
#include"iostream"
class ValidMoves{
public:
    ValidMoves();
    bool blackAttack[NUMBER_OF_SQUARES];
    bool whiteAttack[NUMBER_OF_SQUARES];

    int whiteKingPosition;
    int blackKingPosition;


    bool analyzeMove(Board &board, int src, Piece &pcMoving);

    void checkValidMovesPawn(Board &board, int dst, Piece &pcMoving, int src);
    void analyzeMovePawn(Board &board, int dst, Piece &pcMoving);
    /**TO-generatingValidMethods**/
    void generateValidMovesKingCastle(Board &board, Piece &king);
    void generateValidMovesKing(Piece &piece, Board &board, int src);
    void generateValidMoves(Board &board);
     /**Will be intialized from the engine **/
    Moves moves;

};
#endif // VALIDMOVES_H
