#include <iostream>
#include <cstring>
#include <cstdlib>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() : GridGame("TicTacToe", "XO", TICTACTOE_BOARD_SIZE) {}

TicTacToe::TicTacToe(const char *playerSymbols)
    : GridGame("TicTacToe", playerSymbols, TICTACTOE_BOARD_SIZE) {
}
    

bool TicTacToe::IsDone() const {
    char winner;  // Dummy
    return (FindWinner(winner));
}


/*
 * Returns:
 *   true if game is over, with "winner" set to winning symbol
 *   false if no one has won yet and there are still moves left
 */
bool TicTacToe::FindWinner(char& winner) const {
    int r, c;
    int bdSize = GetBoardSize();

    // Game is over when someone has bdSize-in-a-row
    // First, check each column
    for (r = 0; r < bdSize; r++) {
	winner = m_board[r][0];
	if (winner != '-') {
	    for (c = 1; c < bdSize; c++) {
		if (m_board[r][c] != winner) {
		    break;
		}
	    }
	    if (c >= bdSize) {
		return true;
	    }
	}
    }

    // Now, check each column
    for (c = 0; c < bdSize; c++) {
	winner = m_board[0][c];
	if (winner != '-') {
	    for (r = 1; r < bdSize; r++) {
		if (m_board[r][c] != winner) {
		    break;
		}
	    }
	    if (r >= bdSize) {
		return true;
	    }
	}
    }
    // Lastly, check diagonals
    winner = m_board[0][0];
    if (winner != '-') {
	for (r = 1; r < bdSize; r++) {
	    if (m_board[r][r] != winner) {
		break;
	    }
	}
	if (r >= bdSize) {
	    return true;
	}
    }
    winner = m_board[0][bdSize - 1];
    if (winner != '-') {
	for (r = 1; r < bdSize; r++) {
	    if (m_board[r][bdSize - 1 - r] != winner) {
		break;
	    }
	}
	if (r >= bdSize) {
	    return true;
	}
    }

    // Okay, found no winners--see if there is anywhere else to move
    for (r = 0; r < bdSize; r++) {
	for (c = 0; c < bdSize; c++) {
	    if (m_board[r][c] == '-') {
		return false;
	    }
	}
    }
    winner = '\0';  // Indicate a draw
    return true;
}

/*
 * Puts new piece for player at {row, col} position
 * Preconditions:
 *   Assumes position has already been pre-checked by IsLegalMove() for
 *   valid bounds and emptiness.
 */
void TicTacToe::DoMove(int player, int row, int col) {
    DoBasicMove(player, row, col);
    // Nothing else to do--checking for 3-in-a-row is done elsewhere.
}
    

void TicTacToe::OutputResults() const {
    char winner;

    if (!FindWinner(winner)) {
	cerr << "OutputResults(): called before game over??\n";
	exit(1);
    }
    if (winner != '\0') {
	cout << "Player " << winner << " wins!\n";
    }
    else {
	cout << "The game is a tie\n";
    }
}
