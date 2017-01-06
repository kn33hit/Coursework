/*****************************************                                     
 ** File:    ProjAux.cpp                                                      
 ** Project: CMSC 202 Project 1, Spring 2014                                   
 ** Author:  Neh Patel                                                         
 ** Date:    3/9/14                                                            
 ** Section: 08                                                                
 ** E-mail:  npatel10@umbc.edu                                                 
 **                                                                            
 **   This file contains the functions implementation for Project 1.           
 **   It does not containt the logic for the game, however the making, 
 **   modification of the board is written in this file 
 **   It contains majority of the code needed for the game to function
 **                                                                            
 **                                                                            
 ***********************************************/




#include "ProjAux.h" 
#include <iostream>
using namespace std;
/* 
function: PrintGreeting
PRE:
   none 
POST:
   prints out a statement
*/
void PrintGreeting(){
   cout << "Welcome to Reversi!!" << endl;
}

/* 
function: CheckBoardSize
PRE:
    needs the command-line argument number passed in to check it
POST:
   returns a boolean. True if the nmber is okay; and false, if not.
*/
bool CheckBoardSize(int boardSize){
  // checks for odd number and anything not between 4-10 
  // basically checking the bad value 
  if( ((boardSize % 2) != 0) || ((boardSize < 4) && (boardSize > 10)) ){
      cout << "The board must be an even size between 4 and 10" << endl;
      return false;
    }
  return true;
}

/* 
function: MakeBoard
PRE:
    takes in the board itself and the boardSize value 
POST: 
   makes the board. since arrays are pointers no need for return statements
*/
void MakeBoard(char board[][11], int boardVal){
  // making the board usinf a couple for loops 
  for(int i = 0; i < boardVal; i++){
    for(int j = 0; j < boardVal; j++){
      board[i][j] = '-';
    }
  }
}

/*
function: CheckEndGame
PRE:
   the array board and the size of the board
POST:
   returns a boolean. True if the game has ended, and false if not.
*/
bool CheckEndGame(char board[][11], int boardVal){
  int counter;
  for(int i = 0; i < boardVal; i++){
    for(int j = 0; j < boardVal; j++){
      if (board[i][j] != '-'){
	counter++; // counts how many X's and O's in total exist 
      } 
    }
  }
  if (counter == (boardVal * boardVal)){//compares all the spot in board
                                        // is equal to all taken 
    return true;
  }
  return false;
}

/*
function: CountX
PRE:
   takes in the  array board and the size of the board
POST:
   counts how many X's are there on the board
*/
int CountX(char board[][11], int boardVal){
  int xCount=0;
  for(int i = 0; i < boardVal; i++){
    for(int j = 0; j < boardVal; j++){
      if(board[i][j] == 'X'){
	xCount++;  // counts the number of x that exist on the board 
      }
    }
  }
  cout << "Total number of X's " << xCount;
  return xCount;
}

/*                                                                            
function: Count)                                                              
PRE:                                                                           
   takes in the  array board and the size of the board                        
POST:                                                                          
   counts how many O's are there on the board                                  
*/
int CountO(char board[][11], int boardVal){
  int oCount=0;
  for(int i = 0; i < boardVal; i++){
    for(int j = 0; j < boardVal; j++){
      if(board[i][j] == 'O'){
        oCount++; // counts the numebr O's that exist on the board 
      } 
    }   
  }
  cout << "Total number of O's " << oCount;
  return oCount;
    }

/* 
function: WhoWon
PRE:
    takes in two int, these two numbers are calculated in the 
    CountX and CountO fucntions 
POST:
    prints out who won by comparing the two passed in values
*/
void WhoWon(int xCount, int oCount){
  if(xCount > oCount){  // compares which values is more and prints it 
    cout << "X wins!"; 
  }
  cout << "O wins!";
}

/*
function: GetNextMove
PRE:
    mandatory function. takes in the playerSymbol(according to whichever 
    players move is). and two pointers which represent the x and y 
    value on the board entered by the players 
POST:
    players/users enter the coordinates they want to enter to play the garme
*/
void GetNextMove(char playerSymbol, int& row, int& col){
  cout << "Player " << playerSymbol << "'s move: ";
  cin >> row; // simple inputs, prompt above 
  cin >> col;
}

/*
function: CoordinateValidation
PRE:
    takes in the x and y values. Plus the size of teh board enteredin the 
    command-line argument 
POST: 
    returns boolean. true if coordinates are okay, false if not.
*/
bool CoordinateValidation(int row, int col, int boardValue){
  if((row < 1) || (col < 1) || (row > boardValue) || (col > boardValue)){
      return false;
    }
    return true;
}

