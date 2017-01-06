#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"

using namespace std;

const int DEFAULT_NUM_PLAYERS = 2;

GridGame::GridGame() {
   
    m_gameName = "Unknown";
    m_boardSize = 0;
    m_board = NULL;
    m_playerSymbols = NULL;
    // YOUR CODE HERE
}


/*
 * These constructors are protected, so only called by subclasses
 */

GridGame::GridGame(const char *gameName,
		   const char *playerSymbols, int boardSize) {
  //m_type = type;
    m_gameName = gameName;
    m_boardSize = boardSize;
    m_playerSymbols = playerSymbols;
    m_board = new char *[boardSize];
    for (int r = 0; r < boardSize; r++) {
	m_board[r] = new char[boardSize];
	for (int c = 0; c < boardSize; c++) {
	    m_board[r][c] = '-';
	}
    }
    
}

/* Output the a message saying:
 * "Welcome to <GAME NAME>!\nHope you enjoy playing.\n"
 */
void GridGame::OutputGreeting() const {
    cout << "Welcome to " << m_gameName << "!\n";
}

/* Returns NULL on good move, else returns err string.
 * Note that this check is game-neutral (at least for TTT and Reversi)
 */
char GridGame::GetPlayerSymbol(int player) const {
    if (player >= static_cast<int>(strlen(m_playerSymbols))) {
	cerr << "GetPlayerSymbol: illegal request\n";
	exit(1);
    }
    return m_playerSymbols[player];
}

int GridGame::NumPlayers() const {
    return DEFAULT_NUM_PLAYERS;
}

int GridGame::GetBoardSize() const {
    return m_boardSize;
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

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void GridGame::DoBasicMove(int player, int row, int col) {
    const char *errStr;

    // We're paranoid--double-check
    if ((errStr = IsLegalMove(player, row, col)) != NULL) {
	cerr << errStr << "--exiting\n";
	exit(1);
    }
    m_board[row][col] = m_playerSymbols[player];
}


void GridGame::OutputBoard() const {
    for (int r = 0; r < m_boardSize; r++) {
	for (int c = 0; c < m_boardSize; c++) {
	    cout << m_board[r][c];
	}
	cout << endl;
    }
}

GridGame::~GridGame() {
    for (int r = 0; r < m_boardSize; r++) {
	delete [] m_board[r];
	m_board[r] = NULL;
    }
    delete [] m_board;
    m_board = NULL;
}


// DONT NEED THESE THREE IN HERE BUT JUST HAD THEM IN HERE DUE TO AN ERROR 
// AND ALSO TO MAKE SURE THE RIGHT OVERLOADED FUNCTIONS FROM THE DERIVED 
// CLASSES WERE BEING CALLED 

bool GridGame::IsDone() const{
  cout << "IsDone from gridgame" << endl;
  // just so it doesnt keep looping
  return true;
}

void GridGame::DoMove(int player, int row, int col){
  cout << "DoMove from gridgame" << endl;
}

void GridGame::OutputResults() const{
  cout << "Output from gridgame" << endl;
}
