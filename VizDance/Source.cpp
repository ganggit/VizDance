
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <SFML/Window.hpp>
#include "Audio.h"
#include "Constants.h"
//#include "constants.h"
//#include "Input.h"
//#include "MidiParserIP.h"
#include "Scene.h"
//#include "Resource.h"
//#include "MidiFile.h"
//#include "Options.h"
//#include <iostream>

using namespace cv;
using namespace std;

Constants constants;

void run() {
	input in = input(false, constants);
	
	sf::RenderWindow window2(sf::VideoMode(constants.SCREEN_WIDTH, constants.SCREEN_HEIGHT), "Game start");

	// add button here
	 // declarations
	
	sf::Texture play_button;
	if (!play_button.loadFromFile("../Ressources/play-btn.png"))
		std::cout << "Error LFF : Failed to load  Resource/img_button.png" << std::endl;
	else std::cout << "Resource/img_button.png successfully loaded" << std::endl;


	sf::Texture exit_button;
	if (!exit_button.loadFromFile("../Ressources/exit-btn.png"))
		std::cout << "Error LFF : Failed to load  Resource/img_button.png" << std::endl;
	else std::cout << "Resource/img_button.png successfully loaded" << std::endl;

	sf::Font font_English;
	if (!font_English.loadFromFile("../Ressources/font.ttf"))
		std::cout << "Error LFF : Failed to load Resource/font.ttf" << std::endl;
	else std::cout << "Resource/font_English.ttf successfully loaded" << std::endl;

	sf::Text text_MainWindowText("Viz Dance", font_English);
	text_MainWindowText.setCharacterSize(60);
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
	spr_ButtonNewGame.setTexture(play_button);
	spr_ButtonNewGame.setPosition(50, 250);
	//spr_ButtonNewGame.setSize(sf::Vector2f(100,48));
	spr_ButtonNewGame.setScale(1.8, 1);

	sf::Sprite spr_ButtonExitGame;
	spr_ButtonExitGame.setTexture(exit_button);
	spr_ButtonExitGame.setPosition(50, 310);
	spr_ButtonExitGame.setScale(1.8, 1);

	sf::Sprite spr_SpaceShip;

	//int Resource, sf::Music Song, sf::RenderWindow Screen, int Input, int BeatsPerBoard
	sf::Clock clock;
	while (window2.isOpen())
	{
		sf::Event event;
		while (window2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}

		// main loop :
		
		window2.clear(sf::Color(11, 11, 11));
		window2.draw(spr_ButtonNewGame);
		window2.draw(spr_ButtonExitGame);
		window2.draw(text_MainWindowText);
		sf::Vector2f mouse = window2.mapPixelToCoords(sf::Mouse::getPosition(window2));
		//if (sprite.contains(sf::Mouse::getPosition(mainWindow).x, sf::Mouse::getPosition(mainWindow).y))
		if (spr_ButtonNewGame.getGlobalBounds().contains(mouse))
		{
			std::cout << "Hovered over button!" << std::endl;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Button pressed" << std::endl;

				sf::RenderWindow window(sf::VideoMode(constants.SCREEN_WIDTH, constants.SCREEN_HEIGHT), "VisDance");
				Scene *sc = new Scene(2, window, in, 2);
			
				while (window.isOpen()) {
					sf::Event subevent;
					while (window.pollEvent(subevent))
					{
						if (subevent.type == sf::Event::Closed)
							window.close();
					}
					//window.clear(sf::Color::Black);
					in.run();
					sc->run(in, clock);
					//window.display();
				}
			}
		}

		if (spr_ButtonExitGame.getGlobalBounds().contains(mouse))
		{
			std::cout << "Hovered over button!" << std::endl;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				std::cout << "Button pressed" << std::endl;
				window2.close();
			}
		}
		window2.display();
	}
}

int main()
{
	run();
	return 0;
}