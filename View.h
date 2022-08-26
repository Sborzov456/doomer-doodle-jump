#pragma once
#include "Settings.h"
#include "Doodler.h"

class View
{
private:
	sf::View view;
public:
	View();
	void setDefault();
	bool update(const Doodler& doodler, sf::RenderWindow& window);
	const sf::View& getView() const;
	~View() = default;
};