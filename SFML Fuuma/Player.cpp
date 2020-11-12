#include "Player.h"

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
	this->movementSpeed = 1.0f;
	this->initTexture();
	this->initSprite();
	
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

//Function
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
