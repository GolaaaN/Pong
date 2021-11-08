#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <cmath>

using namespace std;


class Ball 
{
	//vars
	sf::CircleShape shape = sf::CircleShape(8.f);
	
	float ballSpeed = 250;
	float ballAngle = 0;

	sf::Vector2f velocity;

public:

	void randomAngle();
	void setVelocityX(float x);
	void setVelocityY(float y);
	float getVelocityX();
	float getVelocityY();
	float getSpeed();
	void setSpeed(float x);
	void setAngle(float x);
	float getAngle();
	void resetball();


	//counstructor
	Ball(float x, float y);


	sf::CircleShape getShape();
	void setBallAngle(float ballAngle);

	void setShape(sf::CircleShape shape);
	
	
	//functions
	void drawBall(sf::RenderWindow* window);
	void initBall();
	void updateBall(float deltaTime);


};




	
	





