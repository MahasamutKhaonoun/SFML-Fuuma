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
}
void Game::initWorld()
{
	//World
	if (!this->worldBackgroundTex.loadFromFile(""))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
	
}
void Game::initSystems()
{
	this->points = 0;
	this->Bullet_Type = 0;
	this->MovementSpeed = 3.f;
	this->SP_Points = 0;
	this->LifeForce_count = 5.0f;
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
//Con Des
Game::Game()
{

	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
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


	//Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}

	//delete enemies
	for (auto* i : this->enemies)
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
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	this->posX = this->player->getPos().x + this->player->getBounds().width / 2.f;
	this->posY = this->player->getPos().y;
	//Move player
	this->player->setVic();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.0f, 0.0f);
		//this->player->openLifeForce(true, posX, posY);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.0f, -1.0f);
		this->player->setVic_L1();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.0f, 1.0f);
		this->player->setVic_R1();
	//Debug
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		this->player->loseHp(200);
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
		
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && this->player->canAttack())
	{
		//Normal Bullet
		if (Bullet_Type == 0)
		{
			this->bullets.push_back(
				new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
			); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
		}
		//Missle
		else if (Bullet_Type == 1)
		{
			if (checkDouble_On == true)
			{
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets2.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 9, true)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets3.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 1, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
			else
			{
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets2.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 9, true)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
			
		}
		//Double Bullet
		else if (Bullet_Type == 2)
		{
			if (checkMissile_On == true)
			{
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets2.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 9, true)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets3.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 1, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
			else 
			{
				this->bullets.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 0, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON

				this->bullets3.push_back(
					new Bullet(this->textures["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, 25, 1, false)
				); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
			}
		}
		//Ripple Bullet
		else if (Bullet_Type == 3)
		{
			this->bullets.push_back(
				new Bullet(this->textures2["BULLET"], this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y, 1.f, 0.f, 5.f, -20, 0, false)
			); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed, Bullet_Pos, type, Missile_ON
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
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
		this->player->updateLifeForce(this->player->getBounds().left + 75.0f, this->window->getSize().y - this->player->getBounds().height);
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
	
		//Bullet culling (top of screen)
		if (bullet->getBounds().left > 1600.0f)
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
		if (bullet2->getBounds().left > 3000.0f)
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
		if (bullet3->getBounds().left > 1600.0f)
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
	this->spawnTimer += 0.5f;
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
		if (enemy->getBounds().left < -50.0f) //enemy->getBounds().left < 0.0f will delete when collision with window
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
		if (enemy_01S->getBounds_01S().left < -50.0f) //enemy->getBounds().left < 0.0f will delete when collision with window
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
				this->points += this->enemies[i]->getPoints();
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
				this->points += this->enemies[i]->getPoints();
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
				this->points += this->enemies[i]->getPoints();
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
				this->points += this->enemies_01S[i]->getPoints();

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
				this->points += this->enemies_01S[i]->getPoints();

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
				this->points += this->enemies_01S[i]->getPoints();

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
					for (int i = 0; i < 1; i++)
					{
						this->SP_Points += this->Item_SP[i]->getSP_Points();
						checkSpeed = true;
					}
					delete this->Item_SP.at(counter_Item);
					this->Item_SP.erase(this->Item_SP.begin() + counter_Item);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
	{
		if (SP_Points == 1)
		{
			if (checkSpeed == true)
			{
				//this->player->openLifeForce(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
				//this->player->updateLifeForce(this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
				
				this->player->updateSpeed(true);
				SP_Points = 0;
				checkSpeed = false;
			}
		}
		else if (SP_Points == 2)
		{
			Bullet_Type = 1;
			this->checkMissile_On = true;
			SP_Points = 0;
		}
		else if (SP_Points == 3)
		{
			Bullet_Type = 2;
			this->checkDouble_On = true;
			SP_Points = 0;
		}
		else if (SP_Points == 4)
		{
			Bullet_Type = 3;
			this->checkMissile_On = false;
			this->checkDouble_On = false;
			SP_Points = 0;
		}
		else if (SP_Points == 6)
		{
			this->player->openLifeForce(true, this->player->getPos().x + this->player->getBounds().width / 2.f, this->player->getPos().y);
			checkLifeForce_On = true;
			this->LifeForce_count = 5.0f;
			SP_Points = 0;
			printf("%d\n", LifeForce_count);
		}
	}
}

void Game::update()
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

void Game::renderGUI()
{
	
	this->window->draw(this->ItemBarBack);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
	this->window->draw(this->pointText);
	this->window->draw(this->SP_Text);
	this->window->draw(this->ItemBar);
	
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	//Game Over screen
	if (this->player->getHp() <= 0)
	{
		
		this->player->alreadyDead(true, posX, posY);
		this->window->draw(this->gameOverText);
		//printf("SP : %d", SP_Points);
	}

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

	this->window->display();
}
