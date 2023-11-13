#include <iostream>

#include "board/board.hpp"

int main(int, char**) {
    Board::BoardData* board = new Board::BoardData(10, 10);
    Board::DebugBoardDataFill(board);

    Board::DebugBoardData(board);
    Board::DebugBoardDataIndex(board, 2, 7);
    Board::DebugBoardDataRow(board, 6);
    Board::DebugBoardDataColomn(board, 4);
}
