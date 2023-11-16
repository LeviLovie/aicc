#include "gfx.hpp"
#include <iostream>
#include <string>
#include "../board/board.hpp"
using namespace std;

namespace GFX {
    GraphicsStyle::GraphicsStyle() {
        FreeCell = '.';
        OurCell = '#';
        TheirCell = '#';
        MustPutCell = '!';
        FreeColor = "\x1b[37m";
        TheirColor = "\x1b[34m";
        TheirThreeColor = "\x1b[35m";
        TheirFourColor = "\x1b[31m";
        MustPutColor = "\x1b[33m";
        OurColor = "\x1b[32m";
    }

    void DrawBoard(Board::BoardData* board, GFX::GraphicsStyle* style, int cursorY, int cursorX) {
        cout << "   ";
        for (int iy = 0; iy < static_cast<int>(board->GetDataColomn(0).size()); iy++)
            cout << ALPHABET[iy];
        cout << "\n";

        cout << "  +";
        for (int iy = 0; iy < static_cast<int>(board->GetDataColomn(0).size()); iy++)
            cout << "-";
        cout << "+\n";

        string yIndex = "";
        for (int iy = 0; iy < static_cast<int>(board->GetDataColomn(0).size()); iy++) {
            if (iy < 9) yIndex = to_string(iy + 1) + " ";
            else yIndex = to_string(iy + 1);
            cout << yIndex << "|";

            for (int ix = 0; ix < static_cast<int>(board->GetDataColomn(0).size()); ix++) {
                bool isCursor = false;
                if (ix == cursorX && iy == cursorY) isCursor = true;

                short cell = board->GetDataIndex(iy, ix);
                if (cell == FREE_CELL_INDEX) {
                    int result = 0;

                    if (
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 4) &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 4) == FREE_CELL_INDEX
                        ||
                        ix >= 3 &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 3) == THEIR_CELL_INDEX

                        ||

                        iy < static_cast<int>(board->GetDataRow(0).size() - 4) &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 4, ix) == FREE_CELL_INDEX
                        ||
                        iy >= 3 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix) == THEIR_CELL_INDEX

                        ||

