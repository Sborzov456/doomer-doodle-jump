#pragma once
#include "Platform.h"
#include "SecondaryFunctions.h"


class TeleportPlatform : public Platform
{
public:
	TeleportPlatform(const char* textureFilePath, const sf::Vector2f& startPosition = { 0.0, 0.0 });
	void teleportation(const int index);
	void disappearance();
	void appearance();
	virtual const unsigned char getType() const override;
	virtual const float getUpperBound() const override;
	virtual const float getLowerBound() const override;
	virtual const float getRightBound() const override;
	virtual const float getLeftBound() const override;
	virtual ~TeleportPlatform() = default;

	static bool collision;
	static short frameCounter;
};
