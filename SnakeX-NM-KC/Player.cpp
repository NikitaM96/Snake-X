#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "Map.h"
#include "player.h"


void player::loadPlayer()
{
	playerTexture.loadFromFile("./RESOURCES/player.png");
	playerSprite[0].setTexture(playerTexture);
	playerSprite[0].setPosition((playerHeadX )* 32,( playerHeadY) * 32);  

	if (!playerTexture.loadFromFile("./RESOURCES/player.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());

	}

	
	/*playerSprite[1].setTexture(playerTexture);
	

	playerSprite[1].setScale(1.5f, 1.0f);*/

}





void player::draw(RenderWindow *window)
{
	
	
	window->draw(playerSprite[0]);
	/*if (bodyAlive == true)
	{
		if (bodyLength == 5)
		{
			window->draw(playerSprite[1]);
		}


		if (bodyLength == 3)
		window->draw(playerSprite[2]);


		if (bodyLength == 4)
		window->draw(playerSprite[3]);


		if (bodyLength == 5)
		window->draw(playerSprite[4]);

		if (bodyLength == 6)
		window->draw(playerSprite[5]);


		if (bodyLength == 7)
		window->draw(playerSprite[6]);


		if (bodyLength == 8)
		window->draw(playerSprite[7]);


		if (bodyLength == 9)
		window->draw(playerSprite[8]);


		if (bodyLength == 10)
		window->draw(playerSprite[9]);

	}*/
	
}

void player::move()//for testing using the keyboard
{

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_currentDirection !=4)
		{
			m_currentDirection = 3;
				
				
			
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_currentDirection != 2)
		{
			m_currentDirection = 1;
			
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_currentDirection != 1)
		{
			m_currentDirection = 2;
			
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_currentDirection != 3)
		{
			m_currentDirection = 4;
			
		}
	

}
void player::update(Controller *gamePad, button *m_button)
{
	if (gamePad->m_currentState.dPadLeft && !gamePad->m_previousState.dPadLeft)// && m_currentDirection != 4
	{
		

		
			m_button->currentButton--;
			
		

	}
	else if (gamePad->m_currentState.dPadRight && !gamePad->m_previousState.dPadRight)//&& m_currentDirection != 3
	{
		
			m_button->currentButton++;
		
	}

	
	if (gamePad->m_currentState.A && !gamePad->m_previousState.A && m_button->currentButton == 1 && m_currentDirection != 2)
	{
		m_currentDirection = 1;
	}

	if (gamePad->m_currentState.A && !gamePad->m_previousState.A && m_button->currentButton == 2 && m_currentDirection != 1)
	{
		m_currentDirection = 2;
	}

	if (gamePad->m_currentState.A && !gamePad->m_previousState.A && m_button->currentButton == 4 && m_currentDirection != 3)
	{
		m_currentDirection = 4;
	}

	if (gamePad->m_currentState.A && !gamePad->m_previousState.A && m_button->currentButton == 3 && m_currentDirection != 4)
	{
		m_currentDirection = 3;
	}


	if (score > 0)
	{
		bodyAlive = true;
	}

	
	move();
	snakeSelfMovement();
	outOfBounds();
}
void player::snakeSelfMovement()
{

	if (score > 100 && score < 200)
	{
		speed = 4;
	}

	if (score > 200 && score < 300)
	{
		speed = 6;
	}


	if (score > 300 && score < 400)
	{
		speed = 8;
	}


	if (score > 100)
	{
		speed = 4;
	}

	if (m_currentDirection == 3)//left
	{
		timer++;
		
		//moving the head
		x = x - 1;
		playerSprite[0].setPosition(x * speed, y * speed);


		 
	}

	if (m_currentDirection == 1)//up
	{
		y = y - 1;
		playerSprite[0].setPosition(x * speed, y * speed);
	}

	if (m_currentDirection == 2)//down
	{
		y = y + 1;
		playerSprite[0].setPosition(x * speed, y * speed);
	}

	if (m_currentDirection == 4)//right
	{
		x = x + 1;
		playerSprite[0].setPosition(x * speed, y * speed);
	}
}

void player::snakeWallCollition()
{
	playerSprite[0].getPosition().x;
}

void player::outOfBounds() // basic wall hit game over
{
	if (playerSprite[0].getPosition().x > 576)
	{
		m_currentDirection = 0;
	}

	if (playerSprite[0].getPosition().x < 32)
	{
		m_currentDirection = 0;
	}

	if (playerSprite[0].getPosition().y > 700)
	{
		m_currentDirection = 0;
	}

	if (playerSprite[0].getPosition().y < 32)
	{
		m_currentDirection = 0;
	}
}

void player::Score()
{

}

