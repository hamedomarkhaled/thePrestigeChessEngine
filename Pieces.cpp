#include <stack>
#include <bitset>
#include "Pieces.h"


const int INF=1e9;



 Piece::Piece(PieceColor C,PieceType T):pieceColor(C), pieceType(T), moved(0){
     /**Constructor used to init() piece**/
     pieceValue=calculatePieceValue(T);
     /**Valid Move**/
}
 /**
 TO-DO when select piece again I will do the copy constructor
 Piece(){


 }**/
int Piece::calculatePieceValue(PieceType T){
     switch(T){
         case PAWN:
             return 100;
         case KNIGHT:
             return 320;
         case BISHOP:
             return 325;
         case ROOK:
             return 500;
         case QUEEN:
             return 975;
         case KING:
             return INF;
         default:
             return 0;
     }

 }
 int Piece::calculateActionValue(PieceType T){
     switch(T){
         case PAWN:
             return 6;
         case KNIGHT:
             return 3;
         case BISHOP:
             return 3;
         case ROOK:
             return 2;
         case QUEEN:
             return 1;
         case KING:
             return 1;
         default:
             return 0;
     }

 }
