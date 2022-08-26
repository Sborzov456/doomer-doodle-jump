#pragma once
#include "Platform.h"
#include "FastPlatform.h"
#include "TeleportPlatform.h"
#include "SecondaryFunctions.h"

/*
This class controls the position of the background and platforms. 
Also responsible for generating platforms and increasing the difficulty of the game depending on the current score.
*/

class Map
{
private:
	std::vector<Platform*> platforms;
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	std::mt19937 randomEngine;
	float lowestBound;
	/*
	The lower bound for the platform.
	Since the position of the platforms also changes with the change in the camera position, it is possible to set a boundary,
	passing through which a new one is generated instead of the past platform
	*/
public:
	Map();
	void setDefault();
	void deletePlatforms();
	void platformsRandomInitial();
	void updatePlatforms(const sf::View& view, const float score);
	void updateBackground(const sf::View& view);
	void drawPlatforms(sf::RenderWindow& window) const;
	void drawBackground(sf::RenderWindow& window) const;
	const std::vector<Platform*>& getPlatforms() const;
	~Map();
};