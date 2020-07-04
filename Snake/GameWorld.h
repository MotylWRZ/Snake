#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Snake.h"
#include "Food.h"
#include "UITextElement.h"
class GameWorld
{
public:
	GameWorld(sf::RenderWindow& pParentWindow);
	~GameWorld();

	void HandleInput(sf::Keyboard::Key pKey, bool pPressed);
	void Update(sf::Time pDeltaTime);
	void UpdateScore();
	void Render(sf::RenderWindow& pWindow);

private:
	sf::RectangleShape m_worldBounds;
	float m_worldWidth;
	float m_worldHeight;
	int m_borderThickness;

	Snake m_snake;
	Food m_food;
	UITextElement* m_score;
};

