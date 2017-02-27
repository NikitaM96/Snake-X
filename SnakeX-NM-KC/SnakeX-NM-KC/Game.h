#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "player.h"

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
	player m_player;
	
	

private:

	

};