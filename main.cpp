#include <iostream>
#include <string>
#include "board.h"
#include "Score.h"





int main() {
    Board board;
    std::string filename = "board3.txt";
    board.importBoard(filename);
    board.printBoard();

    Score score;
    std::string outputfilename = "sonuclar.txt";
    score.printScore(board, outputfilename, filename);






    return 0;
}
