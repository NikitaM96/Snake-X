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

	loadingTexture.loadFromFile("./RESOURCES/loading.png");
	loadingSprite.setTexture(loadingTexture);
	loadingSprite.setPosition(200, 200);
	//loadingSprite.setTextureRect(sf::IntRect(32 , 32, 32, 32));

	loading.setSize(sf::Vector2f(200, 50));
	loading.setOutlineColor(sf::Color::Black);
	loading.setFillColor(sf::Color::Green);
	loading.setOutlineThickness(5);
	loading.setPosition(245, 375);

	loadingText.setFont(loadingFont);
	loadingText.setColor(sf::Color::Black);
	loadingText.setPosition(245, 375);
	loadingText.setString("Loading");


	if (!loadingTexture.loadFromFile("./RESOURCES/loading.png"))
	{
		std::cout << "effor loading loading picture loading";
	}

	
}

void LoadingScreen::Draw(RenderWindow *window)
{
	//window->display();
	//window->draw(loadingSprite);
	window->draw(loading);
	window->draw(loadingText);
	//window->clear();
}

void LoadingScreen::Update()
{
	DrawLoadingSysmbol();
}

void LoadingScreen::DrawLoadingSysmbol()
{

	loadingTimer++;

	if (loadingTimer %30 == 0)
	{
		loadingSysmbol = true;
	}
	else
	{
		loadingSysmbol = false;
	}


	if (loadingSysmbol == false)
	{
		loading.setSize(sf::Vector2f(200, 150));
		
		loading.setOutlineThickness(5);
		
	}
	if (loadingSysmbol == true)
	{
		loading.setSize(sf::Vector2f(210, 150));
		
		loading.setOutlineThickness(10);
		
	}

}



 