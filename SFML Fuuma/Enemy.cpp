#include "Enemy.h"


void Enemy::initVariables()
{
	this->pointCount	= rand() %  10 + 3;; //min = 3 max = 10
	this->type			= 0;
	this->speed			= static_cast<float>(this->pointCount / 2);
	this->hpMax			= static_cast<float>(this->pointCount);
	this->hp			= this->hpMax;
	this->damage		= this->pointCount;
	this->points		= this->pointCount;

	//Ver1
	//this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	//this->type = 0;
	//this->speed = 5.f;
	//this->hpMax = 10;
	//this->hp = 0;
	//this->damage = 1;
	//this->points = 5;

	//Ver2
	//this->pointCount = rand() % 8 + 3; //min = 3 max = 10
	//this->type = 0;
	//this->speed = static_cast<float>(this->pointCount / 2);
	//this->hpMax = static_cast<float>(this->pointCount);
	//this->hp = this->hpMax;
	//this->damage = this->pointCount;
	//this->points = this->pointCount;
}

void Enemy::initTexture()
{
	//Enemies 01
	if (!this->textureE.loadFromFile("Enemies/Enemies_01.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
}

void Enemy::initSprite()
{
	//Enemies 01
	this->Enemy01.setTexture(this->textureE);
	this->Enemy01.scale(4.0f, 4.0f);
}

void Enemy::initShape()
{
	

	//this->shape.setRadius(this->pointCount * 5); //rand() % 20 + 20
	//this->shape.setPointCount(this->pointCount); //rand() % 20 + 3
	//this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));

	//Ver1
	//this->shape.setRadius(this->pointCount * 5); //rand() % 20 + 20
	//this->shape.setPointCount(this->pointCount); //rand() % 20 + 3
	//this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
	

}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	//this->initShape();

	this->Enemy01.setPosition(pos_x, pos_y);

}

Enemy::~Enemy()
{

}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->Enemy01.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}




//Functions
void Enemy::update()
{
	this->Enemy01.move(-this->speed, 0.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->Enemy01);
}
