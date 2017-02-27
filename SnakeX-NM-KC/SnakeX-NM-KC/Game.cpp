#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>




Game::Game()
	: m_window(sf::VideoMode(640, 900, 32), "SnakeX", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);//to match the framerate of both the monitor and the graphics c4rd.

}

void Game::initialise()
{
	map.LoadMap();
	m_player.loadPlayer();
	
}

void Game::Run()
{
	initialise();
	while (m_window.isOpen())
	{
		sf::Event event;
		Update();
		Draw();
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
	}
}

void Game::Update()
{
	//map.run(filename, m_window);

	//map.LoadMap();
	//map.Draw();
	
	m_player.move();
	m_player.snakeSelfMovement();
	map.wallCollition();
	

}

void Game::Draw()
{
	m_window.clear(sf::Color::Blue);
	
	map.Draw(&m_window);
	
	m_player.draw(&m_window);

	m_window.display();
}