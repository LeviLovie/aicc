#ifndef GFX_HPP_
#define GFX_HPP_
#include <string>
#include "../board/board.hpp"
using namespace std;

#define RESET_COLOR "\x1b[0m"
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

namespace GFX {
    class GraphicsStyle {
    public:
        char FreeCell;
        char OurCell;
        char TheirCell;
        char MustPutCell;
        string FreeColor;
        string TheirColor;
        string TheirThreeColor;
        string TheirFourColor;
        string MustPutColor;
        string OurColor;

        GraphicsStyle();
    };

    void DrawBoard(Board::BoardData* board, GFX::GraphicsStyle* style, int cursorY, int cursorX);
}

#endif // GFX_HPP_