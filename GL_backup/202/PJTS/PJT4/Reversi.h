/*****************************************                                     
 ** File:    Reversi.h                                                        
 ** Project: CMSC 202 Project 4, Spring 2014                                   
 ** Author:  Neh Patel                                                         
 ** Date:    4/25/2014                                                         
 ** Section: 06                                                                
 ** E-mail:  npatel10@umbc.edu                                              
 **                                                                            
 **   This file contains the header file and prototype of the Reversi class   
 **   The Reversi class is the child class under the GridGame class.
 **                                                                       
 ***********************************************/

#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"


class Reversi: public GridGame {
 public:
  /*     * Move as many of these member functions as REASONABLE up
     * into common parent class
     */
    Reversi();

    Reversi(const char *playerSymbols);

     int GetBoardSize() const;

     void DoBasicMove(int player, int row, int col);

     bool IsDone() const;

     void DoMove(int player, int row, int col);

     void OutputResults() const;

protected:
     //    int m_boardSize;
    const char *m_playerSymbols;
    //char **m_board;

    static bool InBounds(int row, int col, int boardSize);

    void FlipTilesInDir(char playerSym, int row, int rowIncr,
			int col, int colIncr);
};

#endif //REVERSI_H
