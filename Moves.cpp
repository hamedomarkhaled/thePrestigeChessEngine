#include "Moves.h"
#include "Board.h"
#include "iostream"
/**
0  1  2  3  4  5  6  7
8  9  10 11 12 13 14 15 always black
16 17 18 19 20 21 22 23
24 25 26 27 28 29 30 31
32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47
48 49 50 51 52 53 54 55 always white
56 57 58 59 60 61 62 63
**/
/**Black Bishop is meant for the square**/


bool Moves::valid(int x, int y){
    if(x<0||y<0||x>7||y>7) return 0;
    return 1;
}
Moves::Moves():
    whitePawnsMoves(NUMBER_OF_SQUARES, vector<int>()),
    blackPawnsMoves(NUMBER_OF_SQUARES, vector<int>()),
    knightMoves(NUMBER_OF_SQUARES,  vector<int>()),
    blackBishopNorthEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    blackBishopNorthWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    blackBishopSouthEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    blackBishopSouthWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    whiteBishopNorthEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    whiteBishopNorthWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    whiteBishopSouthEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    whiteBishopSouthWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    rookNorthMoves(NUMBER_OF_SQUARES,  vector<int>()),
    rookSouthMoves(NUMBER_OF_SQUARES,  vector<int>()),
    rookEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    rookWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensNorthMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensSouthMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensNorthEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensNorthWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensSouthEastMoves(NUMBER_OF_SQUARES,  vector<int>()),
    queensSouthWestMoves(NUMBER_OF_SQUARES,  vector<int>()),
    kingMoves(NUMBER_OF_SQUARES, vector<int>())
    {


    genWhitePawnsMoves();
    genBlackPawnsMoves();
    genKnightMoves();
    genBlackBishopMoves();
    genWhiteBishopMoves();
    genRookMoves();
    genQueenMoves();
    genKingMoves();
}
/** Add to pawn mkanoh**/
void Moves::genWhitePawnsMoves(){
    for(int i = 48;i<=63;i++){
        int x = ROW(i);
        int y = COL(i);
//        whitePawnsMoves[i].push_back(to64Square(x,y));
        if(valid(x-1, y)){
            whitePawnsMoves[i].push_back(to64Square(x-1,y));
        }
        if(valid(x-1, y-1)){
            whitePawnsMoves[i].push_back(to64Square(x-1,y-1));
        }
        if(valid(x-1, y+1)){
            whitePawnsMoves[i].push_back(to64Square(x-1,y+1));
        }
        if(ROW(i) == 6)
            whitePawnsMoves[i].push_back(to64Square(x-2,y));
    }
}
void Moves::genBlackPawnsMoves(){
    for(int i = 8;i <=15;i++){
        int x = ROW(i);
        int y = COL(i);

//        blackPawnsMoves[i].push_back(to64Square(x,y));
        if(valid(x+1, y)){
            blackPawnsMoves[i].push_back(to64Square(x+1, y));
        }
        if(valid(x+1, y-1)){
            blackPawnsMoves[i].push_back(to64Square(x+1, y-1));
        }
        if(valid(x+1, y+1)){
            blackPawnsMoves[i].push_back(to64Square(x+1, y+1));
        }
        if(ROW(i) == 1)
            blackPawnsMoves[i].push_back(to64Square(x+2,y));
    }
}
void Moves::genKnightMoves(){
    for(int i = 0;i <=63;i++){
        int x = ROW(i);
        int y = COL(i);
        if(valid(x-2, y+1)){
            knightMoves[i].push_back(to64Square(x-2, y+1));
        }
        if(valid(x-2, y-1)){
            knightMoves[i].push_back(to64Square(x-2, y-1));
        }
        if(valid(x+2, y+1)){
            knightMoves[i].push_back(to64Square(x+2, y+1));
        }
        if(valid(x+2, y-1)){
            knightMoves[i].push_back(to64Square(x+2, y-1));
        }
        if(valid(x+1, y-2)){
            knightMoves[i].push_back(to64Square(x+1, y-2));
        }
        if(valid(x-1, y-2)){
            knightMoves[i].push_back(to64Square(x-1, y-2));
        }
        if(valid(x+1, y+2)){
            knightMoves[i].push_back(to64Square(x+1, y+2));
        }
        if(valid(x-1, y+2)){
            knightMoves[i].push_back(to64Square(x-1, y+2));
        }


    }
}
void Moves::genBlackBishopMoves(){
    for(int i = 0;i < 64;++i){
        int x = ROW(i);
        int y = COL(i);
        if(IS_BLACK(x,y)){
//            blackBishopMoves[i].push_back(to64Square(x,y));
            for(int j = x, k = y;valid(j,k); j--,k++){
                if(j==x && k==y) continue;
                blackBishopNorthEastMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j--,k--){
                if(j==x && k==y) continue;
                blackBishopNorthWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k--){
                if(j==x && k==y) continue;
                blackBishopSouthWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k++){
                if(j==x && k==y) continue;
                blackBishopSouthEastMoves[i].push_back(to64Square(j,k));
            }
        }

    }

}
void Moves::genWhiteBishopMoves(){
    for(int i = 0;i < 64;++i){
        int x = ROW(i);
        int y = COL(i);

        if(IS_WHITE(x,y)){
//            whiteBishopMoves[i].push_back(to64Square(x,y));
            for(int j = x, k = y;valid(j,k); j--,k++){
                if(j==x && k==y) continue;
                whiteBishopNorthEastMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j--,k--){
                if(j==x && k==y) continue;
                whiteBishopNorthWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k--){
                if(j==x && k==y) continue;
                whiteBishopSouthWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k++){
                if(j==x && k==y) continue;
                whiteBishopSouthEastMoves[i].push_back(to64Square(j,k));
            }
        }

    }
}
void Moves::genRookMoves(){
    for(int i = 0;i < 64;i++){
        int x=ROW(i);
        int y=COL(i);
//        rookMoves[i].push_back(to64Square(x,y));
        for(int j = x, k = y;valid(j,k);j--){
            if(j==x&&k==y) continue;
            rookNorthMoves[i].push_back(to64Square(j,k));
        }
        for(int j = x, k = y;valid(j,k);j++){
            if(j==x&&k==y) continue;
            rookSouthMoves[i].push_back(to64Square(j,k));
        }
        for(int j = x, k = y;valid(j,k);k--){
            if(j==x&&k==y) continue;
            rookWestMoves[i].push_back(to64Square(j,k));
        }
        for(int j = x, k = y;valid(j,k);k++){
            if(j==x&&k==y) continue;
            rookEastMoves[i].push_back(to64Square(j,k));
        }


    }
}
void Moves::genQueenMoves(){
    for(int i = 0;i < 64;i++){
        int x=ROW(i);
        int y = COL(i);
            for(int j = x, k = y;valid(j,k); j--,k++){
                if(j==x && k==y) continue;
                queensNorthEastMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j--,k--){
                if(j==x && k==y) continue;
                queensNorthWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k--){
                if(j==x && k==y) continue;
                queensSouthWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k++){
                if(j==x && k==y) continue;
                queensSouthEastMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k);j--){
                if(j==x&&k==y) continue;
                queensNorthMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k);j++){
                if(j==x&&k==y) continue;
                queensSouthMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k);k--){
                if(j==x&&k==y) continue;
                queensWestMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k);k++){
                if(j==x&&k==y) continue;
                queensEastMoves[i].push_back(to64Square(j,k));
            }
        }
}
void Moves::genKingMoves(){
    for(int i = 0;i < 64;i++){
        int x = ROW(i);
        int y = COL(i);
//        kingMoves[i].push_back(valid(x,y));
        if(valid(x+1, y))
            kingMoves[i].push_back(to64Square(x+1, y));
        if(valid(x-1, y))
            kingMoves[i].push_back(to64Square(x-1, y));
        if(valid(x-1, y+1))
            kingMoves[i].push_back(to64Square(x-1, y+1));
        if(valid(x+1, y+1))
            kingMoves[i].push_back(to64Square(x+1, y+1));
        if(valid(x, y+1))
            kingMoves[i].push_back(to64Square(x, y+1));
        if(valid(x, y-1))
            kingMoves[i].push_back(to64Square(x, y-1));
        if(valid(x-1, y-1))
            kingMoves[i].push_back(to64Square(x-1, y-1));
        if(valid(x+1, y-1))
            kingMoves[i].push_back(to64Square(x+1, y-1));

    }
}
