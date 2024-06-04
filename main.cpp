#include <iostream>
#include <fstream>
#include <string>


const int BOARD_SIZE = 8;

void importBoard(const std::string &filename, std::string board[BOARD_SIZE][BOARD_SIZE]) {
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
                board[i][col++] = std::string(1, line[j]) + std::string(1, line[j+1]);
            }
        } else {
            std::cerr << "hata\n";
            break;
        }
    }
    file.close();
}






void printBoard(const std::string board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::string board[BOARD_SIZE][BOARD_SIZE];
    std::string filename = "board1.txt";
    importBoard(filename, board);
    printBoard(board);
    return 0;
}
