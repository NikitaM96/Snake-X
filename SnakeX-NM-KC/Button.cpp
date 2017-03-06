#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "button.h"
#include "player.h"

void button::intialise()
{

	
	if (!buttonFont.loadFromFile("./RESOURCES/corbel.ttf"))
	{
		std::cout << "error loading text";
	}

	rectangleUp.setSize(sf::Vector2f(100, 50));
	rectangleUp.setOutlineColor(sf::Color::Green);
	rectangleUp.setFillColor(sf::Color::Green);
	rectangleUp.setOutlineThickness(5);
	rectangleUp.setPosition(20, 800);

	rectangleDown.setSize(sf::Vector2f(100, 50));
	rectangleDown.setOutlineColor(sf::Color::Green);
	rectangleDown.setFillColor(sf::Color::Green);
	rectangleDown.setOutlineThickness(5);
	rectangleDown.setPosition(170, 800);

	rectangleLeft.setSize(sf::Vector2f(100, 50));
	rectangleLeft.setOutlineColor(sf::Color::Green);
	rectangleLeft.setFillColor(sf::Color::Green);
	rectangleLeft.setOutlineThickness(5);
	rectangleLeft.setPosition(470, 800);

	rectangleRight.setSize(sf::Vector2f(100, 50));
	rectangleRight.setOutlineColor(sf::Color::Green);
	rectangleRight.setFillColor(sf::Color::Green);
	rectangleRight.setOutlineThickness(5);
	rectangleRight.setPosition(320, 800);// 320, 800



	buttonText1.setFont(buttonFont);
	buttonText1.setColor(sf::Color::Red);
	buttonText1.setPosition(20, 800);
	buttonText1.setString("Up");

	buttonText2.setFont(buttonFont);
	buttonText2.setColor(sf::Color::Red);
	buttonText2.setPosition(170, 800);
	buttonText2.setString("Down");

	buttonText3.setFont(buttonFont);
	buttonText3.setColor(sf::Color::Red);
	buttonText3.setPosition(320, 800);
	buttonText3.setString("Left");

	buttonText4.setFont(buttonFont);
	buttonText4.setColor(sf::Color::Red);
	buttonText4.setPosition(470, 800);
	buttonText4.setString("Right");



}

void button::Draw(RenderWindow *window)
{
	window->draw(rectangleUp);
	window->draw(rectangleDown);
	window->draw(rectangleLeft);
	window->draw(rectangleRight);
	window->draw(buttonText1);
	window->draw(buttonText2);
	window->draw(buttonText3);
	window->draw(buttonText4);


}

void button::Update()
{
	buttonSelect();
	//ChangeButtonLocation(&gamePad);
	
}

void button::buttonSelect()
{

	//left
	if (currentButton == 4)
	{
		rectangleLeft.setFillColor(sf::Color::Red);
		rectangleLeft.setOutlineThickness(7);
	}
	if (currentButton != 4)

	{
		rectangleLeft.setFillColor(sf::Color::Green);
		rectangleLeft.setOutlineThickness(5);
	}

	//up
	if (currentButton == 1)
	{
		rectangleUp.setFillColor(sf::Color::Red);
		rectangleUp.setOutlineThickness(7);
	}
	if (currentButton != 1)

	{
		rectangleUp.setFillColor(sf::Color::Green);
		rectangleUp.setOutlineThickness(5);
	}

	//down
	if (currentButton == 2)
	{
		rectangleDown.setFillColor(sf::Color::Red);
		rectangleDown.setOutlineThickness(7);
	}
	if (currentButton != 2)
	{
	
		rectangleDown.setFillColor(sf::Color::Green);
		rectangleDown.setOutlineThickness(5);
	}

	//right
	if (currentButton == 3)
	{
		rectangleRight.setFillColor(sf::Color::Red);
		rectangleRight.setOutlineThickness(7);
	}
	if (currentButton != 3)
	{
		rectangleRight.setFillColor(sf::Color::Green);
		rectangleRight.setOutlineThickness(5);
	}
}

//to change the button location
void button::ChangeButtonLocation(Controller *gamePad)
//buttonText4.setPosition(470, 800);//rectangleRight.setPosition(320 , 20 , 170, 470
//
//
//
{
	if (gamePad->m_currentState.A && !gamePad->m_previousState.A)// && m_currentDirection != 4
	{
		randNum = rand() % 5;



		if (randNum == 1)
		{
			buttonText1.setPosition(320, 800);
			rectangleUp.setPosition(320, 800);
			buttonText3.setPosition(20, 800);
			rectangleLeft.setPosition(20, 800);
			up = 3;
			left = 1;
		}

		if (randNum == 2)
		{
			buttonText2.setPosition(470, 800);
			rectangleDown.setPosition(470, 800);
			buttonText4.setPosition(170, 800);
			rectangleRight.setPosition(170, 800);
			down = 4;
			right = 2;
			
		}

		if (randNum == 3)
		{
			buttonText3.setPosition(470, 800);
			rectangleLeft.setPosition(470, 800);
			buttonText1.setPosition(20, 800);
			rectangleUp.setPosition(20, 800);
			left = 4;
			up = 1;
		}

		if (randNum == 4)
		{
			buttonText1.setPosition(20, 800);
			rectangleUp.setPosition(20, 800);
			buttonText2.setPosition(170, 800);
			rectangleDown.setPosition(170, 800);
			buttonText3.setPosition(320, 800);
			rectangleLeft.setPosition(320, 800);
			buttonText4.setPosition(470, 800);
			rectangleRight.setPosition(470, 800);

		}
	}

}