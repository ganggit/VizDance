#include "button.h"

void button::showButton(sf::RenderWindow _screen) {
	// add button here

	text_MainWindowText.setString("Viz Dance");
	text_MainWindowText.setCharacterSize(40);
	text_MainWindowText.setFillColor(sf::Color::Blue);
	text_MainWindowText.setPosition(200, 30);
	_screen.draw(text_MainWindowText);
	text_MainWindowNewGame.setString("Start game");
	text_MainWindowNewGame.setCharacterSize(30);
	text_MainWindowNewGame.setFillColor(sf::Color::Green);
	text_MainWindowNewGame.setPosition(60, 150);

	text_MainWindowExit.setString("End game");
	text_MainWindowExit.setCharacterSize(30);
	text_MainWindowExit.setFillColor(sf::Color::Red);
	text_MainWindowExit.setPosition(60, 200);

	spr_ButtonNewGame.setTexture(img_button);
	spr_ButtonNewGame.setPosition(0, 150);
	spr_ButtonNewGame.setScale(1.8, 1);
	_screen.draw(spr_ButtonNewGame);

	spr_ButtonExitGame.setTexture(img_button);
	spr_ButtonExitGame.setPosition(0, 200);
	spr_ButtonExitGame.setScale(1.8, 1);
	_screen.draw(spr_ButtonExitGame);
}

/*
sf::Texture img_button;
if (!img_button.loadFromFile("../Ressources/Center.png"))
	std::cout << "Error LFF : Failed to load  Resource/img_button.png" << std::endl;
else std::cout << "Resource/img_button.png successfully loaded" << std::endl;

sf::Font font_English;
if (!font_English.loadFromFile("../Ressources/font.ttf"))
	std::cout << "Error LFF : Failed to load Resource/font.ttf" << std::endl;
else std::cout << "Resource/font_English.ttf successfully loaded" << std::endl;

sf::Text text_MainWindowText("Viz Dance", font_English);
text_MainWindowText.setCharacterSize(40);
text_MainWindowText.setFillColor(sf::Color::Blue);
text_MainWindowText.setPosition(200, 30);

sf::Text text_MainWindowNewGame("New Game", font_English);
text_MainWindowNewGame.setCharacterSize(30);
text_MainWindowNewGame.setFillColor(sf::Color::Green);
text_MainWindowNewGame.setPosition(60, 150);

sf::Text text_MainWindowExit("Exit Game", font_English);
text_MainWindowExit.setCharacterSize(30);
text_MainWindowExit.setFillColor(sf::Color::Red);
text_MainWindowExit.setPosition(60, 200);

sf::Sprite spr_ButtonNewGame;
spr_ButtonNewGame.setTexture(img_button);
spr_ButtonNewGame.setPosition(0, 150);
//spr_ButtonNewGame.setSize(sf::Vector2f(100,48));
spr_ButtonNewGame.setScale(1.8, 1);

sf::Sprite spr_ButtonExitGame;
spr_ButtonExitGame.setTexture(img_button);
spr_ButtonExitGame.setPosition(0, 200);
spr_ButtonExitGame.setScale(1.8, 1);

sf::Sprite spr_SpaceShip;
*/