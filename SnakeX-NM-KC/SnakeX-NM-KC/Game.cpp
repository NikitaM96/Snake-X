#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


Game::Game()
	: m_window(sf::VideoMode(1200, 800, 32), "SnakeX", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);//to match the framerate of both the monitor and the graphics c4rd.

}

void Game::initialise()
{



}

void Game::Run(const char *filename, sf::RenderWindow &window)
{
	initialise();

	while (true)
	{
		
		Update(filename,window);
		Draw();
		//map.run();

	}
}

void Game::Update(const char *filename, sf::RenderWindow &window)
{
	//map.run(filename, m_window);

	map.LoadMap(filename);

	map.Drawmap(window);
	map.Main();

}

void Game::Draw()
{
	//m_window.clear(sf::Color(360, 360, 360, 360));
	/*m_window.clear();
	map.Drawmap(m_window);
	m_window.display();*/
	

}