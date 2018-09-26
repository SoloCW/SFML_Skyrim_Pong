// Chris Wolinski SFML Pong

//Location of AI code

#include "GameViewAI.h"

using namespace std;

GameViewAI::GameViewAI() // AI constructor
{

}

void GameViewAI::moveEnemyPaddle(GameViewPlayer* currentGame, float timePassed) // Gives the enemy AI a zone on the paddle to try to keep the ball within
{
    ballY = currentGame -> currentBall -> pongBall.getPosition().y;
    paddleY = (currentGame -> currentEnemy -> pongPaddle.getPosition().y) + 40;
    paddleYY = (currentGame -> currentEnemy -> pongPaddle.getPosition().y) + 60;

    if ((ballY > paddleY) && (ballY > paddleYY)) // Creates range on paddle for ball tracking
    {
        currentGame -> currentEnemy -> movePaddleDown("enemy", timePassed);
    }
    else if ((ballY < paddleY) && (ballY < paddleYY))
    {
        currentGame -> currentEnemy -> movePaddleUp("enemy", timePassed);
    }
}
