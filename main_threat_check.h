//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_MAIN_THREAT_CHECK_H
#define CSTECH_MAIN_THREAT_CHECK_H




#include "board.h"
#include "pawn_threat.h."
#include "knight_threat.h"
#include "queen_threat.h"



bool isUnderThreat(int posX, int posY, const Board &currentBoard){

    if(isPawnThreat(posX, posY, currentBoard) ||
    isKnightThreat(posX, posY, currentBoard) ||
    isQueenThreat(posX, posY, currentBoard))
        return true;
    else
        return false;

}

#endif //CSTECH_MAIN_THREAT_CHECK_H