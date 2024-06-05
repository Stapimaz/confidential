//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_SCORE_H
#define CSTECH_SCORE_H


#include "board.h"
#include "Piece.h"


class Score{
private:



public:
    double whiteScore{0};
    double blackScore{0};

    void calculateScore(const Board &currentBoard) {

        for (int i = 0; i < 8; ++i) {

            for (int j = 0; j < 8; ++j) {
                Piece currentPiece;
                currentPiece.firstPieceValue(i, j, currentBoard);
                currentPiece.finalPieceValue(i, j, currentBoard);

                if(currentPieceColor(i,j,currentBoard) == 'b')
                    whiteScore += currentPiece.finalValue;
                else if(currentPieceColor(i,j,currentBoard) == 's')
                    blackScore += currentPiece.finalValue;



            }


        }

    }

    void printScore(const Board &currentBoard, const std::string &outputfilename, const std::string &filename){

        calculateScore(currentBoard);

        std::ofstream outputFile(outputfilename);
        if (outputFile.is_open()) {
            outputFile << "Tahta Dosya Adı\tSonuçlar\n";
            outputFile << filename << "\t\tSiyah:" << blackScore << "\tBeyaz:" << whiteScore << std::endl;
            outputFile.close();
        }

    }




};

#endif //CSTECH_SCORE_H
