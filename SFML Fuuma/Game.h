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
	std::map<std::string, sf::Texture*> textures2;
	std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Font font_Nikkyou;
	sf::Text pointText;
	sf::Text gameOverText;
	sf::Text SP_Text;

	//World
	sf::Texture worldBackgroundTex;
	sf::Texture ItemBarTex;
	sf::Sprite worldBackground;
	sf::Sprite ItemBar;

	//Systems
	unsigned points;
	int SP_Points;
	int Bullet_Type;
	float MovementSpeed;
	float posX;
	float posY;
	bool Item_alive = false;
	bool onetime = false;
	bool getPoint = false;
	bool checkSpeed;

	//Player
	Player* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;
	sf::RectangleShape ItemBarBack;

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
	void updateOption();
	void update();
	void renderGUI();
	void renderWorld();
	void render();

};

