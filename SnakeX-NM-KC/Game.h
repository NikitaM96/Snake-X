#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "player.h"
#include "Controller.h"
#include "food.h"
#include <SFML/Audio.hpp>
#include "LoadingScreen.h"

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
	LoadingScreen m_loadingScreen;
	
	sf::SoundBuffer buffer;
	sf::Sound sound;

	

private:

	

};