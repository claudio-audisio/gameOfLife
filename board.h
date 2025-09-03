#pragma once

#include <cmath>

#include "constants.h"


class Board {
public:
    Board();
    ~Board();

    static void drawGrid();
    void updateTitle();
    void populateEmpty();
    void populateRandom();
    void populateSymmetric();
    void draw() const;
    void tick();
    void tickBorderLess();
    void setCell(int cell, float value) const;
    void invertCell(int cell) const;

    void setPopulation(int population) {
        this->population = population;
    }

    void resetGeneration() {
        generation = 0;
    }

private:
    float* cells;
    float* nextCells;
    int generation;
    int population;

    void tickCell(int position, int neighboursAlive);

    int isAlive(const int position) const {
        if (position < 0 || position >= CELLS_AMOUNT) {
            return 0;
        }

        return floor(cells[position]);
    }

    static int northPos(const int position) {
        return (position - CELLS_PER_ROW + CELLS_AMOUNT) % CELLS_AMOUNT;
    }

    static int eastPos(const int position) {
        return (position + 1) - (CELLS_PER_ROW * ((position + 1) % CELLS_PER_ROW ? 0 : 1));
    }

    static int southPos(const int position) {
        return (position + CELLS_PER_ROW + CELLS_AMOUNT) % CELLS_AMOUNT;
    }

    static int westPos(const int position) {
        return (position - 1) + (CELLS_PER_ROW * (position % CELLS_PER_ROW ? 0 : 1));
    }

    void swapCells() {
        const auto tmpPtr = cells;
        cells = nextCells;
        nextCells = tmpPtr;
    }

};
