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

void food::spawn()
{
	foodTexture.loadFromFile("./RESOURCES/food.png");
	foodSprite.setTexture(foodTexture);
	foodSprite.setPosition(positionX * 32, positionY * 32);

	if (!foodTexture.loadFromFile("./RESOURCES/food.png"))
	{
		std::string s("Error loading texture");
		throw std::exception(s.c_str());

	}

	//positionX = rand() % 10;
}

void food::draw(RenderWindow *window)
{


	window->draw(foodSprite);
}

void food::changeSpawn(player *m_player) //to change food location when eaten
{
	if (foodSprite.getGlobalBounds().intersects(m_player->playerSprite.getGlobalBounds()))
	{
		positionX = rand() % 18;
		positionY = rand() % 27;
		foodSprite.setPosition(positionX * 32, positionY * 32);
	}
	

}
