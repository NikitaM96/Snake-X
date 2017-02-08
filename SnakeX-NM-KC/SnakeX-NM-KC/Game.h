#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Game
{
public:
	Game();
	void Run(const char *filename, sf::RenderWindow &window);
	void Update(const char *filename, sf::RenderWindow &window);
	void Draw();
	void initialise();

	sf::RenderWindow m_window;

	Map map;

private:

	

};