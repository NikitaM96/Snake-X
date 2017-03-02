#pragma once
#include <fstream>
#include <vector>
#include "Game.h"
#include <cctype>
#include <iostream>


class Options
{
public:
	Options();

	sf::Texture m_background;
	sf::Sprite  m_optionBack;

	void Run();
	void Update();
	void Draw(RenderWindow *window);
	void initialise();

	~Options();
};

