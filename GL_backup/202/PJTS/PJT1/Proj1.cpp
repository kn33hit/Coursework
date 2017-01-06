/*****************************************
 ** File:    Proj1.cpp
 ** Project: CMSC 202 Project 1, Spring 2014
 ** Author:  Neh Patel
 ** Date:    3/9/14
 ** Section: 08
 ** E-mail:  npatel10@umbc.edu 
 **
 **   This file contains the main driver program for Project 1.
 ** This program reads the file specified as the first command line
 ** argument, uses the functions to make board and play the game 
 ** in the format specified in the project description.
 **
 **
 ***********************************************/

#include <iostream> 
#include <cstdlib>
#include "ProjAux.cpp"
using namespace std;
const int MAX_SIZE = 11;
int main(int argc, char *argv[]){
  
  // DECLARING VARIABLES  
  bool boardSizeGood = false;
  char board[MAX_SIZE][MAX_SIZE] = {};
  bool gameEnded = false;
  bool xFlag = true;
  bool oFlag = true;
  char playerSymbol;
  int row;
  int col;
  int xCount, oCount;
  int x,y;

  // GREETING 
  PrintGreeting();

  // CHECKING BOARD SIZE 
  boardSizeGood = CheckBoardSize(atoi(argv[1]));
  
  // just like asked, if the size given is no good, then the game will not be 
  // run 
  if (boardSizeGood == true){
    // MAKING THE BOARD
    MakeBoard(board, atoi(argv[1]));
    
    // THIS IS WHERE THE GAME ACTUALLY IS LOOPED AND PLAYED 
    while(gameEnded == false){ // ends when all the squares are filled up
      // X MOVE 
      playerSymbol = 'X'; // as x goes first 
      while (xFlag == true){ // repeats until the correct values are entered
    	GetNextMove(playerSymbol, row, col);
	row -= 1; x = row; // did this cause i kept getting pointer errors
	col -= 1; y =  col;// subtracted it by 1 to make it array compatible
    	xFlag = CoordinateValidation(x,y, atoi(argv[1]));
      }
      // CHECK REVERSI ACCORDING TO X
      // as the player symbol is still x 
      CheckReversi(board, playerSymbol,atoi(argv[1]), x,y); 
      // O MOVE
      playerSymbol = 'O'; // now we want to use O so it was switched 
      while(oFlag == true){
    	GetNextMove(playerSymbol, row, col);
	row -=1; x = row; 
	col -=1; y = col;
    	oFlag = CoordinateValidation(x,y,atoi(argv[1]));
      }
      // CHECK REVERSI ACCORDING TO O 
      CheckReversi(board, playerSymbol,atoi(argv[1]), x,y);
      // THIS IS THE LAST FUNCTION TO BE CALLED IN THIS BLOCK
      // not necesaarily, but having it at the end makes it easier for the 
      // reader 
      gameEnded = CheckEndGame(board, atoi(argv[1]));
    } // ends while loop 
    // once game is over and all the squares are filled up 
    // these functions have to run in order for the required post game outputs
    cout << "The game is over." << endl;
    xCount = CountX(board, atoi(argv[1]));
    oCount = CountO(board, atoi(argv[1]));
    WhoWon(xCount,oCount);
    // whoWon uses if x > o, x won and vice versa 
    // cout "Player _ wins!" 
  } //ends if statement 
}
