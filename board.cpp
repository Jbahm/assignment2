#include "board.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

board::board(){
  row = 1;
  column = 1;
  grid = new char*[1];
}

board::board( int rows,  int columns, string map){
  row = rows;
  column = columns;
  string mapLoc = map;    //string of map file (map locator)
  grid = new char*[row];
  for(int i = 0; i < row; i++){
    grid[i] = new char[column];
  }
}

//board::~board(){
  //delete grid;
//cout << "board deleted" << endl;
//}//make sure we are deleting the right thing

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
      if(grid[i][j] == '*'){
        cout << "X";
      }else{
        cout << "-";
      }
    }
    cout << endl;
  }
  cout << "" << endl;
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
      grid[i][j] = '-';
    }
  }
}

void board::populateRandom(double populationDensity){//CHANGE TO ACCOUNT FOR POP DENSITY LATER
  srand(time(NULL));
  int r;
  int maxPopulation = populationDensity*row*column;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      r = (rand()%10) + 1;
      if(r%2 == 0 && (maxPopulation > 0)){
        grid[i][j] = '*';
        maxPopulation-1;
      }else{
        grid[i][j] = '-';
      }
    }
  }
}

void board::populateMap(string targetMap){
  ifstream layout;
  string currentLine;
  layout.open(targetMap);
  for(int i = 0; i < row+2; i++){
    layout >> currentLine;
    if(i > 1){
    for(int j = 0; j < column; j++){
      if(currentLine[j] == 'X'){
        grid[i-2][j] = '*';
      }else{
        grid[i-2][j] = '-';
      }
    }
  }
  }
}

/*void board::outputBoard(){
  ofstream outfile;
  ofstream.open("output.txt");
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      if(grid[i][j] == '*'){
        outfile << "X";
      }else{
        cout << "-";
      }
    }
    cout << endl;
  }
  cout << "" << endl;
}*/
