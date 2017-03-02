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
	m_food.spawn(&m_player);
	m_loadingScreen.intialise();

	if (!buffer.loadFromFile("./RESOURCES/snake.wav"))
	{
		std::cout << "error loading sound";
	}


	sound.setBuffer(buffer);
	sound.play();
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
	
	gameController.update();
	//map.run(filename, m_window);

	//map.LoadMap();
	//map.Draw();
	
	
	map.wallCollition();
	
	m_food.changeSpawn(&m_player);
	m_player.update(&gameController);

}

void Game::Draw()
{
	m_window.clear(sf::Color::Blue);
	
	map.Draw(&m_window);
	
	m_player.draw(&m_window);

	m_food.draw(&m_window);
	
	m_loadingScreen.Draw(&m_window);

	m_window.display();
}