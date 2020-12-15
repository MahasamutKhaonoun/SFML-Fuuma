#include "Game.h"

//Private Functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1600,900),"Fuuma-Den",sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures2["BULLET"] = new sf::Texture();
	this->textures["BULLET"] -> loadFromFile("Player/Vic Bullet.png");
	this->textures2["BULLET"]->loadFromFile("Player/Item_Laser.png");
}
void Game::initGUI()
{
	//Load font
	if(!this->font.loadFromFile("Fonts/G7Gradius21ByteFont-Jaem.ttf"))
		std::cout << "ERROR::GAME ::Failed to load font" << "\n";
	if (!this->font_Nikkyou.loadFromFile("Fonts/NikkyouSans-B6aV.ttf"))
		std::cout << "ERROR::GAME ::Failed to load font" << "\n";
		
	//Init point text
	this->pointText.setPosition(920.f, 770.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(35);
	this->pointText.setFillColor(sf::Color::White);
	//this->pointText.setString("test");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("GAME OVER!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2 - this->gameOverText.getGlobalBounds().width / 2.0f, 
		this->window->getSize().y / 2 - this->gameOverText.getGlobalBounds().height /2.0f);

	//Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.0f, 25.0f));
	this->playerHpBar.setFillColor(sf::Color::Blue);
	this->playerHpBar.setPosition(sf::Vector2f(50.0f, 780.0f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color::White);//(25, 25, 25, 200)
	this->playerHpBarBack.setOutlineThickness(3.f);
	this->playerHpBarBack.setOutlineColor(sf::Color::White);

	this->ItemBarBack.setSize(sf::Vector2f(1600.0f, 150.0f));
	this->ItemBarBack.setFillColor(sf::Color::Blue);
	this->ItemBarBack.setPosition(sf::Vector2f(0.0f, 750.0f));

	this->topBar.setSize(sf::Vector2f(1600.0f, 70.0f));
	this->topBar.setFillColor(sf::Color::Black);
	this->topBar.setPosition(sf::Vector2f(0.0f, 0.0f));

	//SP Point Text
	this->SP_Text.setPosition(50.0f,835.0f);
	this->SP_Text.setFont(this->font);
	this->SP_Text.setCharacterSize(35);
	this->SP_Text.setFillColor(sf::Color::White);
	//this->SP_Text.setString("SP : ");

	//ItemBar
	if (!this->ItemBarTex.loadFromFile("Item/ItemScreen.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->ItemBar.setTexture(this->ItemBarTex);
	this->ItemBar.scale(1.8f, 2.f);
	this->ItemBar.setPosition(280.f, 830.f);

	this->framePower.setSize(sf::Vector2f(190.0f, 50.0f));
	this->framePower.setOutlineThickness(10.f);
	this->framePower.setOutlineColor(sf::Color(250, 150, 100));
	this->framePower.setFillColor(sf::Color::Transparent);
	
}
void Game::initBGMenu()
{
	//Main menu
	if (!this->backgroundMainMenuTex.loadFromFile("Screen/MainMenu.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->backgroundMainMenu.setTexture(&backgroundMainMenuTex);
	this->backgroundMainMenu.setSize(sf::Vector2f(1600.0f, 900.0f));

	//Leaderboard
	if (!this->backgroundLeaderboardTex.loadFromFile("Screen/Leaderboard.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->backgroundLeaderboard.setTexture(&backgroundLeaderboardTex);
	this->backgroundLeaderboard.setSize(sf::Vector2f(1600.0f, 900.0f));

	//Tutorial
	if (!this->backgroundTutorialTex.loadFromFile("Screen/Tutorial.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->backgroundTutorial.setTexture(&backgroundTutorialTex);
	this->backgroundTutorial.setSize(sf::Vector2f(1600.0f, 900.0f));
	
	//Tutorial
	if (!this->backgroundCreditTex.loadFromFile("Screen/Credit.png"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->backgroundCredit.setTexture(&backgroundCreditTex);
	this->backgroundCredit.setSize(sf::Vector2f(1600.0f, 900.0f));


	


	if (!this->choice_ShipTex.loadFromFile("Player/Vic Viper.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
	this->choice_Ship.setTexture(this->choice_ShipTex);
	this->choice_Ship.setScale(3.0f, 3.0f);
	this->choice_Ship.setPosition(320.0f, 475.0f);
	
}
void Game::initWorld()
{
	//World
	if (!this->worldBackgroundTex.loadFromFile("Screen/Space_Background.jpg"))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->worldBackground.setTexture(&worldBackgroundTex);
	this->worldBackground.setSize(sf::Vector2f(1600.0f,900.0f));
	this->worldBackground.setPosition(sf::Vector2f(0.0f, 0.0f));
	this->worldBackground2.setTexture(&worldBackgroundTex);
	this->worldBackground2.setSize(sf::Vector2f(1600.0f, 900.0f));
	this->worldBackground2.setPosition(sf::Vector2f(1600.0f, 0.0f));
	//this->worldBackground.setScale(2.0f, 2.0f);
	
}
void Game::initSound()
{
	//Title
	if (!title.openFromFile("Sound/Fuuma title music.ogg"))
	{
		std::cout << "ERROR::GAME::Could not load background music" << "\n";
	}
	title.play();
	//title.setVolume(50.0f);
	title.setLoop(true);

	//Leaderboard
	if (!leaderboard.openFromFile("Sound/Leaderboard music.ogg"))
	{
		std::cout << "ERROR::GAME::Could not load background music" << "\n";
	}
	leaderboard.setVolume(90.0f);
	leaderboard.setLoop(true);

	//Tutorial
	if (!tutorial.openFromFile("Sound/Tutorial music.ogg"))
	{
		std::cout << "ERROR::GAME::Could not load background music" << "\n";
	}
	//tutorial.setVolume(50.0f);
	tutorial.setLoop(true);

	//Credit
	if (!credit.openFromFile("Sound/Credit music.ogg"))
	{
		std::cout << "ERROR::GAME::Could not load background music" << "\n";
	}
	credit.setVolume(20.0f);
	credit.setLoop(true);

	//Soundtrack
	if (!soundtrack.openFromFile("Sound/Soundtrack music.ogg"))
	{
		std::cout << "ERROR::GAME::Could not load background music" << "\n";
	}
	//soundtrack.setVolume(20.0f);
	soundtrack.setLoop(true);

	/////////////////////////////////////// Sound Effect ////////////////////////////////////////////

	if (!SB_choose.loadFromFile("Sound/SE_choose.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	choose.setBuffer(SB_choose);
	this->choose.setVolume(50.0f);

	if (!SB_start.loadFromFile("Sound/SE_start.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	start.setBuffer(SB_start);
	this->start.setVolume(50.0f);

	if (!SB_pause.loadFromFile("Sound/SE_pause.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	pause.setBuffer(SB_pause);
	this->pause.setVolume(50.0f);

	if (!SB_shoot.loadFromFile("Sound/SE_shoot.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	shoot.setBuffer(SB_shoot);
	this->shoot.setVolume(50.0f);

	if (!SB_shoot2.loadFromFile("Sound/SE_shoot2.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	shoot2.setBuffer(SB_shoot2);
	this->shoot2.setVolume(50.0f);

	if (!SB_SP.loadFromFile("Sound/SE_take SP.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	SP.setBuffer(SB_SP);
	this->SP.setVolume(50.0f);

	if (!SB_SPAfter.loadFromFile("Sound/SE_SPAfter.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	SPAfter.setBuffer(SB_SPAfter);
	this->SPAfter.setVolume(50.0f);

	if (!SB_dead.loadFromFile("Sound/SE_dead.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	dead.setBuffer(SB_dead);
	this->dead.setVolume(50.0f);

	if (!SB_boom.loadFromFile("Sound/SE_boom.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	boom.setBuffer(SB_boom);
	this->boom.setVolume(50.0f);

	if (!SB_takedamage.loadFromFile("Sound/SE_takedamage.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	takedamage.setBuffer(SB_takedamage);
	this->takedamage.setVolume(30.0f);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (!SB_speedup.loadFromFile("Sound/GRADIUS SPEED UP.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	speedup.setBuffer(SB_speedup);
	this->speedup.setVolume(30.0f);

	if (!SB_missile.loadFromFile("Sound/GRADIUS MISSILE.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	missile.setBuffer(SB_missile);
	this->missile.setVolume(30.0f);

	if (!SB_double.loadFromFile("Sound/GRADIUS DOUBLE.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	Double.setBuffer(SB_double);
	this->Double.setVolume(30.0f);

	if (!SB_laser.loadFromFile("Sound/GRADIUS LASER.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	laser.setBuffer(SB_laser);
	this->laser.setVolume(30.0f);

	if (!SB_multiple.loadFromFile("Sound/GRADIUS MULTIPLE.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	multiple.setBuffer(SB_multiple);
	this->multiple.setVolume(30.0f);

	if (!SB_shield.loadFromFile("Sound/GRADIUS SHIELD.wav"))
	{
		std::cout << "ERROR::GAME::Could not load Sound Effect" << "\n";
	}
	shield.setBuffer(SB_shield);
	this->shield.setVolume(30.0f);

}
void Game::initSystems()
{
	this->points = 0;
	this->Bullet_Type = 0;
	this->MovementSpeed = 3.f;
	this->SP_Points = 0;
	this->LifeForce_count = 5;
	this->choiceMenu = 1.0f;
	this->framePower_count = 0;
	this->canEnter = false;
	
}
void Game::initPlayer()
{
	this->player = new Player(MovementSpeed);

}
void Game::initEnemies()
{
	this->spawnTimerMax = 50.0f;
	this->spawnTimer = this->spawnTimerMax;

	this->spawnTimerMax_01S = 50.0f;
	this->spawnTimer_01S = this->spawnTimerMax_01S;
}
void Game::clearall()
{
	this->points = 0.0f;
	this->choiceMenu = 1.0f;
	this->SP_Points = 0;
	this->player->alreadyDead(false, posX, posY);
	this->player->setHp(100);
	this->Bullet_Type = 0;
	this->MovementSpeed = 3.f;
	this->initPlayer();
	this->checkMissile_On = false;
	this->checkDouble_On = false;
	this->checkLifeForce_On = false;
	this->checkOption_1 = false;
	this->player->openOption_1(false, this->player->getPos().x + this->player->getBounds().width / 2.f - 130.0f, this->player->getPos().y + 80.0f);
	//delete enemies
	for (auto* en : this->enemies)
	{
		delete en;
	}
	this->enemies.clear();

	for (auto* en1 : this->enemies_01S)
	{
		delete en1;
	}
	this->enemies_01S.clear();

	for (auto* iS : this->Item_SP)
	{
		delete iS;
	}
	this->Item_SP.clear();
}
//Con Des
Game::Game()
{

	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initBGMenu();
	this->initWorld();
	this->initSound();
	this->initSystems();
	this->initPlayer();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	for (auto& i : this->textures2)
	{
		delete i.second;
	}
	for (auto& i : this->textures3)
	{
		delete i.second;
	}


	//Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
	for (auto* i : this->bullets2)
	{
		delete i;
	}
	for (auto* i : this->bullets3)
	{
		delete i;
	}

	//delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}
	for (auto* i : this->enemies_01S)
	{
		delete i;
	}

	//Delete Item
	for (auto* i : this->Item_SP)
	{
		delete i;
	}
}

//Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvents();
		if (this->player->getHp() > 0)
		{
			this->update();
			this->render();
		}
		
	}
	
}

void Game::updatePollEvents()
{
	
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		/*if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}*/
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Home)
		{
			this->window->close();
		}
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::LShift)
		{
			this->namePage = 1.0f;
			this->gameStart = false;
			this->clearall();
			title.play();
			leaderboard.stop();
			tutorial.stop();
			credit.stop();
			soundtrack.stop();
			this->canEnter = false;
		}
		if (canEnter == false)
		{
			if (this->gameStart == false)
			{
				if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
				{
					title.play();
					leaderboard.stop();
					tutorial.stop();
					credit.stop();
					soundtrack.stop();
					this->namePage = 1.0f;
					this->gameStart = false;
				}
				if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Enter)
				{

					if (this->choiceMenu == 1) //Start
					{

						this->spawnTimer = 0.0f;
						this->spawnTimer_01S = 0.0f;
						this->multiSpawn = 0.0f;
						this->multiScore = 1.0f;
						this->start.play();
						title.stop();
						soundtrack.play();
						this->choiceMenu = 1;
						this->gameStart = true;
					}
					if (this->choiceMenu == 2) //LeaderBoard
					{
						title.stop();
						leaderboard.play();
						this->choiceMenu = 2;
						this->namePage = 2.0f;
						this->gameStart = false;
					}
					if (this->choiceMenu == 3) //Tutorial
					{
						title.stop();
						tutorial.play();
						this->choiceMenu = 3;
						this->namePage = 3.0f;
						this->gameStart = false;
					}
					if (this->choiceMenu == 4) // Credit
					{
						title.stop();
						credit.play();
						this->choiceMenu = 4;
						this->namePage = 4.0f;
						this->gameStart = false;
					}
				}
				if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::W)
				{

					this->choiceMenu -= 0.5f;
					this->choose.play();
					if (this->choiceMenu == 0)
					{
						this->choiceMenu = 1;
					}
				}
				if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::S)
				{

					this->choiceMenu += 0.5f;
					this->choose.play();
					if (this->choiceMenu >= 4)
					{
						this->choiceMenu = 4;
					}
				}
			}
		}

		if (this->choiceMenu == 1)
		{
			this->choice_Ship.setPosition(320.0f, 475.0f);
		}
		if (this->choiceMenu == 2)
		{
			this->choice_Ship.setPosition(320.0f, 570.0f);
		}
		if (this->choiceMenu == 3)
		{
			this->choice_Ship.setPosition(320.0f, 660.0f);
		}
		if (this->choiceMenu == 4)
		{
			this->choice_Ship.setPosition(320.0f, 750.0f);
		}
		if (this->player->getHp() <= 0)
		{
			if (this->canEnter == true)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					this->gameStart = false;
					this->clearall();
					title.play();
					this->canEnter = false;
				}
			}

		}
	}
}



void Game::updateInput()
{
	this->posX = this->player->getPos().x + this->player->getBounds().width / 2.f;
	this->posY = this->player->getPos().y;
	//Move player Main
	this->player->setVic();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->move(-1.0f, 0.0f);
		this->player->updateOption_1(1, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
		this->option_Pos1 = true;
		this->option_Pos2 = false;
		this->option_Pos3 = false;
		this->option_Pos4 = false;
		this->option_Pos5 = false;
		this->option_Pos6 = false;
		this->option_Pos7 = false;
		this->option_Pos8 = false;
	
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->move(1.0f, 0.0f);
		this->player->updateOption_1(1, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
		this->option_Pos1 = false;
		this->option_Pos2 = false;
		this->option_Pos3 = true;
		this->option_Pos4 = false;
		this->option_Pos5 = false;
		this->option_Pos6 = false;
		this->option_Pos7 = false;
		this->option_Pos8 = false;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->move(0.0f, -1.0f);
		this->player->updateOption_1(1, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
		this->player->setVic_L1();
		this->option_Pos1 = false;
		this->option_Pos2 = false;
		this->option_Pos3 = false;
		this->option_Pos4 = true;
		this->option_Pos5 = false;
		this->option_Pos6 = false;
		this->option_Pos7 = false;
		this->option_Pos8 = false;
	}
		

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->move(0.0f, 1.0f);
		this->player->updateOption_1(1, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
		this->player->setVic_R1();
		this->option_Pos1 = false;
		this->option_Pos2 = true;
		this->option_Pos3 = false;
		this->option_Pos4 = false;
		this->option_Pos5 = false;
		this->option_Pos6 = false;
		this->option_Pos7 = false;
		this->option_Pos8 = false;
	}
		
	//Move player Sub Main
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->option_Pos1 = false; //A
		this->option_Pos2 = false; //S
		this->option_Pos3 = false; //D
		this->option_Pos4 = false; //W
		this->option_Pos5 = true; //AS
		this->option_Pos6 = false; //SD
		this->option_Pos7 = false; //DW
		this->option_Pos8 = false;// AW
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->option_Pos1 = false; //A
		this->option_Pos2 = false; //S
		this->option_Pos3 = false; //D
		this->option_Pos4 = false; //W
		this->option_Pos5 = false; //AS
		this->option_Pos6 = true; //SD
		this->option_Pos7 = false; //DW
		this->option_Pos8 = false;// AW
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->option_Pos1 = false; //A
		this->option_Pos2 = false; //S
		this->option_Pos3 = false; //D
		this->option_Pos4 = false; //W
		this->option_Pos5 = false; //AS
		this->option_Pos6 = false; //SD
		this->option_Pos7 = true; //DW
		this->option_Pos8 = false; //AW
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->option_Pos1 = false; //A
		this->option_Pos2 = false; //S
		this->option_Pos3 = false; //D
		this->option_Pos4 = false; //W
		this->option_Pos5 = false; //AS
		this->option_Pos6 = false; //SD
		this->option_Pos7 = false; //DW
		this->option_Pos8 = true;  //AW
	}
	
	//Debug
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		this->player->loseHp(200);*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		this->player->openLifeForce(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		this->SP_Points = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		this->SP_Points = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		this->SP_Points = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		this->SP_Points = 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
		this->SP_Points = 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		this->SP_Points = 6;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		
	}
		
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->player->canAttack())
	{
		//Normal Bullet
		if (Bullet_Type == 0)
		{
			this->shoot.play();
			this->bullets.push_back(
				new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
			); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
		if (this->checkOption_1 == true)
		{
			if (this->option_Pos1 == true) // ขวา
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

			}
			if (this->option_Pos2 == true) //บน
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y - 90.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

			}
			if (this->option_Pos3 == true) //ซ้าย
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 180.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

			}
			if (this->option_Pos4 == true) //ล่าง
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y + 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

			}
			if (this->option_Pos5 == true) // ขวาบน
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
			if (this->option_Pos6 == true) // :ซ้ายบน
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
			if (this->option_Pos7 == true) // :ซ้ายล่าง
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
			if (this->option_Pos8 == true) // :ขวาล่าง
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}

		}
			
		}
		//Missle
		else if (Bullet_Type == 1)
		{
			if (checkDouble_On == true)
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets2.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 9, true)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets3.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 1, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				if (this->checkOption_1 == true)
				{
					if (this->option_Pos1 == true) // ขวา
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos2 == true) //บน
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y - 90.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos3 == true) //ซ้าย
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 180.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos4 == true) //ล่าง
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y + 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos5 == true) // ขวาบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos6 == true) // :ซ้ายบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos7 == true) // :ซ้ายล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos8 == true) // :ขวาล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}

				}
			}
			else
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets2.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 9, true)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				if (this->checkOption_1 == true)
				{
					if (this->option_Pos1 == true) // ขวา
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos2 == true) //บน
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y - 90.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos3 == true) //ซ้าย
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 180.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos4 == true) //ล่าง
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y + 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos5 == true) // ขวาบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos6 == true) // :ซ้ายบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos7 == true) // :ซ้ายล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos8 == true) // :ขวาล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}

				}
			}
			
		}
		//Double Bullet
		else if (Bullet_Type == 2)
		{
			if (checkMissile_On == true)
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets2.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 9, true)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets3.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 1, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				if (this->checkOption_1 == true)
				{
					if (this->option_Pos1 == true) // ขวา
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos2 == true) //บน
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y - 90.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos3 == true) //ซ้าย
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 180.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos4 == true) //ล่าง
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y + 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos5 == true) // ขวาบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos6 == true) // :ซ้ายบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos7 == true) // :ซ้ายล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos8 == true) // :ขวาล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}

				}
			}
			else 
			{
				this->shoot.play();
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets3.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 1, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
				if (this->checkOption_1 == true)
				{
					if (this->option_Pos1 == true) // ขวา
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos2 == true) //บน
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y - 90.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos3 == true) //ซ้าย
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 180.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos4 == true) //ล่าง
					{

						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y + 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

					}
					if (this->option_Pos5 == true) // ขวาบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos6 == true) // :ซ้ายบน
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos7 == true) // :ซ้ายล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}
					if (this->option_Pos8 == true) // :ขวาล่าง
					{
						this->bullets.push_back(
							new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, 25, 0, false)
						); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
					}

				}
			}
		}
		//Ripple Bullet
		else if (Bullet_Type == 3)
		{
			this->shoot2.play();
			this->bullets.push_back(
				new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, -20, 0, false)
			); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			if (this->checkOption_1 == true)
			{
				if (this->option_Pos1 == true) // ขวา
				{

					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				}
				if (this->option_Pos2 == true) //บน
				{

					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y - 90.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				}
				if (this->option_Pos3 == true) //ซ้าย
				{

					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 180.0f, this->player->getPos().y - 10.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				}
				if (this->option_Pos4 == true) //ล่าง
				{

					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 50.0f, this->player->getPos().y + 70.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				}
				if (this->option_Pos5 == true) // ขวาบน
				{
					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
				}
				if (this->option_Pos6 == true) // :ซ้ายบน
				{
					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y - 70.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
				}
				if (this->option_Pos7 == true) // :ซ้ายล่าง
				{
					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f - 150.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
				}
				if (this->option_Pos8 == true) // :ขวาล่าง
				{
					this->bullets.push_back(
						new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f + 70.0f, this->player->getPos().y + 50.0f, 1.f, 0.f, 5.f, -20, 0, false)
					); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
				}
			}
		}
		
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "SCORE : " << this->points;
	this->pointText.setString(ss.str());

	std::stringstream ssPoint;
	ssPoint << "SP : " << this->SP_Points;
	this->SP_Text.setString(ssPoint.str());

	//Update player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.0f * hpPercent, this->playerHpBar.getSize().y));


	

}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	//Left World Collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.0f, this->player->getBounds().top);
		this->player->updateLifeForce(75.0f, this->player->getBounds().top);
	}
	

	//Right world collision
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top );
		this->player->updateLifeForce(this->window->getSize().x - this->player->getBounds().width + 75.0f, this->player->getBounds().top );
	}

	//Top world collision
	if (this->player->getBounds().top < 60.f)
	{
		this->player->setPosition(this->player->getBounds().left , 60.f);
		this->player->updateLifeForce(this->player->getBounds().left + 75.0f, 60.f);
	}

	//Bottom world collision
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y - 150.0f)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height - 150.0f );
		this->player->updateLifeForce(this->player->getBounds().left + 75.0f, this->window->getSize().y - this->player->getBounds().height - 150.0f);
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
	
		//Bullet culling (top of screen)
		if (bullet->getBounds().left > 1570.0f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}
		

		++counter;
	}

	unsigned counter_Missile = 0;
	for (auto* bullet2 : this->bullets2)
	{
		bullet2->update();

		//Bullet culling (top of screen)
		if (bullet2->getBounds().left > 2800.0f)
		{
			//Delete bullet
			delete this->bullets2.at(counter_Missile);
			this->bullets2.erase(this->bullets2.begin() + counter_Missile);
		}

		++counter_Missile;
	}

	unsigned counter_Double = 0;
	for (auto* bullet3 : this->bullets3)
	{
		bullet3->update();

		//Bullet culling (top of screen)
		if (bullet3->getBounds().left > 1570.0f)
		{
			//Delete bullet
			delete this->bullets3.at(counter_Double);
			this->bullets3.erase(this->bullets3.begin() + counter_Double);

		}

		++counter_Missile;
	}
}

