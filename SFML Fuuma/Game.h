#pragma once

#include<map>
#include<string>
#include<sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Item.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	//Systems
	unsigned points;
	float posX;
	float posY;
	bool Item_alive = false;
	int time = 0;

	//Player
	Player* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	float spawnTimer_01S;
	float spawnTimerMax_01S;
	std::vector<Enemy*> enemies;
	std::vector<Enemy*> enemies_01S;
	std::vector<Enemy*> Item_SP;
	//Private Function
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystems();
	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void updateItem();
	void update();
	void renderGUI();
	void renderWorld();
	void render();

};

