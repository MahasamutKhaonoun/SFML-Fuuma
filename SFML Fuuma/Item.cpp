#include "Item.h"

void Item::initVariables()
{
	//this->pointCount = rand() % 10 + 3;; //min = 3 max = 10
	this->speed = 5;
	//this->points = this->pointCount;
	this->SP_points = 1;

}

void Item::initTexture()
{
	if (!this->textureItem_01.loadFromFile("Item/ItemSP.png"))
	{
		std::cout << "Error::Could not load texture player file." << "\n";
	}
}

void Item::initSprite()
{
	//ItemSP
	this->Item_01.setTexture(this->textureItem_01);
	this->Item_01.scale(4.0f, 4.0f);
}

Item::Item(float pos_x, float pos_y, int type)
{
	this->posX = pos_x;
	this->posY = pos_y;
	this->type = type;
	this->updatePos();
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Item::~Item()
{

}

const sf::FloatRect Item::getBounds() const
{
	return this->Item_01.getGlobalBounds();
}

const int& Item::getSP() const
{
	return this->SP_points;
}

void Item::updatePos()
{
	this->Item_01.setPosition(posX, posY);
}

void Item::update()
{
	this->Item_01.move(-this->speed, 0.f);
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->Item_01);
}
