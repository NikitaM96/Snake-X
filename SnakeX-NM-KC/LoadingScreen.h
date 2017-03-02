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






	void intialise();
	void Draw(RenderWindow *window);



private:
};



#endif // !LOADING


