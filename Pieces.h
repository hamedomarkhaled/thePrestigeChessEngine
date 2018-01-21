#ifndef PIECE_H
#define PIECE_H
#include <stack>
#include <bitset>

//typedef std::bitset<8> BYTE;
enum PieceColor{
    COLOR_WHITE,
    COLOR_BLACK,
    COLOR_NONE,
};
enum PieceType{
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN,
    NONE, // WHY!
};


class Piece{
public:
Piece(PieceType T, PieceColor C);
PieceColor pieceColor;
PieceType pieceType;


    int pieceValue;
    int pieceActionValue;
    int attackedValue;
    int defendedValue;
    bool selected; /** GUI**/
    bool moved;
    int lastValidMoveCnt;
    std::stack <int> validMoves;
    int calculatePieceValue(PieceType T);
    int calculateActionValue(PieceType T);

};
#endif // PIECE_H
