#include "simulation.hpp"
#include <iostream>

using namespace std;



int main(int argc, char** argv){
  int boardHeight;
  int boardWidth;
  double popDense;
  string choice;
  string mode;

  cout << "Do you want to generate a file from a map?" << endl;
  cout << "if so, input the filename now, otherwise input a 0" << endl;
  cin >> choice;
  //if(choice == ""){
  cout << "Enter the height of the board" << endl;
  cin >> boardHeight;
  cout << "Enter the width of the board" << endl;
  cin >> boardWidth;
  cout << "Enter the population density" << endl;
  cin >> popDense;
  board map(boardHeight, boardWidth, "");
  map.populate();
  //}else{
  //  board map(boardHeight, boardWidth, "");
  //}

  cout << "Which of the following boundary modes do you want to play in?:" << endl;
  cout << "classic" << endl;
  cout << "donut" << endl;
  cout << "mirror" << endl;
  cin >> mode;
  simulation game(map, mode);
  map.printBoard();
  game.advanceGeneration();
  map.printBoard();



}
