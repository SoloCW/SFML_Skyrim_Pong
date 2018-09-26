// Chris Wolinski SFML Pong

// location of score, winning and losing states, physics for ball movement, winning and losing states.

#include "GameLogic.h"
#include <iostream>

using namespace std;

GameLogic::GameLogic() // Logic constructor
{
    playerScore = 0; // Defaults scores to 0
    enemyScore  = 0;
    randomDirectionGenerator(); // Determines initial direction of ball

    if (!swordSound.loadFromFile("../assets/Sword_Sound.ogg")) // Loads and initializes all sounds based on impact
    cout << "Could not load request music." << endl;

    if (!staffSound.loadFromFile("../assets/Staff_Sound.ogg"))
    cout << "Could not load request music." << endl;

    if (!wallSound1.loadFromFile("../assets/Wall_Sound1.ogg"))
    cout << "Could not load request music." << endl;

    if (!wallSound2.loadFromFile("../assets/Wall_Sound2.ogg"))
    cout << "Could not load request music." << endl;

    if (!pointSound1.loadFromFile("../assets/Point_Sound1.ogg"))
    cout << "Could not load request music." << endl;

    if (!pointSound2.loadFromFile("../assets/Point_Sound2.ogg"))
    cout << "Could not load request music." << endl;

    bounceSoundSword.setBuffer(swordSound);

    bounceSoundStaff.setBuffer(staffSound);

    bounceSoundStaff.setVolume(40);

    bounceSoundWall1.setBuffer(wallSound1);

    bounceSoundWall1.setVolume(40);

    bounceSoundWall2.setBuffer(wallSound2);

    bounceSoundWall2.setVolume(40);

    winnerPointSound1.setBuffer(pointSound1);

    winnerPointSound2.setBuffer(pointSound2);
}

