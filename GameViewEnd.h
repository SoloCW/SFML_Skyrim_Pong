// Chris Wolinski SFML Pong

#ifndef GAMEVIEWEND_H
#define GAMEVIEWEND_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

class GameViewEnd {

    private:
        sf::Font endFont;
        sf::Texture endImage;
        sf::RectangleShape background;
        sf::SoundBuffer endSoundSword;
        sf::SoundBuffer endSoundStaff;
        sf::Sound endVictorySound;
        sf::Text menuTitle;
        sf::Text endWinner;
        sf::Text endState;
        sf::Text endRestart;
        sf::Text endQuit;
        string winner;

        float titleX = 130;
        float titleY = 20;

        float winnerX = 70;
        float winnerY = 140;

        float stateX = 220;
        float stateY = 140;

        float restartX = 50;
        float restartY = 215;

        float quitX = 50;
        float quitY = 260;

    public:
        sf::RenderWindow endWindow;
        GameViewEnd();
        void updateWinner(string winner);
        bool quitOrRestart(void);
        void updateEnd(void);


};

#endif
