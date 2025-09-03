#include <format>
#include <iostream>
#include <string>

#include <chrono>
#include <thread>

#include "board.h"
#include "boardCamera.h"
#include "raylib.h"
#include "raymath.h"

#include "constants.h"
#include "pattern.h"

bool running = false;
bool step = false;
bool showCommands = true;
int fps = FPS;

void keyPressionManager(Board *board, BoardCamera *camera) {
    int key = GetKeyPressed();
    while (key != 0) {
        switch (key) {
        case KEY_UP:
            if (!running) {
                running = true;
                showCommands = false;
                SetTargetFPS(fps);
            } break;
        case KEY_DOWN:
            if (running) {
                running = false;
                showCommands = true;
                SetTargetFPS(60);
            } break;
        case KEY_RIGHT:
            if (!running) {
                step = true;
                showCommands = false;
            }
        case KEY_PAGE_UP: ++fps; SetTargetFPS(fps); break;
        case KEY_PAGE_DOWN: if (--fps < 1) fps = 1; SetTargetFPS(fps); break;
        case KEY_SPACE: showCommands = !showCommands; break;
        case KEY_R: board->populateRandom(); break;
        case KEY_C: board->populateEmpty(); break;
        case KEY_H: board->populateSymmetric(); break;
        case KEY_G: setGosperGliderGun(board, camera); break;
        case KEY_K: setKoksGalaxy(board, camera); break;
        default: break;
        }
        key = GetKeyPressed();
    }
}

void mouseButtonManager(const Board *board, const BoardCamera *camera) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        const Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera->getCamera());
        const int position = (static_cast<int>(worldPos.y) / CELL_SIZE) * CELLS_PER_ROW + (static_cast<int>(worldPos.x) / CELL_SIZE);
        board->invertCell(position);
    }
}

void DrawCommands() {
    DrawRectangle(10, 10, 350, 360, ColorAlpha(RAYWHITE, 0.8));
    //DrawRectangle(10, 10, 350, 500, ColorAlpha(RAYWHITE, 0.8));

    DrawText("UP -> start", 20, 20, FONT_SIZE, FONT_COLOR);
    DrawText("DOWN -> pause", 20, 50, FONT_SIZE, FONT_COLOR);
    DrawText("RIGHT -> step", 20, 80, FONT_SIZE, FONT_COLOR);
    DrawText("pgUP -> up speed", 20, 110, FONT_SIZE, FONT_COLOR);
    DrawText("pgDOWN -> down speed", 20, 140, FONT_SIZE, FONT_COLOR);
    DrawText("SPACE -> show/hide commands", 20, 170, FONT_SIZE, FONT_COLOR);
    DrawLine(20, 200, 350, 200, FONT_COLOR);
    DrawText("R -> random", 20, 210, FONT_SIZE, FONT_COLOR);
    DrawText("H -> symmetric", 20, 240, FONT_SIZE, FONT_COLOR);
    DrawText("C -> reset", 20, 270, FONT_SIZE, FONT_COLOR);
    DrawLine(20, 300, 350, 300, FONT_COLOR);
    DrawText("G -> Gosper glider gun", 20, 310, FONT_SIZE, FONT_COLOR);
    DrawText("F -> Kok's Galaxy", 20, 340, FONT_SIZE, FONT_COLOR);

    /*std::string offset = std::format("offset {}-{}", camera.offset.x, camera.offset.y);
    DrawText(offset.c_str(), 20, 300, FONT_SIZE, FONT_COLOR);
    std::string target = std::format("target {}-{}", camera.target.x, camera.target.y);
    DrawText(target.c_str(), 20, 330, FONT_SIZE, FONT_COLOR);
    std::string zoom = std::format("zoom {}", camera.zoom);
    DrawText(zoom.c_str(), 20, 360, FONT_SIZE, FONT_COLOR);*/
}

void validateConstant() {
    if (WORLD_W % CELL_SIZE != 0 || WORLD_H % CELL_SIZE != 0) {
        throw std::runtime_error("wrong cell size");
    }
}

int main() {
    validateConstant();
    InitWindow(WINDOW_W, WINDOW_H, "game of life");
    SetTargetFPS(60);
    const auto board = new Board();
    const auto boardCamera = new BoardCamera();

    while (!WindowShouldClose())
    {
        if (running || step) {
            board->tick();
            //board->tickBorderLess();
            step = false;
        }

        boardCamera->update(GetFrameTime());
        keyPressionManager(board, boardCamera);
        mouseButtonManager(board, boardCamera);

        BeginDrawing();
        BeginMode2D(boardCamera->getCamera());

        ClearBackground(GROUND_COLOR);
        board->drawGrid();
        board->draw();

        EndMode2D();

        if (showCommands) {
            DrawCommands();
        }

        EndDrawing();
    }

    delete board;
    CloseWindow();

    return 0;

}



