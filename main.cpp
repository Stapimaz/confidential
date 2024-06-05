#include <string>
#include "board.h"
#include "Score.h"





int main() {
    Board board;
    std::string filename = "board3.txt";
    board.importBoard(filename);    //Board açılıyor ve
    board.printBoard();             //konsola yazdırılıyor

    Score score;
    std::string outputfilename = "sonuclar.txt";
    score.printScore(board, outputfilename, filename);      //printScore fonksiyonu ile skorlar "skorlar.txt"'ye yazılıyor.


    return 0;
}
