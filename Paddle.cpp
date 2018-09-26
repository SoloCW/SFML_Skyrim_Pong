// Chris Wolinski SFML Pong

#include "Paddle.h"

using namespace std;


Paddle::Paddle()
{

}

Paddle::Paddle(float positionX, float positionY, float originX, float originY) // Paddle constructor
{
    pongPaddle.setSize(sf::Vector2f(30, 125));

    pongPaddle.setOrigin(originX, originY);

    pongPaddle.setPosition(positionX, positionY);
}

void Paddle::drawPaddle (sf::RenderWindow& window)
{
    window.draw(pongPaddle);
}

void Paddle::movePaddleUp(string whichPaddle, float timePassed) // Moves paddle, speed determined if AI or not
{
    if (pongPaddle.getPosition().y > 0)
    {
        if(whichPaddle == "player")
        {
            pongPaddle.move(0, timePassed * -400);
        }
        else if(whichPaddle == "enemy")
        {
            pongPaddle.move(0, timePassed * -325);
        }
    }
}

void Paddle::movePaddleDown(string whichPaddle, float timePassed)
{
    if (pongPaddle.getPosition().y < 475)
    {
        if(whichPaddle == "player")
        {
            pongPaddle.move(0, timePassed * 400);
        }
        else if(whichPaddle == "enemy")
        {
            pongPaddle.move(0, timePassed * 325);
        }
    }
}
