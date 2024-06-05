//
// Created by Korhan on 5.06.2024.
//

#ifndef CSTECH_BOARD_H
#define CSTECH_BOARD_H



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>



const int BOARD_SIZE = 8;

class Board {
private:

public:

    std::string board[BOARD_SIZE][BOARD_SIZE];


    void importBoard(const std::string &filename) {
        std::ifstream file(filename);
        std::string line;

        if (!file.is_open()) {
            std::cerr << filename << "açılamadı, konumunu kontrol edin " << "\n";
            return; // or handle the error accordingly
        }

        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (std::getline(file, line)) { // Read a line from the file
                int col = 0;
                for (int j = 0; j < 22; j += 3) { // Increment by 3 to skip spaces
                    board[i][col++] = std::string(1, line[j]) + std::string(1, line[j + 1]);
                }
            } else {
                std::cerr << "hata\n";
                break;
            }
        }
        file.close();
    }

    void printBoard() const {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


};

char whichSide(int posX, int posY, const Board &currentBoard);

#endif //CSTECH_BOARD_H

