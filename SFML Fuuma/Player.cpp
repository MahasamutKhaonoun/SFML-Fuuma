#include "Player.h"

void Player::initVariables()
{
	//this->movementSpeed = 2.f;
	this->attackCooldownMax = 30.0f;
	this->attackCooldown = this->attackCooldownMax;
	this->hpMax = 100;
	this->hp = this->hpMax;
	this->sprite.setPosition(100.f, 360.f);
}

void Player::initTexture()
{
	//load a texture from file
	//Vic Viper normal
	if (!this->texture.loadFromFile("Player/Vic Viper.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	//Vic Viper R1
	else if (!this->texture_R1.loadFromFile("Player/Vic Viper_R1.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	//Vic Viper R2
	else if (!this->texture_R2.loadFromFile("Player/Vic Viper_R2.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	//Vic Viper L1
	else if (!this->texture_L1.loadFromFile("Player/Vic Viper_L1.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	//Vic Viper L2
	else if (!this->texture_L2.loadFromFile("Player/Vic Viper_L2.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	//Vic Viper Dead
	else if (!this->texture_Dead.loadFromFile("Player/126794005_374521303768688_3223597176188986233_n.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	//Life Force
	else if (!this->texture_LifeForce.loadFromFile("Player/Life Force.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(5.0f, 4.0f);
}

Player::Player(float speed)
{
	this->movementSpeed = speed;
	this->initVariables();
	this->initTexture();
	this->initSprite();
	
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::openLifeForce(bool open, float pos_X, float pos_Y)
{
	this->Pos_X = pos_X;
	this->Pos_Y = pos_Y;
	this->checkLifeforce = open;
	this->sprite_LifeForce.setTexture(this->texture_LifeForce);
	//this->sprite_LifeForce.setTextureRect(sf::IntRect(0, 0, 30, 30));
	this->sprite_LifeForce.setPosition(pos_X - 120, pos_Y - 20);
	
	this->sprite_LifeForce.setScale(5.f, 5.f);

}

void Player::updateLifeForce(float pos_X, float pos_Y)
{
	//this->sprite_LifeForce.setPosition(this->sprite.getPosition().x/2, this->sprite.getPosition().y / 2);
	//this->sprite_LifeForce.setPosition(this->sprite.getPosition());
	this->sprite_LifeForce.setPosition(pos_X - 120, pos_Y - 20);
}

void Player::alreadyDead(bool dead, float pos_X, float pos_Y)
{
	this->checkDead = dead;
	this->sprite_Dead.setTexture(this->texture_Dead);
	this->sprite_Dead.setScale(1.5f, 1.5f); //1.5 1.5
	this->sprite_Dead.setPosition(pos_X - 120,pos_Y-30);
	//this->sprite_Dead.setPosition(dirx)
}

void Player::move(const float dirX, const float dirY)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		this->movementSpeed = 3.f;
	}*/
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	if (checkLifeforce == true)
	{
		this->sprite_LifeForce.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
	}
	//this->movementSpeed = 2.0f;
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.0f;
		return true;
	}
	return false;
}

void Player::setVic()
{
	this->sprite.setTexture(this->texture);
}

void Player::setVic_R1()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.setTexture(this->texture_R1);
	}
		
}

void Player::setVic_R2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->sprite.setTexture(this->texture_R2);
	}
}

void Player::setVic_L1()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.setTexture(this->texture_L1);
	}
}

void Player::setVic_L2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->sprite.setTexture(this->texture_L2);
	}
}

void Player::updateSpeed(bool checkspeed)
{
	this->checkSpeed = checkspeed;
	//this->newSpeed = newspeed;
	if (checkSpeed == true)
	{
			this->movementSpeed += 1.f;
			checkSpeed = false;
			printf("%.2f ", movementSpeed);
	}
	if (movementSpeed > 5.f)
	{
		this->movementSpeed = 6.f;
		printf("End Speed");
	}
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.8f;
	}
	
}

//Function
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	if (checkLifeforce == true)
	{
		target.draw(this->sprite_LifeForce);
	}

	target.draw(this->sprite);

	if (checkDead == true)
	{
		target.draw(this->sprite_Dead);
	}
	
}
