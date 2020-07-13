#include "GameWorld.h"
#include "Application.h"

#include <string>


GameWorld::GameWorld(Application* pAppPtr)
	:m_borderThickness(30)
	, m_AppPtr(pAppPtr)
{
	Initialise();
}


GameWorld::~GameWorld()
{
	delete m_score;
	delete m_endGameMessage;
}

void GameWorld::Initialise()
{
	// Initialise World Bounds
	m_worldBounds.setSize(sf::Vector2f(m_AppPtr->GetWindow().getSize().x - m_borderThickness * 2,
		m_AppPtr->GetWindow().getSize().y - m_borderThickness * 2));
	m_worldBounds.setFillColor(sf::Color::Black);
	m_worldBounds.setOutlineColor(sf::Color(192, 192, 192, 155));
	m_worldBounds.setOutlineThickness(m_borderThickness);
	m_worldBounds.setOrigin(m_worldBounds.getSize().x / 2, m_worldBounds.getSize().y / 2);
	m_worldBounds.setPosition(m_AppPtr->GetWindow().getSize().x / 2, m_AppPtr->GetWindow().getSize().y / 2);

	// Initialise food, score and endMessage
	m_food = Food(sf::Vector2f(100, 100), 20.0f, sf::Color::Green, 10);
	m_score = new UITextElement("Score", 30, sf::Color::White, sf::Vector2f(m_worldBounds.getSize().x - 200.0f
		, 17.0f));

	std::string tString = "You scored " + std::to_string(m_snake.GetFoodCollected()) + " points \n Press Esc to continue";
	m_endGameMessage = new UITextElement(tString, 100, sf::Color::Blue, sf::Vector2f(m_worldBounds.getSize().x / 2.0f,
																					m_worldBounds.getSize().y / 2.0f));

	// Set Playable Arena bounds
	m_playableArea = sf::FloatRect(sf::Vector2f(m_worldBounds.getGlobalBounds().left + m_borderThickness, m_worldBounds.getGlobalBounds().top + m_borderThickness),
		sf::Vector2f(m_worldBounds.getGlobalBounds().width - m_borderThickness * 2, m_worldBounds.getGlobalBounds().height - m_borderThickness * 2));
}

void GameWorld::HandleInput(sf::Keyboard::Key pKey, bool pPressed)
{
	m_snake.HandleInput(pKey, pPressed);

	switch (pKey)
	{
	case sf::Keyboard::Escape:
	{
		MenuReturn();
		break;
	}
	default:
		break;
	}
}

void GameWorld::Update(sf::Time pDeltaTime)
{
	if (!m_snake.IsAlive())
		m_endGameMessage->SetString("You scored " + std::to_string(m_snake.GetFoodCollected()) + " points \n Press Esc to continue");
	
	m_snake.Update(pDeltaTime.asSeconds());
	m_snake.HandleCollision(m_food, true, m_playableArea);
	this->UpdateScore();
}

void GameWorld::UpdateScore()
{
	m_score->SetString("Score " + std::to_string(m_snake.GetFoodCollected()));
}

void GameWorld::Render(sf::RenderWindow& pWindow)
{
	
	pWindow.draw(m_worldBounds);
	m_food.Render(pWindow);
	m_snake.Render(pWindow);
	m_score->Render(pWindow);

	if (!m_snake.IsAlive())
		m_endGameMessage->Render(pWindow);
	
}

void GameWorld::MenuReturn()
{
	// reset the game world and change the state of the Application
	GameWorldReset();
	m_AppPtr->m_appState = Application::AppState::MAIN_MENU;
}

void GameWorld::GameWorldReset()
{
	// Check whether the m_score and m_endMessage are nullptr. If not, free the allocated memory before calling
	// the Initialise() function in which new elements will be created
	if (m_score != nullptr)
	{
		delete m_score;
		m_score = nullptr;
	}
	if (m_endGameMessage != nullptr)
	{
		delete m_endGameMessage;
		m_endGameMessage = nullptr;
	}
		m_snake = Snake();
		Initialise();
}
