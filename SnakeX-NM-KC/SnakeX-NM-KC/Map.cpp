#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Map.h"


#define BLOCKSIZE 5

std::vector < std::vector <int> > mapVector;


void Map::LoadMap(const char *filename)
{
	std::ifstream openfile(filename);
	std::vector <int> tempvector;

	std::string line;

	if (openfile.is_open())
	{
		while (!openfile.eof())
		{
			std::getline(openfile, line);
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] != ' ')
					{
						char value[1] = { line[i] };
						tempvector.push_back(atoi(value));

					}
				}

				mapVector.push_back(tempvector);
				tempvector.clear();
			}
		}
	}


}

void Map::Drawmap(sf::RenderWindow &window)
{

	//sf::Shape rect = sf::Shape::Rectangle(0, 0, BLOCKSIZE, BLOCKSIZE, sf::Color::(100,100,100,100));

	sf::RectangleShape rect(sf::Vector2f( 32, 32));

	rect.setSize(sf::Vector2f(32, 32));


	sf::Color rectcol;
	for (int i = 0; i < mapVector.size(); i++)
	{
		for (int j = 0; j < mapVector[i].size(); j++)
		{
			if (mapVector[i][j] == 0)
			{
				rectcol = sf::Color::Green;
			}
			else if (mapVector[i][j] == 1)
			{
				rectcol = sf::Color::Red;
			}


			rect.setPosition(j * BLOCKSIZE, i * BLOCKSIZE);
			rect.setFillColor(rectcol);
		}
	}


}

void Map::Main()
{
	LoadMap("Map.txt");
	while (m_game->m_window.isOpen())
	{
		std::cout << " ass";
		sf::Event Event;
		while (m_game->m_window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed || Event.key.code == sf::Keyboard::Escape)
			{
				m_game->m_window.close();
			}

			m_game->m_window.clear();
			Drawmap(m_game->m_window);
			m_game->m_window.display();
		}
	}
	//return 1;
}


//void Map::run(const char *filename, sf::RenderWindow &window)
//{
//
//
//	while (true)
//	{
//
//		LoadMap(filename);
//		Drawmap(window);
//		Main();
//	}
//
//
//}

