#pragma once
#include <stdexcept>

#include "board.h"
#include "boardCamera.h"
#include "constants.h"


inline void setGosperGliderGun(Board *board, BoardCamera *camera) {
    if (CELLS_PER_ROW < 36 || CELLS_PER_COL < 9) {
        throw std::runtime_error("cannot set gosper glider gun");
    }

    board->populateEmpty();

    constexpr int start = ((CELLS_PER_ROW - 36) / 4) + ((CELLS_PER_COL - 9) / 4) * CELLS_PER_ROW;

    board->setCell(start + 24, 1);

    board->setCell(start + 22 + CELLS_PER_ROW, 1);
    board->setCell(start + 24 + CELLS_PER_ROW, 1);

    board->setCell(start + 12 + CELLS_PER_ROW * 2, 1);
    board->setCell(start + 13 + CELLS_PER_ROW * 2, 1);
    board->setCell(start + 20 + CELLS_PER_ROW * 2, 1);
    board->setCell(start + 21 + CELLS_PER_ROW * 2, 1);
    board->setCell(start + 34 + CELLS_PER_ROW * 2, 1);
    board->setCell(start + 35 + CELLS_PER_ROW * 2, 1);

    board->setCell(start + 11 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 15 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 20 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 21 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 34 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 35 + CELLS_PER_ROW * 3, 1);

    board->setCell(start + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 10 + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 16 + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 20 + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 21 + CELLS_PER_ROW * 4, 1);

    board->setCell(start + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 10 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 14 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 16 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 17 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 22 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 24 + CELLS_PER_ROW * 5, 1);

    board->setCell(start + 10 + CELLS_PER_ROW * 6, 1);
    board->setCell(start + 16 + CELLS_PER_ROW * 6, 1);
    board->setCell(start + 24 + CELLS_PER_ROW * 6, 1);

    board->setCell(start + 11 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 15 + CELLS_PER_ROW * 7, 1);

    board->setCell(start + 12 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 13 + CELLS_PER_ROW * 8, 1);

    board->setPopulation(36);
    board->resetGeneration();
    board->updateTitle();

    camera->updatePosition(UP_LEFT_QUARTER);
}

inline void setKoksGalaxy(Board *board, BoardCamera *camera) {
    if (CELLS_PER_ROW < 13 || CELLS_PER_COL < 13) {
        throw std::runtime_error("cannot set gosper glider gun");
    }

    board->populateEmpty();

    constexpr int start = ((CELLS_PER_ROW - 14) / 2) + ((CELLS_PER_COL - 14) / 2) * CELLS_PER_ROW;

    board->setCell(start, 1);
    board->setCell(start + 1, 1);
    board->setCell(start + 2, 1);
    board->setCell(start + 3, 1);
    board->setCell(start + 4, 1);
    board->setCell(start + 5, 1);
    board->setCell(start + 7, 1);
    board->setCell(start + 8, 1);

    board->setCell(start + CELLS_PER_ROW, 1);
    board->setCell(start + 1 + CELLS_PER_ROW, 1);
    board->setCell(start + 2 + CELLS_PER_ROW, 1);
    board->setCell(start + 3 + CELLS_PER_ROW, 1);
    board->setCell(start + 4 + CELLS_PER_ROW, 1);
    board->setCell(start + 5 + CELLS_PER_ROW, 1);
    board->setCell(start + 7 + CELLS_PER_ROW, 1);
    board->setCell(start + 8 + CELLS_PER_ROW, 1);

    board->setCell(start + 7 + CELLS_PER_ROW * 2, 1);
    board->setCell(start + 8 + CELLS_PER_ROW * 2, 1);

    board->setCell(start + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 7 + CELLS_PER_ROW * 3, 1);
    board->setCell(start + 8 + CELLS_PER_ROW * 3, 1);

    board->setCell(start + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 7 + CELLS_PER_ROW * 4, 1);
    board->setCell(start + 8 + CELLS_PER_ROW * 4, 1);

    board->setCell(start + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 7 + CELLS_PER_ROW * 5, 1);
    board->setCell(start + 8 + CELLS_PER_ROW * 5, 1);

    board->setCell(start + CELLS_PER_ROW * 6, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 6, 1);

    board->setCell(start + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 3 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 4 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 5 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 6 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 7 + CELLS_PER_ROW * 7, 1);
    board->setCell(start + 8 + CELLS_PER_ROW * 7, 1);

    board->setCell(start + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 1 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 3 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 4 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 5 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 6 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 7 + CELLS_PER_ROW * 8, 1);
    board->setCell(start + 8 + CELLS_PER_ROW * 8, 1);


    board->setPopulation(48);
    board->resetGeneration();
    board->updateTitle();

    camera->updatePosition(CENTER);
}
