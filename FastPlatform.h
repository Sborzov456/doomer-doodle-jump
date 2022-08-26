#pragma once
#include "Platform.h"

/*
A platform in constant motion from edge to edge of the screen
*/

class FastPlatform : public Platform
{
private:
	float speed; //movement speed
public:
	FastPlatform(const char* textureFilePath, const sf::Vector2f& startPosition = { 0.0, 0.0 });
	void horizontalUpdate();
	virtual const unsigned char getType() const override;
	virtual const float getUpperBound() const override;
	virtual const float getLowerBound() const override;
	virtual const float getRightBound() const override;
	virtual const float getLeftBound() const override;
	virtual ~FastPlatform() = default;
};