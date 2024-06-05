//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_MAIN_THREAT_CHECK_H
#define CSTECH_MAIN_THREAT_CHECK_H


#include "board.h"
#include "pawn_threat.h."
#include "knight_threat.h"
#include "queen_threat.h"


bool isUnderThreat(int satir, int sutun, const Board &currentBoard){   //kontrol edilmesi gereken 3 tehdit durumu için
                                                                        //ilgili fonskiyonları çağırıyor
    if(isPawnThreat(satir, sutun, currentBoard) ||
    isKnightThreat(satir, sutun, currentBoard) ||               //en az 1 sayıda tehdit olup olmadığı önemli,
    isQueenThreat(satir, sutun, currentBoard))                  //true dönerse taşın puanı yarıya inecek
        return true;
    else
        return false;

}

#endif //CSTECH_MAIN_THREAT_CHECK_H