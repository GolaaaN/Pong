#include "Game.h"
#include "Ball.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//constructors & disctructor
Game::Game(){
	//initVariables();
	initWindow();
	initScores();
	initBorders();
	ball.randomAngle();
	cout << ball.getAngle() << endl;
}

Game::~Game() {
	delete this->window;
}

//functions 
void Game::update() {
	this->pollEvents();
	
	sf::Time time = clock.restart();
	float deltaTime = time.asSeconds();
	ball.updateBall(deltaTime);

	//Fps
	cout << time.asMilliseconds() << endl;
	//Fps

	if ((ball.getShape().getGlobalBounds().intersects(pad1.getShape().getGlobalBounds())) || ball.getShape().getGlobalBounds().intersects(pad2.getShape().getGlobalBounds()))
	{
		
		ball.setAngle(-ball.getAngle());
		ball.setAngle(ball.getAngle()+M_PI);
		
	}
	//
	if (ball.getShape().getGlobalBounds().intersects(botBorder.getGlobalBounds()) || ball.getShape().getGlobalBounds().intersects(topBorder.getGlobalBounds())) {
		
		ball.setAngle(-ball.getAngle());
	}
	//


	//update scores
	if (ball.getShape().getPosition().x < pad1.getShape().getPosition().x )
	{
		reset();
		cout << "reset the game" << flush;
	}
	if (ball.getShape().getPosition().x > pad2.getShape().getPosition().x)
	{
		reset();
		cout << "reset the game" << flush;
	}

	



	
	//pad 1 movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !(pad1.getShape().getGlobalBounds().intersects(topBorder.getGlobalBounds()))) {
		pad1.movePlayer('u', 6.0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !(pad1.getShape().getGlobalBounds().intersects(botBorder.getGlobalBounds()))) {
		pad1.movePlayer('d', 6.0);
	}
	//pad 2 movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !(pad2.getShape().getGlobalBounds().intersects(topBorder.getGlobalBounds()))) {
		pad2.movePlayer('u', 6.0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(pad2.getShape().getGlobalBounds().intersects(botBorder.getGlobalBounds()))) {
		pad2.movePlayer('d', 6.0);
	}
	
}

void Game::render() {
	this->window->clear(sf::Color::Black);
	pad2.drawPlayer(window);
	pad1.drawPlayer(window);
	ball.drawBall(window);
	window->draw(midBorder);
	window->draw(topBorder);
	window->draw(botBorder);
	
	this->window->display();
	

}

const bool Game::getWindowIsOpen()
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		window->setFramerateLimit(50);
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed){ 
			window->close(); 
		}
			
			
	}
}

void Game::initBorders() {
	//topborder
	topBorder.setSize(sf::Vector2f(800, 5));
	topBorder.setPosition(0, -5);
	topBorder.setFillColor(sf::Color::White);
	//bot border
	botBorder.setSize(sf::Vector2f(800, 5));
	botBorder.setPosition(0, 600);
	botBorder.setFillColor(sf::Color::White);
	//midborder
	midBorder.setSize(sf::Vector2f(3, 600));
	midBorder.setPosition((800 - 1.5) / 2, 0);
	midBorder.setFillColor(sf::Color::White);

}



void Game::initScores()
{
	sf::Font font;
	font.loadFromFile("ariel.ttf");
	score1.setFont(font);
	score1.setString("Hello world");
	score1.setFillColor(sf::Color::White);
	score1.setCharacterSize(80);
}

void Game::reset()
{
	ball.resetball();
}



void Game::initWindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pong", sf::Style::Close);
	window->setFramerateLimit(30);
	
}

void Game::initVariables() {
	this->window = nullptr;
}
