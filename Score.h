#pragma once
#include <fstream>
#include "Settings.h"
#include "View.h"

class Score
{
private:
	sf::Font font;
	sf::Text scoreText;
	float scoreValue;
	float bestScoreValue;
public:
	Score();
	void setDefault();
	void updateTextPosition(const sf::View& view);
	void updateBestScore();
	const sf::Text& getScoreText() const;
	const float getScoreValue() const;
	const float getBestScoreValue() const;
	Score& operator += (const float value);
	~Score() = default;
	
};