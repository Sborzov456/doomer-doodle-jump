#include "Doodler.h"

Doodler::Doodler(const sf::Vector2f& startPosition) : speed(START_VERTICAL_SPEED - 1.0), acceleration(VERTICAL_ACCELERATION)
{
	textureRight.loadFromFile(DOODLER_RIGHT_FILE_PATH);
	textureLeft.loadFromFile(DOODLER_LEFT_FILE_PATH);
	sprite.setTexture(textureRight);
	sprite.setOrigin(textureRight.getSize().x / 2, textureRight.getSize().y / 2);
	sprite.setPosition(startPosition);
}

void Doodler::setDefault(const sf::Vector2f& startPosition)
{
	sprite.setTexture(textureRight);
	sprite.setOrigin(textureRight.getSize().x / 2, textureRight.getSize().y / 2);
	sprite.setPosition(startPosition);
	speed = START_VERTICAL_SPEED - 1.0;
	acceleration = VERTICAL_ACCELERATION;
}

void Doodler::verticalUpdate()
{
	sprite.move(0, speed);
	speed += acceleration;
}

void Doodler::horizontalUpdate(const float horizontalSpeed)
{
	sprite.move(horizontalSpeed, 0);
	if (horizontalSpeed >= 0) {
		sprite.setTexture(textureRight);
	}
	else {
		sprite.setTexture(textureLeft);
	}
	if (sprite.getPosition().x >= WINDOW_WIDTH) {
		sprite.setPosition(sprite.getTexture()->getSize().x / 2, sprite.getPosition().y);
	}
	if (sprite.getPosition().x <= 0) {
		sprite.setPosition(WINDOW_WIDTH - sprite.getTexture()->getSize().x / 2, sprite.getPosition().y);
	}
}

void Doodler::setSpeed(const float newSpeed)
{
	speed = newSpeed;
}

void Doodler::setAcceleration(const float newAcceleration)
{
	acceleration = newAcceleration;
}

void Doodler::setPosition(const sf::Vector2f& newPosition)
{
	sprite.setPosition(newPosition);
}

const sf::Vector2f& Doodler::getPosition() const
{
	return sprite.getPosition();
}

const sf::Sprite& Doodler::getSprite() const
{
	return sprite;
}

const float Doodler::getSpeed() const
{
	return speed;
}

const float Doodler::getAcceleration() const
{
	return acceleration;
}

const float Doodler::getLeftBound() const
{
	if (sprite.getTexture() == &textureRight) {
		return DOODLER_LEFT_BOUND;
	}
	else {
		return DOODLER_RIGHT_BOUND;
	}
}

const float Doodler::getRightBound() const
{
	if (sprite.getTexture() == &textureRight) {
		return DOODLER_RIGHT_BOUND;
	}
	else {
		return DOODLER_LEFT_BOUND;
	}
}