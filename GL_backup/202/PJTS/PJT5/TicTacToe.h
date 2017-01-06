#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "GridGame.h"

const int TICTACTOE_BOARD_SIZE = 3;

class TicTacToe: public GridGame {
public:
    /*
     * Move as many of these member functions as REASONABLE up
     * into common parent class
     */
    TicTacToe();

    TicTacToe(const char *playerSymbols);

    bool IsDone() const;

    bool FindWinner(char& winner) const;

    void DoMove(int player, int row, int col);

    void OutputResults() const;

};

#endif //TICTACTOE_H
