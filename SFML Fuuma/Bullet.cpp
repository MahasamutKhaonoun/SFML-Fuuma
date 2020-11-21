#include "Bullet.h"


Bullet::Bullet()
{

}

Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.scale(2.0f, 3.0f);
	this->shape.setPosition(pos_x + 65, pos_y + 25);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}



const sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	//Movement
	this->shape.move(this->movementSpeed * this->direction);

}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
