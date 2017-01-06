/*****************************************                                     
 ** File:    TicTacToe.h
 ** Project: CMSC 202 Project 4, Spring 2014                                  
 ** Author:  Neh Patel                                                         
 ** Date:    4/25/2014                                                        
 ** Section: 06                                                                
 ** E-mail:  npatel10@umbc.edu                                              
 **                                                                            
 **   This file contains the hader and prototype  of Tic Tac Toe     
 **   The TicTacToe class is the child class under the GridGame class.         
 **   Most of the code for this class was provided by the professor in the     
 **   Reversi class.    
 **                                                                            
 ***********************************************/


#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"


class TicTacToe: public GridGame {
public:
    
  /*
    TicTacToe() 
      default constructor, creates a game of tic tac toe with XO symbols 
   PRE 
      a gridgame constructor should be made so a board to play on is created 
   POST 
     board is created from the gridgame constructore in the parent class 
   */
    TicTacToe();

    /*                                                                         
    TicTacToe()                                                                
      default constructor, creates a game of tic tac toe with symbols that    
      are passed in 
   PRE                                                                         
      a gridgame constructor should be made so a board to play on is created   
   POST                                                                        
     board is created from the gridgame constructore in the parent class       
    */
    TicTacToe(const char *playerSymbols);

    //
    // SORRY, JANE DOE, BUT I DID NOT GET TO REALLY WORK ON
    // THIS MUCH--YOU SHOULD LOOK AT THE MOST EXCELLENT CODE IN
    // REVERSI TO SEE WHAT THIS SHOULD LOOK LIKE.
    //
    // I ALSO HAVE A PREMONITION THAT I WILL BE CHANGING THE REVERSI
    // CLASS A LOT, AND I HAVE THIS SINKING FEELING THAT I AM DESTINED
    // TO LOSE THE MODIFICATIONS, SO IF THAT HAPPENS, YOU SHOULD FINISH
    // UPGRADING REVERSI.H AND REVERSI.CPP FIRST BEFORE WORKING ON
    // THE TICTACTOE CLASS--IT MIGHT SAVE YOU A LOT OF WORK.
    //
    // THE PROFESSOR
    //
   

    // THE HEADERS FOR THESE FUNCTIONS ARE IDENTICAL TO THE SAME FUNCTIONS IN 
    // GRIDGAME CLASS HEADER FILE 
    int GetBoardSize() const;
 
    void DoBasicMove(int player, int row, int col);
    
    /*
      IsDone() 
         very identiacl when it comes to a filled out board 
	 the only thing is added is that when a player wins, isDone returns 
	 true
      PRE 
         none really
      POST 
        returns a boolean
    */
    bool IsDone() const;

    void DoMove(int player, int row, int col);

    /* 
       OutputResults()
         outputs who won, x or o or a tie. 
	 The implementation in this class fucniton is a lot shorter than 
	 the Reversi class function 
       PRE 
         The game should've ended 
       POST 
         outputs results 
    */
    void OutputResults() const;

 protected:
    //    int  m_boardSize;
      const char *m_playerSymbols;
    // char **m_board;
    
    // this member keeps track of who won the game
    bool m_XWon;
    bool m_OWon;
    bool m_gameWon;
     static bool InBounds(int row, int col, int boardSize);
     
     /* 
	FlipTilesInDir
	  this function is changed entirely.
	  new algorithm just checks for three in a row and returns 
	  whichever player has won by changing a data member's function 
        PRE 
	  can onyl be called from DoMove 
       POST 
          decides who won 
     */
     void FlipTilesInDir(char playerSym, int row, int rowIncr, int col,
			 int colIncr);
};

#endif //TICTACTOE_H
