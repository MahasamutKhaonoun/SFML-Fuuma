#include "Game.h"

//Private Functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1360,780),"Fuuma-Den",sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"] -> loadFromFile("Player/Vic Bullet.png");
}
void Game::initGUI()
{
	//Load font
	if(!this->font.loadFromFile("Fonts/G7Gradius21ByteFont-Jaem.ttf"))
		std::cout << "ERROR::GAME ::Failed to load font" << "\n";
		
	//Init point text
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(12);
	this->pointText.setFillColor(sf::Color::Blue);
	this->pointText.setString("SCORE : ");
}
void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile(""))
	{
		std::cout << "ERROR::GAME::Could not load background texture" << "\n";
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
}
void Game::initPlayer()
{
	this->player = new Player();

}
void Game::initEnemies()
{
	this->spawnTimerMax = 50.0f;
	this->spawnTimer = this->spawnTimerMax;
}
//Con Des
Game::Game()
{

	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
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
		this->update();
		this->render();

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
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.0f, -1.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.0f, 1.0f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
			this->bullets.push_back(
			new Bullet(
			this->textures["BULLET"], 
			this->player->getPos().x + this->player->getBounds().width/2.f, 
			this->player->getPos().y, 
			1.f, 
			0.f, 
			5.f)
			); //texture, pos_x, pos_y, dir_x, dir_y, movement_speed
	}
}

void Game::updateGUI()
{

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
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
	
		//Bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.0f)
		{
			//Delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;

		}

		++counter;
	}
}

void Game::updateEnemies()
{
	//Spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(this->window->getSize().x - 20.f, rand() % this->window->getSize().y ));
		this->spawnTimer = 0.0f;
	}

	//Update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//Bullet culling (top of screen)
		if (enemy->getBounds().top > this->window->getSize().y) //enemy->getBounds().left < 0.0f will delete when collision with window
		{
			//Delete bullet
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;

		}

		++counter;
	}

	
	
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}
		}

	}
}

void Game::update()
{
	this->updatePollEvents();

	this->updateInput();

	this->player->update();

	this->updateCollision();

	this->updateBullets();

	this->updateEnemies();

	this->updateCombat();
	
	this->renderGUI();

	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	//Draw world
	this->renderWorld();


	//Draw all the stuffs
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->renderGUI();

	this->window->display();

}
