#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "food.h"
#include "Controller.h"
#include "player.h"


//food::food()
//{
//
//}

void food::spawn(player *m_player)
{
	foodTexture.loadFromFile("./RESOURCES/food.png");
	foodSprite.setTexture(foodTexture);
	foodSprite.setPosition(positionX * 32, positionY * 32);

	if (!foodTexture.loadFromFile("./RESOURCES/food.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());

	}

	
	if (!scoreFont.loadFromFile("./RESOURCES/corbel.ttf"))
	{
		std::cout << "error loading text";
	}

	scoreText.setFont(scoreFont);

	

	// set the character size
	scoreText.setCharacterSize(24); 

							   // set the color
	scoreText.setColor(sf::Color::Red);

	scoreText.setPosition(10 , 0);

	scoreText.setString("Score = ");

		
}

void food::draw(RenderWindow *window)
{
	
	window->draw(scoreText);

	window->draw(foodSprite);
}

void food::changeSpawn(player *m_player) //to change food location when eaten
{
	if (foodSprite.getGlobalBounds().intersects(m_player->playerSprite[0].getGlobalBounds()))
	{
		positionX = rand() % 17 + 1;
		positionY = rand() % 21 + 1;
		foodSprite.setPosition(positionX * 32, positionY * 32);

		m_player->score = m_player->score + 100;
		// set the string to display
		scoreText.setString("Score = " +  std::to_string(m_player->score));
	}
	

}
