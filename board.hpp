#include <iostream>

using namespace std;

class board
{
  public:
    board();
    board(int rows, int columns, string map);
    ~board();

    int getRows();
    int getColumns();
    void editCell(int rowLoc, int columnLoc, char newContents);
    char getCell(int rowLoc, int columnLoc);
    void copyBoard(board newBoard);
    void printBoard();
    void clearBoard();

    string mapLoc;
    int row;
    int column;
    char grid[rows][columns];







}
