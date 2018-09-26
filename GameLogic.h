// Chris Wolinski SFML Pong

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Audio.hpp>
#include "GameViewPlayer.h"
#include <cstdlib>
#include <string>

using namespace std;

class GameLogic {

    private:
       int playerScore;
       int enemyScore;

       int permutation;
       int leftOrRight;

       float ballX;
       float ballY;

       float playerX;
       float playerY1;
       float playerY2;
       float playerY3;
       float playerY4;
       float playerY5;
       float playerY6;

       float enemyX;
       float enemyY1;
       float enemyY2;
       float enemyY3;
       float enemyY4;
       float enemyY5;
       float enemyY6;

       float pongPie = 3.14159265359;
       float ballVelocity;
       float ballVelocityStart = 300.0;
       float ballVelocityNormal = 450.0;
       float ballVelocityEdge = 650.0;
       float ballAngle;

       string winner;

       sf::SoundBuffer swordSound;
       sf::SoundBuffer staffSound;
       sf::SoundBuffer wallSound1;
       sf::SoundBuffer wallSound2;
       sf::SoundBuffer pointSound1;
       sf::SoundBuffer pointSound2;

       sf::Sound bounceSoundSword;
       sf::Sound bounceSoundStaff;
       sf::Sound bounceSoundWall1;
       sf::Sound bounceSoundWall2;
       sf::Sound winnerPointSound1;
       sf::Sound winnerPointSound2;

       char wall;
       bool leftSide = false;
       bool rightSide = false;
       bool topSide = false;
       bool downSide = false;

    public:
        GameLogic();
        void updateGameScores(GameViewPlayer* currentGame, string winner);
        void moveBall(GameViewPlayer* currentGame, float timePassed);
        void stopRepeatBounce(char wall);
        void randomDirectionGenerator();
        string checkForWinner(GameViewPlayer* currentGame);
};

#endif

