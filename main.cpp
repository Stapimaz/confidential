#include <iostream>
#include <fstream>
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

class Piece {
private:
    double firstPieceValue(int posX, int posY, const Board &currentBoard) const {
        std::basic_string<char> piece = currentBoard.board[posX][posY];
        char type = piece[0];
        if (type == '-') {
            return 0.0; 
        }

        switch (type) {
            case 'p':
                return 1.0;
            case 'a':
                return 3.0;
            case 'f':
                return 3.0;
            case 'k':
                return 5.0;
            case 'v':
                return 9.0;
            case 's':
                return 100.0;
            default:
                return 0.0;
        }
    }
    char whichSide(int posX, int posY, const Board &currentBoard){
        std::basic_string<char> piece = currentBoard.board[posX][posY];
        return piece[1];

    }
    int numberOfTreaths(int posX, int posY, const Board &currentBoard) {
        int number{0};
        if(whichSide(posX, posY, currentBoard) == 'b'){      //piyon tehditinde mi
            if(currentBoard.board[posX+1][posY+1] == "ps")
                ++number;
            if(currentBoard.board[posX-1][posY+1] == "ps")
                ++number;
        }
        if(whichSide(posX, posY, currentBoard) == 's'){
            if(currentBoard.board[posX+1][posY-1] == "bs")
                ++number;
            if(currentBoard.board[posX-1][posY-1] == "bs")
                ++number;
        }

        // tüm tehdit türlerini yaz, tehdit sayısı elde ettin, sonra piece value güncelle, firstpiece value gereksiz olabilir, tek bir value belirleme fonks yeter




    }




};

int main() {
    Board board;
    std::string filename = "board1.txt";
    board.importBoard(filename);
    board.printBoard();



    return 0;
}

/*
score calculator // tehdit varsa first value yarıya düşürecek

bool is threatened
 */