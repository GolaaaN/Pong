#include "Ball.h"
#include <time.h> 



//functions
void Ball::randomAngle()
{
	srand(time(NULL));
	
	
	this->ballAngle = ((rand() % 100) / 100.f) * (2*M_PI);

}

void Ball::setVelocityX(float x)
{
	this->velocity.x = x;
}

void Ball::setVelocityY(float y)
{
	this->velocity.y = y;
}

float Ball::getVelocityX()
{
	return this->velocity.x;
}
float Ball::getVelocityY()
{
	return this->velocity.y;
}


void Ball::setSpeed(float x)
{
	this->ballSpeed = x;
}


float Ball::getSpeed()
{
	return this->ballSpeed;
}


void Ball::setAngle(float x)
{
	this->ballAngle = x;
}


float Ball::getAngle()
{
	return this->ballAngle;
}

void Ball::resetball()
{
	randomAngle();
	shape.setPosition(400 - 8, 300 - 8);
}






Ball::Ball(float x, float y)
{
	shape.setPosition(400 - 8, 300 - 8);
}

sf::CircleShape Ball::getShape()
{
	return shape;
}


void Ball::drawBall(sf::RenderWindow* window)
{
	window->draw(shape);
}

void Ball::initBall()
{
	shape.setFillColor(sf::Color::White);
	shape.setPosition(400-8, 300-8);
}

void Ball::updateBall(float deltaTime)
{
	float factor = deltaTime * ballSpeed;
	velocity.x = std::cos(ballAngle) * factor;
	velocity.y = std::sin(ballAngle) * factor;
	shape.move(velocity.x, velocity.y);

}






