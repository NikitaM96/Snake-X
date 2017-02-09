#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Game
{
public:
	Game();
	void Run();
	void Update();
	void Draw();
	void initialise();

	sf::RenderWindow m_window;

	Map map;

private:

	

};