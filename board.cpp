#include <cstdlib>
#include <format>

#include "raylib.h"

#include "board.h"
#include "random.h"


Board::Board() : generation(0), population(0) {
    cells = static_cast<float*>(malloc(CELLS_AMOUNT * sizeof(float)));
    nextCells = static_cast<float*>(malloc(CELLS_AMOUNT * sizeof(float)));
}

Board::~Board() {
    free(cells);
    free(nextCells);
}

void Board::drawGrid() {
    // vertical lines
    for (int i = 0; i <= WORLD_W; i += CELL_SIZE) {
        DrawLine(i, 0, i, WORLD_H, LINE_COLOR);
    }
    // horizontal lines
    for (int i = 0; i <= WORLD_H; i += CELL_SIZE) {
        DrawLine(0, i, WORLD_W, i, LINE_COLOR);
    }
}

void Board::updateTitle() {
    const std::string title = std::format("game of life - generation: {} - population: {}", generation, population);
    SetWindowTitle(title.c_str());
}

void Board::populateEmpty() {
    for (int i = 0; i < CELLS_AMOUNT; i++) {
        cells[i] = 0;
        nextCells[i] = 0;
    }

    population = 0;
    generation = 0;

    updateTitle();
}

void Board::populateRandom() {
    population = 0;

    for (int i = 0; i < CELLS_AMOUNT; i++) {
        if (distrib(gen) < 30) {
            cells[i] = 1;
            population++;
        } else {
            cells[i] = 0;
        }
    }

    generation = 0;

    updateTitle();
}

void Board::populateSymmetric() {
    population = 0;

    for (int i = 0; i < CELLS_AMOUNT / 2; i++) {
        if (i % CELLS_PER_ROW < CELLS_PER_ROW / 2) {
            if (distrib(gen) < 30) {
                cells[i] = 1;
                population += 4;
            } else {
                cells[i] = 0;
            }
        }
    }

    for (int i = 0; i < CELLS_AMOUNT / 2; i++) {
        if (i % CELLS_PER_ROW < CELLS_PER_ROW / 2) {
            cells[CELLS_AMOUNT - i - 1] = cells[i];
            cells[CELLS_PER_ROW * (i / CELLS_PER_ROW + 1) - (i % CELLS_PER_ROW) - 1] = cells[i];
            cells[CELLS_AMOUNT - CELLS_PER_ROW + 2 * (i % CELLS_PER_ROW) - i] = cells[i];
        }
    }

    generation = 0;

    updateTitle();
}

void Board::draw() const {
    for (int i = 0; i < CELLS_AMOUNT; i++) {
        if (cells[i] > 0) {
            const int startPosX = (i % CELLS_PER_ROW) * CELL_SIZE;
            const int startPosY = (i / CELLS_PER_ROW) * CELL_SIZE;
            DrawRectangle(startPosX, startPosY, CELL_SIZE - 1, CELL_SIZE - 1, ColorAlpha(CELL_COLOR, cells[i]));
            DrawLine(startPosX, startPosY, startPosX, startPosY + CELL_SIZE, LINE_COLOR);
            DrawLine(startPosX, startPosY, startPosX + CELL_SIZE, startPosY, LINE_COLOR);
        }
    }
}

void Board::tickCell(const int position, const int neighboursAlive) {
    nextCells[position] = cells[position];

    if (cells[position] == 1) { // alive
        if (neighboursAlive < 2 || neighboursAlive > 3) {
            nextCells[position] = 1 - DEATH_SPEED;
            //std::cout << "cell " << i << " dies " << std::endl;
        } else {
            population++;
        }
    } else { // dead
        if (neighboursAlive == 3) {

            //std::cout << "cell " << i << " is born " << std::endl;
            nextCells[position] = 1;
            population++;
        } else if (nextCells[position] > 0) {
            nextCells[position] -= DEATH_SPEED;
            if (nextCells[position] < 0) {
                nextCells[position] = 0;
            }
        }
    }
}

void Board::tick() {
    population = 0;

    for (int i = 0; i < CELLS_AMOUNT; i++) {
        int neighboursAlive = 0;
        const bool onFirstRow = i < CELLS_PER_ROW;
        const bool onFirstColumn = i % CELLS_PER_ROW == 0;
        const bool isOnLastRow = i >= CELLS_AMOUNT - CELLS_PER_ROW;
        const bool isOnLastColumn = (i + 1) % (CELLS_PER_ROW) == 0;

        if (!onFirstRow) {
            if (!onFirstColumn) {
                neighboursAlive += isAlive(i - CELLS_PER_ROW - 1);
            }
            neighboursAlive += isAlive(i - CELLS_PER_ROW);
            if (!isOnLastColumn) {
                neighboursAlive += isAlive(i - CELLS_PER_ROW + 1);
            }
        }

        if (!onFirstColumn) {
            neighboursAlive += isAlive(i - 1);
        }

        if (!isOnLastColumn) {
            neighboursAlive += isAlive(i + 1);
        }

        if (!isOnLastRow) {
            if (!onFirstColumn) {
                neighboursAlive += isAlive(i + CELLS_PER_ROW - 1);
            }
            neighboursAlive += isAlive(i + CELLS_PER_ROW);
            if (!isOnLastColumn) {
                neighboursAlive += isAlive(i + CELLS_PER_ROW + 1);
            }
        }

        tickCell(i, neighboursAlive);
    }

    generation++;
    updateTitle();
    swapCells();
}

void Board::tickBorderLess() {
    population = 0;

    for (int i = 0; i < CELLS_AMOUNT; i++) {
        const int neighboursAlive = floor(cells[northPos(i)]) + floor(cells[southPos(i)]) +
            floor(cells[westPos(i)]) + floor(cells[eastPos(i)]) +
            floor(cells[northPos(eastPos(i))]) + floor(cells[southPos(eastPos(i))]) +
            floor(cells[southPos(westPos(i))]) + floor(cells[northPos(westPos(i))]);

        //std::cout << "cell " << i << " has " << neighboursAlive << " neighbours alive" << std::endl;

        tickCell(i, neighboursAlive);
    }

    generation++;
    updateTitle();
    swapCells();
}

void Board::setCell(const int cell, const float value) const {
    cells[cell] = value;
}

void Board::invertCell(const int cell) const {
    cells[cell] = 1 - cells[cell];
}
