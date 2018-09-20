#include <board.hpp>
#include <iostream>

using namspace std;

board::board(){
  row = 1;
  column = 1;
  grid = new char[row][column];
}

board::board(int rows, int columns, string map){
  row = rows;
  column = columns;
  mapLoc = map;
  grid = new char[rows][columns];
}

board::~board(){
  delete grid;
  cout << "board deleted" << endl;
}

board::getRows(){
  return row;
}

board::getColumns(){
  return column;
}

board::editCell(int rowLoc, int columnLoc, char newContents){
  grid[rowLoc][columnLoc] = newContents;
}

board::copyBoard(board newBoard){
  for(int i = 0; i < grid.getRows(); i++){
    for(int j = 0; j < grid.getColumns(); j++){
      newBoard[i][j] = grid[i][j];
    }
  }
  return newBoard;
}

board::printBoard(){
  for(int i = 0; i < grid.getRows(); i++){
    for(int j = 0; j < grid.getColumns(); j++){
      cout << "[" << grid[i][j] << "]";
    }
    cout << "" << endl;
  }
}

board::clearBoard(){
  for(int i = 0; i < grid.getRows(); i++){
    for(int j = 0; j < grid.getColumns(); j++){
      grid[i][j] = '';
    }
  }
}
