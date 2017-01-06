/*****************************************                                      ** File:    TicTacToe.cpp 
 ** Project: CMSC 202 Project 4, Spring 2014                                   
 ** Author:  Neh Patel                                                        
 ** Date:    4/25/2014                                                         
 ** Section: 06                                                                
 ** E-mail:  npatel10@umbc.edu                                              
 **                                                                            
 **   This file contains the main cpp file & implemetation  of Tic Tac Toe     
 **   The TicTacToe class is the child class under the GridGame class.        
 **   Most of the code for this class was provided by the professor in the   
 **   Reversi class. FlipInDir and OutputResults were the one mostly changes 
 **                                                                            
 ***********************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
  : GridGame(GAME_TICTACTOE, "Tic Tac Toe"){
  m_playerSymbols = "XO";
  m_gameWon = false; // initially set them all to false so the isDone 
  m_XWon = false;   // does not retrun the wrong boolean
  m_OWon = false;
  /*   m_boardSize = TICTACTOE_BOARD_SIZE;
   m_board = new char *[m_boardSize];
   for (int r = 0; r < m_boardSize; r++) {
     m_board[r] = new char[m_boardSize];
     for (int c = 0; c < m_boardSize; c++) {
       m_board[r][c] = '-';
     }
     }*/
}

TicTacToe::TicTacToe(const char *playerSymbols) 
  : GridGame(GAME_TICTACTOE, "Tic Tac Toe"){
  m_playerSymbols = "XO";
  /*
  m_boardSize = TICTACTOE_BOARD_SIZE;
  m_board = new char *[m_boardSize];
  for (int r = 0; r < m_boardSize; r++) {
    m_board[r] = new char[m_boardSize];
    for (int c = 0; c < m_boardSize; c++) {
      m_board[r][c] = '-';
    }
    }*/
}


//
// SEE THE APOLOGY IN TICTACTOE.H EXPLAINING THE PITIFUL STATE
// OF THIS FILE  --PROFESSOR
//

int TicTacToe::GetBoardSize() const {
  return m_boardSize;
}

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void TicTacToe::DoBasicMove(int player, int row, int col) {
  //  const char *errStr;

  // We're paranoid--double-check
  /*
  if ((errStr = IsLegalMove(player, row, col)) != NULL) {
    cerr << errStr << "--exiting\n";
    exit(1);
  }*/

  m_board[row][col] = m_playerSymbols[player];
}

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void TicTacToe::DoMove(int player, int row, int col) {
  
  int rowIncr, colIncr;
  char playerSym = GetPlayerSymbol(player);
  // used the same code to get two values and sending them out 
  DoBasicMove(player, row, col);
  for (rowIncr = -1; rowIncr <= 1; rowIncr++) {
    for (colIncr = -1; colIncr <= 1; colIncr++) {
      if (rowIncr || colIncr) { // Going in some direction
	FlipTilesInDir(playerSym, row, rowIncr, col, colIncr);
      }
    }
  }
}

bool TicTacToe::InBounds(int row, int col, int boardSize) {
  return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
}

void TicTacToe::FlipTilesInDir(char playerSym, int row, int rowIncr, int col, 
			       int colIncr) {
  int r, c,count;
  int boardSize = GetBoardSize();

  for (r = row + rowIncr, c = col + colIncr; InBounds(r, c, boardSize);
       r += rowIncr, c += colIncr) {
    if (m_board[r][c] == '-') {
      break;
    }
    else if (m_board[r][c] == playerSym) {
     
      // We found a range of pieces to flip--Work backwards flipping
      // Note: in following, need to test both r and c, since one or
      // other might not be changing
      for (r -= rowIncr, c -= colIncr; r != row || c!= col;
	   r -= rowIncr, c -= colIncr) {
	cout << count << endl;
	count++;
        }
      if(count == 3){
	m_gameWon = true;  // this says that a game did have an outcome 
	if(playerSym == 'X'){  // checks which player it is 
	  m_XWon = true; // if X then x wins 
	}else{
	  m_OWon = true; // if O then o wins 
	}
      }
      return;
    }
  }
}

bool TicTacToe::IsDone() const {
  int boardSize = GetBoardSize();
  if(m_gameWon){
    // returns true is the game is won 
    return true;
  }else{
  for (int r = 0; r < boardSize; r++) {
    for (int c = 0; c < boardSize; c++) {
      if (m_board[r][c] == '-') {
	// returns false if no one has won or all the spots are not filled in
	return false;
      }
    }
  }
  }
  // returns true if all the places are filled in and no result 
  return true;
}

void TicTacToe::OutputResults() const {
  
  if (m_XWon) { // X won 
    cout << "Player X  wins!\n";
  }
  else if (m_OWon) { // O won 
    cout << "Player O wins!\n";
  }
  else { // no winner
    cout << "The game is a tie\n";
  }
}
