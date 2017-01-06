#ifndef REVERSI_H
#define REVERSI_H
#include "GridGame.h"

const int REVERSI_BOARD_SIZE = 4;

class Reversi: public GridGame {
public:
    /*
     * Move as many of these member functions as REASONABLE up
     * into common parent class
     */
    Reversi();

    Reversi(const char *playerSymbols);

    bool IsDone() const;

    void DoMove(int player, int row, int col);

    void OutputResults() const;

private:
    static bool InBounds(int row, int col, int boardSize);

    void FlipTilesInDir(char playerSym, int row, int rowIncr,
			int col, int colIncr);
};

#endif //REVERSI_H
