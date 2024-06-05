//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_PIECE_H
#define CSTECH_PIECE_H

#include "board.h"
#include "main_threat_check.h"


class Piece {

private:
    double firstValue{0};

public:
    double finalValue{0};



    void finalPieceValue(int satir, int sutun, const Board &currentBoard){


        std::string piece = currentBoard.board[satir][sutun];
        char type = piece[0];                                   //board matrisindeki taşların ilk hanesine bakılarak
        if (type == '-') {                                      //taşın türüne göre taşın ilk değerleri atanıyor
            firstValue = 0.0;
        } else {
            switch (type) {
                case 'p':
                    firstValue = 1.0;
                    break;
                case 'a':
                    firstValue = 3.0;
                    break;
                case 'f':
                    firstValue = 3.0;
                    break;
                case 'k':
                    firstValue = 5.0;
                    break;
                case 'v':
                    firstValue = 9.0;
                    break;
                case 's':
                    firstValue = 100.0;
                    break;
                default:
                    firstValue = 0.0;
                    break;
            }
        }











        if(isUnderThreat(satir, sutun, currentBoard)){
            finalValue = firstValue*0.5;}                   //Tehdit varsa taşın değeri yarıya iniyor
        else
            finalValue = firstValue;                        //yoksa taşın değeri sabit kalıyor

    }

};

#endif //CSTECH_PIECE_H
