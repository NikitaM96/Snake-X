#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "player.h"
#include "Controller.h"
#include "food.h"
#include <SFML/Audio.hpp>
#include "LoadingScreen.h"
#include "Button.h"
#include "Menu.h"

enum GameState
{
	TheLicence,
	TheSplash,
	Playing,
	TheOptions,
	TheMenu,
	GameOver
};



class Game
{
public:
	Game();
	void Run();
	void Update(Controller* gamePad);
	void Draw();
	void initialise();
	void ProcessEvents();
	GameState getGameState();

	int timer = 0;

	sf::RenderWindow m_window;

	Controller gameController;
	Map map;
	player m_player;
	food m_food;
	LoadingScreen m_loadingScreen;
	button m_button;
	Menu m_menu;
	
	
	sf::SoundBuffer buffer;
	sf::Sound sound;

	

private:

	GameState m_currentState = GameState::TheMenu;

};