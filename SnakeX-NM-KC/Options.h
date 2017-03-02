#ifndef OPTIONS_H
#define OPTIONS_H

#include <SFML\Graphics.hpp>
#include <fstream>
#include <vector>
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
	void Draw(sf::RenderWindow *window);
	void initialise();

	~Options();
};

#endif