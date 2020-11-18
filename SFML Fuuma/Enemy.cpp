#include "Enemy.h"


void Enemy::initVariables()
{
	this->pointCount	= rand() % 8 + 3; //min = 3 max = 10
	this->type			= 0;
	this->speed			= static_cast<float>(this->pointCount/2);
	this->hpMax			= static_cast<float>(this->pointCount);
	this->hp			= this->hpMax;
	this->damage		= this->pointCount;
	this->points		= this->pointCount;

	//this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	//this->type = 0;
	//this->speed = 5.f;
	//this->hpMax = 10;
	//this->hp = 0;
	//this->damage = 1;
	//this->points = 5;
}

void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount * 5); //rand() % 20 + 20
	this->shape.setPointCount(this->pointCount); //rand() % 20 + 3
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
	

}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();

	this->shape.setPosition(pos_x, pos_y);

}

Enemy::~Enemy()
{

}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}




//Functions
void Enemy::update()
{
	this->shape.move(-this->speed, 0.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
