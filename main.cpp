#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include "Enimies.h"
using namespace std;
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(900, 800), "SFML Tutorial", Style::Close | Style::Resize);
	window.setFramerateLimit(60);

	//bug
	//View view(Vector2f(0.0f, 0.0f), Vector2f(900.0f, 800.0f));

	const float gravity = 9.8;

	Player Hero;
	Hero.Init("kit_from_firefox.png", 0,3,9,5);
	Hero.setScale(Vector2f(2.0f, 2.0f));
	Hero.setPosition(Vector2f(206.0f, 206.0f));

	Enimies Enimie;
	Enimie.Init("Android2.png",0,3,9,9);
	Enimie.setScale(Vector2f(2.0f, 2.0f));
	Enimie.setPosition(Vector2f(700.0f, 206.0f)); 


	RectangleShape ground;
	ground.setPosition(Vector2f(0, window.getSize().y / 5*4));
	ground.setSize(Vector2f(window.getSize().x, window.getSize().y/5));
	ground.setFillColor(Color::Blue);




	

	float deltaTime;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event evt;

		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::MouseButtonReleased:
				cout << "Mouse Released\n";
				break;
			case Event::KeyReleased:
				//velocity.x = 0;
				break;
			default:
				break;
			}
		}
		// Hero
		if (ground.getGlobalBounds().intersects(Hero.getBody().getGlobalBounds())) {
			//cout << "da va cham ne" << endl;
			Hero.Jump();
		}
		// Enimie
		if (ground.getGlobalBounds().intersects(Enimie.getBody().getGlobalBounds())) {
			//cout << "da va cham ne" << endl;
			Enimie.Jump();
		}

		// Collision
		if (Hero.getBody().getGlobalBounds().intersects(Enimie.getBody().getGlobalBounds()))
		{
			//cout << "dead" << endl;
			Hero.Dead(deltaTime);
		}


		window.clear(Color(150, 150, 150));

		// view
		

		window.draw(ground);

		window.draw(Hero.getBody());
		Hero.Update(deltaTime,true);

		window.draw(Hero);
		
		window.draw(Enimie.getBody());
		Enimie.Update(deltaTime,false);
		window.draw(Enimie);


		
		window.display();
	}


	return 0;
}