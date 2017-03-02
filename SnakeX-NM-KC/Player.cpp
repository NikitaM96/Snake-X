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
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(5 * 32, 5 * 32);

	if (!playerTexture.loadFromFile("./RESOURCES/player.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());

	}

}



void player::draw(RenderWindow *window)
{

	
	window->draw(playerSprite);
}

void player::move()
{

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_currentDirection !=4)
		{
			m_currentDirection = 3;
				
				/*x--;
				playerSprite.setPosition(x * 32, y * 32);*/
			
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_currentDirection != 2)
		{
			m_currentDirection = 1;
			/*y--;
			playerSprite.setPosition(x * 32, y * 32);*/
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_currentDirection != 1)
		{
			m_currentDirection = 2;
			/*y++;
			playerSprite.setPosition(x * 32, y * 32);*/
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_currentDirection != 3)
		{
			m_currentDirection = 4;
			/*x++;
			playerSprite.setPosition(x * 32, y * 32);*/
		}
	

}
void player::update(Controller *gamePad)
{
	if (gamePad->m_currentState.dPadLeft && !gamePad->m_previousState.dPadLeft&& m_currentDirection != 4)
	{
		m_currentDirection = 3;
	}
	else if (gamePad->m_currentState.dPadRight && !gamePad->m_previousState.dPadRight&& m_currentDirection != 3)
	{
		m_currentDirection = 4;
	}

	if (gamePad->m_currentState.dPadUp && !gamePad->m_previousState.dPadUp&& m_currentDirection != 2)
	{
		m_currentDirection = 1;
	}
	else if (gamePad->m_currentState.dPadDown && !gamePad->m_previousState.dPadDown && m_currentDirection != 1)
	{
		m_currentDirection = 2;
	}



	move();
	snakeSelfMovement();
	outOfBounds();
}
void player::snakeSelfMovement()
{
	if (m_currentDirection == 3)//left
	{
		x = x - 1;
		playerSprite.setPosition(x * 3.2, y * 3.2);
	}

	if (m_currentDirection == 1)//up
	{
		y = y - 1;
		playerSprite.setPosition(x * 3.2, y * 3.2);
	}

	if (m_currentDirection == 2)//down
	{
		y = y + 1;
		playerSprite.setPosition(x * 3.2, y * 3.2);
	}

	if (m_currentDirection == 4)//right
	{
		x = x + 1;
		playerSprite.setPosition(x * 3.2, y * 3.2);
	}
}

void player::snakeWallCollition()
{
	playerSprite.getPosition().x;
}

void player::outOfBounds() // basic wall hit game over
{
	if (playerSprite.getPosition().x > 576)
	{
		m_currentDirection = 0;
	}

	if (playerSprite.getPosition().x < 32)
	{
		m_currentDirection = 0;
	}

	if (playerSprite.getPosition().y > 608)
	{
		m_currentDirection = 0;
	}

	if (playerSprite.getPosition().y < 0)
	{
		m_currentDirection = 0;
	}
}