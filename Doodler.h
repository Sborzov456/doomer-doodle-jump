#pragma once
#include "Settings.h"



class Doodler
{
private:
	float speed; // vertical component of jump speed
	float acceleration; // vertical acceleration of jump
	//horizontal speed is a constant defined in Settings

	sf::Sprite sprite; //doodler sprite

	sf::Texture textureRight; //texture for right turn
	sf::Texture textureLeft; // texture for left turn
public:
	Doodler(const sf::Vector2f& startPosition);
	void setDefault(const sf::Vector2f& startPosition);
	void verticalUpdate();
	void horizontalUpdate(const float speed); 
	void setSpeed(const float newSpeed);
	void setAcceleration(const float newAcceleration);
	void setPosition(const sf::Vector2f& newPosition);
	const sf::Vector2f& getPosition() const;
	const sf::Sprite& getSprite() const;
	const float getSpeed() const;
	const float getAcceleration() const;
	const float getLeftBound() const;
	const float getRightBound() const;
	~Doodler() = default;
};