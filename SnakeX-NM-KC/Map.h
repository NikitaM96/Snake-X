#pragma once
#include <SFML/Graphics.hpp>
//#include "Game.h"
 
using namespace sf;
class Game;

class Map
{
public:
	/*int loudCounterX;
	int loudCounterY;
	int mapSizeX;
	int mapSizeY;*/


	//map tiles tecure and sprite
	sf::Texture mapTexture;
	sf::Sprite mapSprite;

	std::string mapTileLocation;

	//vector array of for map
	sf::Vector2i map[50][50];


	sf::Vector2i loadImage = sf::Vector2i(0, 0);


	//getting the 2 number values from the file to load what colour sqaure we want.
	std::string str;

	//to load the map from the file , also to save the value from the file into a temp 
	//value then pass it to the map vector value one line at a time so the temp vector is empty after each line saved.
	void LoadMap();
	void wallCollition();

	void Draw(RenderWindow *window);
	//void run(const char *filename, sf::RenderWindow &window);

	


	//temp files 
	/*sf::Sprite playerSprite;
	sf::Texture playerTexture;*/

	

};