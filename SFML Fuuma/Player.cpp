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
	this->movementSpeed = 2.0f;
	this->initTexture();
	this->initSprite();
	
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
		this->movementSpeed += 0.01f;*/
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
