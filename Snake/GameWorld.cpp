#include "GameWorld.h"



GameWorld::GameWorld(sf::RenderWindow& pParentWindow)
	:m_borderThickness(30)
{
	m_worldBounds.setSize(sf::Vector2f(pParentWindow.getSize().x - m_borderThickness * 2,
							pParentWindow.getSize().y - m_borderThickness * 2));
	m_worldBounds.setFillColor(sf::Color::Black);
	m_worldBounds.setOutlineColor(sf::Color(192, 192, 192, 155));
	m_worldBounds.setOutlineThickness(m_borderThickness);
	m_worldBounds.setOrigin(m_worldBounds.getSize().x / 2, m_worldBounds.getSize().y / 2);
	m_worldBounds.setPosition(pParentWindow.getSize().x / 2, pParentWindow.getSize().y / 2);

	m_food = Food(sf::Vector2f(100, 100), 20.0f, sf::Color::Green, 10);
	m_score = new UITextElement("ScoreTest", 30, sf::Color::White, sf::Vector2f(m_worldBounds.getSize().x - 200.0f
																				, 0.0f));
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
	pWindow.draw(m_worldBounds);
	m_food.Render(pWindow);
	m_snake.Render(pWindow);
	m_score->Render(pWindow);
	
}
