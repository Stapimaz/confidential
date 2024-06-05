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

    void firstPieceValue(int posX, int posY, const Board &currentBoard) {
        std::string piece = currentBoard.board[posX][posY];
        char type = piece[0];
        if (type == '-') {
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

        //DEBUG
        std::cout << type << "   type \n";

        //DEBUG
        std::cout << firstValue << "   FrstVALUE \n";

    }

    void finalPieceValue(int posX, int posY, const Board &currentBoard){

        if(isUnderThreat(posX, posY, currentBoard))
            finalValue = firstValue*0.5;
        else
            finalValue = firstValue;

    }

};

#endif //CSTECH_PIECE_H
