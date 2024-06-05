//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_PAWN_THREAT_H
#define CSTECH_PAWN_THREAT_H


#include "board.h"
#include "current_color_check.h"


bool isPawnThreat(int satir, int sutun, const Board &currentBoard) {   //mevcut taşın rakip piyon tarafından tehditini kontrol eden fonksiyon

    std::string possibleThreatPiece;   //rakip piyon ps mi pb mi, mevcut piyonun son harfine bakılarak bulunuyor

    if(currentPieceColor(satir, sutun, currentBoard) == 'b')
        possibleThreatPiece = "ps";
    else if(currentPieceColor(satir, sutun, currentBoard) == 's')
        possibleThreatPiece = "pb";

        if(possibleThreatPiece == "ps") {                   //Rakip ps ise yukarı çaprazlardan saldırabilir, kontrol ediliyor
            if (satir - 1 >= 0 && sutun - 1 >= 0 &&
                currentBoard.board[satir - 1][sutun - 1] == "ps")
                return true;
            else if ((satir - 1 >= 0 && sutun + 1 < BOARD_SIZE) &&
                currentBoard.board[satir - 1][sutun + 1] == "ps")
                return true;
            else
                return false;
        }

        else if(possibleThreatPiece == "pb") {              //Rakip pb ise aşağı çaprazlardan saldırabilir, kontrol ediliyor
              if (satir + 1 < BOARD_SIZE && sutun - 1 >= 0 &&
              currentBoard.board[satir + 1][sutun - 1] == "pb"){
                    return true;}
              else if (satir + 1 < BOARD_SIZE && sutun + 1 < BOARD_SIZE &&
                  currentBoard.board[satir + 1][sutun + 1] == "pb")
                    return true;
              else
                  return false;
        }
        else
            return false;
}


#endif //CSTECH_PAWN_THREAT_H