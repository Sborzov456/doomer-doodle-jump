#include "Score.h"

Score::Score() : scoreValue(0.0)
{
	font.loadFromFile(FONT_FILE_PATH);
	scoreText.setFont(font);
	scoreText.setString(std::to_string(scoreValue));
	scoreText.setFillColor(sf::Color::White);
	std::ifstream in;
	in.open(BEST_SCORE_FILE_PATH);
	if (in.is_open()) {
		in >> bestScoreValue;
	}
	in.close();
}

void Score::setDefault()
{
	scoreValue = 0.0;
}

void Score::updateTextPosition(const sf::View& view)
{
	scoreText.setPosition(sf::Vector2f(view.getCenter().x - WINDOW_WIDTH / 2, view.getCenter().y - WINDOW_HEIGHT / 2));
}

void Score::updateBestScore()
{
	std::ifstream in;
	in.open(BEST_SCORE_FILE_PATH);
	if (in.is_open()) {
		in >> bestScoreValue;
	}
	in.close();

	std::ofstream out;
	out.open(BEST_SCORE_FILE_PATH);
	if (scoreValue > bestScoreValue && out.is_open()) {
		out.clear();
		bestScoreValue = scoreValue;
		out << bestScoreValue;
	}
	out.close();
}

const sf::Text& Score::getScoreText() const
{
	return scoreText;
}

const float Score::getScoreValue() const
{
	return scoreValue;
}

const float Score::getBestScoreValue() const
{
	return bestScoreValue;
}

Score& Score::operator+=(const float value) 
{
	scoreValue += static_cast<float>(abs(value));
	scoreText.setString(std::to_string(scoreValue));
	return *this;
}
