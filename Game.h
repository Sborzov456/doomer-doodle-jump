#pragma once
#include "Doodler.h"
#include "Platform.h"
#include "Map.h"
#include "GameEngine.h"
#include "View.h"
#include "Score.h"
#include "Menu.h"

class Game
{
private:
	sf::RenderWindow window;
	Doodler doodler;
	Map map;
	GameEngine gameEngine;
	View view;
	Score score;
	Menu menu;
	bool startGame;
	bool gameOver;
	std::string scoreString;
	std::string bestScoreString;
public:
	Game();
	bool checkGameOver() const;
	void reset();
	void updateFrame(); // the main game loop
	void run(); // launch game and menu
	~Game() = default;
};