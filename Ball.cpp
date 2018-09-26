// Chris Wolinski SFML Pong

#include "Ball.h"
#include <iostream>

using namespace std;

Ball::Ball()
{

}

Ball::Ball(float positionX, float positionY, float originX, float originY) // Ball constructor
{
        pongBall.setRadius(10);
        pongBall.setOrigin(originX, originY);
        pongBall.setPosition(positionX, positionY);
        pongBall.setPointCount(50);
        pongBall.setFillColor(sf::Color::White);
}

void Ball::drawBall (sf::RenderWindow& window) // Pass window in and draw ball
{
    window.draw(pongBall);
}

