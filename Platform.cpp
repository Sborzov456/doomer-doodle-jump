#include "Platform.h"
Platform::Platform(const char* textureFilePath, const sf::Vector2f& startPosition)
{
	texture.loadFromFile(textureFilePath);
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	sprite.setPosition(startPosition);
}

void Platform::setPosition(const sf::Vector2f& newPosition)
{
	sprite.setPosition(newPosition);
}

const sf::Vector2f& Platform::getPosition() const
{
	return sprite.getPosition();
}

const sf::Sprite& Platform::getSprite() const
{
	return sprite;
}

const sf::Vector2u& Platform::getSize() const
{
	return texture.getSize();
}

const unsigned char Platform::getType() const
{
	return 0;
}

const float Platform::getUpperBound() const
{
	return PLATFORM_UPPER_BOUND;
}

const float Platform::getLowerBound() const
{
	return PLATFORM_LOWER_BOUND;
}

const float Platform::getRightBound() const
{
	return PLATFORM_RIGHT_BOUND;
}

const float Platform::getLeftBound() const
{
	return PLATFORM_LEFT_BOUND;
}