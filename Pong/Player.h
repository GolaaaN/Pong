#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player 
{

	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(10.f, 70.f));
	int score = 0;

public:
	//constructors
	Player();

	Player(float x, float y);
	




	//functions
	public:
		void setScore(int score);
		int getScore();
		sf::RectangleShape getShape();
		void initPlayer();
		void drawPlayer(sf::RenderWindow* window);
		void movePlayer(char direction, float moveSpeed);
		
		
};




