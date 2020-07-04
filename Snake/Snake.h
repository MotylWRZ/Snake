#pragma once
#include "SFML/Graphics.hpp"
#include "SinglyLinkedList.h"
#include "SnakeBodyElem.h"
#include "Food.h"

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
	void Update(float pDeltaTime);
	void Render(sf::RenderWindow& pWindow);
	void HandleCollision(Food& pFood, bool pWorldCollisionActive = false, 
						sf::FloatRect pWorldBounds = sf::FloatRect(sf::Vector2f(0.0f,0.0f), sf::Vector2f(0.0f, 0.0f)));

	inline int GetFoodCollected() { return m_foodColected; };

private:
	void CheckSnakeSnakeCollision();
	void CheckSnakeFoodCollision(Food& pFood);
	void CheckSnakeWorldCollision(sf::FloatRect pWorldBounds);
	void AddBodyElem();
	void Move();
	

private:
	bool	m_bIsAlive;
	bool	m_worldCollisonActive;
	int		m_health;
	float	m_speed;
	int		m_foodColected;
	float	m_BodyElemSpace;
	int		m_initialSnakeLenght;
	sf::Vector2f	m_snakeBodyElemSize;
	sf::Vector2f	m_position;
	sf::Color		m_headColor;
	sf::Color		m_bodyColor;
	sf::FloatRect	m_worldBounds;

	SinglyLinkedList<SnakeBodyElem> m_snakeBody;
	EMoveDirection					m_eCurrMoveDirection;
	sf::Vector2f					m_movement;
};

