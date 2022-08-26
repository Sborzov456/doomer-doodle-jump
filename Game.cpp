#include "Game.h"

Game::Game() : doodler(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - WINDOW_HEIGHT / 9)),
map(),
gameEngine(),
view(),
score(),
menu(),
startGame(false),
gameOver(false),
window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Doomer Doodle"),
scoreString(),
bestScoreString()
{
	bestScoreString = std::to_string(score.getBestScoreValue());
	window.setFramerateLimit(240);
}

bool Game::checkGameOver() const
{
	if (doodler.getPosition().y + DOODLER_UPPER_BOUND >= view.getView().getCenter().y + WINDOW_HEIGHT / 2) {
		return true;
	}
	return false;
}

void Game::reset()
{
	view.setDefault();
	window.setView(view.getView());
	doodler.setDefault(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - WINDOW_HEIGHT / 9));
	map.setDefault();
	score.setDefault();
}

void Game::updateFrame()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		doodler.horizontalUpdate(HORIZONTAL_SPEED);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		doodler.horizontalUpdate(-HORIZONTAL_SPEED);
	}

	if (!gameEngine.collision(map.getPlatforms(), doodler)) {
		doodler.verticalUpdate();
	}

	if (view.update(doodler, window)) {
		score += doodler.getSpeed();
		score.updateTextPosition(view.getView());
	}

	map.updatePlatforms(view.getView(), score.getScoreValue());
	map.updateBackground(view.getView());

	map.drawBackground(window);
	map.drawPlatforms(window);
	window.draw(doodler.getSprite());
	window.draw(score.getScoreText());

	window.display();
}

void Game::run()
{
	std::string scoreString;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return;
			}
		}
		if (!startGame) {
			menu.frameCounter++;
			menu(!gameOver, scoreString, bestScoreString);
			startGame = menu.playButtonPressed(event, window);
			menu.draw(window);
			window.display();
		}
		else {
			this->updateFrame();
			if (gameOver = checkGameOver()) {
				startGame = false;
				scoreString = std::to_string(score.getScoreValue());
				score.updateBestScore();
				bestScoreString = std::to_string(score.getBestScoreValue());
				reset();
			}
		}
	}

}
