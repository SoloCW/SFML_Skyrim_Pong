// Chris Wolinski SFML Pong

#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

using namespace std;

class Paddle {

    private:
        float positionX;
        float positionY;
        float originX;
        float originY;
        float timePassed;
        string whichPaddle;

    public:
        sf::RectangleShape pongPaddle;

        Paddle ();
        Paddle (float positionX, float positionY, float originX, float originY);

        void drawPaddle (sf::RenderWindow& window);

        void movePaddleUp(string whichPaddle, float timePassed);

        void movePaddleDown(string whichPaddle, float timePassed);

};

#endif
