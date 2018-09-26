// Chris Wolinski SFML Pong

// Location of main loop and keyboard input

#include <SFML/Graphics.hpp>
#include "GameViewPlayer.h"
#include "GameViewMenu.h"
#include "GameViewEnd.h"
#include "GameLogic.h"
#include "GameViewAI.h"
#include "Paddle.h"

using namespace std;

int main(int argc, char** argv)
{

    sf::Event Event; // Process events

    string currentWinner;

    bool gameOver = false; // Never gets set to true
    bool twoPlayerGame = false;
    bool quit = false;

    while(!gameOver) // Start game loop
    {
        GameViewMenu* currentMenu = new GameViewMenu(); //Create menu window for player

        currentMenu -> menuWindow.display();

        currentMenu -> updateMenu();

        while(currentMenu -> menuWindow.isOpen()) // Menu loop
        {
            while(currentMenu -> menuWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    currentMenu -> menuWindow.close(); // Quit game
                    return 0;
                }
            }

            twoPlayerGame = currentMenu -> menuSelection(); // Determines # of players

        }

        delete currentMenu; // Contain any memory leaks

        // # of players has been determined and the game is starting

        //--------------------------------------------------------------------------------------

        GameViewPlayer* currentGame = new GameViewPlayer(); // Create player window

        GameLogic* currentRules = new GameLogic(); // Create game logic

        GameViewAI* currentAI = new GameViewAI(); // create game AI

        sf::Clock clock; // Game loop clock

        float delta; // Time between game loops

        currentGame -> pongWindow.display();

        while(currentGame -> pongWindow.isOpen()) // Game loop
        {
            while(currentGame -> pongWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    currentGame -> pongWindow.close(); // Quit game
                    return 0;
                }
            }

            delta = clock.getElapsedTime().asSeconds(); // Gets clock time between loops

            clock.restart();  // Resets game clock between loops

            currentGame -> movePlayer(delta); // Player 1 moves its paddle through input

            if (twoPlayerGame == true)
            {
                currentGame -> moveEnemy(delta); // Player 2 moves its paddle through input
            }
            else
            {
                currentAI -> moveEnemyPaddle(currentGame, delta); // AI moves its paddle to follow ball
            }

            currentRules -> moveBall(currentGame, delta); // Ball moves according to physics

            currentWinner = currentRules -> checkForWinner(currentGame); // Checks for winner

            currentGame -> updateGame(); // Draws all the visuals on the screen

        }

        delete currentAI; // Contain any memory leaks

        delete currentRules;

        currentGame -> deleteObjects();

        delete currentGame;

        // Winner has scored 11 points moving to end screen

        //--------------------------------------------------------------------------------------

        GameViewEnd* currentEnd = new GameViewEnd(); // Creates end window

        currentEnd -> endWindow.display();

        currentEnd -> updateWinner(currentWinner); // Modifies end screen based on winner

        currentEnd -> updateEnd(); // Draws end screen

        while(currentEnd -> endWindow.isOpen()) // End loop
        {
            while(currentEnd -> endWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    currentEnd -> endWindow.close(); // Quit game
                    return 0;
                }
            }

            quit = currentEnd -> quitOrRestart(); // Takes input from player to quit or restart

            if (quit == true)
            {
                return 0;
            }

        }
        delete currentEnd; // Contain any memory leaks
    }
}


