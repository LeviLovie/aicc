#include <gtest/gtest.h>
#include <vector>
#include "../src/board/board.hpp"

TEST(Board, SetGetIndex) {
    Board::BoardData* board = new Board::BoardData(1, 1);
    board->SetIndex(0, 0, 1);
    short data = board->GetDataIndex(0, 0);
    ASSERT_EQ(data, 1);
}

TEST(Board, DebugBoardDataFill) {
    Board::BoardData* board = new Board::BoardData(10, 10);
    Board::DebugBoardDataFill(board);
    vector<vector<short> > data = board->GetData();
    ASSERT_EQ(data[0][0], 1);
    ASSERT_EQ(data[8][0], 81);
    ASSERT_EQ(data[0][6], 7);
    ASSERT_EQ(data[3][5], 36);
    ASSERT_EQ(data[9][9], 100);
}

TEST(Board, GetDataRow) {
    Board::BoardData* board = new Board::BoardData(10, 10);
    Board::DebugBoardDataFill(board);
    vector<short> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQ(board->GetDataRow(0), data);
    data = {51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    ASSERT_EQ(board->GetDataRow(5), data);
    board->SetIndex(5, 3, 16);
    data = {51, 52, 53, 16, 55, 56, 57, 58, 59, 60};
    ASSERT_EQ(board->GetDataRow(5), data);
    board->SetRow(3, data);
    ASSERT_EQ(board->GetDataRow(3), data);
}

TEST(Board, GetDataColomn) {
    Board::BoardData* board = new Board::BoardData(10, 10);
    Board::DebugBoardDataFill(board);
    vector<short> data = {1, 11, 21, 31, 41, 51, 61, 71, 81, 91};
    ASSERT_EQ(board->GetDataColomn(0), data);
    data = {6, 16, 26, 36, 46, 56, 66, 76, 86, 96};
    ASSERT_EQ(board->GetDataColomn(5), data);
    board->SetIndex(6, 2, 72);
    data = {3, 13, 23, 33, 43, 53, 72, 73, 83, 93};
    ASSERT_EQ(board->GetDataColomn(2), data);
}
