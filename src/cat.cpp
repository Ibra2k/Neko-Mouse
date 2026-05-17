#include "cat.h"
#include <memory>
#include <raylib.h>
#include <cmath>

// struct Cat::Implementation
// {
//
// };

// Cat Constructor
Cat::Cat() :
    m_currCatPosX {screen.width/2.0f}, m_currCatPosY {screen.height/2.0f}
    // , pimpl { std::make_unique<Implementation>() }
{}


// Cat methods

float Cat::getDimensions() const
{
    return m_pixels;
}

float Cat::getScale() const
{
    return m_scale;
}

float Cat::getCurrCatPosX() const
{
    return m_currCatPosX;
}

float Cat::getCurrCatPosY() const
{
    return m_currCatPosY;
}


std::pair<float, float> Cat::getCenterPos(float frameWidth, float frameHeight)
{

    float catWidth {frameWidth * m_scale};
    float catHeight {frameHeight * m_scale};

    float centerX = (GetScreenWidth() - catWidth) / 2.0f;
    float centerY = (GetScreenHeight() - catHeight) / 2.0f;

    return {centerX, centerY};
}

// Perform linear interp
std::pair<float, float> Cat::getNewPos(MousePos &mouse)
{

    m_currCatPosX += (mouse.x - m_currCatPosX) * m_speed * GetFrameTime();
    m_currCatPosY += (mouse.y - m_currCatPosY) * m_speed * GetFrameTime();


    return {m_currCatPosX, m_currCatPosY};
}


void Cat::updateMouseTracking(const MousePos& mouse)
{


    if(mouse.x != m_prevMousePosX || mouse.y != m_prevMousePosY)
    {
        m_idleTimer = 0.0f;
        m_prevMousePosX = mouse.x;
        m_prevMousePosY = mouse.y;
    }
    else
    {
        // if mouse stopped moving -> start timer
        m_idleTimer += GetFrameTime();
    }
}

bool Cat::isMouseIdle() const
{
    return m_idleTimer >= m_idleThreashold;
}


void Cat::drawTexture(const Texture2D& currentFrame)
{

    auto centerPos = getCenterPos(m_pixels, m_pixels);

    DrawTexturePro(
        currentFrame,
        {0, 0, m_pixels, m_pixels},
        {centerPos.first, centerPos.second, m_pixels * m_scale, m_pixels * m_scale},
        {0, 0},
        0.0f,
        PINK
    );
}

bool Cat::hasCatReachedMouse(const MousePos& mouse)
{

    int deltaX = std::abs(mouse.x - m_currCatPosX);
    int deltaY = std::abs(mouse.y - m_currCatPosY);

    if (deltaX < 5 && deltaY < 5)
    {
        hasReachedTarget = true;
    }
    else 
    {
        hasReachedTarget = false;
    }

    return hasReachedTarget;

}

Direction Cat::checkCatQuadrant(float catX, float catY)
{

    MousePos mouse {getGlobalMousePos()};

    float newXPos = mouse.x - catX;
    float newYPos = catY - mouse.y;

    float angle = std::atan2(newYPos, newXPos) * 180.0f / m_PI;

    if (angle > -22.5f && angle <= 22.5f) return Direction::EAST;
    else if (angle > 22.5f && angle <= 67.5f) return Direction::NORTH_EAST;
    else if (angle > 67.5f && angle <= 112.5f) return Direction::NORTH;
    else if (angle > 112.5f && angle <= 157.5f) return Direction::NORTH_WEST;
    else if (angle > 157.5f || angle <= -157.5f) return Direction::WEST;
    else if (angle > -157.5f && angle <= -112.5f) return Direction::SOUTH_WEST;
    else if (angle > -112.5f && angle <= -67.5f) return Direction::SOUTH;
    else return Direction::SOUTH_EAST;

}
