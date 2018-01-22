#include "ValidMoves.h"
bool ValidMoves::analyzeMove(Board &board, int index, Piece &pcMoving){
    if(pcMoving.pieceColor == COLOR_WHITE)
        whiteAttack[index]=true;
    else
        blackAttack[index]=true;

    if(board.squares[index].piece.pieceType == NONE){
        pcMoving.validMoves.push(index);
        return true;
    }

    Piece pcAttacked = board.squares[index].piece;
    if(pcAttacked.pieceColor != pcMoving.pieceColor){
        pcAttacked.attackedValue += pcMoving.pieceActionValue;
        if(pcAttacked.pieceType == KING){
            if(pcAttacked.pieceColor == COLOR_BLACK)
                board.blackCheck = true;
            else
                board.whiteCheck = true;
        }
        else{
            pcMoving.validMoves.push(index);
        }
        /**WHY FALSE!!*/
        return false;

    }
    pcAttacked.defendedValue += pcMoving.pieceActionValue;
    return false;
}
void ValidMoves::checkValidMovesPawn(Board &board, int dst, Piece &pcMoving, int src){

        if(COL(src) != COL(dst)){
            analyzeMovePawn(board, dst, pcMoving);
            if(pcMoving.pieceColor == COLOR_WHITE)
                whiteAttack[dst] = true;
            else
                blackAttack[dst] = true;
        }
        else if(board.squares[dst].piece.pieceType != NONE)
            return ;
        else
            pcMoving.validMoves.push(dst);

}
void ValidMoves::analyzeMovePawn(Board &board, int dst, Piece &pcMoving){
    /**Ignnnore En Passant**/
    Piece pcAttacked = board.squares[dst].piece;
    if(pcAttacked.pieceType == NONE)
        return;
    if(pcMoving.pieceColor == COLOR_WHITE){
        whiteAttack[dst] = true;
        if(pcAttacked.pieceColor == pcMoving.pieceColor){
            pcAttacked.defendedValue += pcMoving.pieceActionValue;
        return;

        }
        pcAttacked.attackedValue += pcMoving.pieceActionValue;
        if(pcAttacked.pieceType == KING){
            board.blackCheck = true;

        }
        else{
            pcMoving.validMoves.push(dst);
        }
    }
    else{
        blackAttack[dst] = true;
        if(pcAttacked.pieceColor == pcMoving.pieceColor){
            pcAttacked.defendedValue += pcMoving.pieceActionValue;
        return;
        }
        if(pcAttacked.pieceType == KING){
            board.whiteCheck = true;
        }
        else{
            pcMoving.validMoves.push(dst);
        }

    }
    return ;
}
void ValidMoves::generateValidMovesKing(Piece &piece, Board &board, int src){
    if(piece.pieceType == NONE) return ;
    for(int i = 0;(int)moves.kingMoves[src].size();i++){
        int dst=moves.kingMoves[src][i];
        if(piece.pieceColor == COLOR_WHITE ){
            if(blackAttack[dst]){
                whiteAttack[dst]=true;
                continue;
            }
        }
        else{
            if(whiteAttack[dst]){
                whiteAttack[dst]=true;
                continue;
            }
        }
        analyzeMove(board, dst, piece);
    }
}
void ValidMoves::generateValidMovesKingCastle(Board &board, Piece &king){
	if(king.pieceType == NONE || king.moved ||
	   (king.pieceColor == COLOR_WHITE && (board.whiteCastled || board.whiteCheck)) ||
	   (king.pieceColor == COLOR_BLACK && (board.blackCastled || board.blackCheck)))
		return;

	int pieceRow = ((king.pieceColor == COLOR_WHITE) ? 7 : 0);
	const bool *opponentAttack = ((king.pieceColor == COLOR_WHITE) ? blackAttack : whiteAttack);
	bool *allyAttack = ((king.pieceColor == COLOR_WHITE) ? whiteAttack : blackAttack);
	int rightKnight64 = to64Square(pieceRow,6),
	    rightBishop64 = to64Square(pieceRow,5),
		queen64 = to64Square(pieceRow,3),
		leftBishop64 = to64Square(pieceRow,2);
	const Piece &rightRookPiece = board.squares[to64Square(pieceRow,7)].piece;
	const Piece &rightKnightPiece = board.squares[rightKnight64].piece;
	const Piece &rightBishopPiece = board.squares[rightBishop64].piece;
	const Piece &queenPiece = board.squares[queen64].piece;
	const Piece &leftBishopPiece = board.squares[leftBishop64].piece;
	const Piece &leftKnightPiece = board.squares[to64Square(pieceRow,1)].piece;
	const Piece &leftRookPiece = board.squares[to64Square(pieceRow,0)].piece;

	if((rightRookPiece.pieceType == ROOK) &&
	   (!rightRookPiece.moved) &&
	   (rightRookPiece.pieceColor == king.pieceColor) && // redundant?
	   (rightKnightPiece.pieceType == NONE) &&
	   (rightBishopPiece.pieceType == NONE) &&
	   (!opponentAttack[rightBishop64]) &&
	   (!opponentAttack[rightKnight64])){
		   king.validMoves.push(rightKnight64);
		   allyAttack[rightKnight64] = true;
	}
	if((leftRookPiece.pieceType == ROOK) &&
	   (!leftRookPiece.moved) && // not sure
	   (leftRookPiece.pieceColor == king.pieceColor) && // redundant?
	   (leftKnightPiece.pieceType == NONE) &&
	   (leftBishopPiece.pieceType == NONE) &&
	   (queenPiece.pieceType == NONE) &&
	   (!opponentAttack[queen64]) &&
	   (!opponentAttack[leftBishop64])){
		   king.validMoves.push(leftBishop64);
		   allyAttack[leftBishop64] = true;
	}
}
void ValidMoves::generateValidMoves(Board &board){
    board.blackCheck=false;
    board.whiteCheck=false;
    int blackRooksMoved=0;
    int whiteRooksMoved=0;
    int remainingPieces=0;

    for(int index = 0;index < NUMBER_OF_SQUARES;index++){

        Square sqr = board.squares[index];
        if(sqr.piece.pieceType == NONE)
            continue;
    remainingPieces++;
    switch(sqr.piece.pieceType){
        case PAWN:{
            if(sqr.piece.pieceColor == COLOR_WHITE){
                for(int i = 0;i < (int)moves.whitePawnsMoves[index].size();i++)
                    checkValidMovesPawn(board, moves.whitePawnsMoves[index][i], sqr.piece, index);

            }
            else if (sqr.piece.pieceColor == COLOR_BLACK){
                for(int i = 0;i < (int)moves.blackPawnsMoves[index].size();i++)
                    checkValidMovesPawn(board, moves.blackPawnsMoves[index][i], sqr.piece,index);

            }
            break;
        }
        case KNIGHT:{
            for(int i = 0;i < (int)moves.knightMoves[index].size();i++){
                analyzeMove(board,moves.knightMoves[index][i] , sqr.piece);
            }
            break;
        }
        case BISHOP:{
            int x = ROW(index);
            int y = COL(index);
            if(IS_BLACK(x,y)){
                //BLACK
                for(int i = 0;i < (int)moves.blackBishopMoves[index].size();i++){
                    analyzeMove(board, moves.blackBishopMoves[index][i], sqr.piece);
                }
                break;
            }
            else{
                //WHITE
                for(int i = 0;i < (int)moves.whiteBishopMoves[index].size();i++){
                    analyzeMove(board, moves.whiteBishopMoves[index][i], sqr.piece);
                }
                break;
            }
        }
        case ROOK:{
            if(sqr.piece.moved && sqr.piece.pieceColor == COLOR_WHITE) whiteRooksMoved++;
            if(sqr.piece.moved && sqr.piece.pieceColor == COLOR_BLACK) blackRooksMoved++;
            for(int i = 0;i < (int)moves.rookMoves[index].size();i++){
                    analyzeMove(board, moves.rookMoves[index][i], sqr.piece);
            }
            break;
        }
        case QUEEN:{
            for(int i = 0;i < (int)moves.queensMoves[index].size();i++){
                    analyzeMove(board, moves.queensMoves[index][i], sqr.piece);
            }
            break;
        }
        case KING:{
            if(sqr.piece.pieceColor == COLOR_WHITE){
                if(sqr.piece.moved){
                    board.whiteCanCastle=0;
                }
                whiteKingPosition = index;
            }
            else if(sqr.piece.pieceColor == COLOR_BLACK){
                if(sqr.piece.moved){
                    board.blackCanCastle=0;
                }
                blackKingPosition = index;

            }
            break;
        }


    }


    }
    if(blackRooksMoved > 1) board.blackCanCastle = 0;
        if(whiteRooksMoved > 1) board.whiteCanCastle = 0;
        if(remainingPieces < 10) board.endGamePhase = 1;
        if(board.whosMove == COLOR_WHITE){
            generateValidMovesKing(sqr.piece, board, blackKingPosition);
            generateValidMovesKing(sqr.piece, board, whiteKingPosition);
        }
        else if(board.whosMove == COLOR_BLACK){
            generateValidMovesKing(sqr.piece, board, whiteKingPosition);
        generateValidMovesKing(sqr.piece, board, blackKingPosition);

        }
        if(!board.whiteCastled && board.whiteCanCastle && !board.whiteCheck)
            generateValidMovesKingCastle(board, sqr.piece);
        if(!board.blackCastled && board.blackCanCastle && !board.blackCheck)
            generateValidMovesKingCastle(board, sqr.piece);

}
