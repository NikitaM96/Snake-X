#include "Menu.h"



Menu::Menu()
{
}


void Menu::initialise()
{

	m_menuBack.loadFromFile("./RESOURCES/Menu Screen.png");
	if (m_menuBack.loadFromFile("./Resources/Menu Screen"))
	{
		std::cout << "error loading menu image";
	}

	m_Background.setTexture(m_menuBack);
	m_Background.setPosition(0, 0);


}

void Menu::Run()
{

}

void Menu::Update()
{

}

void Menu::Draw(sf::RenderWindow *window)
{
	window->draw(m_Background);
}


Menu::~Menu()
{
}
