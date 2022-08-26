#include "Map.h"

Map::Map() : lowestBound(WINDOW_HEIGHT / 2)
{
	backgroundTexture.loadFromFile(BACKGROUND_FILE_PATH);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setOrigin(backgroundTexture.getSize().x / 2, backgroundTexture.getSize().y / 2);
	randomEngine.seed(std::time(nullptr));
	this->platformsRandomInitial();
}

void Map::setDefault()
{
	this->deletePlatforms();
	this->platformsRandomInitial();
	lowestBound = WINDOW_HEIGHT / 2;
}

void Map::deletePlatforms()
{
	for (auto platform : platforms) {
		delete platform;
	}
	platforms.erase(platforms.begin(), platforms.end());
}

void Map::platformsRandomInitial()
{
	for (float i = START_PLATFORM_OFFSET; i < WINDOW_HEIGHT; i += DISTANCE_BETWEEN_PLATFORMS) {
		Platform* platform = new Platform(PLATFORM_FILE_PATH);
		platform->setPosition(sf::Vector2f(getRandomNumber(LAYER_LEFT_BOUND, LAYER_RIGHT_BOUND, randomEngine), WINDOW_HEIGHT - i));
		platforms.push_back(platform);
	}

}

void Map::updatePlatforms(const sf::View& view, const float score) 
{
	for (int i = 0; i < platforms.size(); i++) {
		if (platforms[i]->getPosition().y >= view.getCenter().y + lowestBound) {
			//CHANGING THE DIFFICULTY OF THE GAME
			if (score <= MAX_LEVEL_SCORE) {
				lowestBound = WINDOW_HEIGHT / 2 * (score / LEVELS_CHANGE_SPEED + 1);
			}
			//FAST PLATOFORMS INITIAL
			if (randomEngine() % 100 <= 15 && score >= 5000.0 || 
				randomEngine() % 100 <= 25 && score >= 10000.0) {
				delete platforms[i];
				platforms[i] = new FastPlatform(FAST_PLATFORM_FILE_PATH);
			}
			else if (platforms[i]->getType() == 1) {
				delete platforms[i];
				platforms[i] = new Platform(PLATFORM_FILE_PATH);
			}
			//TELEPORT PLATFORMS INITIAL
			if (randomEngine() % 100 <= 30 && score >= 15000.0 ||
				randomEngine() % 100 <= 50 && score >= 20000.0) {
				delete platforms[i];
				platforms[i] = new TeleportPlatform(TELEPORT_PLATFORM_FILE_PATH);
			}
			else if (platforms[i]->getType() == 2) {
				delete platforms[i];
				platforms[i] = new Platform(PLATFORM_FILE_PATH);
			}

			platforms[i]->setPosition(sf::Vector2f(getRandomNumber(LAYER_LEFT_BOUND, LAYER_RIGHT_BOUND, randomEngine), view.getCenter().y - WINDOW_HEIGHT / 2));
		}
		//FAST PLATFORMS PROCESSING
		if (platforms[i]->getType() == 1) {
			dynamic_cast<FastPlatform*>(platforms[i])->horizontalUpdate();
		}
		//TELEPORT PLATFORMS PROCESSING
		if (platforms[i]->getType() == 2) {
			if (TeleportPlatform::collision) {
				TeleportPlatform::frameCounter = FRAMES_FOR_TELEPORTING;
				TeleportPlatform::collision = false;
			}
			if (TeleportPlatform::frameCounter == 0) {
				dynamic_cast<TeleportPlatform*>(platforms[i])->teleportation(i);
			}
			else if (TeleportPlatform::frameCounter > 0) {
				dynamic_cast<TeleportPlatform*>(platforms[i])->disappearance();
			}
			else if (TeleportPlatform::frameCounter >= -FRAMES_FOR_TELEPORTING) {
				dynamic_cast<TeleportPlatform*>(platforms[i])->appearance();
			}
		}
	}
	if (TeleportPlatform::frameCounter > -FRAMES_FOR_TELEPORTING - 1) {
		TeleportPlatform::frameCounter--;
	}
}

void Map::updateBackground(const sf::View& view) 
{
	backgroundSprite.setPosition(view.getCenter());
}

void Map::drawPlatforms(sf::RenderWindow& window) const
{
	for (int i = 0; i < platforms.size(); i++) {
		window.draw(platforms[i]->getSprite());
	}
}

void Map::drawBackground(sf::RenderWindow& window) const
{
	window.draw(backgroundSprite);
}

const std::vector<Platform*>& Map::getPlatforms() const
{
	return platforms;
}

Map::~Map()
{
	this->deletePlatforms();
}

