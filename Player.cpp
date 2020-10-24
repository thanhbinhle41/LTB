#include "Player.h"


Player::Player()
{
	speed = 100.0f;
	//jumpHeight = 5;
	canJump = true;
	canMove = true;
	Body.setFillColor(Color(0, 0, 0, 0));
	animation.setOrigin((Vector2f)animation.getSize()*0.5f);
	
	
}

Player::~Player()
{
}

void Player::Init(const std::string& name, unsigned int act,int col, int row, float jumpHeight)
{
	this->col = col;
	this->row = row;
	this->nameImg = name;
	this->jumpHeight = jumpHeight;
	animation.Init(name, act,this->col,this->row); // 3 9
	animation.setOrigin((Vector2f)animation.getSize() * 0.5f);
}


void Player::Jump()
{
	if (canJump)
	{
		velocity.y = -sqrtf(2.0f * 9.810f * this->jumpHeight);
		animation.Init(nameImg, 2, this->col, this->row);
	}
		
}

void Player::Dead(float deltaTime)
{
	canJump = false;
	animation.Init(this->nameImg, 8, 3, 9);
	velocity.y += 9.810f * deltaTime ;
}


RectangleShape Player::getBody()
{
	return this->Body;
}

void Player::Update(float deltaTime, bool canMove)
{
	velocity.x = 0.0f;

	if (Keyboard::isKeyPressed(sf::Keyboard::A) && canMove)
	{
		
		velocity.x -= speed* deltaTime*4;
		animation.Init(nameImg, 3, this->col, this->row);
		
	}
		
	if (Keyboard::isKeyPressed(sf::Keyboard::D) && canMove)
	{
		
		velocity.x += speed* deltaTime*5;
		animation.Init(nameImg, 1, this->col, this->row);
		//velocity.y += 9.810f * deltaTime;
	}
		
	
	if (canJump)
	{
		velocity.y += 9.810f * deltaTime;
	}
		

	
	
	animation.Update(deltaTime);
	
	move(velocity);
	Body.setSize((Vector2f)animation.getSize()*2.f);
	Body.setOrigin(Body.getSize() * 0.5f);
	Body.setPosition(this->getPosition());
	Body.setOutlineThickness(3.f);
	Body.setOutlineColor(Color::Red);

	
}






