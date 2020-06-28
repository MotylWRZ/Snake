#pragma once
#include "SFML/Graphics.hpp"
#include "SinglyLinkedList.h"
#include "SnakeBodyElem.h"
#include <vector>


enum EMoveDirection
{
	E_MOVE_UP,
	E_MOVE_RIGHT,
	E_MOVE_DOWN,
	E_MOVE_LEFT
};

class Snake
{
public:
	Snake();
	virtual ~Snake();

	void ChangeMoveDirection(EMoveDirection pNewDirection);
	void HandleInput(sf::Keyboard::Key pKey, bool pPressed);
	void Move();
	void AddBodyElem();
	
	
	void Update(float pDeltaTime);
	void Render(sf::RenderWindow& pWindow);

private:
	
	int m_health;
	float m_speed;
	int m_foodColected;
	sf::Vector2f m_snakeBodyElemSize;
	sf::Vector2f m_position;
	sf::Color m_headColor;
	sf::Color m_bodyColor;

	SinglyLinkedList<SnakeBodyElem> m_snakeBody;
	EMoveDirection m_eCurrMoveDirection;
	sf::Vector2f m_movement;
};

