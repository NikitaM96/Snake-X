#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
 

class Game;

class Map
{
public:
	int loudCounterX;
	int loudCounterY;
	int mapSizeX;
	int mapSizeY;

	//to load the map from the file , also to save the value from the file into a temp 
	//value then pass it to the map vector value one line at a time so the temp vector is empty after each line saved.
	void LoadMap(const char *filename);

	void Drawmap(sf::RenderWindow &window);

	void Main();
	//void run(const char *filename, sf::RenderWindow &window);

	Game *m_game;



};