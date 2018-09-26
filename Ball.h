// Chris Wolinski SFML Pong

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

class Ball {

    private:
        float positionX;
        float positionY;
        float originX;
        float originY;

    public:
        sf::CircleShape pongBall;

        Ball ();
        Ball (float positionX, float positionY, float originX, float originY);

        void drawBall (sf::RenderWindow& window);


};

#endif
