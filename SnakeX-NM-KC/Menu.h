#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <iostream>


class Menu
{
public:
	Menu();

	sf::Texture m_menuBack;
	sf::Sprite m_Background;

	void Run();
	void Update();
	void Draw(sf::RenderWindow *window);
	void initialise();
	~Menu();
};

#endif