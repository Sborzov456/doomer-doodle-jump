#pragma once
#include "SecondaryFunctions.h"

const float getRandomNumber(const float& min, const float& max, std::mt19937& engine)
{
	const float fraction = 1.0 / (static_cast<float>(engine.max()) + 1.0);
	return (static_cast<float>(engine()) * fraction * (max - min + 1) + min);
}

const float transparencyGradientFunction(const float x)
{
	return static_cast<float>(pow(x, 0.66));
}