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

	void spawn();
	void draw(RenderWindow *window);
	void changeSpawn(player *m_player);
	

	int positionX = 3;
	int positionY = 3;
	
	

private:
};

#endif // !FOOD