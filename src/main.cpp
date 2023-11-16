#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "board/board.hpp"
#include "gfx/gfx.hpp"

vector<string> splitString(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<string> getInput(int counter, Board::BoardData* board, GFX::GraphicsStyle* style) {
    string input;
    if (counter % 2 == 0)
        cout << "(" << style->TheirColor << "Opp" << RESET_COLOR << "): ";
    else
        cout << "(" << style->OurColor << "Our" << RESET_COLOR << "): ";
    getline(cin, input);
    cout << endl;
    if (input == "") input = "ret";
    vector<string> words = splitString(input, ' ');
    if (words.size() < 1) cout << "Commands: cls, set";
    return words;
}

int applyCommnads(vector<string> tokens, int incounter, Board::BoardData* board, int* cursorY, int* cursorX) {
    int counter = incounter;
    if (tokens[0] == "cls") {
        board->RandomSet(0, 1.0);
        counter = 0;
        cout << "\x1b[32m" << "Sucseed" << RESET_COLOR;
    } else if (tokens[0] == "s") {
        cout << tokens.size() << endl;
        if (tokens.size() == 3) {
            int iy = 0;
            try {
                iy = stoi(tokens[1]) - 1;
            } catch (exception e) {
                cout << "\x1b[31m" << e.what() << RESET_COLOR;
                return counter;
            }
            int ix = 0;
            for (int i = 0; i < 26; i++)
                if (ALPHABET[i] == tokens[2].c_str()[0]) ix = i;
            if (board->GetDataIndex(iy, ix) == 0) {
                if (incounter % 2 == 0)
                    board->SetIndex(iy, ix, THEIR_CELL_INDEX);
                else
                    board->SetIndex(iy, ix, OUR_CELL_INDEX);
                counter++;
                cout << "\x1b[32m" << "Sucseed" << RESET_COLOR;
            } else {
                cout << "\x1b[33m" << "Cell is filled" << RESET_COLOR;
            }
        } else {
            cout << "\x1b[33m" << "Requires: Y and X numbers of a cell" << RESET_COLOR;
        }
    } else if (tokens[0] == "h" || tokens[0] == "j" || tokens[0] == "k" || tokens[0] == "l") {
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "h") {
                if (*cursorX > 0) (*cursorX)--;
                else *cursorX = static_cast<int>(board->GetDataRow(0).size()) - 1;
            } else if (tokens[i] == "j") {
                if (*cursorY > 0) (*cursorY)--;
                else *cursorY = static_cast<int>(board->GetDataColomn(0).size()) - 1;
            } else if (tokens[i] == "k") {
                if (*cursorY < static_cast<int>(board->GetDataColomn(0).size()) - 1) (*cursorY)++;
                else *cursorY = 0;
            } else if (tokens[i] == "l") {
                if (*cursorX < static_cast<int>(board->GetDataRow(0).size()) - 1) (*cursorX)++;
                else *cursorX = 0;
            }
        }
    } else if (tokens[0] == "x") {
        int iy = *cursorY, ix = *cursorX;
        if (board->GetDataIndex(iy, ix) == 0) {
            if (incounter % 2 == 0)
                board->SetIndex(iy, ix, THEIR_CELL_INDEX);
            else
                board->SetIndex(iy, ix, OUR_CELL_INDEX);
            counter++;
            cout << "\x1b[32m" << "Sucseed" << RESET_COLOR;
        } else {
            cout << "\x1b[33m" << "Cell is filled" << RESET_COLOR;
        }
    } else if (tokens[0] == "ret") {
        return counter;
    } else {
        cout << "\x1b[31m" << "Wat?" << RESET_COLOR;
    }
    return counter;
}

int main(int, char**) {
    Board::BoardData* board = new Board::BoardData(16, 16);
    GFX::GraphicsStyle* style = new GFX::GraphicsStyle();
    // board->RandomSet(2, 0.5);

    int counter = 0;
    int cursorY = 0, cursorX = 0;
    while (true) {
        GFX::DrawBoard(board, style, cursorY, cursorX);
        counter = applyCommnads(getInput(counter, board, style), counter, board, &cursorY, &cursorX);
        cout << endl;
    }
}
