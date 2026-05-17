#pragma once

#include "mouse.h"
#include <memory>
#include <utility>

struct Texture;
typedef Texture Texture2D;

enum class Direction  // All ways cat can go
{
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
};

class Cat
{

    ScreenDimensions screen = getScreenDimensions();

    float m_speed {1.0f};
    const float m_scale {2.0f};
    const float m_pixels {32.0f};
    const float m_PI {3.14};
    bool hasReachedTarget {false};

    float m_currCatPosX {};
    float m_currCatPosY {};

    float m_prevCatPosX {};
    float m_prevCatPosY {};

    float m_idleTimer {};
    float m_idleThreashold {2.0f};
    int m_prevMousePosX {};
    int m_prevMousePosY {};


public:
    //
    // struct Implementation;
    // std::unique_ptr<Implementation> pimpl {};

    Cat();

    float getDimensions() const;
    float getScale() const;

    float getCurrCatPosX() const;
    float getCurrCatPosY() const;

    std::pair<float, float> getCenterPos(float frameWidth, float frameHeight);
    std::pair<float, float> getNewPos(MousePos &mouse);

    void updateMouseTracking(const MousePos& mouse);
    bool isMouseIdle() const;
    void drawTexture(const Texture& currentFrame);
    bool hasCatReachedMouse(const MousePos& mouse);
    Direction checkCatQuadrant(float catX, float catY);


};

