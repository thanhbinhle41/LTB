 #pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>
using namespace sf;


class Player :public Drawable, public Transformable
{

private:
	
	Animation animation;
	float speed;
	RectangleShape Body;
	Vector2f velocity;
	float jumpHeight;
	int row,col;
	std::string nameImg;
	bool canMove;
	bool canJump;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		target.draw(animation, states);
	}


public:
	Player();
	~Player();

	RectangleShape getBody();
	void Update(float deltaTime, bool canMove);
	void Init(const std::string& name, unsigned int act, int col, int row, float JumpHeight);
	void Jump();
	void Dead(float deltaTime);


	// bug view
	//Vector2f getPosition() { return Body.getPosition(); }
	



}; 
