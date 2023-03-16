#include "frog.h"
#include "globals.h"
#include <SFML/Graphics.hpp>
#include<Windows.h>

//contructor needed for class variables
frog::frog() {
	xpos = 500;
	ypos = 954;
	lives = 5;
	xVel = 0;
	yVel = 0;
}

//draw function for square frog
void frog::draw(sf::RenderWindow& window) {
	sf::RectangleShape FrogPic(sf::Vector2f(20, 20));
	FrogPic.setFillColor(sf::Color(50, 200, 50));
	FrogPic.setPosition(xpos, ypos);
	window.draw(FrogPic);
}

//unfinshed movement function,, a pointer to the array that holds key presses
void frog::jump(bool* keys) {
	if (keys[UP] == true)
		yVel = -50;
	else if (keys[DOWN] == true)
		yVel = 50;
	else
		yVel = 0;
	ypos += yVel;
}

//this function kills the frog
void frog::ded() {
	//play explosion here
	Beep(500, 500); //temporary sound effects
	lives--;
	xpos = 500;
	ypos = 954;
}
