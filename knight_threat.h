//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_KNIGHT_THREAT_H
#define CSTECH_KNIGHT_THREAT_H


#include "board.h"
#include "current_color_check.h"


bool isKnightThreat(int satir, int sutun, const Board &currentBoard) { // mevcut taş rakip at tarafından tehdit ediliyor mu kontrol eden fonskyion


    std::string possibleThreatPiece;  //mevcut taşın rengine bakılarak rakip as mi ab mi belirleniyor

    if(currentPieceColor(satir, sutun, currentBoard) == 'b')
        possibleThreatPiece = "as";
    else if(currentPieceColor(satir, sutun, currentBoard) == 's')
        possibleThreatPiece = "ab";




    int knightMoves[8][2] = {  //atın yapabileceği tüm hareketler
            { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 },
            { 2,  1 }, { 1,  2 }, { -1,  2 }, { -2,  1 }
    };

    for (int i = 0; i < 8; ++i) { //atın tehdit oluşturabileceği tüm konumlar kontrol ediliyor
        int newSatir = satir + knightMoves[i][0];
        int newSutun = sutun + knightMoves[i][1];
        if (newSatir >= 0 && newSatir < 8 && newSutun >= 0 && newSutun < 8) {
            if (currentBoard.board[newSatir][newSutun] == possibleThreatPiece) {
                return true;
            }
        }
    }
    return false;

}

#endif //CSTECH_KNIGHT_THREAT_H