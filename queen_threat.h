//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_QUEEN_THREAT_H
#define CSTECH_QUEEN_THREAT_H



#include "board.h"
#include "current_color_check.h"




bool isQueenThreat(int posX, int posY, const Board &currentBoard) {


    std::string possibleThreatPiece;

    if(currentPieceColor(posX, posY, currentBoard) == 'b')
        possibleThreatPiece = "vs";
    else if(currentPieceColor(posX, posY, currentBoard) == 's')
        possibleThreatPiece = "vb";


//VEZİR TEHDİTİ ALTINDA MI


        // Check horizontally to the right
        for (int i = posY + 1; i < 8; ++i) {
            if (currentBoard.board[posX][i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[posX][i] != "--") {
                break; // another piece is blocking the way
            }
        }

        // Check horizontally to the left
        for (int i = posY - 1; i >= 0; --i) {
            if (currentBoard.board[posX][i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[posX][i] != "--") {
                break; // another piece is blocking the way
            }
        }

        // Check vertically upwards
        for (int i = posX - 1; i >= 0; --i) {
            if (currentBoard.board[i][posY] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[i][posY] != "--") {
                break; // another piece is blocking the way
            }
        }

        // Check vertically downwards
        for (int i = posX + 1; i < 8; ++i) {
            if (currentBoard.board[i][posY] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[i][posY] != "--") {
                break; // another piece is blocking the way
            }
        }


        // Check diagonally top-right
        for (int i = 1; posX - i >= 0 && posY + i < 8; ++i) {
            if (currentBoard.board[posX - i][posY + i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[posX - i][posY + i] != "--") {
                break; // another piece is blocking the way
            }
        }

        // Check diagonally top-left
        for (int i = 1; posX - i >= 0 && posY - i >= 0; ++i) {
            if (currentBoard.board[posX - i][posY - i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[posX - i][posY - i] != "--") {
                break; // another piece is blocking the way
            }
        }

        // Check diagonally bottom-right
        for (int i = 1; posX + i < 8 && posY + i < 8; ++i) {
            if (currentBoard.board[posX + i][posY + i] == possibleThreatPiece) {
                return true;
            } else if (currentBoard.board[posX + i][posY + i] != "--") {
                break; // another piece is blocking the way
            }
        }

        // Check diagonally bottom-left
        for (int i = 1; posX + i < 8 && posY - i >= 0; ++i) {
            if (currentBoard.board[posX + i][posY - i] == "Q") {
                return true;
            } else if (currentBoard.board[posX + i][posY - i] != ".") {
                break; // another piece is blocking the way
            }
        }
    return false; // tehdit yoksa


}

#endif //CSTECH_QUEEN_THREAT_H
