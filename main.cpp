#include <iostream>
#include "Pieces.h"
#include "Moves.h"
#include "Board.h"
#include "ValidMoves.h"
using namespace std;
int convert(int x, int y){
    return x*8+y;
}
int main()
{

    Board board;

    for(int i = 0, j = 48;i < 16;i++,j++){
//        std::cout << i << " " << j << "\n";
        board.squares[i].piece.pieceColor=COLOR_BLACK;
        board.squares[j].piece.pieceColor=COLOR_WHITE;
    }

    for(int i = 8, j = 48;i < 16;i++, j++){
        board.squares[i].piece.pieceType =PAWN;
        board.squares[j].piece.pieceType =PAWN;
    }
    board.squares[60].piece.pieceType =KING;
    board.squares[4].piece.pieceType = KING;
    board.squares[59].piece.pieceType =QUEEN;
    board.squares[3].piece.pieceType = QUEEN;
    board.squares[0].piece.pieceType =ROOK;
    board.squares[7].piece.pieceType = ROOK;
    board.squares[56].piece.pieceType =ROOK;
    board.squares[63].piece.pieceType = ROOK;
    board.squares[62].piece.pieceType =KNIGHT;
    board.squares[57].piece.pieceType = KNIGHT;
    board.squares[6].piece.pieceType =KNIGHT;
    board.squares[1].piece.pieceType = KNIGHT;

    board.squares[61].piece.pieceType =BISHOP;
    board.squares[58].piece.pieceType = BISHOP;
    board.squares[2].piece.pieceType =BISHOP;
    board.squares[5].piece.pieceType = BISHOP;
    for(int i = 0;i <8;i++){
        for(int j = 0;j < 8;j++){
            switch(board.squares[convert(i, j)].piece.pieceType){
                case PAWN:{
                    std::cout << "P ";
                    break;
                }
                case KING:{
                    std::cout << "K ";
                    break;
                }
                case QUEEN:{
                    std::cout << "Q ";
                    break;
                }
                case KNIGHT:{
                    std::cout << "N ";
                    break;
                }
                case BISHOP:{
                    std::cout << "B ";
                    break;
                }
                case ROOK:{
                    std::cout << "R ";
                    break;
                }
                case NONE:{
                    std::cout << ". ";
                    break;
                }

            }
        }
        std:: cout << "\n";
    }
    ValidMoves VM;
    VM.generateValidMoves(board);
////    for(int i = 0;i < VM.moves.knightMoves[62].size();i++){
////        std::cout << "Possible Square " << VM.moves.knightMoves[62][i] << " is analyzed as " <<
////        VM.analyzeMove(board, VM.moves.knightMoves[62][i], board.squares[62].piece)<<"\n";
////    }
////    std::cout << board.squares[62].piece.validMoves.size() <<"\n";
////    while(!board.squares[62].piece.validMoves.empty()){
////        int x = board.squares[62].piece.validMoves.top();
////        board.squares[62].piece.validMoves.pop();
////        std::cout << x << "\n";
////
////    }
    for(int i = 0;i < NUMBER_OF_SQUARES;i++){
        if(board.squares[i].piece.pieceType != NONE){
            std::cout << board.squares[i].piece.pieceType << " "
            << board.squares[i].piece.pieceColor<< " " << board.squares[i].piece.validMoves.size() << "\n";
        }
    }
//    std::cout << board.squares[50].piece.validMoves.size() << "\n";
//    while(!board.squares[50].piece.validMoves.empty()){
//        int x = board.squares[50].piece.validMoves.top();
//        board.squares[50].piece.validMoves.pop();
//        std::cout << x << "\n";
//    }
    return 0;
}
