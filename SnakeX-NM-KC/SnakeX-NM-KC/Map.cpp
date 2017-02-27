#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "Map.h"


#define BLOCKSIZE 5

//std::vector < std::vector <int> > mapVector;

//std::ifstream openfile("Map.txt");

void Map::LoadMap()
{


	//temp files for player

	

	//playerTexture.loadFromFile("./RESOURCES/player.png");
	//playerSprite.setTexture(playerTexture);

	//if (!playerTexture.loadFromFile("./RESOURCES/player.png"))
	//{
	//	std::string s("Error loading texture");
	//	throw std::exception(s.c_str());

	//}




	std::ifstream openfile("Map.txt");
	mapTexture.loadFromFile("./RESOURCES/tiles.png");
	mapSprite.setTexture(mapTexture);

	

	if (!openfile.is_open())
	{
		std::cout << "Error , did not open file. " ;
	}


	//opeing the file, and if there checks if the text in side are numbers or not to display colour wanted on screen
	if (openfile.is_open())
	{
		std::cout << "File opened. ";
		openfile >> mapTileLocation;
		mapTexture.loadFromFile(mapTileLocation);
		mapSprite.setTexture(mapTexture);
		

		while (!openfile.eof())
		{
			openfile >> str;
			char x = str[0];
			char y = str[2];


			//checking if the numbers are relivent and if not set the location to the images to -1 so it doesnt draw anything
			if (!isdigit(x) || !isdigit(y))
			{
				map[loadImage.x][loadImage.y] = sf::Vector2i(-1, -1);
			}

			else
			{
				map[loadImage.x][loadImage.y] = sf::Vector2i(x - '0', y - '0');
			}


			//if new line in file is reached , resets loadimage.x to 0 and implements loadimage.y by one
			if (openfile.peek() == '\n')
			{
				loadImage.x = 0;
				loadImage.y++;
			}
			else
			{
				loadImage.x++;
			}

		}
		loadImage.x++;
	}
}

void Map::Draw(RenderWindow *window)
{

	//for lop to display map
	for (int i = 0; i < loadImage.x; i++)
	{
		for (int k = 0; k < loadImage.y; k++)
		{
			if (map[i][k].x != -1 && map[i][k].y != -1)
			{
				mapSprite.setPosition(i * 32, k * 32);
				mapSprite.setTextureRect(sf::IntRect(map[i][k].x * 32, map[i][k].y * 32, 32, 32));
				window->draw(mapSprite);
			}
		}
	}

	/*playerSprite.setPosition(5 * 32 , 5 * 32);
	window->draw(playerSprite);*/

}


void Map::wallCollition()
{
	for (int i = 0; i < loadImage.x; i++)
	{
		for (int k = 0; k < loadImage.y; k++)
		{
			if (map[i][k].x != 1 && map[i][k].y != 0)
			{
				std::cout << "nope";
				/*mapSprite.setPosition(i * 32, k * 32);
				mapSprite.setTextureRect(sf::IntRect(map[i][k].x * 32, map[i][k].y * 32, 32, 32));*/
				
			}
		}
	}
}