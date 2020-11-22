#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <iostream>
class Item
{
private:
	unsigned pointCount;

	sf::Texture textureItem_01;
	sf::Sprite Item_01;

	int type;
	float speed;
	int points;
	int SP_points;

	float posX;
	float posY;

	void initVariables();
	void initTexture();
	void initSprite();

public:
	Item(float pos_x, float pos_y, int type);
	virtual ~Item();



	//Accesssors
	const sf::FloatRect getBounds() const;
	const int& getSP() const; //getPoint

	//Functions
	void updatePos();
	void update();
	void render(sf::RenderTarget* target);

};
#endif // !ITEM_H

