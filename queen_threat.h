//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_QUEEN_THREAT_H
#define CSTECH_QUEEN_THREAT_H



#include "board.h"
#include "current_color_check.h"




bool isQueenThreat(int satir, int sutun, const Board &currentBoard) { //mevcut taş rakip vezir tarafından tehdit ediliyor mu kontrol eden fonks.


    std::string possibleThreatPiece; //mevcut taşın son rengine göre rakip vs mi vb mi belirleniyor

    if(currentPieceColor(satir, sutun, currentBoard) == 'b')
        possibleThreatPiece = "vs";
    else if(currentPieceColor(satir, sutun, currentBoard) == 's')
        possibleThreatPiece = "vb";



                                                // mevcut taşın sağına bakılıyor
        for (int i = sutun + 1; i < 8; ++i) {
            if (currentBoard.board[satir][i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[satir][i] != "--") {
                break; // vezirin yolunu kesen başka taş varsa tehdit edemez, break
            }
        }

                                             // mevcudun soluna bakılıyor
        for (int i = sutun - 1; i >= 0; --i) {
            if (currentBoard.board[satir][i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[satir][i] != "--") {
                break;
            }
        }

                                    // yukarı bakılıyor
        for (int i = satir - 1; i >= 0; --i) {
            if (currentBoard.board[i][sutun] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[i][sutun] != "--") {
                break;
            }
        }

                                    // aşağı bakılıyor
        for (int i = satir + 1; i < 8; ++i) {
            if (currentBoard.board[i][sutun] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[i][sutun] != "--") {
                break;
            }
        }


                                     // sağ üst çapraz
        for (int i = 1; satir - i >= 0 && sutun + i < 8; ++i) {
            if (currentBoard.board[satir - i][sutun + i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[satir - i][sutun + i] != "--") {
                break;
            }
        }

                                    // sol üst çapraz
        for (int i = 1; satir - i >= 0 && sutun - i >= 0; ++i) {
            if (currentBoard.board[satir - i][sutun - i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[satir - i][sutun - i] != "--") {
                break;
            }
        }

                                    // sağ alt çapraz
        for (int i = 1; satir + i < 8 && sutun + i < 8; ++i) {
            if (currentBoard.board[satir + i][sutun + i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[satir + i][sutun + i] != "--") {
                break;
            }
        }

                                    // sol alt çapraz
        for (int i = 1; satir + i < 8 && sutun - i >= 0; ++i) {
            if (currentBoard.board[satir + i][sutun - i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[satir + i][sutun - i] != "--") {
                break;
            }
        }
    return false; // tehdit yoksa


}

#endif //CSTECH_QUEEN_THREAT_H
