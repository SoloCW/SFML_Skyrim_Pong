// Chris Wolinski SFML Pong

//This is where the player views what happens onscreen.

#include "GameViewPlayer.h"

using namespace std;

     GameViewPlayer::GameViewPlayer() // Player window constructor
     : pongWindow(sf::VideoMode(800, 600, 32), "Skyrim Pong",sf::Style::Titlebar | sf::Style::Close)
     {
        currentPlayer = new Paddle(playerX, playerY, pOriginX, pOriginY);   // Creates both paddles and balls
        currentEnemy = new Paddle(enemyX, enemyY, eOriginX, eOriginY);
        currentBall = new Ball(pongX, pongY, bOriginX, bOriginY);

        if(!gameFont.loadFromFile("../assets/Game_Font.ttf"))
            cout << "Could not load requested font." << endl;

        if (!gameSound.loadFromFile("../assets/Game_Music.ogg"))
            cout << "Could not load request music." << endl;

        if (!gameImage.loadFromFile("../assets/Game_Screen.jpg"))
            cout << "Could not load requested image." << endl;

        if (!ballImage.loadFromFile("../assets/Game_Ball.png"))
            cout << "Could not load requested image." << endl;

        if (!playerImage.loadFromFile("../assets/Player_Sword.png"))
            cout << "Could not load requested image." << endl;

        if (!enemyImage.loadFromFile("../assets/Enemy_Staff.png"))
            cout << "Could not load requested image." << endl;


        background.setPosition(0,0);                    // Applies textures to ball, paddles and background
        background.setSize(sf::Vector2f(800,600));
        background.setTexture(&gameImage);

        currentBall -> pongBall.setFillColor(sf::Color::White);
        currentBall -> pongBall.setTexture(&ballImage);

        currentPlayer -> pongPaddle.setTexture(&playerImage);
        currentEnemy -> pongPaddle.setTexture(&enemyImage);

        gameMusic.setBuffer(gameSound);
        gameMusic.play();
        gameMusic.setLoop(true);

        playerScore.setFont(gameFont); // Player score is created
        playerScore.setCharacterSize(75);
        playerScore.setColor(sf::Color::Cyan);
        playerScore.setPosition(playerScoreX,playerScoreY);
        playerScore.setString("0");

        enemyScore.setFont(gameFont); // Enemy score is created
        enemyScore.setCharacterSize(75);
        enemyScore.setColor(sf::Color::Magenta);
        enemyScore.setPosition(enemyScoreX,enemyScoreY);
        enemyScore.setString("0");
    }

    void GameViewPlayer::movePlayer(float timePassed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Takes keyboard input to move paddle
    {
        currentPlayer -> movePaddleUp("player", timePassed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        currentPlayer -> movePaddleDown("player", timePassed);
    }
}

void GameViewPlayer::moveEnemy(float timePassed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Takes keyboard input to move paddle
    {
        currentEnemy -> movePaddleUp("player", timePassed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        currentEnemy -> movePaddleDown("player", timePassed);
    }
}

    void GameViewPlayer::updateGame(void) // Draws all elements of screen
    {

        pongWindow.clear(sf::Color::Black);

        pongWindow.draw(background);

        pongWindow.draw(playerScore);

        pongWindow.draw(enemyScore);

        currentBall -> drawBall(pongWindow);

        currentPlayer -> drawPaddle(pongWindow);

        currentEnemy -> drawPaddle(pongWindow);

        pongWindow.display();
   }

   void GameViewPlayer::deleteObjects(void)
   {
       delete currentBall;
       delete currentEnemy;
       delete currentPlayer;
   }

