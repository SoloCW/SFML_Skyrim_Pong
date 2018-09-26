// Chris Wolinski SFML Pong

#ifndef GAMEVIEWAI_H
#define GAMEVIEWAI_H

#include <SFML/Graphics.hpp>
#include "GameViewPlayer.h"

using namespace std;

class GameViewAI {

    private:
        float ballY;
        float paddleY;
        float paddleYY;
        float timePassed;

    public:
        GameViewAI();
        void moveEnemyPaddle(GameViewPlayer* currentGame, float timePassed);

};

#endif

