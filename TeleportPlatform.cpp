#include "TeleportPlatform.h"

bool TeleportPlatform::collision = false;
short TeleportPlatform::frameCounter = -FRAMES_FOR_TELEPORTING - 1;

TeleportPlatform::TeleportPlatform(const char* textureFilePath, const sf::Vector2f& startPosition) :
	Platform(textureFilePath, startPosition) {}

void TeleportPlatform::teleportation(const int index)
{
	std::mt19937 engine;
	engine.seed(std::time(nullptr) + index);
	sprite.setPosition(sf::Vector2f(getRandomNumber(TELEPORT_PLATFORM_LEFT_BOUND + 50, WINDOW_WIDTH - TELEPORT_PLATFORM_RIGHT_BOUND - 50, engine) + 10, 
		sprite.getPosition().y));
	sprite.setColor(sf::Color(255, 255, 255, 0));
}

void TeleportPlatform::disappearance()
{
	sprite.setColor(sf::Color(255, 255, 255, 255 * transparencyGradientFunction(static_cast<float>(frameCounter) / FRAMES_FOR_TELEPORTING)));
}

void TeleportPlatform::appearance()
{
	sprite.setColor(sf::Color(255, 255, 255, 255 * transparencyGradientFunction(static_cast<float>(-frameCounter) / FRAMES_FOR_TELEPORTING)));
}

const unsigned char TeleportPlatform::getType() const
{
	return 2;
}

const float TeleportPlatform::getUpperBound() const
{
	return TELEPORT_PLATFORM_UPPER_BOUND;
}

const float TeleportPlatform::getLowerBound() const
{
	return TELEPORT_PLATFORM_LOWER_BOUND;
}

const float TeleportPlatform::getRightBound() const
{
	return TELEPORT_PLATFORM_RIGHT_BOUND;
}

const float TeleportPlatform::getLeftBound() const
{
	return TELEPORT_PLATFORM_LEFT_BOUND;
}