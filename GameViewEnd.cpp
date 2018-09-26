// Chris Wolinski SFML Pong

//This is where the player views what happens onscreen.

#include "GameViewEnd.h"

using namespace std;

     GameViewEnd::GameViewEnd() // End window constructor
     : endWindow(sf::VideoMode(400, 300, 32), "Skyrim Pong by Chris Wolinski",sf::Style::Titlebar | sf::Style::Close)
     {
        if(!endFont.loadFromFile("../assets/Game_Font.ttf"))       // Constructor loads and sets all items on screen
            cout << "Could not load requested font." << endl;

        if (!endImage.loadFromFile("../assets/Menu_Screen.jpg"))
           cout << "Could not load requested image." << endl;

        if (!endSoundSword.loadFromFile("../assets/Sword_Win.ogg"))
            cout << "Could not load request music." << endl;

        if (!endSoundStaff.loadFromFile("../assets/Staff_Win.ogg"))
            cout << "Could not load request music." << endl;

        background.setPosition(0,0);
        background.setSize(sf::Vector2f(400,300));
        background.setTexture(&endImage);

        menuTitle.setFont(endFont);
        menuTitle.setCharacterSize(75);
        menuTitle.setColor(sf::Color::Black);
        menuTitle.setPosition(titleX,titleY);
        menuTitle.setString("Pong");

        endWinner.setFont(endFont);
        endWinner.setCharacterSize(50);
        endWinner.setPosition(winnerX,winnerY);

        endState.setFont(endFont);
        endState.setCharacterSize(50);
        endState.setColor(sf::Color::White);
        endState.setPosition(stateX,stateY);
        endState.setString("Wins!");

        endRestart.setFont(endFont);
        endRestart.setCharacterSize(25);
        endRestart.setColor(sf::Color::White);
        endRestart.setPosition(restartX,restartY);
        endRestart.setString("Press SPACEBAR To Restart");

        endQuit.setFont(endFont);
        endQuit.setCharacterSize(25);
        endQuit.setColor(sf::Color::White);
        endQuit.setPosition(quitX,quitY);
        endQuit.setString("Press Q To Quit");
    }

    void GameViewEnd::updateWinner(string winner) // Based on winner sets appropriate sounds and text
    {
        endWinner.setString(winner);

        if(winner == "Sword")
        {
            endWinner.setColor(sf::Color::Cyan);
            endVictorySound.setBuffer(endSoundSword);
            endVictorySound.play();
        }
        if(winner == "Staff")
        {
            endWinner.setColor(sf::Color::Magenta);
            endVictorySound.setBuffer(endSoundStaff);
            endVictorySound.play();
        }
    }

    bool GameViewEnd::quitOrRestart(void)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // Starts the entire game loop again
        {
            endWindow.close();
            return false;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Quit game
        {
            endWindow.close();
            return true;
        }
    }

    void GameViewEnd::updateEnd(void) // Updates screen
    {
        endWindow.clear(sf::Color::Black);

        endWindow.draw(background);

        endWindow.draw(menuTitle);

        endWindow.draw(endWinner);

        endWindow.draw(endState);

        endWindow.draw(endRestart);

        endWindow.draw(endQuit);
        // display
        endWindow.display();
   }





