#ifndef GFX_HPP_
#define GFX_HPP_
#include <string>
#include "../board/board.hpp"
using namespace std;

namespace GFX {
    class GraphicsStyle {
    public:
        char FreeCell;
        char OurCell;
        char TheirCell;
        string FreeColor;
        string TheirColor;
        string TheirThreeColor;
        string TheirFourColor;
        string OurColor;

        GraphicsStyle();
    };

    void DrawBoard(Board::BoardData* board, GFX::GraphicsStyle* style);
}

#endif // GFX_HPP_