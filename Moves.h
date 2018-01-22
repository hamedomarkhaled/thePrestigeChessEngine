#ifndef MOVES_H
#define MOVES_H
#include <vector>
using std::vector;
const int NUMBER_OF_SQUARES(64);
/**WHY VECTOR PROBLEM**/
/**
0  1  2  3  4  5  6  7
8  9  10 11 12 13 14 15
16 17 18 19 20 21 22 23 always black
24 25 26 27 28 29 30 31
32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47
48 49 50 51 52 53 54 55 always white
56 57 58 59 60 61 62 63
**/
/**
TO-DO handling special moves Castling , Pawn Promotion, En Passant
**/
class Moves{
public:

    vector <vector < int > > whitePawnsMoves;

    vector <vector < int > > blackPawnsMoves;

    vector <vector < int > > knightMoves;

    vector <vector < int > > blackBishopMoves;

    vector <vector < int > > whiteBishopMoves;

    vector <vector < int > > rookMoves;

    vector <vector < int > > queensMoves;

    vector <vector < int > > kingMoves;


    void genWhitePawnsMoves();
    void genBlackPawnsMoves();
    void genKnightMoves();
    void genBlackBishopMoves();
    void genWhiteBishopMoves();
    void genRookMoves();
    void genQueenMoves();
    void genKingMoves();

    static bool valid(int x, int y);

        Moves();
};
#endif // MOVES_H
