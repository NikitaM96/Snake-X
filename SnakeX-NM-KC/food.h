#ifndef FOOD
#define FOOD


#include <SFML/Graphics.hpp>
//#include "Map.h"
#include "Game.h"



//class Game;

class food
{
public:

	/*food();
	~food();*/

	sf::Sprite foodSprite;
	sf::Texture foodTexture;

	void spawn(player *m_player);
	void draw(RenderWindow *window);
	void changeSpawn(player *m_player);
	

	int positionX = 3;
	int positionY = 3;
	
	sf::Text scoreText;
	sf::Font scoreFont;

private:
};

#endif // !FOOD