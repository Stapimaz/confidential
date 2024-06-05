//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_KNIGHT_THREAT_H
#define CSTECH_KNIGHT_THREAT_H


#include "board.h"
#include "current_color_check.h"


bool isKnightThreat(int posX, int posY, const Board &currentBoard) {


    std::string possibleThreatPiece;

    if(currentPieceColor(posX, posY, currentBoard) == 'b')
        possibleThreatPiece = "as";
    else if(currentPieceColor(posX, posY, currentBoard) == 's')
        possibleThreatPiece = "ab";




    int knightMoves[8][2] = {
            { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 },
            { 2,  1 }, { 1,  2 }, { -1,  2 }, { -2,  1 }
    };

    for (int i = 0; i < 8; ++i) {
        int newX = posX + knightMoves[i][0];
        int newY = posY + knightMoves[i][1];
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
            if (currentBoard.board[newX][newY] == possibleThreatPiece) {
                return true;
            }
        }
    }
    return false;



}

#endif //CSTECH_KNIGHT_THREAT_H
