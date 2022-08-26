#pragma once
#include "Doodler.h"
#include "Platform.h"
#include "TeleportPlatform.h"

/*
This class collects something that cannot be unambiguously attributed to any other
*/

class GameEngine
{
private:
	sf::SoundBuffer platformSoundBuffer;
	sf::SoundBuffer fastPlatformSoundBuffer;
	sf::SoundBuffer teleportPlatformSoundBuffer;
	sf::Sound sound;
public:
	GameEngine();
	bool intersects(const Doodler& doodler, const Platform* platform);
	bool collision(const std::vector<Platform*>& platforms, Doodler& doodler);
	~GameEngine() = default;
};