void Game::updateEnemies()
{
	/////////////////////////////////////////////////-ENEMIES_01-////////////////////////////////////////////////////////
	//Spawning
	this->spawnTimer += 0.7f + this->multiSpawn; // 2.0 กำลังดี
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(this->window->getSize().x - 20.f, rand() % this->window->getSize().y,1 ));
		this->spawnTimer = 0.0f;
	}

	//Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//Bullet culling (top of screen)
		if (enemy->getBounds().left < -20.0f) //enemy->getBounds().left < 0.0f will delete when collision with window -50
		{
			//Delete bullet
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//Enemy player collision  
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			
			if (checkLifeForce_On == false)
			{
				this->boom.play();
				this->player->loseHp(this->enemies.at(counter)->getDamage());
				delete this->enemies.at(counter);
				this->enemies.erase(this->enemies.begin() + counter);
			}
			else if (checkLifeForce_On == true)
			{
				this->points += 60.0f;
				this->LifeForce_count -= 1;
				printf("%d\n", LifeForce_count);
				delete this->enemies.at(counter);
				this->enemies.erase(this->enemies.begin() + counter);
			}			
		}
		++counter;
	}
	/////////////////////////////////////////////////-ENEMIES_01S-////////////////////////////////////////////////////////
	//Spawning
	this->spawnTimer_01S += 0.1f;
	if (this->spawnTimer_01S >= this->spawnTimerMax_01S)
	{
		this->enemies_01S.push_back(new Enemy(this->window->getSize().x -20.f, rand() % this->window->getSize().y, 2));
		this->spawnTimer_01S = 0.0f;
		
	}

	//Update
	unsigned counter_01S = 0;
	for (auto* enemy_01S : this->enemies_01S)
	{
		enemy_01S->update_01S();

		//Bullet culling (top of screen)
		if (enemy_01S->getBounds_01S().left < -20.0f) //enemy->getBounds().left < 0.0f will delete when collision with window -50
		{
			//Delete bullet
			delete this->enemies_01S.at(counter_01S);
			this->enemies_01S.erase(this->enemies_01S.begin() + counter_01S);
		}
		//Enemy player collision  
		else if (enemy_01S->getBounds_01S().intersects(this->player->getBounds()))
		{
			if (checkLifeForce_On == false)
			{
				this->boom.play();
				this->player->loseHp(this->enemies_01S.at(counter_01S)->getDamage());
				delete this->enemies_01S.at(counter_01S);
				this->enemies_01S.erase(this->enemies_01S.begin() + counter_01S);
			}
			else if (checkLifeForce_On == true)
			{
				this->points += 60.0f;
				this->LifeForce_count -= 1.0f;
				printf("%d\n", LifeForce_count);
				delete this->enemies_01S.at(counter_01S);
				this->enemies_01S.erase(this->enemies_01S.begin() + counter_01S);
				
			}

			
		}
		++counter_01S;
	}
	
}

