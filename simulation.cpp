#include "simulation.hpp"

using namespace std;


simulation::simulation(){
  //gameBoard = new board(1, 1, "");
  gameMode = "classic";
}

simulation::simulation(board grid, string mode){
  gameBoard = grid;
  gameMode = mode;
}

//simulation::~simulation(){
  //delete gameBoard;
  //cout<< "simulation deleted" << endl;
//}//make sure we are deleting the right thing


int simulation::countNeighbors(int rowLoc, int colLoc){
  int neighbors = 0;
  if(gameMode == "classic"){
    if(rowLoc == 0 && colLoc==0){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc+1)== true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == 0 && colLoc == gameBoard.getColumns()){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == 0 && colLoc != 0 && colLoc != gameBoard.getColumns()){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == gameBoard.getRows() && colLoc == 0){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == gameBoard.getRows() && colLoc == gameBoard.getColumns()){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc-1, rowLoc)==true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
        neighbors++;
      }
      return neighbors;
    }else if(rowLoc == gameBoard.getRows() && colLoc != 0 && colLoc!= gameBoard.getColumns()){
      neighbors = 0;
      if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
        neighbors++;
      }
      if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
        neighbors++;
      }
      return neighbors;
   }else if(colLoc == 0 && rowLoc != 0 && rowLoc != gameBoard.getRows()){
     neighbors = 0;
     if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
       neighbors++;
     }
     return neighbors;
   }else if(colLoc == gameBoard.getColumns() && rowLoc != 0 && rowLoc != gameBoard.getRows()){
     neighbors = 0;
     if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
       neighbors++;
     }
     return neighbors;
   }else{
     neighbors = 0;
     if(gameBoard.isPopulated(colLoc, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc-1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc-1, rowLoc+1) == true){
       neighbors++;
     }
     if(gameBoard.isPopulated(colLoc+1, rowLoc+1) == true){
       neighbors++;
     }
     return neighbors;
   }
  }
}

void simulation::advanceGeneration(){
  board nextGen(gameBoard.getRows(), gameBoard.getColumns(), "");

  int neighbors = 0;
  for(int i = 0; i < gameBoard.getRows(); i++){
    for(int j = 0; j < gameBoard.getRows(); j++){
      neighbors = countNeighbors(i, j);
      if(neighbors <= 1){
        nextGen.editCell(i, j, ' ');

      }else if(neighbors == 2){
        if(nextGen.isPopulated(j, i)){
          nextGen.editCell(i, j, '*');
        }
      }else if(neighbors == 3){
        nextGen.editCell(i, j, '*');

      }else{
        nextGen.editCell(i, j, ' ');

      }
      }
    }
    cout << "test1" << endl;
  gameBoard.copyBoard(nextGen);
}

string simulation::getMode(){
  return gameMode;
}
