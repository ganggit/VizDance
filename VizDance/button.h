#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class button {

public:
	sf::Texture img_button;
	sf::Font font;
	sf::Text text_MainWindowText;
	sf::Text text_MainWindowNewGame;
	sf::Text text_MainWindowExit;
	sf::Sprite spr_ButtonNewGame;
	sf::Sprite spr_ButtonExitGame;

	button();

	void showButton(sf::RenderWindow _screen);

};