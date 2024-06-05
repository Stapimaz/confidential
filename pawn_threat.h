//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_PAWN_THREAT_H
#define CSTECH_PAWN_THREAT_H


#include "board.h"
#include "current_color_check.h"




bool isPawnThreat(int posX, int posY, const Board &currentBoard) {

    std::string possibleThreatPiece;

    if(currentPieceColor(posX, posY, currentBoard) == 'b')
        possibleThreatPiece = "ps";
    else if(currentPieceColor(posX, posY, currentBoard) == 's')
        possibleThreatPiece = "pb";


                                                                                //piyon tehditinde mi
        if(currentBoard.board[posX+1][posY+1] == possibleThreatPiece)
            return true;
        if(currentBoard.board[posX-1][posY+1] == possibleThreatPiece)
            return true;


         return false;


}


#endif //CSTECH_PAWN_THREAT_H
