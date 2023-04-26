#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"globals.h"
using namespace std;

class Car {
private:
	float xpos = 900;
	float ypos = 500;
	int green = rand() % 101 + 100;
	int blue = rand() % 101 + 100;
	int direction = RIGHT;

public:
	void draw(sf::RenderWindow& window);
	void move();
	bool collide(int x, int y);
	void PrintInfo() { cout << "I am a car and my position is" << xpos << "," << ypos << endl; }
};
