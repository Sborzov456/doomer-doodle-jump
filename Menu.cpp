#include "Menu.h"

Menu::Menu() : frameCounter(0), tileLeft(0), tileTop(0), mouse(), isFirstGame(true)
{
	playButtonTexture.loadFromFile(PLAY_BUTTON_FILE_PATH);
	playButtonSprite.setTexture(playButtonTexture);
	playButtonSprite.setOrigin(playButtonTexture.getSize().x / 2, playButtonTexture.getSize().y / 2);
	playButtonSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100);

	backgroundTexture.loadFromFile(MENU_BACKGROUND_FILE_PATH);
	backgroundSprite.setTexture(backgroundTexture);

	scoreTextTexture.loadFromFile(SCORE_TEXT_FILE_PATH);
	scoreTextSprite.setTexture(scoreTextTexture);
	scoreTextSprite.setOrigin(scoreTextTexture.getSize().x / 2, scoreTextTexture.getSize().y / 2);
	scoreTextSprite.setPosition(130, 700);

	bestScoreTextTexture.loadFromFile(BEST_SCORE_TEXT_FILE_PATH);
	bestScoreTextSprite.setTexture(bestScoreTextTexture);
	bestScoreTextSprite.setOrigin(bestScoreTextTexture.getSize().x / 2, bestScoreTextTexture.getSize().y / 2);
	bestScoreTextSprite.setPosition(180, 750);

	font.loadFromFile(FONT_FILE_PATH);

	//SCORE
	scoreValueText.setFont(font);
	scoreValueText.setPosition(200, 680);
	scoreValueText.setFillColor(sf::Color::White);
	scoreValueText.setLetterSpacing(1.5);

	scoreValuePurpleStroke.setFont(font);
	scoreValuePurpleStroke.setPosition(203, 680);
	scoreValuePurpleStroke.setFillColor(sf::Color(103, 65, 233));
	scoreValuePurpleStroke.setScale(1.15, 1.15);
	
	scoreValueBlackStroke.setFont(font);
	scoreValueBlackStroke.setPosition(195, 680);
	scoreValueBlackStroke.setFillColor(sf::Color::Black);
	scoreValueBlackStroke.setScale(1.15, 1.15);
	scoreValueBlackStroke.setLetterSpacing(1.11);

	//BEST SCORE
	bestScoreValueText.setFont(font);
	bestScoreValueText.setPosition(300, 730);
	bestScoreValueText.setFillColor(sf::Color::White);
	bestScoreValueText.setLetterSpacing(1.5);

	bestScoreValuePurpleStroke.setFont(font);
	bestScoreValuePurpleStroke.setPosition(303, 730);
	bestScoreValuePurpleStroke.setFillColor(sf::Color(103, 65, 233));
	bestScoreValuePurpleStroke.setScale(1.15, 1.15);

	bestScoreValueBlackStroke.setFont(font);
	bestScoreValueBlackStroke.setPosition(295, 730);
	bestScoreValueBlackStroke.setFillColor(sf::Color::Black);
	bestScoreValueBlackStroke.setScale(1.15, 1.15);
	bestScoreValueBlackStroke.setLetterSpacing(1.11);


	gameOverTexture.loadFromFile(GAME_OVER_FILE_PATH);

	doodlerTileSet.loadFromFile(SMOKING_DOODLER_TILESET_FILE_PATH);
	doodlerTile.setTexture(doodlerTileSet);
	doodlerTile.setOrigin(87 / 2, 77 / 2);
	doodlerTile.setPosition(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50);
}

void Menu::operator()(const bool isFirstGame, const std::string scoreString, const std::string bestScoreString)
{
	if (frameCounter == 400) {
		frameCounter = 0;
	}
	if (frameCounter >= 200) {
		tileLeft = (frameCounter - 200) / 20 * 250;
	}
	else {
		tileLeft = frameCounter / 20 * 250;
	}
	tileTop = frameCounter / 200 * 250;
	doodlerTile.setTextureRect(sf::Rect<int>(tileLeft, tileTop, 250, 250));

	if (!isFirstGame) {
		gameOverSprite.setTexture(gameOverTexture);
	}
	scoreValueText.setString(scoreString);
	scoreValuePurpleStroke.setString(scoreString);
	scoreValueBlackStroke.setString(scoreString);

	bestScoreValueText.setString(bestScoreString);
	bestScoreValuePurpleStroke.setString(bestScoreString);
	bestScoreValueBlackStroke.setString(bestScoreString);

}

bool Menu::playButtonPressed(const sf::Event& event, const sf::RenderWindow& window)
{
	if (mouse.getPosition(window).x >= playButtonSprite.getPosition().x - PLAY_BOTTON_LEFT_BOUND &&
		mouse.getPosition(window).x <= playButtonSprite.getPosition().x + PLAY_BOTTON_RIGHT_BOUND &&
		mouse.getPosition(window).y >= playButtonSprite.getPosition().y - PLAY_BOTTON_UPPER_BOUND &&
		mouse.getPosition(window).y <= playButtonSprite.getPosition().y + PLATFORM_LOWER_BOUND) {
		playButtonSprite.setScale(1.05, 1.05);
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				return true;
			}
		}
	}
	else {
		playButtonSprite.setScale(1.0, 1.0);
	}
	return false;
}

void Menu::draw(sf::RenderWindow& window) const
{
	window.draw(backgroundSprite);
	window.draw(playButtonSprite);
	window.draw(scoreTextSprite);
	window.draw(scoreValuePurpleStroke);
	window.draw(scoreValueBlackStroke);
	window.draw(scoreValueText);
	window.draw(bestScoreValuePurpleStroke);
	window.draw(bestScoreValueBlackStroke);
	window.draw(bestScoreValueText);
	window.draw(bestScoreTextSprite);
	window.draw(gameOverSprite);
	window.draw(doodlerTile);
}

