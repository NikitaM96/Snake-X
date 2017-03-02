#include "Options.h"



Options::Options()
{
}


void Options::initialise()
{
	m_background.loadFromFile("options.png");
	if (!m_background.loadFromFile("./Resources/Menu Screen"))
	{

	}

	m_optionBack.setTexture(m_background);



}

void Options::Run()
{

}

void Options::Update()
{

}

void Options::Draw(sf::RenderWindow *window)
{
	window->draw(m_optionBack);
}

Options::~Options()
{
}
