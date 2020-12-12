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
	std::map<std::string, sf::Texture*> textures3;
	std::vector<Bullet*> bullets;
	std::vector<Bullet*> bullets2;
	std::vector<Bullet*> bullets3;

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
	int LifeForce_count;
	float MovementSpeed;
	float posX;
	float posY;
	bool Item_alive = false;
	bool onetime = false;
	bool getPoint = false;
	bool checkSpeed;
	bool checkMissile_On = false;
	bool checkDouble_On = false;
	bool checkLifeForce_On = false;
	bool checkOption_1 = false;
	bool option_Pos1 = false;
	bool option_Pos2 = false;
	bool option_Pos3 = false;
	bool option_Pos4 = false;
	bool option_Pos5 = false;
	bool option_Pos6 = false;
	bool option_Pos7 = false;
	bool option_Pos8 = false;

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

