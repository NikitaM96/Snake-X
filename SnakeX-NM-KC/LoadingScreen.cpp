#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "LoadingScreen.h"


void LoadingScreen::intialise()
{

	loadingTexture.loadFromFile("./RESOURCES/food.png");
	loadingSprite.setTexture(loadingTexture);
	loadingSprite.setPosition(300, 800);
	loadingSprite.setTextureRect(sf::IntRect(232 , 232, 232, 232));

	

	if (!loadingTexture.loadFromFile("./RESOURCES/loading.png"))
	{
		std::cout << "effor loading loading picture";
	}
}

void LoadingScreen::Draw(RenderWindow *window)
{
	//window->display();
	window->draw(loadingSprite);
	//window->clear();
}



 