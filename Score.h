//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_SCORE_H
#define CSTECH_SCORE_H


#include "board.h"
#include "Piece.h"


class Score{
private:
    double whiteScore{0};
    double blackScore{0};

    void calculateScore(const Board &currentBoard) {            //board matrisinde gezilerek her bir taşın final değeri
        //bulunuyor ve birikerek beyazın ve siyahın son skorları bulunuyor
        for (int satir = 0; satir < 8; ++satir) {
            for (int sutun = 0; sutun < 8; ++sutun) {
                Piece currentPiece;
                currentPiece.finalPieceValue(satir, sutun, currentBoard);

                if(currentPieceColor(satir,sutun,currentBoard) == 'b') //taş beyaz ise
                    whiteScore += currentPiece.finalValue;
                else if(currentPieceColor(satir,sutun,currentBoard) == 's') //taş siyah ise
                    blackScore += currentPiece.finalValue;

            }
        }
    }

public:

    void printScore(const Board &currentBoard, const std::string &outputfilename, const std::string &filename){
                                                            // calculateScore çağırarak son skorları hesaplatıyor
        calculateScore(currentBoard);                       //bu skorları main'de belirtilen .txt'ye yazıyor.

        std::ofstream outputFile(outputfilename);
        if (outputFile.is_open()) {
            outputFile << "Tahta Dosya Adı\tSonuçlar\n";
            outputFile << filename << "\t\tSiyah:" << blackScore << "\tBeyaz:" << whiteScore << std::endl;
            outputFile.close();
        }
    }

};

#endif //CSTECH_SCORE_H
