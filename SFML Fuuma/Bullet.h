#ifndef BULLET_H
#define BULLET_H



#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:

	sf::Sprite shape;
	sf::Sprite shape2;
	sf::Sprite shape3;
	sf::Texture* texture;

	sf::Vector2f direction;
	float movementSpeed;
	int Bullet_Pos;
	int Type;

	float pos_X;
	float pos_Y;

	bool checkMissile;

public:
	Bullet(sf::Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed,int Bullet_Pos, int type, bool checkmissile);
	virtual ~Bullet();

	//Accessor
	const sf::FloatRect getBounds() const;
	const sf::FloatRect getBounds2() const;

	void updateDouble();
	void update();
	void render(sf::RenderTarget* target);
};

#endif // !BULLET_H

