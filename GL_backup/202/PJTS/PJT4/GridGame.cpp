/*****************************************                                     
 ** File:    GridGame.cpp                                                     
 ** Project: CMSC 202 Project 4, Spring 2014                                   
 ** Author:  Neh Patel                                                         
 ** Date:    4/25/2014                                                         
 ** Section: 06                                                                
 ** E-mail:  npatel10@umbc.edu                                              
 **                                                                            
 **   This file contains the main cpp file of the GridGame class.   
 **   The GridGame class is the parent class which has two child classes under 
 **   it. This class ends up having a few empty functinos due to the fact that
 **   GridGame is not a game but supports functions that are common between 
 **   actual game classes. The empty ones will have different implementation
 **   for different games.
 **                                                                            
 ***********************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"

using namespace std;


GridGame::GridGame() {
    m_type = GAME_UNKNOWN;
    m_gameName = "Unknown";
    }

GridGame::GridGame(enum GameType type, const char *gameName) {
  // this is bad codding. I know it is hard coding however the user is not the 
  // one entering these symbols so it is okay to hard code this for now unless
  // changed in the Proj4Aux.cpp
  m_playerSymbols = "XO";;
    m_type = type;
    m_gameName = gameName;
    // if game type is reversi the board is made according that size 
    // for tic tac toe it ould always be 3x3. 8x8 for reversi right now 
    if(m_type == GAME_REVERSI){
      m_boardSize = REVERSI_BOARD_SIZE;  // making reveris board if reversi 
      m_board = new char *[m_boardSize];// game
      for (int r = 0; r < m_boardSize; r++) {
	m_board[r] = new char[m_boardSize];
	for (int c = 0; c < m_boardSize; c++) {
	  m_board[r][c] = '-';
	}
      }
    }else{
      m_boardSize = TICTACTOE_BOARD_SIZE;// making a tic tac board if it tic
      m_board = new char *[m_boardSize]; // toe game
      for (int r = 0; r < m_boardSize; r++) {
        m_board[r] = new char[m_boardSize];
        for (int c = 0; c < m_boardSize; c++) {
	  m_board[r][c] = '-';
        }
      }
    }
}

GridGame::~GridGame(){
  if(m_type  == GAME_REVERSI){
    m_boardSize = REVERSI_BOARD_SIZE;
    // deleting the dynamic memory
    for (int r = m_boardSize - 1; r >= 0; r--) {
      // frist delete the array of character at each character
      delete[]  m_board[r];
	 m_board[r] =NULL;
      }
    // now delete the intial row of char 
    delete[] *m_board;
    *m_board = NULL;  
  }else{
    // same for tic tac toe 
    m_boardSize = TICTACTOE_BOARD_SIZE;
    for (int r = m_boardSize - 1; r >= 0; r--) {
      delete[] m_board[r];
      m_board[r] = NULL; // making sure you set the deleted memory to null
      }
    delete[] *m_board;
    *m_board = NULL;
  }

}

/* Output the a message saying:
 * "Welcome to <GAME NAME>!\nHope you enjoy playing.\n"
 */
void GridGame::OutputGreeting() const{
  cout << "Welcome to " << m_gameName << "!\n";  
}

/*
int Reversi::GetBoardSize() const {
  return m_boardSize;
}
*/

void GridGame::OutputBoard() const {
  for (int r = 0; r < m_boardSize; r++) {
    for (int c = 0; c < m_boardSize; c++) {
      cout << m_board[r][c];
      // called in the main. Just outputs the board 
    }
    cout << endl;
  }
}

char GridGame::GetPlayerSymbol(int player) const {
  // gets the player symbol 
  // static helps it so the next time the function is used the next symbol 
  // can be decided 
  if (player >= static_cast<int>(strlen(m_playerSymbols))) {
    cerr << "GetPlayerSymbol: illegal request\n";
    exit(1);
  }
  return m_playerSymbols[player];
}


const char *GridGame::IsLegalMove(int player, int row, int col) const {
  if (row < 0 || row >= m_boardSize || col < 0 || col >= m_boardSize) {
    return "Row or column out of range";
  }
  else if (m_board[row][col] != '-') {
    return "Position already played";
  }
  else {
    return NULL;
  }
}

int GridGame::GetBoardSize() const {
  return m_boardSize;
}

bool GridGame::IsDone() const{
  // basically wont do anything as there exist overloaded functions in 
  // child class 
  // this output just to know if this function si called by mistake 
  cout << "IsDone in the Grid Game" << endl;
  return true;
}

void GridGame::DoMove(int player, int row, int col){
  cout << "DoMove in the GridGame" << endl;
}

void GridGame::OutputResults() const{
  cout << "OutputResult in the GridGame" << endl;
}

