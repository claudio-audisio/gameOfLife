#pragma once

#include <raylib.h>


class BoardCamera {
public:
    BoardCamera();
    ~BoardCamera() {}

    void update(float dt);
    void updatePosition(float offsetX, float offsetY);
    void updatePosition(int position);

    Camera2D getCamera() const {
        return camera;
    }

    float getZoom() {
        return camera.zoom;
    }

private:
    Camera2D camera;

    void updateZoom();
    void adjustOffset();

};
