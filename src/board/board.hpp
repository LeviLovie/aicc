#ifndef BOARD_HPP_
#define BOARD_HPP_
#include <vector>
using namespace std;

#define FREE_CELL_INDEX 0
#define OUR_CELL_INDEX 1
#define THEIR_CELL_INDEX 2

namespace Board {
  class BoardData {
    vector<vector<short> > data;

  public:
    // Constructors and destructors
    BoardData(short sizeY, short sizeX);
    ~BoardData();

    // Getters
    vector<vector<short> > GetData();
    short GetDataIndex(short iy, short ix);
    vector<short> GetDataRow(short i);
    vector<short> GetDataColomn(short i);

    // Setters
    void SetData(vector<vector<short> > data);
    void SetIndex(short iy, short ix, short data);
    void SetRow(short i, vector<short> data);
    void SetColomn(short i, vector<short> data);

    // Random
    void RandomSet(short setto, float chance);
  };

  void DebugBoardDataIndex(BoardData* data, short iy, short ix);
  void DebugBoardDataRow(BoardData* data, short i);
  void DebugBoardDataColomn(BoardData* data, short i);
  void DebugBoardData(BoardData* data);
  void DebugBoardDataFill(BoardData* data);
}

#endif // BOARD_HPP_
