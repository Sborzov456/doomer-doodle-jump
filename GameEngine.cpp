#include "GameEngine.h"

GameEngine::GameEngine()
{
	platformSoundBuffer.loadFromFile(PLATFORM_SAMPLE_FILE_PATH);
	fastPlatformSoundBuffer.loadFromFile(FAST_PLATFORM_SAMPLE_FILE_PATH);
	teleportPlatformSoundBuffer.loadFromFile(TELEPORT_PLATFORM_SAMPLE_FILE_PATH);
}

bool GameEngine::intersects(const Doodler& doodler, const Platform* platform)
{
	if (doodler.getPosition().y + DOODLER_UPPER_BOUND <= platform->getPosition().y - platform->getUpperBound() &&
		doodler.getPosition().y + DOODLER_UPPER_BOUND >= platform->getPosition().y - platform->getUpperBound() - EPSILON &&
		doodler.getPosition().x + doodler.getRightBound() >= platform->getPosition().x - platform->getLeftBound() &&
		doodler.getPosition().x - doodler.getLeftBound() <= platform->getPosition().x + platform->getRightBound() &&
		doodler.getSpeed() >= 0) return true;
	return false;
}

bool GameEngine::collision(const std::vector<Platform*>& platforms, Doodler& doodler)
{
	for (int i = 0; i < platforms.size(); i++) {
		if (intersects(doodler, platforms[i])) {
			doodler.setPosition(sf::Vector2f(doodler.getPosition().x, platforms[i]->getPosition().y - platforms[i]->getUpperBound() - DOODLER_UPPER_BOUND));
			doodler.setSpeed(START_VERTICAL_SPEED);
			doodler.setAcceleration(VERTICAL_ACCELERATION);
			if (platforms[i]->getType() == 0) {
				sound.setBuffer(platformSoundBuffer);
				sound.play();
			}
			if (platforms[i]->getType() == 1) {
				sound.setBuffer(fastPlatformSoundBuffer);
				sound.play();
			}
			if (platforms[i]->getType() == 2) {
				TeleportPlatform::collision = true;
				sound.setBuffer(teleportPlatformSoundBuffer);
				sound.play();
			}
			return true;
		}
	}
	return false;
}