void Game::updateCombat()
{
	//ENEMIES_01 Normal Bullet
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->takedamage.play();
				this->points += this->enemies[i]->getPoints() * this->multiScore;
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				enemy_deleted = true;
			}
		}
	}
	//ENEMIES_01 Missile
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets2.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets2[k]->getBounds3()))
			{
				this->takedamage.play();
				this->points += this->enemies[i]->getPoints() * this->multiScore;
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets2[k];
				this->bullets2.erase(this->bullets2.begin() + k);
				enemy_deleted = true;
			}
		}
	}

	//ENEMIES_01 Double
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets3.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets3[k]->getBounds2()))
			{
				this->takedamage.play();
				this->points += this->enemies[i]->getPoints() * this->multiScore;
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets3[k];
				this->bullets3.erase(this->bullets3.begin() + k);
				enemy_deleted = true;
			}
		}
	}
	//ENEMIES_01S Normal Bullet
	for (int i = 0; i < this->enemies_01S.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies_01S[i]->getBounds_01S().intersects(this->bullets[k]->getBounds()))
			{
				this->takedamage.play();
				this->points += this->enemies_01S[i]->getPoints() * this->multiScore;

				delete this->enemies_01S[i];
				this->enemies_01S.erase(this->enemies_01S.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				enemy_deleted = true;
				Item_alive = true;
				onetime = true;
				getPoint = true;
			}
		}
	}
	//ENEMIES_01S Missile
	for (int i = 0; i < this->enemies_01S.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets2.size() && enemy_deleted == false; k++)
		{
			if (this->enemies_01S[i]->getBounds_01S().intersects(this->bullets2[k]->getBounds3()))
			{
				this->takedamage.play();
				this->points += this->enemies_01S[i]->getPoints() * this->multiScore;

				delete this->enemies_01S[i];
				this->enemies_01S.erase(this->enemies_01S.begin() + i);

				delete this->bullets2[k];
				this->bullets2.erase(this->bullets2.begin() + k);
				enemy_deleted = true;
				Item_alive = true;
				onetime = true;
				getPoint = true;
			}
		}
	}
	
	//ENEMIES_01S Double
	for (int i = 0; i < this->enemies_01S.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets3.size() && enemy_deleted == false; k++)
		{
			if (this->enemies_01S[i]->getBounds_01S().intersects(this->bullets3[k]->getBounds2()))
			{
				this->takedamage.play();
				this->points += this->enemies_01S[i]->getPoints() * this->multiScore;

				delete this->enemies_01S[i];
				this->enemies_01S.erase(this->enemies_01S.begin() + i);

				delete this->bullets3[k];
				this->bullets3.erase(this->bullets3.begin() + k);
				enemy_deleted = true;
				Item_alive = true;
				onetime = true;
				getPoint = true;
			}
		}
	}
}

