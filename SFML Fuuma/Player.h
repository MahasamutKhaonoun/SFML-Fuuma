#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Texture texture_R1;
	sf::Texture texture_R2;
	sf::Texture texture_L1;
	sf::Texture texture_L2;


	float movementSpeed;
	float newSpeed;

	bool checkSpeed;

	float attackCooldown;
	float attackCooldownMax;

	int hp;
	int hpMax;

	//Private Functions
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player(float speed);
	virtual ~Player();

	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;
	
	//Modifers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);



	//Function
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void setVic();
	void setVic_R1();
	void setVic_R2();
	void setVic_L1();
	void setVic_L2();

	void updateSpeed(float newspeed,bool checkspeed);
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

