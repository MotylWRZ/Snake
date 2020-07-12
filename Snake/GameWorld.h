#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Snake.h"
#include "Food.h"
#include "UITextElement.h"

class Application;

class GameWorld
{
public:
	GameWorld(Application* pAppPtr);
	~GameWorld();

	void Initialise();
	void HandleInput(sf::Keyboard::Key pKey, bool pPressed);
	void Update(sf::Time pDeltaTime);
	void UpdateScore();
	void Render(sf::RenderWindow& pWindow);
	void MenuReturn();
	void GameWorldReset();

private:
	sf::RectangleShape m_worldBounds;
	sf::FloatRect m_playableArea;
	float m_worldWidth;
	float m_worldHeight;
	int m_borderThickness;

	Snake m_snake;
	Food m_food;
	UITextElement* m_score;
	UITextElement* m_endGameMessage;

	Application* m_AppPtr;
};

