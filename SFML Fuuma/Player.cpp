#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.0f;
	this->attackCooldownMax = 10.0f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 10;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	//load a texture from file
	if (!this->texture.loadFromFile("Player/Vic Viper.png"))
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

Player::Player()
{
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
}

void Player::move(const float dirX, const float dirY)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		this->movementSpeed += 0.01f;*/
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
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

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.5f;
	}
	
}

//Function
void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
