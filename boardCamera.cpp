#include "boardCamera.h"

#include "constants.h"

BoardCamera::BoardCamera() {
    camera = {
        .offset = {CAMERA_OFFSET_X, CAMERA_OFFSET_Y},
        .target = {0, CAMERA_ZOOM},
        .rotation = 0,
        .zoom = CAMERA_ZOOM
    };
}

void BoardCamera::updateZoom() {
    const float wheel = GetMouseWheelMove();

    if (wheel != 0) {
        const Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera);
        float scale = wheel * CAMERA_ZOOM_SPEED;
        camera.zoom += scale;

        if (camera.zoom < 1) {
            camera.zoom = 1;
            scale = 0;
        } else if (camera.zoom > 10) {
            camera.zoom = 10;
            scale = 0;
        }
        //std::cout << "world pos: " << worldPos.x << " - " << worldPos.y << std::endl;

        camera.offset.x -= worldPos.x * scale;
        camera.offset.y -= worldPos.y * scale;

        adjustOffset();
    }
}


void BoardCamera::update(const float dt) {
    updateZoom();

    const int posX = GetMouseX();
    const int posY = GetMouseY();

    if (posX < CAMERA_BORDER) {
        camera.offset.x += CAMERA_SPEED * dt;
    } else if (posX > WINDOW_W - CAMERA_BORDER) {
        camera.offset.x -= CAMERA_SPEED * dt;
    }

    if (posY < CAMERA_BORDER) {
        camera.offset.y += CAMERA_SPEED * dt;
    } else if (posY > WINDOW_H - CAMERA_BORDER) {
        camera.offset.y -= CAMERA_SPEED * dt;
    }

    adjustOffset();
}

void BoardCamera::updatePosition(const float offsetX, const float offsetY) {
    camera.offset.x = offsetX;
    camera.offset.y = offsetY;
    adjustOffset();
}

void BoardCamera::updatePosition(int position) {
    switch (position) {
        case CENTER: updatePosition(-WORLD_W * camera.zoom / 2 + WINDOW_W / 2, -WORLD_H * camera.zoom / 2 + WINDOW_H / 2); break;
        case UP_LEFT_QUARTER: updatePosition(-WORLD_W * camera.zoom / 4 + WINDOW_W / 4, -WORLD_H * camera.zoom / 4 + WINDOW_H / 4); break;
        default: break;
    }
}

void BoardCamera::adjustOffset() {
    if (camera.offset.x > 0) {
        camera.offset.x = 0;
    } else if (camera.offset.x < WINDOW_W - WORLD_W * camera.zoom) {
        camera.offset.x = WINDOW_W - WORLD_W * camera.zoom;
    }

    if (camera.offset.y > 0) {
        camera.offset.y = 0;
    } else if (camera.offset.y < WINDOW_H - WORLD_H * camera.zoom) {
        camera.offset.y = WINDOW_H - WORLD_H * camera.zoom;
    }
}
