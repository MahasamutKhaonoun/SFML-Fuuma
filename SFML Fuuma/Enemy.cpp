#include "Enemy.h"


void Enemy::initVariables()
{
	this->pointCount	= rand() %  10 + 3;; //min = 3 max = 10
	//this->type			= 0;
	this->speed			= static_cast<float>(this->pointCount / 2);
	this->hpMax			= static_cast<float>(this->pointCount);
	this->hp			= this->hpMax;
	this->damage		= this->pointCount * 3;
	this->points		= this->pointCount;
	this->SP_Point		= 1;
	this->speedSP		= 5;

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
	if (!this->texture01.loadFromFile("Enemies/Enemies_01.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
	//Enemies 01S
	if (!this->texture01S.loadFromFile("Enemies/Enemies_01S.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}

	if (!this->textureItem_01.loadFromFile("Item/ItemSP.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
}

void Enemy::initSprite()
{
	//Enemies 01
	this->Enemy01.setTexture(this->texture01);
	this->Enemy01.scale(4.0f, 4.0f);
	//Enemies 01
	this->Enemy01S.setTexture(this->texture01S);
	this->Enemy01S.scale(4.0f, 4.0f);
	//Item_SP
	this->Item_01.setTexture(this->textureItem_01);
	this->Item_01.scale(4.0f, 4.0f);
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

Enemy::Enemy(float pos_x, float pos_y, int type)
{
	this->posX = pos_x;
	this->posY = pos_y;
	this->type = type;

	this->initVariables();
	this->initTexture();
	this->initSprite();
	//this->initShape();
	this->updatePos();
	this->returnPosX();
	this->returnPosY();


}

Enemy::~Enemy()
{

}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->Enemy01.getGlobalBounds();
}

const sf::FloatRect Enemy::getBounds_01S() const
{
	return this->Enemy01S.getGlobalBounds();
}

const sf::FloatRect Enemy::getBounds_Item() const
{
	return this->Item_01.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getSP_Points() const
{
	return this->SP_Point;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const float& Enemy::returnPosX() const
{
	return this->posX;
}

const float& Enemy::returnPosY() const
{
	return this->posY;
}




void Enemy::updatePos()
{
	if (type == 1)
	{
		this->Enemy01.setPosition(posX, posY);
	}
	else if (type == 2)
	{
		this->Enemy01S.setPosition(posX, posY);
	}
	else if (type == 3)
	{
		this->Item_01.setPosition(posX, posY);
	}
	
}

//Functions
void Enemy::update()
{
	this->Enemy01.move(-this->speed, 0.f);
}

void Enemy::update_01S()
{
	this->Enemy01S.move(-this->speed, 0.f);
}

void Enemy::update_Item()
{
	this->Item_01.move(-this->speedSP, 0.f);
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->Enemy01);
	target->draw(this->Enemy01S);
	target->draw(this->Item_01);
	/*if (type == 3)
	{
		target->draw(this->Enemy01);
		target->draw(this->Enemy01S);
		target->draw(this->Item_01);
	}*/
}
