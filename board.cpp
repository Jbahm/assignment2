#include "board.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

board::board(){
  //row = 1;
  //column = 1;
  //grid = new char[1];
}

board::board( int rows,  int columns, string map){
  row = rows;
  column = columns;
  string mapLoc = map;    //string of map file (map locator)
  grid = new char*[row];
  char gridCols[column];
  for(int i = 0; i < row; i++){
    grid[i] = gridCols;
  }
}

board::~board(){
  delete grid;
cout << "board deleted" << endl;
}//make sure we are deleting the right thing

int board::getRows(){
  return row;
}

int board::getColumns(){
  return column;
}

string board::getMap(){
  return mapLoc;
}

char board::getCell(int row, int col){
  return grid[row][col];
}

void board::editCell(int rowLoc, int columnLoc, char newContents){
    grid[rowLoc][columnLoc] = newContents;
}

void board::copyBoard(board newBoard){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      char contents = newBoard.getCell(i, j);
      editCell(i, j, contents);
    }
  }
}


void board::printBoard(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      cout << "[" << grid[i][j] << "]";
    }
    cout << endl;
  }
}


bool board::isPopulated(int col, int row){
  if(grid[row][col] == '*'){
    return true;
  }else{
    return false;
  }
}


void board::clearBoard(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      grid[i][j] = ' ';
    }
  }
}

void board::populate(){//CHANGE TO ACCOUNT FOR POP DENSITY LATER
  srand(time(NULL));
  int r;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      r = (rand() % 10) + 1;
      if(r % 2 == 0){
        grid[i][j] = '*';
      }else{
        grid[i][j] = ' ';
      }
    }
  }
}
