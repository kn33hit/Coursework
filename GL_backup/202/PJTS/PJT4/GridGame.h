/*****************************************
 ** File:    GridGame.h
 ** Project: CMSC 202 Project 4, Spring 2014
 ** Author:  Neh Patel
 ** Date:    4/25/2014
 ** Section: 06
 ** E-mail:  npatel10@umbc.edu 
 **
 **   This file contains the header file and prototype of the GridGame class
 **   The GridGame class is the parent class which has two child classes under
 **   it. 
 ** 
 **
 ***********************************************/


#ifndef GRIDGAME_H
#define GRIDGAME_H

#include "GameType.h"

const int REVERSI_BOARD_SIZE = 8;
const int TICTACTOE_BOARD_SIZE = 3;

class GridGame {
public:
  /*                                                                          
    GridGame()                                                       
     a default constructor that sets type and name to unknown 
    NO PRE OR POST                
  */  
  GridGame();

  /*                                                                      
    GridGame(type, name)                                                       
     creates an object with  a name and type and creates the board and other   
     variables accordingly                                                     
    PRE                                                                        
     must create a Reversi or TicTacToe object and pass name and type          
    POST                                                                       
     a board is created                                                        
  */
    GridGame(enum GameType type, const char *name);

    /*                                                                            ~GridGame()                                                      
     destroys/ deletes the board which was made though dynamic memory                                      
    PRE                                                                        
     constructor must be called first           
    POST                                                                       
     a board is destroyed                                          
    */
    ~GridGame();
    
    /* 
       GetType 
         gets the type of game
       nor pre or post
    */
    enum GameType GetType() { return m_type;}

    /*
      OutputGreeting 
        outputs a grreting (called from the main)
      No PRE 
      POST 
        outputs a message
     */
    void OutputGreeting() const;
    
    /* 
       OutputBoard
         outputs the board 
       NO pre or post
    */
    void OutputBoard() const;

    /*
      GetBiardSize 
        returns an int teh size of the board 
    */
    int GetBoardSize() const;
    
    /* 
       GetPlayerSymbol 
         gets the symbol for the player 
    */
    char GetPlayerSymbol(int player) const;

    /*
      IsLegalMove 
        checks if the moce entered by the player is legal or not 
      PRE 
        must have x y coordinate 
      POST 
        none 
    */
    const char *IsLegalMove(int player, int row, int col) const;

    /* these three funcitons do not do anything in this class,
       As they will be called in child classes where actaul implementation is
    */
    bool IsDone() const;

    void DoMove(int player, int row, int col);

    void OutputResults() const;


protected:
    int m_boardSize;
    const char *m_playerSymbols;
    char **m_board;
    enum GameType m_type;
    const char *m_gameName;
};

#endif //GRIDGAME_H