/*
function: CheckReversi
PRE:
    takes in almost every parameters passed in all the other functions
    that is, the board(array), player symbol, size of board, x and y.
POST:
    calls in other functions to check in other directions
    otherwise the function would be too long
*/
void CheckReversi(char board[][11], char playerSymbol,int boardVal, int row, int col){
  checkUp(row,col,playerSymbol,board); // checks up
  checkDown(row,col,playerSymbol,board,boardVal); // checks down
  checkRight(row,col,playerSymbol,board,boardVal); // checks right 
  checkLeft(row,col,playerSymbol,board); // checks left 
}

/*
function: checkUp
PRE:
    takes in x,y, player's Symbol and the board itself. checks the up direction
POST:
    modifies the board in the function if needed.
*/
  void checkUp(int row, int col, char playerSymbol, char board[][11]){
     
     int count = 0;
     bool reversiMatch = false;
     row--; // did this so in the first condition it doesnt check the original
            // spot and never enter a loop 
     while((row >= 0) && (playerSymbol != board[row][col])){
       count++; // if there is more to check than just one step 
       if(board[row-1][col] == playerSymbol){ 
         reversiMatch = true; // to ensure that later we have to reverse symbol
       }
       row--; // the incrmentation still exists 
     }
     if(reversiMatch == true){
       for(int j = 0; j < count; j++){// this is the flip the signs and 
	                              // actually modify the board 
	 board[row][col] = playerSymbol;
	 row++;
       }
     }
   }

/*                                                                             
function: checkDown                                                           
PRE:                                                                           
    takes in x,y, player's Symbol and the board itself. checks in the down 
    direction                        
POST:                                                                          
    modifies the board in the function if needed.                              
*/
void checkDown(int row, int col, char playerSymbol, char board[][11], int boardVal){
  int count = 0;
  bool reversiMatch = false;
  row++; // reverse of previous fucntion
  // also note: the condtions to cehck the border has changed as well 
  // eveyrthing else is also identical 
  while((row < boardVal) && (playerSymbol != board[row][col])){ 
    count++;
    if(board[row+1][col] == playerSymbol){
      reversiMatch = true;
    }
    row++;
  }
  if(reversiMatch == true){
    for(int j = 0; j < count; j++){ // modification to the board 
      board[row][col] = playerSymbol;
      row--;
    }
  }
}

/*                                                                             
function: checkRight 
PRE:                                                                          
    takes in x,y, player's Symbol and the board itself. checks the right
    direction
POST:                                                                         
    modifies the board in the function if needed.                             
*/
void checkRight(int row, int col, char playerSymbol, char board[][11], int boardVal){
  int count = 0;
  bool reversiMatch = false;
  col++; // this time the col are checked to move horizontally 
  while((col < boardVal) && (playerSymbol != board[row][col])){ 
    count++; 
    if(board[row][col+1] == playerSymbol){
      reversiMatch = true;
    }
    col++; // col added to go right 
  }
  if(reversiMatch == true){
    for(int j = 0; j < count; j++){ // modifying the board
      board[row][col] = playerSymbol;
      col--;
    }
  }
}

/*                                                                             
function: checkUp                                                              
PRE:                                                                          
    takes in x,y, player's Symbol and the board itself. checks the left
    direction
POST:                                                                          
    modifies the board in the function if needed.                             
*/
void checkLeft(int row, int col, char playerSymbol, char board[][11]){
  int count = 0;
  bool reversiMatch = false;
  col--; // col decreses to move to left 
  // condition to check left border has changed 
  while((col <= 0) && (playerSymbol != board[row][col])){
    count++;
    if(board[row][col-1] == playerSymbol){
      reversiMatch = true;
    }
    col--;
  }
  if(reversiMatch == true){
    for(int j = 0; j < count; j++){// using the count as the limit gives the 
                                   // exact number to flip signs.
      // this logic is almost magical. Coding logic is so great.
      board[row][col] = playerSymbol;
      col++;
    }
  }
}


// pointer errors were unfixable for me. So I just didnt do these mentioned 
// functions. Hopefully you get the same errors as mine. 
// They would just be copies of checkup/down/left/right. 
// both row and col varibales being manipulated  

// void checkLeftUp()
// void checkRightUp()
// void checkLeftDown()
// void checkRightDown()
