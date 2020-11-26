#include "Bullet.h"


Bullet::Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int Bullet_Pos,int type,bool checkmissile)
{
	if (!this->texture_Missile.loadFromFile("Player/Item_Missile.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
	this->Bullet_Pos = Bullet_Pos;
	this->Type = type;
	this->pos_X = pos_x;
	this->pos_Y = pos_y;
	this->checkMissile = checkmissile;

	if (Type == 0)
	{
		this->shape.setTexture(*texture);
		this->shape.scale(2.0f, 3.0f);
		this->shape.setPosition(pos_X + 65, pos_Y + Bullet_Pos); //25 -20
	}

	if (Type == 1)
	{
		this->shape2.setTexture(*texture);
		this->shape2.scale(2.0f, 3.0f);
		this->shape2.setPosition(pos_X - 50, pos_Y + Bullet_Pos); //25 -20
	}

	if (checkMissile == true)
	{
		this->shape3.setTexture(texture_Missile);
		this->shape3.scale(2.0f, 3.0f);
		this->shape3.setPosition(pos_X - 10, pos_Y + Bullet_Pos + 35); //25 -20
	}

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

const sf::FloatRect Bullet::getBounds2() const
{
	return this->shape2.getGlobalBounds();
}

const sf::FloatRect Bullet::getBounds3() const
{
	return this->shape3.getGlobalBounds();
}

void Bullet::updateDouble()
{
	
}

void Bullet::update()
{
	//Movement
	//this->updateDouble();
	this->shape.move(this->movementSpeed * this->direction * 2.f);
	this->shape2.move(-this->movementSpeed * this->direction * 2.f);
	this->shape3.move(this->movementSpeed * this->direction * 0.8f);

}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->shape2);
	target->draw(this->shape3);
}