void GameLogic::moveBall(GameViewPlayer* currentGame, float timePassed) // Moves ball and determines bounces with different surfaces
{
    ballX = currentGame -> currentBall -> pongBall.getPosition().x; // Simplifies the ball's x and y values
    ballY = currentGame -> currentBall -> pongBall.getPosition().y;

    playerX = currentGame -> currentPlayer -> pongPaddle.getPosition().x; // Simplifies the player's x and y values

    playerY1 = currentGame -> currentPlayer -> pongPaddle.getPosition().y; // Sets each segmented zone of the paddle
    playerY2 = playerY1 + 25;
    playerY3 = playerY1 + 50;
    playerY4 = playerY1 + 75;
    playerY5 = playerY1 + 100;
    playerY6 = playerY1 + 125;

    enemyX = currentGame -> currentEnemy -> pongPaddle.getPosition().x; // Simplifies the enemy's x and y values

    enemyY1 = currentGame -> currentEnemy -> pongPaddle.getPosition().y; // Sets each segmented zone of the paddle
    enemyY2 = enemyY1 + 25;
    enemyY3 = enemyY1 + 50;
    enemyY4 = enemyY1 + 75;
    enemyY5 = enemyY1 + 100;
    enemyY6 = enemyY1 + 125;



    if (downSide == false) // check stopRepeatBounce() for more info
    {
        if (ballY + 10 > 599) // Ball hits the bottom
        {
            permutation = rand() % 5 + -5; // Creates random number between -5 and 5 and adds it to the ballAngle
            ballVelocity = -ballVelocity;
            ballAngle =  ((pongPie / 180) * permutation) +  (pongPie - ballAngle);
            stopRepeatBounce('d');
            bounceSoundWall1.play();
        }
    }

    if (topSide == false)
    {
        if (ballY - 10 < 1) // Ball hits the top
        {
            permutation = rand() % 5 + -5; // Creates random number between -5 and 5 and adds it to the ballAngle
            ballVelocity = -ballVelocity;
            ballAngle =  ((pongPie / 180) * permutation) +  (pongPie - ballAngle);
            stopRepeatBounce('t');
            bounceSoundWall2.play();
        }
    }

    if (ballX > 810.0) // player scores a point
    {
        currentGame -> currentBall -> pongBall.setPosition(currentGame -> pongX,currentGame -> pongY);
        currentGame->currentBall->pongBall.setFillColor(sf::Color::White);
        randomDirectionGenerator(); // Resets ball position and random direction
        updateGameScores(currentGame, "player");
        stopRepeatBounce('n');
        winnerPointSound1.play();
    }

    if (ballX < -10.0) // enemy scores a point
    {
        currentGame -> currentBall -> pongBall.setPosition(currentGame -> pongX,currentGame -> pongY);
        currentGame->currentBall->pongBall.setFillColor(sf::Color::White);
        randomDirectionGenerator(); // Resets ball position and random direction
        updateGameScores(currentGame, "enemy");
        stopRepeatBounce('n');
        winnerPointSound2.play();
    }

    if (rightSide == false)
    {
        if ((ballX > enemyX) && (ballX < enemyX + 5)) // Ball's intersect range for triggering bounce on enemy paddle
        {
            if(ballY > enemyY1)
            {
                if(ballY < enemyY2) // Top segmented zone, ball speed, direction, and color are determined
                {
                    ballVelocity = ballVelocityEdge;
                    ballAngle = (pongPie / 180) * 240;
                    stopRepeatBounce('r');
                    currentGame->currentBall->pongBall.setFillColor(sf::Color::Magenta);
                    bounceSoundStaff.play();

                }
                else if(ballY < enemyY3) // Next segmented zone and so on
                {
                    ballVelocity = ballVelocityNormal;
                    ballAngle = (pongPie / 180) * 210;
                    stopRepeatBounce('r');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Magenta);
                    bounceSoundStaff.play();

                }
                else if(ballY < enemyY4)
                {
                    ballVelocity = -ballVelocity;
                    ballAngle = -ballAngle;
                    stopRepeatBounce('r');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Magenta);
                    bounceSoundStaff.play();

                }
                else if(ballY < enemyY5)
                {
                    ballVelocity = ballVelocityNormal;
                    ballAngle = (pongPie / 180) * 150;
                    stopRepeatBounce('r');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Magenta);
                    bounceSoundStaff.play();

                }
                else if(ballY < enemyY6)
                {
                    ballVelocity = ballVelocityEdge;
                    ballAngle = (pongPie / 180) * 120;
                    stopRepeatBounce('r');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Magenta);
                    bounceSoundStaff.play();

                }

            }
        }
    }

    if (leftSide == false)
    {
        if ((ballX < playerX + 10) && (ballX + 10 > playerX)) // Ball's intersect range for triggering bounce on player paddle
        {
            if(ballY > playerY1)
            {
                if(ballY < playerY2)
                {
                    ballVelocity = ballVelocityEdge;

                    ballAngle = (pongPie / 180) * -60;
                    stopRepeatBounce('l');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Cyan);
                    bounceSoundSword.play();

                }
                else if(ballY < playerY3)
                {
                    ballVelocity = ballVelocityNormal;

                    ballAngle = (pongPie / 180) * -30;
                    stopRepeatBounce('l');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Cyan);
                    bounceSoundSword.play();

                }
                else if(ballY < playerY4)
                {
                    ballVelocity = -ballVelocity;

                    ballAngle = -ballAngle;
                    stopRepeatBounce('l');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Cyan);
                    bounceSoundSword.play();

                }
                else if(ballY < playerY5)
                {
                    ballVelocity = ballVelocityNormal;

                    ballAngle = (pongPie / 180) * 30;
                    stopRepeatBounce('l');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Cyan);
                    bounceSoundSword.play();

                }
                else if(ballY < playerY6)
                {
                    ballVelocity = ballVelocityEdge;

                    ballAngle = (pongPie / 180) * 60;
                    stopRepeatBounce('l');
                    currentGame -> currentBall -> pongBall.setFillColor(sf::Color::Cyan);
                    bounceSoundSword.play();

                }
            }
        }
    }

    currentGame -> currentBall -> pongBall.move(timePassed * ballVelocity * std::cos(ballAngle), timePassed * ballVelocity * std::sin(ballAngle)); // determines how the ball moves, based on trigonometry
}

