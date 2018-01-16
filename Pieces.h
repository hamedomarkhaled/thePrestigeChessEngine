#ifndef PIECE_H
#define PIECE_H
#include <stack>
#include <bitset>

typedef std::bitset<8> BYTE;

enum PieceColor{
    WHITE,
    BLACK,
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
     Piece(PieceColor C,PieceType T);
private:
    PieceColor pieceColor;
    PieceType pieceType;
    int pieceValue;
    int pieceActionValue;
    int attackedValue;
    int defendedValue;
    bool selected; /** GUI**/
    bool moved;
    std::stack <BYTE> validMoves;
    int calculatePieceValue(PieceType T);
    int calculateActionValue(PieceType T);

};
#endif // PIECE_H
