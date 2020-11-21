#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{

private:
	unsigned pointCount;
	sf::CircleShape shape;

	sf::Texture texture01;
	sf::Texture texture01S;
	sf::Sprite Enemy01;
	sf::Sprite Enemy01S;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	float posX;
	float posY;

	void initVariables();
	void initTexture();
	void initSprite();
	void initShape();

public:
	Enemy(float pos_x, float pos_y,int type);
	virtual ~Enemy();

	

	//Accesssors
	const sf::FloatRect getBounds() const;
	const sf::FloatRect getBounds_01S() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//Functions
	void updatePos();
	void update();
	void update_01S();
	void render(sf::RenderTarget* target);
};
#endif // !ENEMY_H

