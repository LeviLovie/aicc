#include "board.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <fstream>
#include <sstream>
using namespace std;

namespace Board {
  BoardData::BoardData(short sizeY, short sizeX) {
    data.clear();
    data.reserve(sizeY);
    for (short y = 0; y < sizeY; y++) {
      vector<short> currentLine;
      currentLine.reserve(sizeX);
      for (short x = 0; x < sizeX; x++)
        currentLine.push_back(0);
      data.push_back(currentLine);
    }
  }

  BoardData::~BoardData() {
    data.clear();
  };

  vector<vector<short> > BoardData::GetData() {
    return data;
  }


  short BoardData::GetDataIndex(short iy, short ix) {
    if (iy > static_cast<short>(GetDataColomn(0).size())) {
      cout << "BoardDataSetIndex: Y index is bigger then BoardData size" << endl;
      exit(1);
    }
    if (ix > static_cast<short>(GetDataRow(0).size())) {
      cout << "BoardDataSetIndex: X index is bigger then BoardData size" << endl;
      exit(1);
    }
    
    return data[iy][ix];
  }

  vector<short> BoardData::GetDataRow(short i) {
    return data[i];
  }

  vector<short> BoardData::GetDataColomn(short i) {
    vector<short> resultColomn;
    resultColomn.reserve(data.size());
    for (short iy = 0; iy < static_cast<short>(data.size()); iy++)
      resultColomn.push_back(data[iy][i]);
    return resultColomn;
  }

  void BoardData::SetData(vector<vector<short> > indata) {
    data = indata;
  }

  void BoardData::SetIndex(short iy, short ix, short indata) {
    if (iy > static_cast<short>(GetDataColomn(0).size())) {
      cout << "BoardDataSetIndex: Y index is bigger then BoardData size" << endl;
      exit(1);
    }
    if (ix > static_cast<short>(GetDataRow(0).size())) {
      cout << "BoardDataSetIndex: X index is bigger then BoardData size" << endl;
      exit(1);
    }

    data[iy][ix] = indata;
  }

  void BoardData::SetRow(short i, vector<short> indata) {
    if (i > static_cast<short>(GetDataColomn(0).size())) {
      cout << "BoardDataSetRow: Y index is bigger then BoardData size" << endl;
      exit(1);
    }
    if (indata.size() != GetDataRow(0).size()) {
      cout << "BoardDataSetRow: Data size is not equal then BoardData size" << endl;
      exit(1);
    }

    data[i] = indata;
  }

  void BoardData::SetColomn(short i, vector<short> indata) {
    if (i > static_cast<short>(GetDataRow(0).size())) {
      cout << "BoardDataSetRow: X index is bigger then BoardData size" << endl;
      exit(1);
    }
    if (indata.size() != GetDataColomn(0).size()) {
      cout << "BoardDataSetRow: Data size is not equal then BoardData size" << endl;
      exit(1);
    }

    for (short ix = 0; ix < static_cast<short>(indata.size()); ix++)
      data[i][ix] = indata[ix];
  }

  void BoardData::RandomSet(short setto, float chance) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    for (short iy = 0; iy < static_cast<short>(GetDataColomn(0).size()); iy++) {
      for (short ix = 0; ix < static_cast<short>(GetDataRow(0).size()); ix++) {
        if (dis(gen) <= chance) data[iy][ix] = setto;
      }
    }
  }

  void BoardData::BackupSave(string name) {
    string backupData = "";

    for (short iy = 0; iy < static_cast<short>(GetDataColomn(0).size()); iy++) {
      for (short ix = 0; ix < static_cast<short>(GetDataRow(0).size()); ix++) {
        backupData += to_string(GetDataIndex(iy, ix));
        if (ix != static_cast<short>(GetDataRow(0).size()) - 1)
          backupData += ",";
      }
      backupData += ";";
    }

    std::ofstream outputFile(name + ".backup.aicc");
    if (outputFile.is_open()) {
      outputFile << backupData;
      outputFile.close();
    } else {
      std::cerr << "Unable to open the file" << std::endl;
    }

    cout << "Backup made!";
  }

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
  
  void BoardData::BackupLoad(string name) {
    string backupData = "";
    std::ifstream inputFile(name + ".backup.aicc");
    if (inputFile.is_open()) {
      std::stringstream buffer;
      buffer << inputFile.rdbuf();
      backupData = buffer.str();
      inputFile.close();
    } else {
      std::cerr << "Unable to open the file" << std::endl;
    }

    vector<string> rows = splitString(backupData, ';');
    for (int iy = 0; iy < rows.size(); iy++) {
      vector<string> indexes = splitString(rows[iy], ',');
      for (int ix = 0; ix < indexes.size(); ix++)
        SetIndex(iy, ix, stoi(indexes[ix]));
    }

    cout << "backup loaded!";
  }



  void DebugBoardDataIndex(BoardData* data, short iy, short ix) {
    if (iy > static_cast<short>(data->GetDataColomn(0).size())) {
      cout << "DEBUG: DebugBoardDataIndex: Y index is bigger then BoardData size" << endl;
      exit(1);
    }
    if (ix > static_cast<short>(data->GetDataRow(0).size())) {
      cout << "DEBUG: DebugBoardDataIndex: X index is bigger then BoardData size" << endl;
      exit(1);
    }

    cout << "DEBUG: BoardData for " << iy << "x" << ix << ": "
         << data->GetDataIndex(iy, ix) << endl;
  }

  void DebugBoardDataRow(BoardData* data, short i) {
    if (i > static_cast<short>(data->GetDataRow(0).size())) {
      cout << "DEBUG: DebugBoardDataRow: index is bigger then BoardData size" << endl;
      exit(1);
    }

    cout << "DEBUG: BoardData row for " << i << ": ";
    vector<short> row = data->GetDataRow(i);
    for (short ix = 0; ix < static_cast<short>(row.size()); ix++)
      cout << row[ix] << " ";
    cout << endl;
  }

  void DebugBoardDataColomn(BoardData* data, short i) {
    if (i > static_cast<short>(data->GetDataColomn(0).size())) {
      cout << "DEBUG: DebugBoardDataColomn: index is bigger then BoardData size" << endl;
      exit(1);
    }

    cout << "DEBUG: BoardData colomn for " << i << ": ";
    vector<short> colomn = data->GetDataColomn(i);
    for (short ix = 0; ix < static_cast<short>(colomn.size()); ix++)
      cout << colomn[ix] << " ";
    cout << endl;
  }

  void DebugBoardData(BoardData* data) {
    cout << "DEBUG: BoardData: " << endl;
    for (short iy = 0; iy < static_cast<short>(data->GetDataColomn(0).size()); iy++) {
      for (short ix = 0; ix < static_cast<short>(data->GetDataRow(0).size()); ix++) {
        string result = "";
        short number = data->GetDataIndex(iy, ix);
        if (abs(number) <= 10) result = to_string(number) + "  ";
        else if (abs(number) <= 100) result = to_string(number) + " ";
        else result = to_string(number);
        cout << result << " ";
      }
      cout << endl;
    }
  }

  void DebugBoardDataFill(BoardData* data) {
    short counter = 1;
    for (short iy = 0; iy < static_cast<short>(data->GetDataColomn(0).size()); iy++) {
      for (short ix = 0; ix < static_cast<short>(data->GetDataRow(0).size()); ix++) {
        data->SetIndex(iy, ix, counter);
        counter++;
      }
    }
  }
}