void GameLogic::stopRepeatBounce(char wall) // Prevents the ball from getting stuck inside a wall or paddle and constantly bouncing within itself
{
    switch(wall)
    {
        case 'l': downSide = false;
                  topSide = false;
                  leftSide = true;
                  rightSide = false;
            break;
        case 'r': downSide = false;
                  topSide = false;
                  leftSide = false;
                  rightSide = true;
            break;
        case 't': downSide = false;
                  topSide = true;
                  leftSide = false;
                  rightSide = false;
            break;
        case 'd': downSide = true;
                  topSide = false;
                  leftSide = false;
                  rightSide = false;
            break;
        case 'n': downSide = false; // Reset case after a point is won
                  topSide = false;
                  leftSide = false;
                  rightSide = false;
            break;
    }
}

void GameLogic::randomDirectionGenerator() // "Randomly" determines direction of starting ball and after a point is won
{
    leftOrRight = rand() % 4 + 1;

    switch(leftOrRight)
    {
        case 1: ballAngle = (pongPie / 180) * 30;
                ballVelocity = ballVelocityStart;
            break;
        case 2: ballAngle = (pongPie / 180) * 30;
                ballVelocity = ballVelocityStart;
            break;
        case 3: ballAngle = (pongPie / 180) * 150;
                ballVelocity = ballVelocityStart;
            break;
        case 4: ballAngle = (pongPie / 180) * 210;
                ballVelocity = ballVelocityStart;
            break;
    }
}

void GameLogic::updateGameScores(GameViewPlayer* currentGame, string winner) // Updates scores based on who wins a point
{
    if (winner == "player")
    {
        playerScore++;

        switch(playerScore)
        {
            case 1: currentGame -> playerScore.setString("1");
                break;
            case 2: currentGame -> playerScore.setString("2");
                break;
            case 3: currentGame -> playerScore.setString("3");
                break;
            case 4: currentGame -> playerScore.setString("4");
                break;
            case 5: currentGame -> playerScore.setString("5");
                break;
            case 6: currentGame -> playerScore.setString("6");
                break;
            case 7: currentGame -> playerScore.setString("7");
                break;
            case 8: currentGame -> playerScore.setString("8");
                break;
            case 9: currentGame -> playerScore.setString("9");
                break;
            case 10: currentGame -> playerScore.setString("10");
                break;
            case 11: currentGame -> playerScore.setString("11");
                break;
            default: currentGame -> playerScore.setString("11+");
                break;
        }
    }

    else if (winner == "enemy")
    {
        enemyScore++;

        switch(enemyScore)
        {
            case 1: currentGame -> enemyScore.setString("1");
                break;
            case 2: currentGame -> enemyScore.setString("2");
                break;
            case 3: currentGame -> enemyScore.setString("3");
                break;
            case 4: currentGame -> enemyScore.setString("4");
                break;
            case 5: currentGame -> enemyScore.setString("5");
                break;
            case 6: currentGame -> enemyScore.setString("6");
                break;
            case 7: currentGame -> enemyScore.setString("7");
                break;
            case 8: currentGame -> enemyScore.setString("8");
                break;
            case 9: currentGame -> enemyScore.setString("9");
                break;
            case 10: currentGame -> enemyScore.setString("10");
                break;
            case 11: currentGame -> enemyScore.setString("11");
                break;
            default: currentGame -> enemyScore.setString("11+");
                break;
        }
    }
}

string GameLogic::checkForWinner(GameViewPlayer* currentGame) // Checks to see if someone won 11 points and returns a string for the end screen
{
    if (playerScore == 11)
    {
        currentGame -> pongWindow.close();
        return "Sword";
    }

    else if(enemyScore == 11)
    {
        currentGame -> pongWindow.close();
        return "Staff";
    }
    else return "No Winner";
}
