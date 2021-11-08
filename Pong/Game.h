#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Player.h"
#include "Ball.h"

class Game
{
	//variables
private:
	sf::RenderWindow* window;
	sf::Event event;

public:
	//constructors & disctructor
	Game();
	~Game();
	

	//functions 
	void update();
	void render();

	const bool getWindowIsOpen();

private:
	void pollEvents();
	void initWindow();
	void initVariables();
	void initBorders();
	void initPlayers();
	void initScores();
	void reset();
	


	//clock 
	sf::Clock clock;
	

	//Game objects
	Ball ball = Ball(400 - 8, 300 - 8);
	Player pad1 = Player(10,300-35);
	Player pad2 = Player(780,300-35);
	sf::RectangleShape topBorder;
	sf::RectangleShape botBorder;
	sf::RectangleShape midBorder;
	sf::Text score1;
	sf::Text score2;
	
	

};

