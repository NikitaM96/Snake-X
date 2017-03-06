
#pragma once
#ifndef LOADING
#define LOADING
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>


class LoadingScreen
{
public:

	sf::Texture loadingTexture;
	sf::Sprite loadingSprite;

	sf::Font loadingFont;
	sf::Text loadingText;

	//for drawing the loading symbol
	void DrawLoadingSysmbol();
	bool loadingSysmbol = false;
	int loadingTimer;


	void intialise();
	void Update();
	void Draw(RenderWindow *window);



private:

	RectangleShape loading;

};



#endif // !LOADING


