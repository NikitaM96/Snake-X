#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Map.h"
#include "Controller.h"
#include "button.h"

class player
{
public:

	sf::Sprite playerSprite[10];
	

	/*sf::Vector2f temp = ;*/
	

	sf::Texture playerTexture;

	int bodyLength = 5;

	void draw(RenderWindow *window);
	void loadPlayer();
	void move();
	void update(Controller* gamePad, button* button);
	void snakeSelfMovement();
	void snakeWallCollition();
	void outOfBounds();

	void Score();

	double speed = 3.2;

	int count = 1;

	//for direction
	int x = 15;
	int y = 15;

	//timer
	int timer = 0;
	//body moving bool
	bool nextMove = false;

	//int count = 0;

	//bool for snake body
	bool bodyAlive = false;

	//player head position
	int playerHeadX = 10;
	int playerHeadY = 10;

	//temp head position
	int tempPlayerHeadX ;
	int tempPlayerHeadY ;

	int up = 1;
	int down = 2;
	int left = 3;
	int right = 4;

	int m_currentDirection = 2;

	int score = 10;

	

private:
};