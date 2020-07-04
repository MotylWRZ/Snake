#include "GameWorld.h"



GameWorld::GameWorld()
{
	m_food = Food(sf::Vector2f(100, 100), 20.0f, sf::Color::Green, 10);
	m_score = new UITextElement("ScoreTest", 30, sf::Color::White, sf::Vector2f(1000.0f, 100.0f));
}


GameWorld::~GameWorld()
{
	delete m_score;
}

void GameWorld::HandleInput(sf::Keyboard::Key pKey, bool pPressed)
{
	m_snake.HandleInput(pKey, pPressed);
}

void GameWorld::Update(sf::Time pDeltaTime)
{
	m_snake.Update(pDeltaTime.asSeconds());
	m_snake.HandleCollision(m_food);
}

void GameWorld::Render(sf::RenderWindow& pWindow)
{
	m_food.Render(pWindow);
	m_snake.Render(pWindow);
	m_score->Render(pWindow);
}
