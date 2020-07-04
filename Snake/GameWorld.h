#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Snake.h"
#include "Food.h"
#include "UITextElement.h"
class GameWorld
{
public:
	GameWorld();
	~GameWorld();

	void HandleInput(sf::Keyboard::Key pKey, bool pPressed);
	void Update(sf::Time pDeltaTime);
	void Render(sf::RenderWindow& pWindow);

private:
	sf::RenderWindow* m_parentWindow;

	Snake m_snake;
	Food m_food;
	UITextElement* m_score;
};

