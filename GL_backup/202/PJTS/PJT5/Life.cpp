/*****************************************
 ** File:    Life.cpp
 ** Project: CMSC 202 Project 5, Spring 2014
 ** Author:  Neh Patel
 ** Date:    5/14/2014
 ** Section: 06
 ** E-mail:  npatel10@gl.umbc.edu 
 **
 **   This file contains the implementation of the class of the Life game.
 ** This program reads the creates the game and contains the overloaded 
 ** funcitons needed to have the game function correctly according to the 
 ** specifications provided 
 **
 **
 ***********************************************/
#include <cstring>
#include <cstdlib>
#include "Life.h"
#include <iostream>
#include <vector>
using namespace std;

const int DEFAULT_LIFE_PLAYER = 1;

Life::Life() : GridGame("Life", "O", LIFE_BOARD_SIZE) {
  m_exit = false; // just making sure it is set to false to begin with 
}

Life::Life(const char *playerSymbols)
  : GridGame("Life", playerSymbols, LIFE_BOARD_SIZE) {
}

bool Life::IsDone() const{ 
  if(m_exit == true){ // if exiting 
    return true; // return the opposite because that is how it is in main
  }
  return false;;
}

void Life::DoMove(int player, int row, int col) {
  
  if(row != -1){ // when user enters 0, the nummber passed in is -1 
    // decremented in main 
    DoBasicMove(player,row,col); // the only thing that should happen is 
    // the position that is enterd to be chnaged
  }else{
    m_genCountEntered = col++; // since the number is decremented in main
    while(m_genCountEntered >= 0){ // equal to 0 as cool was ++ above
      // DO NOT FORGET TO DECREMENT COL BY 1 AT THE END 
      CheckDeadCell();  // check for dead cells
      CheckAliveCell(); // check for alive cells
      ModifyBoard();    // now modify board according to it
      m_totalGenCount++; // to output the board 
      m_genCountEntered--;
    }
    if(col == 0){ // - 1 is zero entered by the user
      m_exit = true; // set it to exit so when isDone handles exiting the
                     // program
    }
  }
}

void Life::CheckDeadCell(){
  int count;
  int boardSize = GetBoardSize(); // get board size
  for(int i = 0; i < boardSize; i++){
    for(int j = 0; j < boardSize; j++){
      count = GoAround(i,j); // check around that cell
      if(count == 5){ // because goAround checks the same cells value 
	// push this coordinate into the vector makeCell vectors
	m_makeCellX.push_back(i); // I could've done pair but it would have 
	m_makeCellY.push_back(j); // complicated my way of thinking 
      }
    }
  }
}

void Life::CheckAliveCell(){
  int count;
  int boardSize = GetBoardSize();
  for(int i = 0; i < boardSize; i++){
    for(int j = 0; j < boardSize; j++){
      count = GoAround(i,j); // check arounf that cell and return the 
      // number of same cells around it 
      if(count < 2 || count > 3){
	m_killCellX.push_back(i);// pushes in the coordinate to make 
	m_killCellY.push_back(j);// changes accordint to the coordinates entere
        // push this coordinate into the vector to kill                      
      } 
    }
  }
}

int Life::GoAround(int x, int y){
  int count;
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <=1; j++){
      if(InBounds(x+i,y+j,GetBoardSize())){ // make sure it is inBounds 
	if(m_board[x][y] == m_board[x+i][y+j]){
	  count++; // count the same type of cell 
	}
      }
    }
  }
  return count-1; // -1 because when i,j are 0 it basically is at the same 
  // position as we passed it in and we dont want to check that so subtract it
}

bool Life::InBounds(int row, int col, int boardSize) { // check in bounds
  return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
}

void Life::ModifyBoard(){  
  for(int i = 0; (int)m_killCellX.size() > i; i++){ // coordinates to kill at
    m_board[m_killCellX[i]][m_killCellY[i]] = '-'; // kill the cell
  }
  for(int i = 0; (int)m_makeCellX.size() > i; i++){ // coordinates to give 
    // birth at
    m_board[m_makeCellX[i]][m_makeCellY[i]] = 'O'; // give birth to cell
  }
  m_killCellX.clear();  // clearing out the vectors just to make sure
  m_makeCellX.clear();  // they are never filled back up so the 
  m_killCellY.clear();  // the coordinates used for gen 1 is not used for gen 2
  m_makeCellY.clear();
  // clear out the two vectors now 
}

void Life::OutputResults() const{
  int boardSize = GetBoardSize();
  int cellCount=0;
  cout << "Completed " << m_totalGenCount << " generations" << endl;
  for(int i = 0; boardSize > i; i++){
    for(int j = 0; boardSize > j; j++){
      if(m_board[i][j] == 'O'){// go through entire board and if the 
	cellCount++;           // cell is zero account for it to print later
      }
    }
  }
  cout << cellCount << " live cells at end" << endl;
}

const char *Life::IsLegalMove(int player, int row, int col)const {
  int boardSize = GetBoardSize();
  if(row >= 0){ // special move 0 check, -1 as it is decremented before 
    // legal move check is called 
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize) {
      return "Row or column out of range";
    }
    else if (m_board[row][col] != '-') {
      return "Position already played";
    }
    else {
      return NULL;
    }
  }
  else if(col < -1){ // problem if col is less than 1 when row is 0(special mov
    return "number of generations cannot be lower than 1";
  }
  else{
    return NULL; // okay if row = 0 and col > 0
  }
}

int Life::NumPlayers() const{ 
  return DEFAULT_LIFE_PLAYER; // returns 1
}
