#pragma once
#include "Settings.h"
#include <string>

class Menu
{
private:
	sf::Font font;

	sf::Sprite playButtonSprite;
	sf::Texture playButtonTexture;

	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;

	sf::Sprite scoreTextSprite;
	sf::Texture scoreTextTexture;
	sf::Text scoreValueText;
	sf::Text scoreValuePurpleStroke;
	sf::Text scoreValueBlackStroke;

	sf::Sprite bestScoreTextSprite;
	sf::Texture bestScoreTextTexture;
	sf::Text bestScoreValueText;
	sf::Text bestScoreValuePurpleStroke;
	sf::Text bestScoreValueBlackStroke;

	sf::Sprite gameOverSprite;
	sf::Texture gameOverTexture;

	sf::Sprite doodlerTile;
	sf::Texture doodlerTileSet;
	int tileLeft;
	int tileTop;

	sf::Mouse mouse;

	bool isFirstGame;
	
public:
	Menu();
	void operator()(const bool isFirstGame, const std::string scoreString = "", const std::string bestScoreString = "");
	bool playButtonPressed(const sf::Event& event, const sf::RenderWindow& window);
	void draw(sf::RenderWindow& window) const;
	~Menu() = default;

	unsigned short frameCounter;
};