#include "FastPlatform.h"

FastPlatform::FastPlatform(const char* textureFilePath, const sf::Vector2f& startPosition) :
	Platform(textureFilePath, startPosition), speed(FAST_PLATFORM_SPEED) {}

void FastPlatform::horizontalUpdate()
{
	if (sprite.getPosition().x + PLATFORM_RIGHT_BOUND >= WINDOW_WIDTH) {
		speed = -FAST_PLATFORM_SPEED;
	}
	if (sprite.getPosition().x - FAST_PLATFORM_LEFT_BOUND <= 0) {
		speed = FAST_PLATFORM_SPEED;
	}
	sprite.move(speed, 0);
}

const unsigned char FastPlatform::getType() const
{
	return 1;
}

const float FastPlatform::getUpperBound() const
{
	return FAST_PLATFORM_UPPER_BOUND;
}

const float FastPlatform::getLowerBound() const
{
	return FAST_PLATFORM_LOWER_BOUND;
}

const float FastPlatform::getRightBound() const
{
	return FAST_PLATFORM_RIGHT_BOUND;
}

const float FastPlatform::getLeftBound() const
{
	return FAST_PLATFORM_LEFT_BOUND;
}