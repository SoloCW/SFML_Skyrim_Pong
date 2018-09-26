// Chris Wolinski SFML Pong

#ifndef GAMEVIEWPLAYER_H
#define GAMEVIEWPLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Ball.h"
#include <iostream>

using namespace std;

class GameViewPlayer {

    private:
        float playerX = 75;
        float playerY = 250;
        float pOriginX = 15;
        float pOriginY = 0;

        float enemyX = 725;
        float enemyY = 250;
        float eOriginX = 0;
        float eOriginY = 0;

        float bOriginX = 10;
        float bOriginY = 10;

        float playerScoreX = 200;
        float playerScoreY = 0;

        float enemyScoreX = 575;
        float enemyScoreY = 0;

        float timePassed;

    public:
        sf::Font gameFont;
        sf::Text playerScore;
        sf::Text enemyScore;

        sf::RenderWindow pongWindow;
        sf::Texture gameImage;
        sf::Texture ballImage;
        sf::Texture playerImage;
        sf::Texture enemyImage;
        sf::RectangleShape background;
        sf::SoundBuffer gameSound;
        sf::Sound gameMusic;

        Paddle* currentPlayer;
        Paddle* currentEnemy;

        Ball* currentBall;

        float pongX = 400;
        float pongY = 300;

        GameViewPlayer();
        void movePlayer(float timePassed);
        void moveEnemy(float timePassed);
        void updateGame(void);
        void deleteObjects(void);

};

#endif
