#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

/// <summary>
/// Kieran lcothier & Nikita Muliins game using buttons
/// approx hours worked on: 20 hours
/// bugs: method to change buttons positions doesnt work fully because number assigned does not change and with the method we made wont work
/// </summary>



Game::Game()
	: m_window(sf::VideoMode(640, 900, 32), "SnakeX", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);//to match the framerate of both the monitor and the graphics c4rd.

	
}

void Game::ProcessEvents()
{
	switch (m_currentState)
	{
	case GameState::TheMenu:
		//insert
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			m_currentState = TheSplash;
		}
		break;

	case GameState::Playing:
		//insert
		break;
	case GameState::TheLicence:
		//insert
		break;
	case GameState::TheSplash:
		//insert
		break;
	case GameState::TheOptions:
		//insert
		break;
	}
}

void Game::initialise()
{
	map.LoadMap();
	m_player.loadPlayer();
	m_food.spawn(&m_player);
	
	m_button.intialise();
	m_menu.initialise();
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
		Update(&gameController);
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

void Game::Update(Controller* gamePad)
{
	

	switch (m_currentState)
	{
	case GameState::TheMenu:
		


		if (gamePad->m_currentState.A && !gamePad->m_previousState.A)
		{
			m_currentState = TheSplash;
		}
		break;

	case GameState::Playing:

		map.wallCollition();

		m_food.changeSpawn(&m_player);

		m_button.Update();
		map.wallCollition();

		m_food.changeSpawn(&m_player);
		m_player.update(&gameController, &m_button);
		//m_button.ChangeButtonLocation(&gameController);

		if (m_player.m_currentDirection == 0)
		{
			m_currentState = GameOver;
		}

		break;
	case GameState::TheLicence:
		m_loadingScreen.Draw(&m_window);
		break;
	case GameState::TheSplash:
		m_loadingScreen.Update();
		//insert
		timer++;
		if (timer > 300)
		{
			m_currentState = Playing;
		}
		break;
	case GameState::TheOptions:
		//insert
		break;
	case GameState::GameOver:
		
		timer++;
		if (timer > 300)
		{
			m_currentState = TheMenu;

		}
		
		break;
	}
	
	gameController.update();
	
	
	//m_button.Update();

}

void Game::Draw()
{
	

	m_window.clear(sf::Color::Blue);

	switch (m_currentState)
	{
	case GameState::TheMenu:
		m_menu.Draw(&m_window);
		break;

	case GameState::Playing:
		map.Draw(&m_window);

		m_player.draw(&m_window);

		m_food.draw(&m_window);

		m_button.Draw(&m_window);
		break;
	case GameState::TheLicence:
		
		break;
	case GameState::TheSplash:
		//insert
		m_loadingScreen.Draw(&m_window);

		break;
	case GameState::TheOptions:
		//insert
		break;
	}

	m_window.display();

}