#include "gfx.hpp"
#include <iostream>
#include "../board/board.hpp"
using namespace std;

#define RESET_COLOR "\x1b[0m"

namespace GFX {
    GraphicsStyle::GraphicsStyle() {
        FreeCell = '.';
        OurCell = '#';
        TheirCell = '#';
        FreeColor = "\x1b[37m";
        TheirColor = "\x1b[34m";
        TheirThreeColor = "\x1b[31m";
        TheirFourColor = "\x1b[35m";
        OurColor = "\x1b[32m";
    }

    void DrawBoard(Board::BoardData* board, GFX::GraphicsStyle* style) {
        for (int iy = 0; iy < static_cast<int>(board->GetDataColomn(0).size()); iy++) {
            for (int ix = 0; ix < static_cast<int>(board->GetDataColomn(0).size()); ix++) {
                short cell = board->GetDataIndex(iy, ix);
                if (cell == FREE_CELL_INDEX) {
                    cout << style->FreeColor << style->FreeCell << RESET_COLOR;
                } else if (cell == OUR_CELL_INDEX) {
                    cout << style->OurColor << style->OurCell << RESET_COLOR;
                } else if (cell == THEIR_CELL_INDEX) {
                    cout << style->TheirColor << style->TheirCell << RESET_COLOR;
                }
            }
            cout << "\n";
        }
    }
}