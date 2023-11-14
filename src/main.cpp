#include <iostream>
#include "board/board.hpp"
#include "gfx/gfx.hpp"

int main(int, char**) {
    Board::BoardData* board = new Board::BoardData(16, 16);
    GFX::GraphicsStyle* style = new GFX::GraphicsStyle();
    
    board->RandomSet(1, 0.1f);
    board->RandomSet(2, 0.1f);
    GFX::DrawBoard(board, style);
}
