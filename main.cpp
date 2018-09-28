#include "simulation.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void gameLoop(board map){
  string mode;
  int outputOption;
  int generations = 0;
  int maxGenerations = 0;
  cout << "Which of the following boundary modes do you want to play in?:" << endl;
  cout << "classic" << endl;
  cout << "donut" << endl;
  cout << "mirror" << endl;
  cin >> mode;
  simulation game(map, mode);
  cout << "" << endl;

  cout << "How would you like the results displayed?: " << endl;
  cout << "in the terminal?(type a 0)" << endl;
  cout << "or to a file?(type a 1)" << endl;
  cin >> outputOption;
  cout << "" << endl;

  cout << "How many generations would you like the simulation to run for?: " << endl;
  cout << "Enter 0 if you want it to run until the world stabalizes or is empty!" << endl;
  cin >> maxGenerations;
  cout << "" << endl;
  cout << generations << endl;
  map.printBoard();

  if(maxGenerations > 0){
    for(int i = 0; i < maxGenerations; i++){
      generations++;
      game.advanceGeneration();
      if(outputOption == 0){
        cout << generations << endl;
        map.printBoard();
      }else{
      //  map.outputBoard(generations);
      }
    }
  }else{
    //stuff
  }


}


int main(int argc, char** argv){
  int boardHeight;
  int boardWidth;
  double popDense;
  string choice;


  cout << "Do you want to generate a file from a map?" << endl;
  cout << "if so, input the filename now, otherwise input a 0" << endl;
  cin >> choice;

  if(choice == "0"){
    cout << "Enter the height of the board" << endl;
    cin >> boardHeight;
    cout << "Enter the width of the board" << endl;
    cin >> boardWidth;
    cout << "Enter the desired population density" << endl;
    cin >> popDense;
    board map(boardHeight, boardWidth, "");
    map.populateRandom(popDense);
    map.printBoard();
    gameLoop(map);
  }else{
    ifstream layout;
    layout.open(choice);
    layout >> boardHeight >> boardWidth;
    board map(boardHeight, boardWidth, choice);

    layout.close();
    map.populateMap(choice);
    cout << "" << endl;
    gameLoop(map);
  }



}