void Game::updateItem()
{
	if (Item_alive == true)
	{
		if(onetime == true)
		{
			this->Item_SP.push_back(new Enemy(this->window->getSize().x - 20.f, rand() % this->window->getSize().y, 3));
			onetime = false;
		}
		unsigned counter_Item = 0;
		for (auto* ItemSP : this->Item_SP)
		{
			ItemSP->update_Item();
			//Bullet culling (top of screen)
			if (ItemSP->getBounds_Item().top > this->window->getSize().y) //enemy->getBounds().left < 0.0f will delete when collision with window
			{
				//Delete bullet
				delete this->Item_SP.at(counter_Item);
				this->Item_SP.erase(this->enemies_01S.begin() + counter_Item);
			}
			//Enemy player collision  
			else if (ItemSP->getBounds_Item().intersects(this->player->getBounds()))
			{
				if (getPoint == true)
				{
					this->SP.play();
					for (int i = 0; i < 1; i++)
					{
						this->SP_Points += this->Item_SP[i]->getSP_Points();
						checkSpeed = true;
					}
					delete this->Item_SP.at(counter_Item);
					this->Item_SP.erase(this->Item_SP.begin() + counter_Item);
					this->checkTimemultiSpawn = true;
					getPoint = false;
				}
				
			}
			++counter_Item;
		}
	}
}

