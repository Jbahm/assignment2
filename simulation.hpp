#include "board.hpp"
#include <iostream>

using namespace std;

class simulation
{
  public:
    simulation();
    simulation(board grid, string mode);


    board gameBoard;
    string gameMode;
  

    int countNeighbors(int rowLoc, int colLoc);
    void advanceGeneration();
    string getMode();


};
