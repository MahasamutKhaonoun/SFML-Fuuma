#pragma once

#include<map>
#include<string>
#include<sstream>
#include <vector>
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
	std::vector<Bullet*> bullets_Back;
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
	sf::Texture backgroundMainMenuTex;
	sf::Texture backgroundLeaderboardTex;
	sf::Texture backgroundTutorialTex;
	sf::Texture backgroundCreditTex;
	sf::RectangleShape worldBackground;
	sf::RectangleShape worldBackground2;
	sf::RectangleShape backgroundMainMenu;
	sf::RectangleShape backgroundLeaderboard;
	sf::RectangleShape backgroundTutorial;
	sf::RectangleShape backgroundCredit;

	sf::Texture ItemBarTex;
	sf::Texture choice_ShipTex;
	sf::RectangleShape framePower;
	sf::Sprite ItemBar;
	sf::Sprite choice_Ship;

	//Music
	sf::Music title;
	sf::Music tutorial;
	sf::Music leaderboard;
	sf::Music credit;
	sf::Music soundtrack;

	//Sound Effect
	sf::SoundBuffer SB_choose;
	sf::SoundBuffer SB_start;
	sf::SoundBuffer SB_pause;
	sf::SoundBuffer SB_shoot;
	sf::SoundBuffer SB_shoot2;
	sf::SoundBuffer SB_SP;
	sf::SoundBuffer SB_SPAfter;
	sf::SoundBuffer SB_dead;
	sf::SoundBuffer SB_boom;
	sf::SoundBuffer SB_takedamage;

	sf::SoundBuffer SB_speedup;
	sf::SoundBuffer SB_missile;
	sf::SoundBuffer SB_double;
	sf::SoundBuffer SB_laser;
	sf::SoundBuffer SB_multiple;
	sf::SoundBuffer SB_shield;

	sf::Sound choose;
	sf::Sound start;
	sf::Sound pause;
	sf::Sound shoot;
	sf::Sound shoot2;
	sf::Sound SP;
	sf::Sound SPAfter;
	sf::Sound dead;
	sf::Sound boom;
	sf::Sound takedamage;

	sf::Sound speedup;
	sf::Sound missile;
	sf::Sound Double;
	sf::Sound laser;
	sf::Sound multiple;
	sf::Sound shield;


	//Systems
	bool gameStart = false;
	float choiceMenu = 1.0f;
	float namePage = 1.0f;
	float multiSpawn = 0.0f;
	float multiScore = 1.0f;
	bool checkchoiceTime;
	unsigned points;
	int SP_Points;
	int Bullet_Type;
	int LifeForce_count;
	int framePower_count;
	int selectMusic;

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
	bool drawFrame = true;
	bool checkTimemultiSpawn = false;

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
	void initBGMenu();
	void initWorld();
	void initSound();
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
	void updateMusic();
	void update();
	void renderMenu();
	void renderGUI();
	void renderWorld();
	void render();

};

