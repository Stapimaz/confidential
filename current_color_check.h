//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_CURRENT_COLOR_CHECK_H
#define CSTECH_CURRENT_COLOR_CHECK_H


#include "board.h"




char currentPieceColor(int posX, int posY, const Board &currentBoard){
    std::string piece = currentBoard.board[posX][posY];
    return piece[1];
}


#endif //CSTECH_CURRENT_COLOR_CHECK_H
