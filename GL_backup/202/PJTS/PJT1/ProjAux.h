/*****************************************                                     
 ** File:    Proj1.h 
 ** Project: CMSC 202 Project 1, Spring 2014                                   
 ** Author:  Neh Patel                                                        
 ** Date:    3/9/14                                                            
 ** Section: 08                                                                
 ** E-mail:  npatel10@umbc.edu                                                 
 **                                                                            
 **   This file contains the functions prototypes for the ProjAux.cpp file
 **                                                                         
 **                                                                            
 ***********************************************/ 


#ifndef PROJAUX_H
#define PROJAUX_H

// I'm not sure how exactly to use 'MAX_SIZE' instead of 11. I tried but it 
// it gave me errors so I just used 11 and it worked fine 
// same in the ProjAux.cpp file. 
// without defining it in file gave me error, defining it said I redefined it 
// it is a global constant in the main file 

  void PrintGreeting();
  bool CheckBoardSize(char board[][11], int boardVal);
  void MakeBoardSize(char board[][11], int boardSize);
  bool CheckEndGame(char board[][11], int boardVal);
  int CountX(char board[][11], int boardVal);
  int CountO(char board[][11], int boardVal);
  void WhoWon(char xCount, int oCount);
  void GetNextMove(char playerSymbol, int &row , int &col );
  bool coordinateValidation(int row, int col, int boardValue);            
  void checkReversi(char board[][11], char playerSymbol,int boardVal, int row,int col);   
  void checkUp(int row, int col, char playerSymbol, char board[][11]);
 void checkDown(int row, int col, char playerSymbol, char board[][11], int boardVal);
void checkRight(int row, int col, char playerSymbol, char board[][11], int boadVal);                                                      
void checkLeft(int row, int col, char playerSymbol, char board[][11]);         

// void checkLeftUp()                                                         
// void checkRightUp()                                                        
// void checkLeftDown()                                                       
// void checkRightDown()                                                      

#endif
