#pragma once
#include "Settings.h"

/*
Basic platform
*/

class Platform
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Platform(const char* textureFilePath, const sf::Vector2f& startPosition = { 0.0, 0.0 });
	void setPosition(const sf::Vector2f& newPosition);
	const sf::Vector2f& getPosition() const;
	const sf::Sprite& getSprite() const;
	const sf::Vector2u& getSize() const;
	virtual const unsigned char getType() const;
	virtual const float getUpperBound() const;
	virtual const float getLowerBound() const;
	virtual const float getRightBound() const;
	virtual const float getLeftBound() const;
	virtual ~Platform() = default;
};