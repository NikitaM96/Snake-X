#pragma once
#ifndef Button
#define Button
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include "Controller.h"


class button
{
public:

	void intialise();

	void Draw(RenderWindow *window);

	//directions for positions of each button in game
	int up =1;
	int down = 2;
	int right =3;
	int left =4;

	int currentButton = 1;
	int randNum;

	void buttonSelect();
	void Update();
	void ChangeButtonLocation(Controller *gamePad);

	sf::Text buttonText1;
	sf::Text buttonText2;
	sf::Text buttonText3;
	sf::Text buttonText4;

	sf::Font buttonFont;
	


	sf::RectangleShape rectangleUp;
	sf::RectangleShape rectangleDown;
	sf::RectangleShape rectangleLeft;
	sf::RectangleShape rectangleRight;

	

	

	sf::Texture buttonTexture;

private:
};

#endif // !Button