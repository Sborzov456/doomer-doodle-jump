#include "View.h"

View::View() : view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)) {}

void View::setDefault()
{
	view.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
}

/*
	returns true if the view has been changed, 
	which is the same as raising the height of the doodler, which is used for score calculating
*/
bool View::update(const Doodler& doodler, sf::RenderWindow& window)
{
	if (doodler.getPosition().y <= view.getCenter().y - WINDOW_HEIGHT / 2 + VIEW_UPPER_BOUND && doodler.getSpeed() <= 0) {
		view.move(0, doodler.getSpeed());
		window.setView(view);
		return true;
	}
	return false;
}

const sf::View& View::getView() const
{
	return view;
}
