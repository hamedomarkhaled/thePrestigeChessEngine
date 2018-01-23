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
int Moves::to64Square(int x, int y){
    return x*8+y;
}
Moves::Moves():
    whitePawnsMoves(NUMBER_OF_SQUARES, vector<int>()),
    blackPawnsMoves(NUMBER_OF_SQUARES, vector<int>()),
    knightMoves(NUMBER_OF_SQUARES,  vector<int>()),
    blackBishopMoves(NUMBER_OF_SQUARES, vector<int>()),
    whiteBishopMoves(NUMBER_OF_SQUARES, vector<int>()),
    rookMoves(NUMBER_OF_SQUARES, vector<int>()),
    queensMoves(NUMBER_OF_SQUARES, vector<int>()),
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
    for(int i = 48;i>=8;i--){
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
        if(ROW(i) == 7)
            whitePawnsMoves[i].push_back(to64Square(x-2,y));
    }
}
void Moves::genBlackPawnsMoves(){
    for(int i = 8;i <=48;i++){
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
        if((x+y) % 2 == 1){
//            blackBishopMoves[i].push_back(to64Square(x,y));
            for(int j = x, k = y;valid(j,k); j--,k++){
                if(j==x && k==y) continue;
                blackBishopMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j--,k--){
                if(j==x && k==y) continue;
                blackBishopMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k--){
                if(j==x && k==y) continue;
                blackBishopMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k++){
                if(j==x && k==y) continue;
                blackBishopMoves[i].push_back(to64Square(j,k));
            }
        }

    }

}
void Moves::genWhiteBishopMoves(){
    for(int i = 0;i < 64;++i){
        int x = ROW(i);
        int y = COL(i);

        if((x+y) % 2 == 0){
//            whiteBishopMoves[i].push_back(to64Square(x,y));
            for(int j = x, k = y;valid(j,k); j--,k++){
                if(j==x && k==y) continue;
                whiteBishopMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j--,k--){
                if(j==x && k==y) continue;
                whiteBishopMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k--){
                if(j==x && k==y) continue;
                whiteBishopMoves[i].push_back(to64Square(j,k));
            }
            for(int j = x, k = y;valid(j,k); j++,k++){
                if(j==x && k==y) continue;
                whiteBishopMoves[i].push_back(to64Square(j,k));
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
            rookMoves[i].push_back(to64Square(j,k));
        }
        for(int j = x, k = y;valid(j,k);j++){
            if(j==x&&k==y) continue;
            rookMoves[i].push_back(to64Square(j,k));
        }
        for(int j = x, k = y;valid(j,k);k--){
            if(j==x&&k==y) continue;
            rookMoves[i].push_back(to64Square(j,k));
        }
        for(int j = x, k = y;valid(j,k);k++){
            if(j==x&&k==y) continue;
            rookMoves[i].push_back(to64Square(j,k));
        }


    }
}
void Moves::genQueenMoves(){
    for(int i = 0;i < 64;i++){
        for(int j = 0;j < (int)rookMoves[i].size();j++){
            queensMoves[i].push_back(rookMoves[i][j]);
        }
        int x=ROW(i);
        int y = COL(i);
        if( (x+y)%2 == 1){
            //black
            for(int j = 0;j < (int)blackBishopMoves.size();j++){
                queensMoves[i].push_back(blackBishopMoves[i][j]);
            }
        }
        else{
            for(int j = 0;j < (int)whiteBishopMoves.size();j++){
                queensMoves[i].push_back(whiteBishopMoves[i][j]);
            }
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
