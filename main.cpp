#include<SFML/Graphics.hpp>
#include<iostream>
#include"globals.h"
#include"frog.h"
#include"Car.h"

using namespace std;


int main()
{
	//game variables and setup
	srand(time(NULL)); //seed rand
	bool keys[] = { false, false, false, false }; //user input
	int timer = 0;


	frog Phrog;
	Car carr;

	//SFML Boilerplate
	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger!");

	while (screen.isOpen()) { //game loop
		//input section
		sf::Event event;
		while (screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				screen.close();
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else keys[UP] = false;
		

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else keys[DOWN] = false;


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else keys[LEFT ] = false;


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else keys[RIGHT] = false;

		}
		
		//physics section------------------------------------------------
		timer++;
		if (timer > 500) {
			Phrog.jump(keys);
			timer = 0;
			
		}
		carr.move();
		if (carr.collide(Phrog.xpos, Phrog.ypos) == true) {
			Phrog.ded();
		}
		if (Phrog.lives <= 0) {
			screen.close();
		}
		//render section-------------------------------------------------
		screen.clear();

		Phrog.draw(screen);
		carr.draw(screen);

		screen.display();

	} //end of game loop-------------------------------------------------
	cout<< "game over..." << endl;
	return 0;
}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else keys[DOWN] = false;


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else keys[LEFT ] = false;


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else keys[RIGHT] = false;

		}
		
		//physics section------------------------------------------------
		timer++;
		if (timer > 500) {
			Phrog.jump(keys);
			timer = 0;
		}
		
		//render section-------------------------------------------------
		screen.clear();

		Phrog.draw(screen);

		screen.display();

	} //end of game loop-------------------------------------------------
	cout<< "game over..." << endl;
	return 0;
}
