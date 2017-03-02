#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <vector>
#include "Game.h"
#include <cctype>
#include <iostream>


class Menu
{
public:
	Menu();


	sf::Texture m_menuBack;
	sf::Sprite m_Background;

	void Run();
	void Update();
	void Draw(RenderWindow *window);
	void initialise();




	~Menu();
};

