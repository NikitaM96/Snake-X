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

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_currentDirection = 3;
				
				/*x--;
				playerSprite.setPosition(x * 32, y * 32);*/
			
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_currentDirection = 1;
			/*y--;
			playerSprite.setPosition(x * 32, y * 32);*/
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_currentDirection = 2;
			/*y++;
			playerSprite.setPosition(x * 32, y * 32);*/
		}
	

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_currentDirection = 4;
			/*x++;
			playerSprite.setPosition(x * 32, y * 32);*/
		}
	

}

void player::snakeSelfMovement()
{
	if (m_currentDirection == 3)//left
	{
		x = x - 1;
		playerSprite.setPosition(x * 10, y * 10);
	}

	if (m_currentDirection == 1)//up
	{
		y = y - 1;
		playerSprite.setPosition(x * 10, y * 10);
	}

	if (m_currentDirection == 2)//down
	{
		y = y + 1;
		playerSprite.setPosition(x * 10, y * 10);
	}

	if (m_currentDirection == 4)//right
	{
		x = x + 1;
		playerSprite.setPosition(x * 10, y * 10);
	}
}

void player::snakeWallCollition()
{
	playerSprite.getPosition().x;
}