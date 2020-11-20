#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{

private:
	unsigned pointCount;
	sf::CircleShape shape;

	sf::Texture textureE;
	sf::Sprite Enemy01;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initVariables();
	void initTexture();
	void initSprite();
	void initShape();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accesssors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};
#endif // !ENEMY_H

