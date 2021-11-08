#include "Player.h"

//functions



//constructors
Player::Player(){

}
Player::Player(float x, float y) {
	shape.setPosition(sf::Vector2f(x,y));
}



void Player::drawPlayer(sf::RenderWindow* window)
{
	window->draw(shape);
} 

void Player::movePlayer(char direction, float moveSpeed) {	
	
		if (direction == 'u' ) {
			shape.move(0, -moveSpeed);
		}
		if (direction == 'd') {
			shape.move(0, moveSpeed);
		}

}

sf::RectangleShape Player::getShape() {
	return shape;
}

	void Player::setScore(int score)
	{
		this->score = score;
	}

	int Player::getScore()
	{
		return this->score;
	}





void Player::initPlayer()
{
	shape.setPosition(0.f, 300.f);
}