void Game::updateOption()
{
	if (SP_Points > 6)
	{
		SP_Points = 1;
	}
	if (LifeForce_count == 0)
	{
		this->LifeForce_count = 0;
		checkLifeForce_On = false;
		this->player->openLifeForce(false, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
	}
	if (SP_Points == 0)
	{
		this->framePower_count = 0;
	}
	else if (SP_Points == 1)
	{
		this->framePower_count = 1;
	}
	else if (SP_Points == 2)
	{
		this->framePower_count = 2;
	}
	else if (SP_Points == 3)
	{
		this->framePower_count = 3;
	}
	else if (SP_Points == 4)
	{
		this->framePower_count = 4;
	}
	else if (SP_Points == 5)
	{
		this->framePower_count = 5;
	}
	else if (SP_Points == 6)
	{
		this->framePower_count = 6;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
	{
		
		if (SP_Points == 1) // speed up
		{
			this->SPAfter.play();
			this->speedup.play();
			if (checkSpeed == true)
			{
				//this->player->openLifeForce(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
				//this->player->updateLifeForce(this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
				
				this->player->updateSpeed(true);
				SP_Points = 0;
				checkSpeed = false;
			}
			this->multiScore += 0.01f;
			if (this->checkTimemultiSpawn == true)
			{
				this->multiSpawn += 0.5f;
				this->checkTimemultiSpawn = false;
			}
		}
		else if (SP_Points == 2) // missile
		{
			this->SPAfter.play();
			this->missile.play();
			Bullet_Type = 1;
			this->checkMissile_On = true;
			SP_Points = 0;
			this->multiScore += 0.2f;
			if (this->checkTimemultiSpawn == true)
			{
				this->multiSpawn += 0.7f;
				this->checkTimemultiSpawn = false;
			}
		}
		else if (SP_Points == 3) //Double
		{
			this->SPAfter.play();
			this->Double.play();
			Bullet_Type = 2;
			this->checkDouble_On = true;
			SP_Points = 0;
			this->multiScore += 0.2f;
			if (this->checkTimemultiSpawn == true)
			{
				this->multiSpawn += 0.7f;
				this->checkTimemultiSpawn = false;
			}
		}
		else if (SP_Points == 4) //Laser
		{
			this->SPAfter.play();
			this->laser.play();
			Bullet_Type = 3;
			this->checkMissile_On = false;
			this->checkDouble_On = false;
			SP_Points = 0;
			this->multiScore += 0.3f;
			if (this->checkTimemultiSpawn == true)
			{
				this->multiSpawn += 0.8f;
				this->checkTimemultiSpawn = false;
			}
		}
		else if (SP_Points == 5) // Option
		{
			this->SPAfter.play();
			this->multiple.play();
			this->player->openOption_1(true, this->player->getPos().x + this->player->getBounds().width / 2.f - 130.0f, this->player->getPos().y + 80.0f);
			this->checkOption_1 = true;
			SP_Points = 0;
			this->multiScore += 0.5f;
			if (this->checkTimemultiSpawn == true)
			{
				this->multiSpawn += 1.0f;
				this->checkTimemultiSpawn = false;
			}
		}
		else if (SP_Points == 6) //LifeForce
		{
			this->SPAfter.play();
			this->shield.play();
			this->player->openLifeForce(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
			checkLifeForce_On = true;
			this->LifeForce_count = 5.0f;
			SP_Points = 0;
			if (this->checkTimemultiSpawn == true)
			{
				this->multiSpawn += 0.5f;
				this->checkTimemultiSpawn = false;
			}
			printf("%d\n", LifeForce_count);
		}
	}

	
}
void Game::updateMusic()
{
	if (this->namePage == 2.0f)
	{
		title.play();
		title.setLoop(true);
	}
}

void Game::update()
{
	if (this->gameStart == true)
	{
		this->updateInput();

		this->player->update();

		this->updateCollision();

		this->updateBullets();

		this->updateEnemies();

		this->updateCombat();

		this->updateItem();

		this->updateOption();

		this->renderGUI();

		this->updateWorld();

		this->updateGUI();
	}
	/*else
	{
		this->updateMusic();
	}*/
	

}

void Game::renderMenu()
{

}

void Game::renderGUI()
{
	
	this->window->draw(this->ItemBarBack);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->pointText);
	this->window->draw(this->SP_Text);
	this->window->draw(this->ItemBar);
	this->window->draw(this->topBar);
	
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
	this->window->draw(this->worldBackground2);
	this->worldBackground.move(-0.5f, 0.0f);
	this->worldBackground2.move(-0.5f, 0.0f);
	
	if (this->worldBackground.getPosition().x < -1600.0f)
	{
		this->worldBackground.setPosition(1600.0f, 0.0f);
	}
	if (this->worldBackground2.getPosition().x < -1600.0f)
	{
		this->worldBackground2.setPosition(1600.0f, 0.0f);
	}
}

void Game::render()
{
	this->window->clear();

	if (this->gameStart == false)
	{
		if (this->namePage == 1)
		{
			this->window->draw(this->backgroundMainMenu);
			this->window->draw(this->choice_Ship);;
		}
		if (this->namePage == 2)
		{
			this->window->draw(this->backgroundLeaderboard);
		}
		if (this->namePage == 3)
		{
			this->window->draw(this->backgroundTutorial);
		}
		if (this->namePage == 4)
		{
			this->window->draw(this->backgroundCredit);
		}
		
	}
	else
	{
		//Draw world
		this->renderWorld();
		
		
		//Draw all the stuffs
		this->player->render(*this->window);
		for (auto* bullet : this->bullets)
		{
			bullet->render(this->window);
		}

		for (auto* bullet2 : this->bullets2)
		{
			bullet2->render(this->window);
		}

		for (auto* bullet3 : this->bullets3)
		{
			bullet3->render(this->window);
		}

		for (auto* enemy : this->enemies)
		{
			enemy->render(this->window);
		}

		for (auto* enemy_01S : this->enemies_01S)
		{
			enemy_01S->render(this->window);
		}

		for (auto* ItemSP : this->Item_SP)
		{
			ItemSP->render(this->window);
		}

		this->renderGUI();
		
		
		if (framePower_count == 0)
		{
			this->drawFrame = false;
		}
		if (framePower_count == 1)
		{
			this->drawFrame = true;
			this->framePower.setPosition(sf::Vector2f(290.0f, 830.0f)); // speed up
		}
		if (framePower_count == 2)
		{
			this->drawFrame = true;
			this->framePower.setPosition(sf::Vector2f(490.0f, 830.0f)); // missile
		}
		if (framePower_count == 3)
		{
			this->drawFrame = true;
			this->framePower.setPosition(sf::Vector2f(695.0f, 830.0f)); // Double
		}
		if (framePower_count == 4)
		{
			this->drawFrame = true;
			this->framePower.setPosition(sf::Vector2f(900.0f, 830.0f)); // Laser
		}
		if (framePower_count == 5)
		{
			this->drawFrame = true;
			this->framePower.setPosition(sf::Vector2f(1105.0f, 830.0f)); // Option
		}
		if (framePower_count == 6)
		{
			this->drawFrame = true;
			this->framePower.setPosition(sf::Vector2f(1305.0f, 830.0f)); // ?
		}
		if (this->drawFrame == true)
		{
			this->window->draw(framePower);
		}

		//Game Over screen
		if (this->player->getHp() <= 0)
		{
			this->soundtrack.stop();
			this->dead.play();
			this->canEnter = true;
			this->player->alreadyDead(true, posX, posY);
			this->player->render(*this->window);
			this->window->draw(this->gameOverText);
			
		}

		
	}

	

	this->window->display();
}
