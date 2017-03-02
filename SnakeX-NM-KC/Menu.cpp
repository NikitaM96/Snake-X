#include "Menu.h"



Menu::Menu()
{
}


void Menu::initialise()
{

	m_menuBack.loadFromFile("./RESOURCES/Menu Screen.png");
	if(!m_menuBack.loadFromFile("./Resources/Menu Screen"))
	{

	}

	m_Background.setTexture(m_menuBack);
	
	 
}

void Menu::Run()
{
	
}

void Menu::Update()
{
	
}

void Menu::Draw(RenderWindow *window)
{
	window->draw(m_Background);
}


Menu::~Menu()
{
}
