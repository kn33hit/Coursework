/*****************************************                                     
 ** File:    Reversi.cpp
 ** Project: CMSC 202 Project 4, Spring 2014                                   
 ** Author:  Neh Patel                                                         
 ** Date:    4/25/2014                                                        
 ** Section: 06                                                               
 ** E-mail:  npatel10@umbc.edu                                             
 **                                                                           
 **   This file contains the main cpp file & implemetation  of the Reversi
 **   The Reversi class is the child class under the GridGame class.          
 **   All of the code for this class was provided by the professor           
 **
 ***********************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Reversi.h"

using namespace std;


Reversi::Reversi()
  : GridGame(GAME_REVERSI, "Reversi") {
    m_playerSymbols = "XO";
    /*
    m_boardSize = REVERSI_BOARD_SIZE;
    m_board = new char *[m_boardSize];
    for (int r = 0; r < m_boardSize; r++) {
	m_board[r] = new char[m_boardSize];
	for (int c = 0; c < m_boardSize; c++) {
	    m_board[r][c] = '-';
	}
	}*/
}

Reversi::Reversi(const char *playerSymbols)
  : GridGame(GAME_REVERSI, "Reversi") {
    m_playerSymbols = playerSymbols;
    /*
    m_boardSize = REVERSI_BOARD_SIZE;
    m_board = new char *[m_boardSize];
    for (int r = 0; r < m_boardSize; r++) {
	m_board[r] = new char[m_boardSize];
	for (int c = 0; c < m_boardSize; c++) {
	    m_board[r][c] = '-';
	}
    }
    */
}

int Reversi::GetBoardSize() const {
    return m_boardSize;
}

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void Reversi::DoBasicMove(int player, int row, int col) {
    const char *errStr;

    // We're paranoid--double-check
    if ((errStr = IsLegalMove(player, row, col)) != NULL) {
	cerr << errStr << "--exiting\n";
	exit(1);
    }
    m_board[row][col] = m_playerSymbols[player];
}

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void Reversi::DoMove(int player, int row, int col) {
    int rowIncr, colIncr;
    char playerSym = GetPlayerSymbol(player);

    DoBasicMove(player, row, col);
    for (rowIncr = -1; rowIncr <= 1; rowIncr++) {
	for (colIncr = -1; colIncr <= 1; colIncr++) {
	    if (rowIncr || colIncr) { // Going in some direction
		FlipTilesInDir(playerSym, row, rowIncr, col, colIncr);
	    }
	}
    }
}

bool Reversi::InBounds(int row, int col, int boardSize) {
    return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
}

void Reversi::FlipTilesInDir(char playerSym, int row, int rowIncr, int col, int colIncr) {
    int r, c;
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
		m_board[r][c] = playerSym;
	    }
	    return;
	}
    }
}


bool Reversi::IsDone() const {
    int boardSize = GetBoardSize();

    for (int r = 0; r < boardSize; r++) {
	for (int c = 0; c < boardSize; c++) {
	    if (m_board[r][c] == '-') {
		return false;
	    }
	}
    }
    return true;
}

void Reversi::OutputResults() const {
    int count[2];
    char playerSym[2];
    int boardSize = GetBoardSize();


    count[0] = count[1] = 0;
    playerSym[0] = GetPlayerSymbol(0);
    playerSym[1] = GetPlayerSymbol(1);

    // Tabulate results
    for (int r = 0; r < boardSize; r++) {
	for (int c = 0; c < boardSize; c++) {
	    for (int s = 0; s < 2; s++) {
		if (m_board[r][c] == playerSym[s]) {
		    ++(count[s]);
		}
	    }
	}
    }

    // Finally, find highest score
    for (int s = 0; s < 2; s++) {
	cout << "Player " << playerSym[s] << " conrols " << count[s]
	     << " squares.\n";
    }
    if (count[0] > count[1]) {
	cout << "Player " << playerSym[0] << " wins!\n";
    }
    else if (count[1] > count[0]) {
	cout << "Player " << playerSym[1] << " wins!\n";
    }
    else {
	cout << "The game is a tie\n";
    }
}
