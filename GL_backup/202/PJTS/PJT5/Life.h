/*****************************************                                     
 ** File:    Life.h                                                     
 ** Project: CMSC 202 Project 5, Spring 2014                                   
 ** Author:  Neh Patel                                                         
 ** Date:    5/14/2014                                                         
 ** Section: 06                                                               
 ** E-mail:  npatel10@gl.umbc.edu                                              
 **                                                                            
 **   This file contains the prototype of the class of the Life game.     
 ** This program reads the creates the game and contains the overloaded        
 ** funcitons needed to have the game function correctly according to the      
 ** specifications provided                                                    
 **                                                                            
 **                                                                           
 ***********************************************/
#ifndef LIFE_H
#define LIFE_H
#include "GridGame.h"
#include <vector>
const int LIFE_BOARD_SIZE = 20;

class Life: public GridGame {
    /*
     * YOUR CODE HERE.
     * MUST HAVE:
     *
     *   default constructor: calls parent's constructor with "O"
     *
     *   1-arg constructor: takes a char* pointing to a string of
     *     player symbols (will always be a single-echar string),
     *     passes that to GridGame's constructor
     *
     * Virtual functions from GridGame that you might, or might not, want
     * to override in this class:
     *   OutputGreeting()
     *   NumPlayers()  NEW
     *   IsDone();
     *   OutputBoard()
     *   OutputResults()
     *   GetPlayerSymbol()int player)
     *   const char * IsLegalMove(int player, int row, int col)
     *   DoMove(int player, int row, int col)
     *
     * Some of these definitely have to be overridden.  Read the
     * project description for an explanation of how we have adapted
     * the Life game to work like a GridGame--that should provide
     * enough information to decide what you need to do.  For example,
     * the functions IsLegalMove() and DoMove() will very likely
     * need overriding.
     */

 public: 
  /********************************************************************
  Life 
    default constructor for life, never really used but basically creates 
    a life game name, board size, and player symbol 0
  No PRE 
  POST
   creates a Life and GridGame object
  *******************************************************************/
  Life();

  /********************************************************************   
  Life(playerSym)                                                             
    constructor for life, never really used but basically creates      
    a life game name, board size, and player symbol that is passed in        
  No PRE                                                                       
  POST                                                                         
   creates a Life and GridGame object                                         
  *******************************************************************/
  Life(const char *playerSym);

  /********************************************************************    
  IsDone()                                                                     
    checks is the m_exit is true or false                     
  PRE
   needs to handled in DoMove and then is carried to return false or true 
   if 0 0 is entered 
  POST                                                                   
   game ends                                      
  *******************************************************************/
  bool IsDone() const;

  /********************************************************************     
  OutputResults                                                               
    outputs the number of cells alive and also the total number of times  
    the generation is called                         
  PRE
    the game needs to end before this fucntion is called 
  POST                                                                         
   outputs a couple things                      
  *******************************************************************/
  void OutputResults() const;

  /********************************************************************     
  DoMove                                                                      
    this is method changes the sleected coordinates location 
    then calls other functions to have the main game's logic done 
    It also calculates the nuber of generations 
  PRE
    the coordinates should be okay for this                                 
  POST                                                                         
   modifies the board                                       
  *******************************************************************/
  void DoMove(int player, int row, int col);
  
  /********************************************************************    

  IsLegalMove                                                 
    most of its logic is given with a few changes added to it
    1) allows 0 to be okay for rows and columns 
    2) if columns is less than 0 returns a string 
     TRIED TIS FOR ROW BUT THE LOGIC MESSED UP AND THEN GAVE SEG FAULT 
     SO NOW IF -1 IS ENTERED IT STILL GIVES OUT SEG FAULT
  PRE
   coordinates must be entered 
  POST                                                                         
   allows the DoMove fucntion to be called
  *******************************************************************/
  const char *IsLegalMove(int player, int row, int col)const;

  /********************************************************************     
  NumPlayers                                     
    returns the total number of players for this game which is 1            
  No PRE                                                                      
  POST                                                                         
   returns 1                                      
  *******************************************************************/
  int NumPlayers() const;

  /********************************************************************          GoAround                                                                         takes in a coordinate and goes around its neighbors to check if the 
    neighbors have the same symbol
  PRE 
   called from dead alive cell fucntions 
  POST                                                                         
   returns a count of same type of neighbors minus 1. As in the for loop
   it will also count 0 0 which we know is same 
  *******************************************************************/  
  int GoAround(int x, int y);
  
  /********************************************************************    
  ModifyBaord                      
   modifies the board according to the positions stored in the vector  
  PRE
    special case 0 # needs to be the input 
  POST                                                                         
   board is modified                                         
  *******************************************************************/
  void ModifyBoard();

  /********************************************************************       
  CheckDeadCell                                                          
    if the cell is dead and its neighbors are 3 alive cells, a new cell is born    at the current cell                          
  PRE
   special case 0 #
  POST                                                                         
   positions to create new cell is stored in makeCellX/Y vectors              
  *******************************************************************/
  void CheckDeadCell();

  /********************************************************************        
  CheckAliveCells
    if the cell is alive and its neighbors have less than 2 or more than 3 
    alive neighbors than it dies 
  PRE 
   special move 0 #
  POST                                                                         
   positions to destroy a cell is stored in killCellX/Y  
  *******************************************************************/  
  void CheckAliveCell();
  
  /********************************************************************       
  InBounds                           
    checks to see if the coordinate entered is in bounsd or not                  NO PRE
  POST                                             
   returns true if in bounds and false if not                           
  *******************************************************************/
  bool InBounds(int x, int y, int boardSize);

 private:
  int m_genCountEntered; // just to keep track of generations entered
  int m_totalGenCount; // total is needed at the end
  bool m_exit; // to save and handle later into the porgram 
  std::vector<int> m_makeCellX;
  std::vector<int> m_makeCellY;
  std::vector<int> m_killCellX;
  std::vector<int> m_killCellY;




};


#endif //LIFE_H
