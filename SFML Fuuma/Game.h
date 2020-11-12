#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* window;

	//Player
	Player* player;



	//Private Function
	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void update();
	void render();

};

