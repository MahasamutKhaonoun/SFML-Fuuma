#include "Enemy.h"




void Enemy::initShape()
{
	this->shape.setRadius(rand() % 20 + 20);
	this->shape.setPointCount(rand() % 100 + 3);
}

void Enemy::initVariables()
{
	this->type = 0;
	this->hpMax = 10;
	this->hp = 0;
	this->damage = 1;
	this->points = 5;
}

Enemy::Enemy()
{
	this->initShape();
	this->initVariables();

}

Enemy::~Enemy()
{

}