                        ix >= 4 &&
                        iy >= 4 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix - 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 4, ix - 4) == FREE_CELL_INDEX
                        ||
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 3) &&
                        iy < static_cast<int>(board->GetDataRow(0).size() - 3) &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix + 3) == THEIR_CELL_INDEX

                        ||

                        ix < static_cast<int>(board->GetDataColomn(0).size() - 4) &&
                        iy < static_cast<int>(board->GetDataRow(0).size() - 4) &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix - 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 4, ix - 4) == FREE_CELL_INDEX
                        ||
                        ix >= 3 &&
                        iy >= 3 &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix + 3) == THEIR_CELL_INDEX

                        ||
                        
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 5) &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 4) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 5) == FREE_CELL_INDEX
                        ||
                        ix >= 4 &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 4) == THEIR_CELL_INDEX

                        ||
                        
                        iy < static_cast<int>(board->GetDataRow(0).size() - 5) &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 4, ix) == THEIR_CELL_INDEX
                        ||
                        iy >= 4 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 4, ix) == THEIR_CELL_INDEX

                        ||
                        
                        iy < static_cast<int>(board->GetDataRow(0).size() - 5) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 5) &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix + 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 4, ix + 4) == THEIR_CELL_INDEX
                        ||
                        iy >= 4 &&
                        ix >= 4 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix - 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 4, ix - 4) == THEIR_CELL_INDEX

                        ||

                        iy >= 4 &&
                        ix >= 4 &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix + 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 4, ix + 4) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 4) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 4) &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix - 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 4, ix - 4) == THEIR_CELL_INDEX
                    ) result = 1;

                    switch (result) {
                    case 0:
                        if (!isCursor)
                            cout << style->FreeColor << style->FreeCell << RESET_COLOR;
                        else
                            cout << "\x1b[47m" << style->FreeCell << RESET_COLOR;
                        break;
                    case 1:
                        if (!isCursor)
                            cout << style->MustPutColor << style->MustPutCell << RESET_COLOR;
                        else
                            cout << "\x1b[47m" << style->MustPutCell << RESET_COLOR;
                        break;
                    }
                } else if (cell == OUR_CELL_INDEX) {
                    if (!isCursor)
                        cout << style->OurColor << style->OurCell << RESET_COLOR;
                    else
                        cout << "\x1b[47m" << style->OurCell << RESET_COLOR;
                } else if (cell == THEIR_CELL_INDEX) {
                    int result = 0;

                    if (
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 2) &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 2) == THEIR_CELL_INDEX
                        ||
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        ix >= 1 &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX
                        ||
                        ix >= 2 &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 2) == THEIR_CELL_INDEX
                        
                        ||

                        iy < static_cast<int>(board->GetDataRow(0).size() - 2) &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 1) &&
                        iy >= 1 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX
                        ||
                        iy >= 2 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix) == THEIR_CELL_INDEX

                        ||

                        iy < static_cast<int>(board->GetDataRow(0).size() - 1) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        iy >= 1 &&
                        ix >= 1 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX
                        ||
                        iy >= 2 &&
                        ix >= 2 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix - 2) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 2) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 2) &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix + 2) == THEIR_CELL_INDEX

                        ||

                        iy < static_cast<int>(board->GetDataRow(0).size() - 1) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        iy >= 1 &&
                        ix >= 1 &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX
                        ||
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 2) &&
                        iy >= 2 &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix + 2) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 2) &&
                        ix >= 2 &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix - 2) == THEIR_CELL_INDEX
                    ) result = 1;

                    if (
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 3) &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 3) == THEIR_CELL_INDEX
                        ||
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        ix >= 1 &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 2) == THEIR_CELL_INDEX
                        ||
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        ix >= 2 &&
                        board->GetDataIndex(iy, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix + 1) == THEIR_CELL_INDEX
                        ||
                        ix >= 3 &&
                        board->GetDataIndex(iy, ix - 3) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy, ix - 1) == THEIR_CELL_INDEX

                        ||

                        iy < static_cast<int>(board->GetDataRow(0).size() - 3) &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 2) &&
                        iy >= 1 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 1) &&
                        iy >= 2 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix) == THEIR_CELL_INDEX
                        ||
                        iy >= 3 &&
                        board->GetDataIndex(iy - 1, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix) == THEIR_CELL_INDEX

                        ||

                        iy >= 3 &&
                        ix >= 3 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix - 3) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 1) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        iy >= 2 &&
                        ix >= 2 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 2) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 2) &&
                        iy >= 1 &&
                        ix >= 1 &&
                        board->GetDataIndex(iy - 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix + 2) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 3) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 3) &&
                        board->GetDataIndex(iy + 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix + 3) == THEIR_CELL_INDEX

                        ||

                        iy >= 3 &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 3) &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 3, ix + 3) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 1) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 2) &&
                        iy >= 2 &&
                        ix >= 1 &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy - 2, ix + 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 2) &&
                        ix < static_cast<int>(board->GetDataColomn(0).size() - 1) &&
                        iy >= 1 &&
                        ix >= 2 &&
                        board->GetDataIndex(iy - 1, ix + 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix - 2) == THEIR_CELL_INDEX
                        ||
                        iy < static_cast<int>(board->GetDataRow(0).size() - 3) &&
                        ix >= 3 &&
                        board->GetDataIndex(iy + 1, ix - 1) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 2, ix - 2) == THEIR_CELL_INDEX &&
                        board->GetDataIndex(iy + 3, ix - 3) == THEIR_CELL_INDEX
                    ) result = 2;

                    switch (result) {
                    case 0:
                        if (!isCursor)
                            cout << style->TheirColor << style->TheirCell << RESET_COLOR;
                        else
                            cout << "\x1b[47m" << style->TheirCell << RESET_COLOR;
                        break;
                    case 1:
                        if (!isCursor)
                            cout << style->TheirThreeColor << style->TheirCell << RESET_COLOR;
                        else
                            cout << "\x1b[47m" << style->TheirCell << RESET_COLOR;
                        break;
                    case 2:
                        if (!isCursor)
                            cout << style->TheirFourColor << style->TheirCell << RESET_COLOR;
                        else
                            cout << "\x1b[47m" << style->TheirCell << RESET_COLOR;
                        break;
                    }
                }
            }

            cout << "|\n";
        }

        cout << "  +";
        for (int iy = 0; iy < static_cast<int>(board->GetDataColomn(0).size()); iy++)
            cout << "-";
        cout << "+\n";
    }
}