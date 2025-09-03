#pragma once

#include "raylib.h"

#define WORLD_W 3200
#define WORLD_H 2400
#define WINDOW_W 1600
#define WINDOW_H 1200
#define CELL_SIZE 5
#define CELLS_PER_ROW (WORLD_W / CELL_SIZE)
#define CELLS_PER_COL (WORLD_H / CELL_SIZE)
#define CELLS_AMOUNT (CELLS_PER_ROW * CELLS_PER_COL)

#define FONT_SIZE 20
#define DEATH_SPEED 1
#define FPS 20

#define LIGHTBLACK CLITERAL(Color){ 20, 20, 20, 255 }
constexpr auto LINE_COLOR = DARKGRAY;
constexpr auto CELL_COLOR = RAYWHITE;
constexpr auto GROUND_COLOR = LIGHTBLACK;
constexpr auto FONT_COLOR = DARKPURPLE;

#define CAMERA_OFFSET_X ((WINDOW_W - WORLD_W) / 2)
#define CAMERA_OFFSET_Y ((WINDOW_H - WORLD_H) / 2)
#define CAMERA_SPEED 500.0
#define CAMERA_BORDER 100
#define CAMERA_ZOOM 5
#define CAMERA_ZOOM_SPEED 0.2
#define CENTER 0
#define UP_LEFT_QUARTER 1