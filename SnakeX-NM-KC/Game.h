#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "player.h"
#include "Controller.h"
#include "food.h"
#include "Menu.h"
#include "Options.h"


class Game
{
public:
	Game();
	void Run();
	void Update();
	void Draw();
	void initialise();

	sf::RenderWindow m_window;

	Controller gameController;
	Map map;
	player m_player;
	food m_food;
	Menu menu;
	Options options;

	enum GameState m_currentState;

private:

	

};