#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Map.h"
#include "Controller.h"

class player
{
public:

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	void draw(RenderWindow *window);
	void loadPlayer();
	void move();
	void update(Controller* gamePad);
	void snakeSelfMovement();
	void snakeWallCollition();
	void outOfBounds();

	//for direction
	int x = 5;
	int y = 5;

	int up = 1;
	int down = 2;
	int left = 3;
	int right = 4;

	int m_currentDirection = 2;

private:
};